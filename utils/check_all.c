/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:18:43 by adesgran          #+#    #+#             */
/*   Updated: 2022/05/02 18:10:58 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	static_check_if_dead(t_philo *philo)
{
	int	res;

	pthread_mutex_lock(&philo->table->lock_is_dead);
	if (philo->table->is_dead)
		res = 1;
	else
		res = 0;
	pthread_mutex_unlock(&philo->table->lock_is_dead);
	return (res);
}

static int	static_check_all_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->lock_max_eat);
	if (philo->table->n_philo_max_eat == 0)
	{
		pthread_mutex_unlock(&philo->table->lock_max_eat);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->lock_max_eat);
	return (0);
}

int	check_all(t_philo *philo)
{
	if (ft_current_time() - philo->last_eat >= philo->table->time_die)
	{
		kill_philo(philo);
		return (1);
	}
	if (static_check_if_dead(philo))
		return (1);
	if (static_check_all_eat(philo))
		return (1);
	return (0);
}
