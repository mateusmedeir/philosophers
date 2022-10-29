#include "philo.h"

void	ft_get_fork(t_program *prog, t_philo *philo)
{
	if (philo->forks >= 0 && philo->forks < 2)
	{
		if (prog->forks <= 0)
			philo->hungry = ft_get_time();
		while (prog->forks <= 0)
			usleep(1000);
		if (philo->hungry > 0)
		{
			philo->die = ft_get_time() - philo->hungry;
			philo->hungry = 0;
			if (philo->die >= prog->die)
			{
				if (philo->forks > 0)
				{
					while (philo->forks > 0)
						ft_put_fork(prog, philo);
				}
				ft_died(prog, philo);
				return ;
			}
		}
		printf("%lld %d has taken a fork\n", ft_get_time() - prog->start, philo->pos);
		prog->forks--;
		philo->forks++;
	}
}

void	ft_put_fork(t_program *prog, t_philo *philo)
{
	if (philo->forks >= 0)
	{
		prog->forks++;
		philo->forks--;
	}
}
