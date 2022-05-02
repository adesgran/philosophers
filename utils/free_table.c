/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:44:34 by adesgran          #+#    #+#             */
/*   Updated: 2022/05/02 15:45:28 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	free_table(t_table *table)
{
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->is_dead);
	free(table);
}
