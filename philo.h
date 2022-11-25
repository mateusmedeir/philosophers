#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t	thread;
	int			forks;
	int			pos;
	int			die;
	int			times_eat;
	long long	last;
	void		*prog;
}			t_philo;

typedef struct s_program
{
	pthread_mutex_t	mutex_exit;
	pthread_mutex_t	mutex_write;
	pthread_mutex_t	*mutex_forks;
	t_philo			*philos;
	int				*forks;
	int				exit;
	int				size;
	int				eat;
	int				must_eat;
	int				sleep;
	int				die;
	long long		start;
}			t_program;

int		ft_atoi(const char *str);
void		ft_philo_load(t_program *prog);
void		ft_philo_start(t_program *prog);
void		ft_philo_end(t_program *prog);
void		*ft_philo_actions(void *arg);
void		ft_philo(t_program *prog);
int		ft_put_forks(t_program *prog, t_philo *philo, int *pos);
int     	ft_check_died(t_program *prog, t_philo *philo, int *pos);
int		ft_get_forks(t_program *prog, t_philo *philo, int *pos);
int		ft_philo_log(t_program *prog,t_philo *philo, char *str, int time_sleep);
int		ft_eat(t_program *prog,t_philo *philo);
int		ft_died(t_program *prog, t_philo *philo);
long long	ft_get_time(void);
void		ft_sleep(int time_sleep);

#endif
