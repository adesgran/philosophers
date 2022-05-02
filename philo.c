/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 13:18:34 by adesgran          #+#    #+#             */
/*   Updated: 2022/05/02 15:01:57 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	*routine_philo(void* arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	pthread_mutex_lock(&philos->fork);
	ft_print(philos, "Philo is launched\n");
	usleep(1000000);
	pthread_mutex_unlock(&philos->fork);
	return (NULL);
}
static void	launch_philos(t_table *table, t_philo *philos)
{
	int	i;
	int	err;
	pthread_t	id[table->n_philo + 1];

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

	if (ac <  5 || ac > 6)
	{
		printf("Wrong number of aguments\n");
		return (1);
	}
	table = malloc(sizeof(t_table));
	if (!table)
		return (1);
	table->n_philo = ft_atoi(av[1]);
	if (table->n_philo < 1)
	{
		printf("n_philo can't be <= 1\n");
		return (2);
	}
	table->time_die = ft_atoi(av[2]);
	table->time_eat = ft_atoi(av[3]);
	table->time_sleep = ft_atoi(av[4]);
	if (pthread_mutex_init(&table->print, NULL))
		return 1;
	if (!table->time_die || !table->time_eat || !table->time_sleep)
	{
		printf("Input Error\n");
		return (3);
	}
	table->max_eat = 0;
	if (ac == 6)
		table->max_eat = ft_atoi(av[5]);
	philos = static_generate_philos(table);
	if (!philos)
	{
		printf("Error while generate philos list\n");
	}
	launch_philos(table, philos);
	free_list_philo(philos);
}
