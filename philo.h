#ifndef PHILO_H
#define	PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_philo
{
	pthread_t	thread;
	int		pos;
	int		forks;
	void		*prog;
}			t_philo;

typedef struct	s_program
{
	pthread_mutex_t	mutex;
	t_philo		*philos;
	int		forks;
}		t_program;

int	ft_atoi(const char *str);
void	ft_load_philos(t_program *prog, int size);
void	*ft_philo_actions(void *arg);
void	ft_philo(int size);
void	ft_get_fork(t_program *prog, t_philo *philo);
void	ft_put_fork(t_program *prog, t_philo *philo);
void	ft_think(t_philo *philo);
void	ft_eat(t_philo *philo);

#endif
