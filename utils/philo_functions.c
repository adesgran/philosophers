/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:36:46 by adesgran          #+#    #+#             */
/*   Updated: 2022/05/02 10:54:16 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_philo	*philo_init(int n, int die, int eat, int sleep)
{
	t_philo	*res;

	res = malloc(sizeof(t_philo));
	if (!res)
		return (res);
	res->n_philo = n;
	res->time_die = die;
	res->time_eat = eat;
	res->time_sleep = sleep;
	res->number = 0;
	res->next = res;
	res->previous = res;
	return (res);
}

void	push_back_philo(t_philo *list)
{
	t_philo	*next;

	if (!list)
		return ;
	next->n_philo = list->_n_philo;
	next->time_die = list->time_die;
	next->time_eat = list->time_eat;
	next->time_sleep = list->time_sleep;
	next->next = list;
	list->previous = next;
	while (list->next != next->next)
		list = list->next;
	list->next = next;
	next->previous = list;
	next->number = list->number + 1;
}

void	free_list_philo(t_philo *list)
{
	if (list->next->number != 0)
		free_list_philo(list->next);
	free(list);
}
