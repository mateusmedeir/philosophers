#ifndef PHILO_H
#define	PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct	s_philo
{
	pthread_t	thread;
	int		pos;
	int		die;
	long long	hungry;
	void		*prog;
}			t_philo;

typedef struct	s_program
{
	t_philo		*philos;
	pthread_mutex_t	*forks;
	int		size;
	int		eat;
	int		sleep;
	int		die;
	long long	start;
}			t_program;

int		ft_atoi(const char *str);
void		ft_philo_load(t_program *prog);
void		ft_philo_start(t_program *prog);
void		ft_philo_end(t_program *prog);
void		*ft_philo_actions(void *arg);
void		ft_philo(t_program *prog);
void		ft_get_fork(t_program *prog, t_philo *philo, int pos);
void		ft_think(t_program *prog,t_philo *philo);
void		ft_eat(t_program *prog,t_philo *philo);
void		ft_sleep(t_program *prog, t_philo *philo);
void		ft_died(t_program *prog, t_philo *philo);
long long	ft_get_time(void);

#endif
