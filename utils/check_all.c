/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:18:43 by adesgran          #+#    #+#             */
/*   Updated: 2022/05/02 17:39:56 by adesgran         ###   ########.fr       */
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
	t_philo *current;

	if (philo->table->max_eat == 0)
		return (0);
	current = philo;
	if (philo->times_eat < philo->table->max_eat)
		return (0);
	philo = philo->next;
	while (philo != current)
	{
		if (philo->times_eat < philo->table->max_eat)
			return (0);
		philo = philo->next;
	}
	return (1);
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
