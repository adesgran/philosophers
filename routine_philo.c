/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:53:06 by adesgran          #+#    #+#             */
/*   Updated: 2022/05/02 18:31:52 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	static_take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	if (check_all(philo))
	{
		pthread_mutex_unlock(&philo->fork);
		return (1);
	}
	usleep(10);
	ft_print(philo, "has taken a fork\n");
	pthread_mutex_lock(&philo->previous->fork);
	if (check_all(philo))
	{
		pthread_mutex_unlock(&philo->previous->fork);
		pthread_mutex_unlock(&philo->fork);
		return (1);
	}
	usleep(10);
	ft_print(philo, "has taken a fork\n");
	return (0);
}

static void	static_eat(t_philo *philo)
{
	if (check_all(philo))
		return ;
	if (static_take_fork(philo))
		return ;
	ft_print(philo, "is eating\n");
	philo->last_eat = ft_current_time();
	philo->times_eat++;
	pthread_mutex_lock(&philo->table->lock_max_eat);
	if (philo->times_eat == philo->table->max_eat)
		philo->table->n_philo_max_eat--;
	pthread_mutex_unlock(&philo->table->lock_max_eat);
	if (check_all(philo) == 0)
		usleep(philo->table->time_eat * 1000);
	pthread_mutex_unlock(&philo->previous->fork);
	pthread_mutex_unlock(&philo->fork);
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
	if (philo->number % 2 == 0)
		usleep(philo->table->time_eat * 500);
	while (1)
	{
		if (check_all(philo))
			return (NULL);
		if (philo->next != philo)
			static_eat(philo);
		if (check_all(philo))
			return (NULL);
		if (philo->next != philo)
			static_sleep(philo);
		if (check_all(philo))
			return (NULL);
		if (philo->next != philo)
			static_think(philo);
	}
	return (NULL);
}
