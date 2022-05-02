/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 13:18:34 by adesgran          #+#    #+#             */
/*   Updated: 2022/05/02 12:13:57 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static t_philo	*static_generate_philos(t_table table)
{
	t_philo	*res;
	int		i;

	res = philo_init(table);
	if (!res)
		return (res);
	i = 1;
	while (i < table.n_philo)
	{
		if (push_back_philo(res))
			return (NULL);
		i++;
	}
	return (res);
}

int	main(int ac, char **av)
{
	t_table	table;
	t_philo	*philos;

	if (ac <  5 || ac > 6)
	{
		printf("Wrong number of aguments\n");
		return (1);
	}
	table.n_philo = ft_atoi(av[1]);
	if (table.n_philo < 1)
	{
		printf("n_philo can't be <= 1\n");
		return (2);
	}
	table.time_die = ft_atoi(av[2]);
	table.time_eat = ft_atoi(av[3]);
	table.time_sleep = ft_atoi(av[4]);
	table.max_eat = 0;
	if (ac == 6)
		table.max_eat = ft_atoi(av[5]);
	philos = static_generate_philos(table);
	if (!philos)
	{
		printf("Error while generate philos list\n");
	}
	free_list_philo(philos);
}
