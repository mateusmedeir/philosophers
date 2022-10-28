#include "philo.h"

void	ft_get_fork(t_program *prog, t_philo *philo)
{
	if (philo->forks == 0)
	{
		if (prog->forks <= 0)
		{
			printf("Philosopher %d waiting a fork...\n", philo->pos);
			return ;
		}
	}
	else if (philo->forks == 1)
	{
		if (prog->forks <= 0)
		{
			ft_put_fork(prog, philo);
			usleep(5000);
			return ;
		}
	}
	prog->forks--;
	philo->forks++;
}

void	ft_put_fork(t_program *prog, t_philo *philo)
{
	if (philo->forks >= 0)
	{
		prog->forks++;
		philo->forks--;
	}
}
