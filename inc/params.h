/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 01:09:16 by ddecourt          #+#    #+#             */
/*   Updated: 2021/10/23 22:27:28 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMS_H
# define PARAMS_H

typedef struct s_philo
{
	pthread_t		philo;
	pthread_mutex_t	fork;
	pthread_mutex_t	next_fork;
	pthread_mutex_t	mutex_write;
	unsigned int	id;
	long			init_time;
	long			t_wait;
}		t_philo;

typedef struct s_env
{
	int		nb_philo;
	int		nb_time_eat;
	long	start_time;
	long	t_to_die;
	long	t_to_eat;
	long	t_to_sleep;
}		t_env;

#endif