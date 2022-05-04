/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 13:18:34 by adesgran          #+#    #+#             */
/*   Updated: 2022/05/04 13:19:15 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	launch_philos(t_table *table, t_philo *philos)
{
	int			i;
	int			err;
	pthread_t	id[200];

	i = 0;
	while (i < table->n_philo)
	{
		err = pthread_create(&(id[i]), NULL, &routine_philo, (void *)philos);
		if (err)
		{
			ft_print(philos, "Error while creating a philo thread\n");
			return ;
		}
		usleep(100);
		philos = philos->next;
		i++;
	}
	i = 0;
	while (i < table->n_philo)
	{
		pthread_join(id[i], NULL);
		i++;
	}
}

static t_philo	*static_generate_philos(t_table *table)
{
	t_philo	*res;
	int		i;

	res = philo_init(table);
	if (!res)
		return (res);
	i = 1;
	while (i < table->n_philo)
	{
		if (push_back_philo(res))
			return (NULL);
		i++;
	}
	return (res);
}

int	main(int ac, char **av)
{
	t_table	*table;
	t_philo	*philos;

	if (ac < 5 || ac > 6)
		return (1);
	table = malloc(sizeof(t_table));
	if (!table)
		return (1);
	if (init_table(ac, av, table))
	{
		free(table);
		return (1);
	}
	if (!table)
		return (1);
	philos = static_generate_philos(table);
	if (!philos)
	{
		printf("Error while generate philos list\n");
	}
	launch_philos(table, philos);
	free_list_philo(philos);
}
