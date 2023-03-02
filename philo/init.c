/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:22:13 by cegbulef          #+#    #+#             */
/*   Updated: 2023/01/29 12:21:17 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg_error(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("%s\n", "\033[1;31m Please enter the right arguments: \033[0m");
		printf("%s\n", "Ex: ./philo [num of philo] [time 2 die] [time 2 eat]");
		return (-1);
	}
	if (check_digit(argv))
	{
		printf("%s", "\033[1;31m Invalid Arguments \033[0m");
		return (-1);
	}
	return (0);
}

int	int_overflow_check(t_data *data, char **argv)
{
	if (data->n_philo < 0 || data->n_philo > 200 || data->t_die < 0
		|| data->t_eat < 0 || data->t_sleep < 0)
		return (1);
	if (argv[5])
	{
		data->max_lunch = ft_atoi(argv[5]);
		if (data->max_lunch < 0)
			return (1);
	}
	else
		data->max_lunch = false;
	return (0);
}

int	init_var(char **argv, t_data *data)
{
	int	i;

	i = -1;
	data->error = false;
	data->end_game = false;
	data->end_lunch = 0;
	data->n_philo = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (int_overflow_check(data, argv))
	{
		printf("%s", "\033[1;31m Invalid Arguments \033[0m");
		return (free(data), 1);
	}
	data->philo = ft_calloc(data->n_philo, (sizeof(t_philo)));
	data->fork = ft_calloc(data->n_philo, (sizeof(pthread_mutex_t)));
	pthread_mutex_init(&data->checks, NULL);
	while (++i < data->n_philo)
		pthread_mutex_init(&data->fork[i], NULL);
	init_philos(data);
	data->t_start = timestart();
	return (0);
}

void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		data->philo[i].id_num = i + 1;
		data->philo[i].lunch_eaten = 0;
		data->philo[i].last_lunch = 0;
		data->philo[i].l_fork = i;
		data->philo[i].r_fork = (i + 1) % data->n_philo;
		data->philo[i].args = data;
		i++;
	}
}

void	philo_destroy(t_data *data)
{
	int	i;

	i = 0;
	if (data->n_philo > 1)
	{
		while (i < data->n_philo)
			pthread_join(data->philo[i++].thd, NULL);
	}
	i = 0;
	while (i < data->n_philo)
		pthread_mutex_destroy(&data->fork[i++]);
	pthread_mutex_destroy(&data->checks);
	free(data->philo);
	free(data->fork);
	free(data);
}
