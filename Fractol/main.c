/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:34:26 by fhihi             #+#    #+#             */
/*   Updated: 2023/01/04 19:02:44 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

static	void	ft_julia(t_info *data)
{
	juliaset(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	mlx_key_hook(data->win_ptr, &ft_jkevent, data);
	mlx_hook(data->win_ptr, 17, 0, &exit_func, 0);
	mlx_mouse_hook(data->win_ptr, &ft_jmevent, data);
}

static	void	ft_mandl(t_info *data, int n)
{
	data->iterations = n;
	mandlebrot(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	mlx_key_hook(data->win_ptr, &ft_mkevent, data);
	mlx_hook(data->win_ptr, 17, 0, &exit_func, 0);
	mlx_mouse_hook(data->win_ptr, &ft_mmevent, data);
}

static void	get_data(t_info *data)
{
	data->color = 0x000856;
	data->iterations = 50;
	data->min = MIN;
	data->max = MAX;
	data->c.x = -0.835;
	data->c.y = -0.2321;
}

static void	draw(t_info *data, char **av)
{
	int	iter;

	iter = ft_atoi(av[2]);
	*data = window(*data);
	get_data(data);
	if (ft_strncmp(av[1], "M", 2) == 0)
	{
		if (iter == 0)
			help();
		ft_mandl(data, iter);
	}
	else if (ft_strncmp(av[1], "J", 2) == 0)
	{
		ft_sets(ft_atoi(av[2]), &data->c);
		ft_julia(data);
	}
	mlx_loop(data->mlx_ptr);
}

int	main(int ac, char *av[])
{
	t_info	data;

	if (ac != 3)
		help();
	else
	{
		if (ft_strncmp(av[1], "M", 2) == 0 || ft_strncmp(av[1], "J", 2) == 0)
			draw(&data, av);
		else
		{
			help();
			exit(0);
		}
	}
	return (0);
}
