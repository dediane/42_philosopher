/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:48:53 by ddecourt          #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2021/10/26 17:26:12 by ddecourt         ###   ########.fr       */
=======
/*   Updated: 2021/10/26 23:59:28 by ddecourt         ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - 48);
	return (nb);
}

void	init_time(t_env *env)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	env->start_time = t.tv_sec * 1000 + t.tv_usec / 1000;
}

long int	get_timestamp(long int start_time)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (((time.tv_sec * 1000) + time.tv_usec / 1000) - start_time);
}

void	ft_usleep(int duration)
{
	long int	start;
	long int	current;

	start = get_timestamp(0);
	current = start;
	while (duration > current - start)
	{
		usleep(100);
		current = get_timestamp(0);
	}
}

void	ft_print_status(t_philo *ph, char *s)
{
	long int	time;

	time = get_timestamp(ph->env->start_time);
	if (time >= 0 && time <= 2147483647)
		printf("%ld philo %d %s\n", time, ph->id, s);
}

void	ft_free_my_philos(t_philo *ph, int nb)
{
	int	i;

	i = -1;
	while (++i < nb)
	{
		free(&ph[i]);
	}
	free(&ph);
}
