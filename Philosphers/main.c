/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:25:36 by cegbulef          #+#    #+#             */
/*   Updated: 2023/01/17 10:42:18 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//doubts: is there a maxmum number of threads to check for that is allowed

int	main(int argc, char **argv)
{
	t_data	*data;

	if (check_arg_error(argc, argv) != 0)
		return (-1);
	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		return (-1);
	init_var(argv, data);
	lunch_start(data);
	// if (init_var(&data, argv) == 1)
	// {
	// 	free(data.philo);
	// 	return (0);
	// }
	// init_philos(&data);
	// destroy(&data);
}