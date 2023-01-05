/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:52:41 by fhihi             #+#    #+#             */
/*   Updated: 2023/01/04 19:01:43 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

int	ft_jkevent(int keycode, void *param)
{
	t_info	*ma3;

	ma3 = param;
	if (keycode == 53)
	{
		mlx_destroy_image(ma3->mlx_ptr, ma3->img_ptr);
		mlx_destroy_window(ma3->mlx_ptr, ma3->win_ptr);
		exit(0);
	}
	else if (keycode == 49)
	{
		ma3->color = ft_random();
		juliaset(ma3);
		mlx_put_image_to_window(ma3->mlx_ptr, ma3->win_ptr, ma3->img_ptr, 0, 0);
	}
	return (1);
}

int	exit_func(void)
{
	exit(0);
}

int	ft_mkevent(int keycode, void *param)
{
	t_info	*ma3;

	ma3 = param;
	if (keycode == 53)
	{
		mlx_destroy_image(ma3->mlx_ptr, ma3->img_ptr);
		mlx_destroy_window(ma3->mlx_ptr, ma3->win_ptr);
		exit(0);
	}
	else if (keycode == 49)
	{
		ma3->color = ft_random();
		mandlebrot(ma3);
		mlx_put_image_to_window(ma3->mlx_ptr, ma3->win_ptr, ma3->img_ptr, 0, 0);
	}
	return (1);
}

int	ft_mmevent(int botton, int x, int y, void *param)
{
	t_info	*ma3;

	(void )x;
	(void )y;
	ma3 = param;
	if (botton == 5)
	{
		ma3->max *= 0.75;
		ma3->min *= 0.75;
		mandlebrot(ma3);
		mlx_put_image_to_window(ma3->mlx_ptr, ma3->win_ptr, ma3->img_ptr, 0, 0);
	}
	else if (botton == 4)
	{
		ma3->max /= 0.75;
		ma3->min /= 0.75;
		mandlebrot(ma3);
		mlx_put_image_to_window(ma3->mlx_ptr, ma3->win_ptr, ma3->img_ptr, 0, 0);
	}
	return (1);
}

int	ft_jmevent(int botton, int x, int y, void *param)
{
	t_info	*ma3;

	(void )x;
	(void )y;
	ma3 = param;
	if (botton == 5)
	{
		ma3->max *= 0.75;
		ma3->min *= 0.75;
		mlx_clear_window(ma3->mlx_ptr, ma3->win_ptr);
		juliaset(ma3);
		mlx_put_image_to_window(ma3->mlx_ptr, ma3->win_ptr, ma3->img_ptr, 0, 0);
	}
	else if (botton == 4)
	{
		ma3->max /= 0.75;
		ma3->min /= 0.75;
		mlx_clear_window(ma3->mlx_ptr, ma3->win_ptr);
		juliaset(ma3);
		mlx_put_image_to_window(ma3->mlx_ptr, ma3->win_ptr, ma3->img_ptr, 0, 0);
	}
	return (1);
}
