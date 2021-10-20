/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:48:53 by ddecourt          #+#    #+#             */
/*   Updated: 2021/10/15 12:21:35 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	ft_checkcount(int j)
{
	if (j == 1)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	nb;
	int	count;

	i = 0;
	j = 1;
	nb = 0;
	count = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j = j * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i++] - 48);
		count++;
	}
	if (count > 10)
		return (ft_checkcount(j));
	return (nb * j);
}

long	get_timestamp(long start_time)
{
	struct timeval    time;

	gettimeofday(&time, NULL);
	return (((time.tv_sec * 1000) + time.tv_usec / 1000) - start_time);
}

void ft_usleep(int duration)
{
	long start;
	long current;

	start = get_timestamp(0);
	current = start;
	while (duration > current - start)
	{
		usleep(100);
		current = get_timestamp(0);
	}
}