/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:19:25 by adesgran          #+#    #+#             */
/*   Updated: 2022/05/02 16:07:39 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	ft_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->table->lock_is_dead);
	{
		if (!philo->table->is_dead)
		{
			pthread_mutex_lock(&philo->table->print);
			printf("%d %s", philo->number, str);
			pthread_mutex_unlock(&philo->table->print);
		}
	}
	pthread_mutex_unlock(&philo->table->lock_is_dead);
	return ;
}
