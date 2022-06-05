/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 13:20:49 by adesgran          #+#    #+#             */
/*   Updated: 2022/06/05 15:59:56 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	ft_strlen(char *str)
{
	if (!*str)
		return (0);
	return (ft_strlen(str + 1) + 1);
}

static char	*ft_strdup(char *str)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!res)
		return (res);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static int	check_overflow(char *str)
{
	char	*max;
	int		i;

	while (*str == '0')
		str++;
	if (ft_strlen(str) < 10)
		return (0);
	if (ft_strlen(str) > 10)
		return (1);
	max = ft_strdup("2147483647");
	if (!max)
		return (1);
	i = 0;
	while (max[i])
	{
		if (max[i] > str[i])
			return (free(max), 0);
		if (max[i] < str[i])
			return (free(max), 1);
		i++;
	}
	return (free(max), 0);
}

int	ft_atoi(char *str)
{
	int	res;
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-2);
		i++;
	}
	if (check_overflow(str))
		return (-2);
	res = 0;
	while (*str)
	{
		res = 10 * res + *str - '0';
		str++;
	}
	return (res);
}
