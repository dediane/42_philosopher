/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 00:39:07 by ddecourt          #+#    #+#             */
/*   Updated: 2021/10/26 17:26:37 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	exec_routine(t_philo *ph)
{
	pthread_mutex_lock(&ph->next_fork);
	pthread_mutex_lock(&ph->mutex_write);
	ft_print_status(ph, "has taken a fork");
	pthread_mutex_unlock(&ph->mutex_write);
	pthread_mutex_lock(&ph->fork);
	pthread_mutex_lock(&ph->mutex_write);
	ft_print_status(ph, "has taken a fork");
	pthread_mutex_unlock(&ph->mutex_write);
	pthread_mutex_lock(&ph->mutex_write);
	ft_print_status(ph, "is eating");
	//ft_usleep(ph->env->t_to_eat);
	ph->env->nb_time_eat++;
	pthread_mutex_unlock(&ph->mutex_write);
	pthread_mutex_unlock(&ph->fork);
	pthread_mutex_unlock(&ph->next_fork);
	ft_print_status(ph, "is sleeping");
	//ft_usleep(ph->env->t_to_sleep);
	ft_print_status(ph, "is thinking");
}

void	destroy_mutex(t_philo *ph, int nb)
{
	int	i;

	i = -1;
	while (++i < nb)
	{
		pthread_mutex_destroy(&ph[i].fork);
		pthread_mutex_destroy(&ph[i].mutex_write);
	}
}
