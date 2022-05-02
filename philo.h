/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:52:51 by adesgran          #+#    #+#             */
/*   Updated: 2022/05/02 11:53:30 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_table
{
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	max_eat;
}	t_table;

typedef struct s_philo
{
	int				n_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				number;
	pthread_mutex_t	fork;
	t_table			table;
	struct s_philo	*next;
	struct s_philo	*previous;
}	t_philo;

int		ft_atoi(char *str);
void	free_list_philo(t_philo *list);
int		push_back_philo(t_philo *list);
t_philo	*philo_init(t_table table);

#endif
