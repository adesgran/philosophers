/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:46:08 by adesgran          #+#    #+#             */
/*   Updated: 2022/05/02 18:10:01 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	init_table(int ac, char **av, t_table *table)
{
	table->is_dead = 0;
	table->n_philo = ft_atoi(av[1]);
	table->n_philo_max_eat = table->n_philo;
	if (table->n_philo < 1)
		return (1);
	table->time_die = ft_atoi(av[2]);
	table->time_eat = ft_atoi(av[3]);
	table->time_sleep = ft_atoi(av[4]);
	if (!table->time_die || !table->time_eat || !table->time_sleep)
		return (1);
	table->max_eat = 0;
	if (ac == 6)
		table->max_eat = ft_atoi(av[5]);
	if (pthread_mutex_init(&table->print, NULL))
		return (1);
	if (pthread_mutex_init(&table->lock_is_dead, NULL))
	{
		pthread_mutex_destroy(&table->print);
		return (1);
	}
	if (pthread_mutex_init(&table->lock_max_eat, NULL))
	{
		pthread_mutex_destroy(&table->print);
		pthread_mutex_destroy(&table->lock_is_dead);
		return (1);
	}
	return (0);
}
