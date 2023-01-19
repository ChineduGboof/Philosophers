/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:05:00 by cegbulef          #+#    #+#             */
/*   Updated: 2023/01/17 14:11:32 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	timestart(void)
{
	struct timeval start_time;

	gettimeofday(&start_time, NULL);
	return ((start_time.tv_sec * 1000) + (start_time.tv_usec / 1000));
}

long long	timestamp(t_data *data)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return (((time.tv_sec * 1000) + (time.tv_usec / 1000)) - data->t_start);
}

void	ft_sleep(t_philo *phl, int t_2_wait)
{
	long long	current_time;
	long long	diff;

	current_time = timestamp(phl->args);
	while(1)
	{
		diff = (timestamp(phl->args) - current_time);
		if (diff >= t_2_wait)
			break;
		usleep(1000);
	}
}