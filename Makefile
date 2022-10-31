SRCS	= philo.c load.c actions.c fork.c time.c atoi.c

CC	= cc
FLAGS	= -Wall -Wextra -Werror
FTHREAD	= -lpthread
O	= -o
RM	= rm -f

NAME	= philo

all:	$(NAME)

$(NAME):
		$(CC) $(SRCS) $(FLAGS) $(FTHREAD) $(O) $(NAME)

fclean:
		$(RM) $(NAME)

re:		fclean all
