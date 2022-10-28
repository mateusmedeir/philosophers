#include "philo.h"

void	ft_think(t_philo *philo)
{
	printf("Philosopher %d is thinking...\n", philo->pos);
}

void	ft_eat(t_philo *philo)
{
	printf("Philosopher %d is eating...\n", philo->pos);
}
