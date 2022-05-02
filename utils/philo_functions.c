/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:36:46 by adesgran          #+#    #+#             */
/*   Updated: 2022/05/02 15:13:07 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_philo	*philo_init(t_table *table)
{
	t_philo	*res;

	res = malloc(sizeof(t_philo));
	if (!res)
		return (res);
	res->table = table;
	res->number = 1;
	res->next = res;
	res->previous = res;
	if (pthread_mutex_init(&res->fork, NULL))
	{
		free(res);
		return (NULL);
	}
	return (res);
}

int	push_back_philo(t_philo *list)
{
	t_philo	*next;

	if (!list)
		return (1) ;
	next = malloc(sizeof(t_philo));
	if (!next)
	{
		free_list_philo(list);
		return (2);
	}
	if (pthread_mutex_init(&next->fork, NULL))
	{
		free(next);
		free_list_philo(list);
		return (3);
	}
	next->table = list->table;
	next->next = list;
	list->previous = next;
	while (list->next->number != 1)
		list = list->next;
	list->next = next;
	next->previous = list;
	next->number = list->number + 1;
	return (0);
}

void	free_list_philo(t_philo *list)
{
	if (list->next->number != 1)
		free_list_philo(list->next);
	else
	{
		pthread_mutex_destroy(&list->table->print);
		free(list->table);
	}
	pthread_mutex_destroy((&list->fork));
	free(list);
}
