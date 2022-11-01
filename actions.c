#include "philo.h"

int	ft_philo_log(t_program *prog, t_philo *philo, char *str)
{
	pthread_mutex_lock(&prog->mutex);
	if (prog->exit > 0)
	{
		pthread_mutex_unlock(&prog->mutex);
		return (0);
	}
	printf("%lld %d %s\n", ft_get_time() - prog->start, philo->pos, str);
	pthread_mutex_unlock(&prog->mutex);
	return (1);
}

int	ft_eat(t_program *prog, t_philo *philo)
{
	int	left;
	int	right;

	left = philo->pos - 1;
	if (philo->pos == prog->size)
		right = 0;
	else
		right = philo->pos;
	if (!ft_get_fork(prog, philo, right) || !ft_get_fork(prog, philo, left))
		return (0);
	if (!ft_philo_log(prog, philo, "is eating"))
	usleep(prog->eat * 1000);
	pthread_mutex_unlock(&prog->forks[right]);
	pthread_mutex_unlock(&prog->forks[left]);
	return (1);
}

int	ft_sleep(t_program *prog, t_philo *philo)
{
	if (!ft_philo_log(prog, philo, "is sleeping"))
		return (0);
	usleep(prog->sleep * 1000);
	return (1);
}

int	ft_died(t_program *prog, t_philo *philo)
{
	pthread_mutex_lock(&prog->mutex);
	printf("%lld %d died\n", ft_get_time() - prog->start, philo->pos);
	prog->exit = 1;
	pthread_mutex_unlock(&prog->mutex);
	return (0);
}
