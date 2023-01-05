/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandlebrotset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:51:06 by fhihi             #+#    #+#             */
/*   Updated: 2023/01/04 19:01:55 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

static	void	ft_checker(t_var *var, t_info *data)
{
	double	bound;

	bound = 0;
	while (bound < 4 && var->n < data->iterations)
	{
		bound = var->zx * var->zx + var->zy * var->zy;
		var->temp = var->zx * var->zx - var->zy * var->zy + var->c_re;
		var->zy = 2 * var->zx * var->zy + var->c_im;
		var->zx = var->temp;
		var->n++;
	}
}

void	mandlebrot(t_info *data)
{
	t_var	var;

	var.col = 0;
	while (var.col < WIDTH)
	{
		var.row = 0;
		while (var.row < HEIGHT)
		{
			var.c_re = ft_map(var.col, WIDTH, data->min, data->max);
			var.c_im = ft_map(var.row, HEIGHT, data->min, data->max);
			var.zx = 0;
			var.zy = 0;
			var.n = 0;
			ft_checker(&var, data);
			var.rgb = data->color + ft_map(var.n, data->iterations, 0, 255);
			if (var.n < data->iterations)
				ft_pixel_color(var.col, var.row, var.rgb + pow(var.n, 3), data);
			else
				ft_pixel_color(var.col, var.row, 0x000000, data);
			var.row++;
		}
		var.col++;
	}
}

/* the use of an array of varables was used for minimising the number of lines
	var.col >> x-axis on the graph
	var.row >> y-axis on the graph
	var.c_re >> is the real-part of c
	var.c_im >> is the imaginery-part of c
	var.temp >> is a temp varable
	var.zy >> imaginary part of the function z(n+1) = z(n)^2 + c
	var.zx >> real part of the function z(n+1) = z(n)^2 + c
	var.n >> number of iterations
	var.color >> the color of the pixles that dont belong to the set
*/