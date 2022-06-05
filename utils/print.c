/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:19:25 by adesgran          #+#    #+#             */
/*   Updated: 2022/06/05 16:06:37 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	ft_print_error(void)
{
	printf("Error\n");
	return (1);
}

void	ft_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->table->lock_max_eat);
	if (philo->table->n_philo_max_eat == 0)
	{
		pthread_mutex_unlock(&philo->table->lock_max_eat);
		return ;
	}
	pthread_mutex_unlock(&philo->table->lock_max_eat);
	pthread_mutex_lock(&philo->table->lock_is_dead);
	{
		if (!philo->table->is_dead)
		{
			pthread_mutex_lock(&philo->table->print);
			printf("%ld %d %s", ft_current_time(), philo->number, str);
			pthread_mutex_unlock(&philo->table->print);
		}
	}
	pthread_mutex_unlock(&philo->table->lock_is_dead);
	return ;
}
