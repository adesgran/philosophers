#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef	struct s_fork
{
	int				philo_place;
	pthread_mutex_t	*lock;
	struct s_fork	*next;
	struct s_fork	*previous;
}	t_fork;

typedef	struct s_philo
{
	int		n_philo;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		number;
	struct s_philo	*next;
	struct s_philo	*previous;
}	t_philo;

int	ft_atoi(char *str);

#endif
