#include "philo.h"

void	ft_think(t_program *prog, t_philo *philo)
{
	printf("%lld %d is thinking\n", ft_get_time() - prog->start, philo->pos);
}

void	ft_eat(t_program *prog, t_philo *philo)
{
	printf("%lld %d is eating\n", ft_get_time() - prog->start, philo->pos);
	usleep(prog->eat * 1000);
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
