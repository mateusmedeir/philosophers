#include "philo.h"

int	ft_get_fork(t_program *prog, t_philo *philo, int pos)
{
	pthread_mutex_lock(&prog->forks[pos]);
	philo->die += ft_get_time() - philo->last;
	if (philo->die >= prog->die)
	{
		pthread_mutex_unlock(&prog->forks[pos]);
		if (pos == philo->pos)
			pthread_mutex_unlock(&prog->forks[pos - 1]);
		else if (philo->pos == prog->size && pos == 0)
			pthread_mutex_unlock(&prog->forks[philo->pos - 1]);
		pthread_mutex_lock(&prog->mutex);
		if (prog->exit == 1)
		{
			pthread_mutex_unlock(&prog->mutex);
			return (0);
		}
		return (ft_died(prog, philo));
	}
	ft_philo_log(prog, philo, "has taken a fork");
	return (1);
}
