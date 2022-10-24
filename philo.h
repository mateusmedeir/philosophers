#ifndef PHILO_H
#define	PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(const char *str);
void	*ft_thread(void *arg);
void	ft_philo(int size);

#endif
