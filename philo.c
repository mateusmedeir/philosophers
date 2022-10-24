#include "philo.h"

void	*ft_thread(void *arg)
{
	printf("Thread Created\n");
	sleep(3);
	printf("End Thread\n");
	return (arg);
}

void	ft_philo(int size)
{
	pthread_mutex_t	mutex;
	pthread_t       *threads;
	int		counter;

	threads = malloc(sizeof(pthread_t) * size);
	if (!threads)
		return ;
	pthread_mutex_init(&mutex, NULL);
	counter = 0;
	while (counter < size)
	{
		if (pthread_create(&threads[counter], NULL, ft_thread, NULL) != 0)
			return ;
		counter++;
	}
	counter = 0;
	while (counter < size)
	{
		if (pthread_join(threads[counter], NULL) != 0)
			return ;
		counter++;
	}
	pthread_mutex_destroy(&mutex);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		ft_philo(ft_atoi(argv[1]));
}
