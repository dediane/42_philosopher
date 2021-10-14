/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:24:16 by ddecourt          #+#    #+#             */
/*   Updated: 2021/10/14 19:22:47 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//pthread_mutex_t mutex;

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

void	*routine()
{
	pthread_mutex_lock(&mutex);
	pthread_mutex_unlock(&mutex);
	
	return(0);
}

long	get_timestamp(long start_ts)
{
	struct timeval    tv;

	gettimeofday(&tv, NULL);
	return (((tv.tv_sec * 1000) + tv.tv_usec / 1000) - start_ts);
}

/*void ft_usleep(int duration)
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
}*/

int	main(int ac, char **av)
{
	int nb_of_philos;
	t_env var;

	if (ac != 5 && ac != 6)
	{
		printf("Usage: ./philo number_of_philosopher time_to_die time_to_eat \
		time_to_sleep [number_of_times_each_philosopher_must_eat]");
		return (1);
	}
	ft_parsing(av, &var);
	//printf("%ld\n",get_timestamp(0));
	nb_of_philos = ft_atoi(av[1]);
	pthread_t th[nb_of_philos];
	int i = -1;
	pthread_mutex_init(&mutex, NULL);
	while(++i < nb_of_philos)
	{
		pthread_create(th + i, NULL, &routine, NULL);
		printf("Thread created for philo %i\n", i);
		pthread_join(th[i], NULL);
		printf("Thread finished for philo %i\n", i);
	}
	/*i = 0;
	while(++i < nb_of_philos)
	{
	}*/
	pthread_mutex_destroy(&mutex);
	return(0);
}
