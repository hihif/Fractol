/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:03:12 by fhihi             #+#    #+#             */
/*   Updated: 2023/01/03 13:11:22 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

double	ft_map(double x, int end, double rangemin, double rangemax)
{
	return ((x * (rangemax - rangemin) / end + rangemin));
}

void	ft_pixel_color(int x, int y, size_t color, void *param)
{
	t_info	*data;
	int		pixel;

	data = param;
	pixel = ((y * data->line_bytes) + (x * 4));
	if (data->endian == 1)
	{
		data->buffer[pixel + 0] = (color >> 24);
		data->buffer[pixel + 1] = (color >> 16) & 0xFF;
		data->buffer[pixel + 2] = (color >> 8) & 0xFF;
		data->buffer[pixel + 3] = (color) & 0xFF;
	}
	else if (data->endian == 0)
	{
		data->buffer[pixel + 0] = (color) & 0xFF;
		data->buffer[pixel + 1] = (color >> 8) & 0xFF;
		data->buffer[pixel + 2] = (color >> 16) & 0xFF;
		data->buffer[pixel + 3] = (color >> 24);
	}
}

int	ft_random(void)
{
	int	r;
	int	g;
	int	b;

	r = rand() % 256;
	g = rand() % 256;
	b = rand() % 256;
	return (0x000000 + r + g * pow(2, 16) + b * pow(2, 8));
}

int	ft_sets2(int n, t_complex *c)
{
	if (n == 3)
	{
		c->x = -0.70176;
		c->y = -0.3842;
	}
	else if (n == 4)
	{
		c->x = -0.4;
		c->y = 0.6;
	}
	return (0);
}

int	ft_sets(int n, t_complex *c)
{
	if (n == 1)
	{
		c->x = -0.8;
		c->y = 0.156;
	}
	else if (n == 2)
	{
		c->x = 0;
		c->y = -0.8;
	}
	else if (n == 3 || n == 4)
		ft_sets2(n, c);
	else
		help();
	return (0);
}
