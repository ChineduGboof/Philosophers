/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:25:36 by cegbulef          #+#    #+#             */
/*   Updated: 2023/01/26 21:00:30 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Error: Once Time to eat exceeds about 3000 it hangs
*/
#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (check_arg_error(argc, argv) != 0)
		return (-1);
	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		return (-1);
	if (init_var(argv, data))
		return (-1);
	lunch_start(data);
	philo_destroy(data);
	return (0);
}
