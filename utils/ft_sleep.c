/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:16:22 by adesgran          #+#    #+#             */
/*   Updated: 2022/05/04 14:32:04 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	ft_sleep(t_philo *philo, long int time_max)
{
	long int		start;
	long int		curr_time;
	struct timeval	time;

	gettimeofday(&time, NULL);
	start = (time.tv_sec * 1000000) + (time.tv_usec);
	curr_time = start;
	while (curr_time - start < time_max)
	{
		if (check_all(philo))
			return (1);
		usleep(1000);
		gettimeofday(&time, NULL);
		curr_time = (time.tv_sec * 1000000) + (time.tv_usec);
	}
	return (0);
}
