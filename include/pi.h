/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:36:46 by pehenriq          #+#    #+#             */
/*   Updated: 2022/04/17 23:22:20 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PI_H
# define PI_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>

# include "../libft/libft.h"

# define WIN_SIZE_X 400
# define WIN_SIZE_Y 400

typedef struct s_img {
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_params {
	void	*mlx;
	void	*win;
	t_img	img;
	int		color_one;
	int		color_two;
	double	radius;
	double	x;
	double	y;
}				t_params;

void			draw_circle(t_params *pi);
void			draw_pixel(t_img *img, int x, int y, int color);
void			draw_point(t_params *pi, int x, int y, double pi_value);

int				create_trgb(int t, int r, int g, int b);

#endif
