/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:53:06 by adesgran          #+#    #+#             */
/*   Updated: 2022/05/02 16:54:57 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	check_if_dead(t_philo *philo)
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
