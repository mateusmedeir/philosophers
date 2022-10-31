#include "philo.h"

void	ft_think(t_program *prog, t_philo *philo)
{
	printf("%lld %d is thinking\n", ft_get_time() - prog->start, philo->pos);
}

void	ft_eat(t_program *prog, t_philo *philo)
{
	int	left;
	int	right;

	left = philo->pos;
	if (philo->pos == prog->size)
		right = 0;
	else
		right = philo->pos + 1;
	ft_get_fork(prog, philo, left);
	if (philo->die >= prog->die)
		return ;
	ft_get_fork(prog, philo, right);
	if (philo->die >= prog->die)
		return ;
	printf("%lld %d is eating\n", ft_get_time() - prog->start, philo->pos);
	usleep(prog->eat * 1000);
	pthread_mutex_unlock(&prog->forks[left]);
	pthread_mutex_unlock(&prog->forks[right]);
}

void	ft_sleep(t_program *prog, t_philo *philo)
{
	printf("%lld %d is sleeping\n", ft_get_time() - prog->start, philo->pos);
	usleep(prog->sleep * 1000);
}

void	ft_died(t_program *prog, t_philo *philo)
{
	printf("%lld %d died\n", ft_get_time() - prog->start, philo->pos);	
}
