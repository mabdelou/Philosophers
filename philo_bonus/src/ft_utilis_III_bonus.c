/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilis_III_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:05:03 by mabdelou          #+#    #+#             */
/*   Updated: 2022/05/19 15:05:04 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

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
