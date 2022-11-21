#include "philo.h"

int	ft_philo_log(t_program *prog, t_philo *philo, char *str, int sleep)
{
	pthread_mutex_lock(&prog->mutex);
	if (prog->exit > 0)
	{
		pthread_mutex_unlock(&prog->mutex);
		return (0);
	}
	printf("%lld %d %s\n", ft_get_time() - prog->start, philo->pos, str);
	pthread_mutex_unlock(&prog->mutex);
	if (sleep > 0)
		usleep(sleep * 1000);
	return (1);
}

int	ft_eat(t_program *prog, t_philo *philo)
{
	int	pos[2];
	int	swap;;

	pos[0] = philo->pos - 1;
	if (philo->pos == prog->size)
		pos[1] = 0;
	else
		pos[1] = philo->pos;
	if (philo->pos % 2 == 0)
	{
		swap = pos[0];
		pos[0] = pos[1];
		pos[1] = swap;
	}
	if (!ft_get_forks(prog, philo, pos))
		return (0);
	philo->last = ft_get_time();
	philo->die = 0;
	if (!ft_philo_log(prog, philo, "is eating", prog->eat))
		return (ft_put_forks(prog, philo, pos));
	ft_put_forks(prog, philo, pos);
	if (prog->must_eat > 0)
		return (++philo->times_eat < prog->must_eat);
	return (1);
}

int	ft_died(t_program *prog, t_philo *philo)
{
	printf("%lld %d died\n", ft_get_time() - prog->start, philo->pos);
	prog->exit = 1;
	pthread_mutex_unlock(&prog->mutex);
	return (0);
}
