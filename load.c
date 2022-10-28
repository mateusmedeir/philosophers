#include "philo.h"

void	ft_load_philos(t_program *prog, int size)
{
	int	counter;

	prog->philos = malloc(sizeof(t_philo) * size);
	if (!prog->philos)
		return ;
	counter = -1;
	while (++counter < size)
	{
		prog->philos[counter].prog = prog;
		prog->philos[counter].pos = counter;
		prog->philos[counter].forks = 0;
	}
}
