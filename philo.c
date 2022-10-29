#include "philo.h"

void	*ft_philo_actions(void *arg)
{
	t_philo		*philo;
	t_program	*prog;

	philo = arg;
	prog = philo->prog;
	while (1)
	{
		ft_think(prog, philo);
		while (philo->forks < 2)
		{
			ft_get_fork(prog, philo);
			if (philo->die >= prog->die)
				break ;
		}
		ft_eat(prog, philo);
		while (philo->forks >= 0)
			ft_put_fork(prog, philo);
		ft_sleep(prog, philo);
	}
	return (arg);
}

void	ft_philo(t_program *prog, int size)
{
	int		counter;

	ft_load(prog, size);
	counter = -1;
	//pthread_mutex_init(&prog.mutex, NULL);
	while (++counter < size)
	{
		if (pthread_create(&prog->philos[counter].thread, NULL, ft_philo_actions, &prog->philos[counter]) != 0)
			return ;
	}
	counter = -1;
	while (++counter < size)
	{
		if (pthread_join(prog->philos[counter].thread, NULL) != 0)
			return ;
	}
	//pthread_mutex_destroy(&prog.mutex);
}

int	main(int argc, char *argv[])
{
	t_program       prog;

	if (argc == 5)
	{
		prog.die = ft_atoi(argv[2]);
		prog.eat = ft_atoi(argv[3]);
		prog.sleep = ft_atoi(argv[4]);
		ft_philo(&prog, ft_atoi(argv[1]));
	}
}
