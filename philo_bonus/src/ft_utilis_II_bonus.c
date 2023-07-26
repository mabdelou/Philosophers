/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilis_II_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:01:26 by mabdelou          #+#    #+#             */
/*   Updated: 2022/05/19 15:01:33 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	ft_take_forks(t_data *data, int num_of_philo)
{
	sem_wait(data->mutex_eat);
	ft_calc_time(data);
	sem_wait(data->dead_mutex);
	printf("%lld %d has taken fork\n", data->time_now - data->old_time,
		num_of_philo + 1);
	sem_post(data->dead_mutex);
	sem_wait(data->mutex_eat);
	ft_calc_time(data);
	sem_wait(data->dead_mutex);
	printf("%lld %d has taken fork\n", data->time_now - data->old_time,
		num_of_philo + 1);
	sem_post(data->dead_mutex);
	return (0);
}

int	ft_philo_eat(t_data *data, int num_of_philo)
{
	ft_calc_time(data);
	sem_wait(data->dead_mutex);
	data->old_time_eat = data->time_now - data->old_time;
	printf("%lld %d is eating\n", data->time_now - data->old_time,
		num_of_philo + 1);
	sem_post(data->dead_mutex);
	ft_usleep(data, data->time_to_eat);
	data->num_of_times_eat++;
	sem_post(data->mutex_eat);
	sem_post(data->mutex_eat);
	return (0);
}

int	ft_philo_sleep(t_data *data, int num_of_philo)
{
	ft_calc_time(data);
	sem_wait(data->dead_mutex);
	printf("%lld %d is sleeping\n", data->time_now - data->old_time,
		num_of_philo + 1);
	sem_post(data->dead_mutex);
	ft_usleep(data, data->time_to_sleep);
	ft_calc_time(data);
	sem_wait(data->dead_mutex);
	printf("%lld %d is thinking\n", data->time_now - data->old_time,
		num_of_philo + 1);
	sem_post(data->dead_mutex);
	return (0);
}

int	ft_check_if_all_eat(t_data *data)
{
	int	hmpe;
	int	a;

	a = -1;
	hmpe = 0;
	if (data->argc == 5)
		return (0);
	while (++a < data->number_of_philosophers)
	{
		if (data->num_of_times_eat
			>= data->number_of_times_each_philosopher_must_eat)
			hmpe++;
	}
	if (hmpe == data->number_of_philosophers)
	{
		data->all_eat = 1;
		return (1);
	}
	return (0);
}

int	ft_check_if_dead(t_data *data, int num_of_philo)
{
	if ((data->time_now - data->old_time)
		- data->old_time_eat >= data->time_to_die)
	{
		printf("%lld %d died\n", data->time_now - data->old_time,
			num_of_philo + 1);
		return (1);
	}
	return (0);
}
