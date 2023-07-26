/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:37:29 by mabdelou          #+#    #+#             */
/*   Updated: 2022/05/13 18:37:30 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_free(t_data *data)
{
	free(data->philo);
	data->a = -1;
	if (pthread_mutex_destroy(&data->dead_mutex) == -1)
		return (ft_error("ERROR : can't destroy mutex\n"));
	while (++data->a < data->number_of_philosophers)
		if (pthread_mutex_destroy(&data->mutex_eat[data->a]) == -1)
			return (ft_error("ERROR : can't destroy mutex\n"));
	free(data->mutex_eat);
	return (0);
}

void	*works_list_for_phils(void *ptr)
{
	t_data	*data;
	int		num_of_philo;

	data = (t_data *)ptr;
	if (ft_check_if_one_philo(data))
		return (NULL);
	num_of_philo = data->a;
	if (num_of_philo % 2 == 0)
		usleep(10000);
	else
		data->old_time = ft_calc_time(data);
	while (1337)
	{
		if (ft_take_forks(data, num_of_philo))
			return (NULL);
		if (data->argc == 6)
			if (data->philo[num_of_philo].num_of_times_eat
				>= data->number_of_times_each_philosopher_must_eat)
				return (NULL);
		ft_philo_eat(data, num_of_philo);
		ft_philo_sleep(data, num_of_philo);
	}
}

int	ft_create_thread(t_data *data)
{
	data->a = -1;
	while (++data->a < data->number_of_philosophers)
	{
		if (pthread_create(&data->philo[data->a].phil,
				NULL, &works_list_for_phils, data) != 0)
			return (ft_error("ERROR : can't create thread\n"));
		data->philo[data->a].r_fork = data->a;
		if (data->number_of_philosophers > 1)
		{
			if (data->a == 0)
				data->philo[data->a].l_fork = data->number_of_philosophers - 1;
			else
				data->philo[data->a].l_fork = data->a - 1;
		}
		usleep(100);
	}
	return (0);
}

int	ft_data_init(t_data *data, char **argv)
{
	int	a;

	a = -1;
	data->all_eat = 0;
	data->old_time = 0;
	data->time_now = 0;
	data->number_of_philosophers = ft_atoi(argv[1]);
	if (data->number_of_philosophers == 0)
		return (ft_error("invalid num of phils\n"));
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (data->argc == 6)
		data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	data->mutex_eat = malloc(sizeof(pthread_mutex_t)
			* data->number_of_philosophers);
	if (!data->mutex_eat)
		return (ft_error("can't allocate in ft_data_init\n"));
	data->a = -1;
	while (++data->a < data->number_of_philosophers)
		if (pthread_mutex_init(&data->mutex_eat[data->a], NULL) == -1)
			return (ft_error("can't initialise mutex in ft_data_init\n"));
	if (pthread_mutex_init(&data->dead_mutex, NULL) == -1)
		return (ft_error("can't initialise mutex in ft_data_init\n"));
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->argc = argc;
	if (argc != 5 && argc != 6)
		return (ft_error("too litle or too many argumment\n"));
	if (ft_check_argument_if_correct(argv))
		return (1);
	if (ft_data_init(data, argv))
		return (1);
	if (ft_create_philos(data))
		return (1);
	if (ft_create_thread(data))
		return (1);
	if (ft_join_thread(data))
		return (1);
	return (0);
}
