/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:53:06 by adesgran          #+#    #+#             */
/*   Updated: 2022/05/02 16:58:12 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	static_take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	if (ft_current_time() - philo->last_eat >= philo->table->time_die || check_if_dead(philo))
	{
		pthread_mutex_unlock(&philo->fork);
		kill_philo(philo);
		return (1);
	}
	usleep(10);
	ft_print(philo, "has taken a fork\n");
	pthread_mutex_lock(&philo->previous->fork);
	if (ft_current_time() - philo->last_eat >= philo->table->time_die || check_if_dead(philo))
	{
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->previous->fork);
		kill_philo(philo);
		return (1);
	}
	usleep(10);
	ft_print(philo, "has taken a fork\n");
	return (0);
}

static void	static_eat(t_philo *philo)
{
	if (ft_current_time() - philo->last_eat >= philo->table->time_die)
		kill_philo(philo);
	if (static_take_fork(philo))
		return ;
	ft_print(philo, "is eating\n");
	philo->last_eat = ft_current_time();
	usleep(philo->table->time_eat * 1000);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->previous->fork);
}

static void	static_sleep(t_philo *philo)
{
	ft_print(philo, "is sleeping\n");
	usleep(1000 * philo->table->time_sleep);
}

static void	static_think(t_philo *philo)
{
	ft_print(philo, "is thinking\n");
}

void	*routine_philo(void* arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->number % 2)
		usleep(philo->table->time_eat * 1000);
	while (1)
	{
		if (check_if_dead(philo))
			return (NULL);
		static_eat(philo);
		if (check_if_dead(philo))
			return (NULL);
		static_sleep(philo);
		if (check_if_dead(philo))
			return (NULL);
		static_think(philo);
	}
	return (NULL);
}
