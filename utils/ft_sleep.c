/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:16:22 by adesgran          #+#    #+#             */
/*   Updated: 2022/06/05 16:11:08 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	ft_sleep(t_philo *philo, long long int time_max)
{
	long long int		start;
	long long int		curr_time;

	start = ft_current_time() * 1000;
	curr_time = start;
	while (curr_time - start < time_max)
	{
		if (check_all(philo))
			return (1);
		usleep(10);
		curr_time = ft_current_time() * 1000;
	}
	return (0);
}
