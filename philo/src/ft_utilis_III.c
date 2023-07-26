/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilis_III.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:45:23 by mabdelou          #+#    #+#             */
/*   Updated: 2022/05/19 14:45:27 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	ft_calc_time(t_data *data)
{
	struct timeval	tv;

	(void) data;
	gettimeofday(&tv, NULL);
	data->time_now = (tv.tv_sec * 1000 + tv.tv_usec / 1000);
	return (data->time_now);
}

void	ft_usleep(t_data *data, int time)
{
	long long	old_time;

	old_time = ft_calc_time(data);
	while ((ft_calc_time(data) - old_time) < time)
		usleep(400);
}

int	ft_check_if_one_philo(t_data *data)
{
	if (data->number_of_philosophers == 1)
	{
		usleep(data->time_to_die * 1000);
		printf("%d %d dead\n", data->time_to_die, 1);
		data->all_eat = 1;
		return (1);
	}
	return (0);
}
