/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 00:39:07 by ddecourt          #+#    #+#             */
/*   Updated: 2021/10/26 01:41:10 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	exec_routine(t_philo *ph)
{
	pthread_mutex_lock(&ph->next_fork);
	pthread_mutex_lock(&ph->mutex_write);
	ft_print_status(ph, "has taken a fork\n");
	pthread_mutex_unlock(&ph->mutex_write);
	//if (!(&ph->next_fork))
	//{	
	//	return ;
	//}
	pthread_mutex_lock(&ph->fork);
	pthread_mutex_lock(&ph->mutex_write);
	ft_print_status(ph, "has taken a fork\n");
	pthread_mutex_unlock(&ph->mutex_write);
	pthread_mutex_lock(&ph->mutex_write);
	ft_print_status(ph, "is eating\n");
	/*pthread_mutex_lock(&ph->pa->time_eat);
	ph->ms_eat = actual_time();
	pthread_mutex_unlock(&ph->pa->time_eat);*/
	pthread_mutex_unlock(&ph->mutex_write);
	//ft_usleep(ph->pa->eat);
	pthread_mutex_unlock(&ph->fork);
	pthread_mutex_unlock(&ph->next_fork);
	//sleep_think(ph);
}
