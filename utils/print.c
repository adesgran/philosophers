/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:19:25 by adesgran          #+#    #+#             */
/*   Updated: 2022/05/02 14:55:48 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	ft_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->table->print);
	printf("%s", str);
	pthread_mutex_unlock(&philo->table->print);
	return ;
}
