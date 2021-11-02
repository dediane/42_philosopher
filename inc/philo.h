/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 01:09:46 by ddecourt          #+#    #+#             */
/*   Updated: 2021/11/02 12:10:35 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

//struct
typedef struct s_env
{
	pthread_mutex_t	mutex_write;
	pthread_mutex_t eating;
	int				is_dead;
	int				nb_philo;
	int				nb_time_eat;
	long			start_time;
	long			t_to_die;
	long			t_to_eat;
	long			t_to_sleep;
}				t_env;

typedef struct s_philo
{
	t_env			*env;
	pthread_t		ph;
	pthread_mutex_t	fork;
	pthread_mutex_t	*next_fork;
	unsigned int	id;
	long			init_time;
	long			last_meal;
}				t_philo;
//utils
int		ft_atoi(const char *str);
void	init_time(t_env *env);
long	get_timestamp(long start_time);
void	ft_usleep(int duration);
void	ft_print_status(t_philo *ph, char *s);
void	init_mutex(t_env *env);
//parsing
int		ft_parsing(char **av, t_env *var);
int		is_numeric(char **av, int i, int j);
int		ft_check_ac(int ac);
//routine
void	exec_routine(t_philo *ph);
void	destroy_mutex(t_philo *ph, t_env *env, int nb);
void	ft_free_my_philos(t_philo *ph, int nb);
int		check_dead(t_philo *ph);
//
void	is_someone_dead(t_philo *ph);

#endif