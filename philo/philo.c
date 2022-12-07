#include "philo.h"

void	*ft_philo_actions(void *arg)
{
	t_philo		*philo;
	t_program	*prog;

	philo = arg;
	prog = philo->prog;
	if (philo->pos % 2)
		usleep(15000);
	while (1)
	{
		if (!ft_eat(prog, philo) || !ft_philo_log(prog, philo, "is sleeping", prog->sleep)
				|| !ft_philo_log(prog, philo, "is thinking", 0))
			break ;
	}
	return (NULL);
}

void	ft_philo(t_program *prog)
{
	ft_philo_load(prog);
	ft_philo_start(prog);
	ft_philo_end(prog);
}

int	main(int argc, char *argv[])
{
	t_program	prog;

	if (argc == 5 || argc == 6)
	{
		prog.size = ft_atoi(argv[1]);
		prog.die = ft_atoi(argv[2]);
		prog.eat = ft_atoi(argv[3]);
		prog.sleep = ft_atoi(argv[4]);
		if (argc == 6)
			prog.must_eat = ft_atoi(argv[5]);
		else
			prog.must_eat = -1;
		if (prog.size <= 0 || prog.die < 0 || prog.eat < 0 || prog.sleep < 0)
			return (0);
		if (argc == 6)
		{
			if (prog.must_eat <= 0)
				return (0);
		}
		ft_philo(&prog);
	}
}
