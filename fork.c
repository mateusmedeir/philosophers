#include "philo.h"


int	ft_put_forks(t_program *prog, t_philo *philo, int *pos)
{
	pthread_mutex_lock(&prog->forks_mutex);
	while (philo->forks > 0)
		prog->forks[pos[--philo->forks]] = 1;
	pthread_mutex_unlock(&prog->forks_mutex);
	return (0);
}

int	ft_check_died(t_program *prog, t_philo *philo, int *pos)
{
	philo->die = ft_get_time() - philo->last;
	if (philo->die > prog->die)
	{
		ft_put_forks(prog, philo, pos);
		pthread_mutex_lock(&prog->mutex);
		if (prog->exit == 1)
		{
			pthread_mutex_unlock(&prog->mutex);
			return (0);
		}
		return (ft_died(prog, philo));
	}
	return (1);
}

int     ft_get_forks(t_program *prog, t_philo *philo, int *pos)
{
	while (philo->forks < 2 && ft_check_died(prog, philo, pos))
	{
		pthread_mutex_lock(&prog->forks_mutex);
		if (prog->forks[pos[philo->forks]] == 1)
			prog->forks[pos[philo->forks++]] = 0;
		pthread_mutex_unlock(&prog->forks_mutex);
	}
	if (philo->die > prog->die)
		return (0);
	ft_philo_log(prog, philo, "has taken a fork", 0);
	return (1);
}
