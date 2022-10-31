#include "philo.h"

void	*ft_philo_actions(void *arg)
{
	t_philo		*philo;
	t_program	*prog;

	philo = arg;
	prog = philo->prog;
	while (1)
	{
		ft_eat(prog, philo);
		if (philo->die >= prog->die)
			exit(EXIT_FAILURE);
		ft_sleep(prog, philo);
		ft_think(prog, philo);
	}
	return (arg);
}

void	ft_philo(t_program *prog)
{
	ft_philo_load(prog);
	ft_philo_start(prog);
	ft_philo_end(prog);
}

int	main(int argc, char *argv[])
{
	t_program       prog;

	if (argc == 5)
	{
		prog.size = ft_atoi(argv[1]);
		prog.die = ft_atoi(argv[2]);
		prog.eat = ft_atoi(argv[3]);
		prog.sleep = ft_atoi(argv[4]);
		ft_philo(&prog);
	}
}
