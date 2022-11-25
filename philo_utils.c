#include "philo.h"

int	ft_atoi(const char *str)
{
	int	value;
	int	signal;

	value = 0;
	signal = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signal = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		value = value * 10 + (*str - '0');
		str++;
	}
	return (value * signal);
}

long long	ft_get_time(void)
{
	struct timeval  tv;
	
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_sleep(int time_sleep)
{
	long long       time;

	time = ft_get_time();
	while (ft_get_time() - time < time_sleep)
		usleep(100);
}

int	ft_check_died(t_program *prog, t_philo *philo, int *pos)
{
	if (ft_get_time() - philo->last > prog->die)
	{
		ft_put_forks(prog, philo, pos);
		pthread_mutex_lock(&prog->mutex_exit);
		if (prog->exit == 1)
		{
			pthread_mutex_unlock(&prog->mutex_exit);
			return (0);
		}
		return (ft_died(prog, philo));
	}
	return (1);
}
