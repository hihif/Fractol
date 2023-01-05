/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:34:31 by fhihi             #+#    #+#             */
/*   Updated: 2023/01/04 19:02:19 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include	<mlx.h>
# include	<math.h>
# include	<stdlib.h>
# include	"libft/libft.h"
# include	"ft_printf/ft_printf.h"
# define WIDTH 1000
# define HEIGHT 1000
# define MIN -2
# define MAX 2

typedef struct s_comp {
	double	x;
	double	y;
}	t_complex;

typedef struct s_info {
	double		min;
	double		max;
	double		zoom;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*buffer;
	int			bits;
	int			line_bytes;
	int			endian;
	int			iterations;
	size_t		color;
	t_complex	c;
}	t_info;

typedef struct s_variable
{
	double	row;
	double	col;
	double	c_re;
	double	c_im;
	double	temp;
	double	zx;
	double	zy;
	int		n;
	size_t	rgb;
}	t_var;

double	ft_map(double x, int end, double rangemin, double rangemax);
void	ft_pixel_color(int x, int y, size_t color, void *param);
void	mandlebrot(t_info *data);
void	juliaset(t_info *data);
void	help(void);
int		exit_func(void);
int		ft_random(void);
int		ft_jkevent(int keycode, void *param);
int		ft_mkevent(int keycode, void *param);
int		ft_jmevent(int botton, int x, int y, void *param);
int		ft_mmevent(int botton, int x, int y, void *param);
int		ft_sets(int n, t_complex *c);
int		ft_sets2(int n, t_complex *c);
size_t	ft_rand_color(void);
t_info	window(t_info data);

#endif