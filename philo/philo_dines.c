/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:50:17 by cegbulef          #+#    #+#             */
/*   Updated: 2023/01/28 20:02:11 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lunch_start(t_data *data)
{
	int	i;

	if (data->n_philo == 1)
		one_philo(data->philo);
	else
	{
		i = -1;
		while (++i < data->n_philo)
			pthread_create(&data->philo[i].thd, NULL,
				&philo_acts, (void *)&data->philo[i]);
		while (data->end_game == false)
			run_checks(data);
	}
}

void	*philo_acts(void *val)
{
	t_philo	*phl;
	t_data	*data;

	phl = (t_philo *)val;
	data = phl->args;
	while (data->end_game == false)
	{
		pthread_mutex_lock(&phl->args->checks);
		if (data->max_lunch > 0 && phl->lunch_eaten == data->max_lunch)
		{
			pthread_mutex_unlock(&phl->args->checks);
			break ;
		}
		pthread_mutex_unlock(&phl->args->checks);
		phl_eats(phl);
		phl_sleeps(phl);
		phl_thinks(phl);
	}
	return (NULL);
}

void	run_checks(t_data *data)
{
	int	death_nbr;

	death_nbr = 0;
	while (data->end_game == false)
	{
		death_status(&data->philo[death_nbr]);
		max_lunch_check(data);
		usleep(1000);
		if (death_nbr == data->n_philo - 1)
			death_nbr = -1;
		death_nbr++;
	}
}

void	max_lunch_check(t_data *data)
{
	int	lunch_nbr;

	lunch_nbr = 0;
	if (data->max_lunch > 0)
	{
		while (lunch_nbr < data->n_philo)
		{
			pthread_mutex_lock(&data->checks);
			if (data->philo[lunch_nbr].lunch_eaten < data->max_lunch)
			{
				pthread_mutex_unlock(&data->checks);
				break ;
			}
			pthread_mutex_unlock(&data->checks);
			lunch_nbr++;
		}
		if (lunch_nbr == data->n_philo)
		{
			pthread_mutex_lock(&data->checks);
			data->end_game = true;
			pthread_mutex_unlock(&data->checks);
		}
	}
}

void	death_status(t_philo *phl)
{
	bool	lock;

	lock = true;
	pthread_mutex_lock(&phl->args->checks);
	if ((timestamp(phl->args) - phl->last_lunch) >= phl->args->t_die)
	{
		lock = false;
		pthread_mutex_unlock(&phl->args->checks);
		display(phl, "\U0001F480 \033[1;31m died \033[0m");
		pthread_mutex_lock(&phl->args->checks);
		phl->args->end_game = true;
		pthread_mutex_unlock(&phl->args->checks);
	}
	if (lock)
		pthread_mutex_unlock(&phl->args->checks);
}
