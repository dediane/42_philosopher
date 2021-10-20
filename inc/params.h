/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 01:09:16 by ddecourt          #+#    #+#             */
/*   Updated: 2021/10/20 19:43:09 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

typedef struct s_philo
{
	pthread_t		philo;
	pthread_mutex_t	fork;
	int				id;
	long			init_time;
	long			t_wait;
}		t_philo;

typedef struct s_env
{
	int		nb_philo;
	long	start_time;
	long	t_to_die;
	long	t_to_eat;
	long	t_to_sleep;
}		t_env;