/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:50:17 by cegbulef          #+#    #+#             */
/*   Updated: 2023/01/19 15:50:03 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    lunch_start(t_data *data)
{
	int	i;

	if (data->n_philo == 1)
		one_philo(data->philo);
	else
	{
		i = -1;
		while(++i < data->n_philo)
		{
			pthread_create(&data->philo[i].thd, NULL, &philo_eats, (void *)&data->philo[i]);
		}
	}

}

void	*philo_eats(void *val)
{
	t_philo	*phl;
	t_data	*data;

	phl = (t_philo *)val;
	data = phl->args;
	if (phl->id_num % 2)
		usleep(1500);
	while (data->end_game == false)
	{
		if (data->max_lunch > 0 && phl->lunch_eaten == data->max_lunch)
			break;
		phl_eat(phl);
		phl_wait(phl);
		phl_sleep(phl);
	}
	return (NULL);
}

