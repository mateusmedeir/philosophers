#include "philo.h"

int	ft_put_forks(t_program *prog, t_philo *philo, int *pos)
{
	while (philo->forks > 0)
	{
		pthread_mutex_lock(&prog->mutex_forks[pos[--philo->forks]]);
		prog->forks[pos[philo->forks]] = 1;
		pthread_mutex_unlock(&prog->mutex_forks[pos[philo->forks]]);
	}
	return (0);
}

int	ft_get_forks(t_program *prog, t_philo *philo, int *pos)
{
	int	check;

	check = ft_check_died(prog, philo, pos);
	while (philo->forks < 2 && check)
	{
		pthread_mutex_lock(&prog->mutex_forks[pos[philo->forks]]);
		if (prog->forks[pos[philo->forks]] == 1)
		{
			prog->forks[pos[philo->forks]] = 0;
			ft_philo_log(prog, philo, "has taken a fork", 0);
			pthread_mutex_unlock(&prog->mutex_forks[pos[philo->forks++]]);
		}
		else
			pthread_mutex_unlock(&prog->mutex_forks[pos[philo->forks]]);
		check = ft_check_died(prog, philo, pos);
	}
	return (check);
}
