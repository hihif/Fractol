/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:34:36 by fhihi             #+#    #+#             */
/*   Updated: 2023/01/03 13:11:15 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

t_info	window(t_info data)
{
	int	end;
	int	bits;
	int	line;

	line = data.line_bytes;
	bits = data.bits;
	end = data.endian;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Project");
	data.img_ptr = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	data.buffer = mlx_get_data_addr(data.img_ptr, &bits, &line, &end);
	data.line_bytes = line;
	data.endian = end;
	data.bits = bits;
	return (data);
}

void	help(void)
{
	ft_printf("\n\n// --help \n");
	ft_printf("Execute the program with the next Instructions :\n");
	ft_printf("    program name  <Frac'ol keyword> <avail-options>\n");
	ft_printf("---------------------------------------------------\n");
	ft_printf("Available fractols \n");
	ft_printf("    Name          Keyword            Options\n");
	ft_printf("  Mandlebrot 	   [ M ]	    Iterations \n");
	ft_printf("  JuliaSet         [ J ] 	     Set Number\n");
	ft_printf("---------------------------------------------------\n");
	ft_printf("For the Julia Set numbers you cab use any number from 1 to 4\n\n");
	exit(0);
}
