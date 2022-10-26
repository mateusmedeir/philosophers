#include "philo.h"

void	*ft_philo_actions(void *arg)
{
	t_philo	*philo;

	philo = arg;
	printf("Thread %d Created\n", philo->pos);
	sleep(3);
	printf("End Thread %d\n", philo->pos);
	return (arg);
}

void	ft_philo(int size)
{
	t_program	prog;
	int		counter;

	ft_load_philos(&prog, size);
	prog.forks = 2;
	counter = -1;
	pthread_mutex_init(&prog.mutex, NULL);
	while (++counter < size)
	{
		if (pthread_create(&prog.philos[counter].thread, NULL, ft_philo_actions, &prog.philos[counter]) != 0)
			return ;
	}
	counter = -1;
	while (++counter < size)
	{
		if (pthread_join(prog.philos[counter].thread, NULL) != 0)
			return ;
	}
	pthread_mutex_destroy(&prog.mutex);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		ft_philo(ft_atoi(argv[1]));
}
