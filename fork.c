#include "philo.h"

void	ft_get_fork(t_program *prog, t_philo *philo, int pos)
{
	philo->hungry = ft_get_time();
	pthread_mutex_lock(&prog->forks[pos]);
	philo->die += ft_get_time() - philo->hungry;
	if (philo->die >= prog->die)
	{
		pthread_mutex_unlock(&prog->forks[pos]);
		if (pos == philo->pos)
			pthread_mutex_unlock(&prog->forks[pos - 1]);
		ft_died(prog, philo);
		return ;
	}
	printf("%lld %d has taken a fork\n", ft_get_time() - prog->start, philo->pos);
}
