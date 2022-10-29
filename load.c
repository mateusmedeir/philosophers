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
		prog->philos[counter].die = 0;
		prog->philos[counter].hungry = 0;
	}
}

void	ft_load(t_program *prog, int size)
{
	ft_load_philos(prog, size);
	prog->forks = size;
	prog->start = ft_get_time();
}
