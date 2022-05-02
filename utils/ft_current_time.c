/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_current_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:23:17 by adesgran          #+#    #+#             */
/*   Updated: 2022/05/02 16:27:40 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

long int	ft_current_time(void)
{
	static long int	start;
	struct timeval	time;

	if (!start)
	{
		gettimeofday(&time, NULL);
		start = (time.tv_sec * 1000) + (time.tv_usec / 1000);
		return (0);
	}
	gettimeofday(&time, NULL);
	return (start - ((time.tv_sec * 1000) + (time.tv_usec / 1000)))
}
