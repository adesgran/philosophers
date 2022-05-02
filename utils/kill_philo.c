/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:36:42 by adesgran          #+#    #+#             */
/*   Updated: 2022/05/02 16:43:04 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	kill_philo(t_philo *philo)
{
	ft_print(philo, "died\n");
	pthread_mutex_lock(&philo->table->lock_is_dead);
	philo->table->is_dead = 1;
	pthread_mutex_unlock(&philo->table->lock_is_dead);
}
