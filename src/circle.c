/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:42:03 by pehenriq          #+#    #+#             */
/*   Updated: 2022/04/17 22:27:09 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pi.h"

void	draw_circle(t_params *pi)
{
	double	x;
	double	y;
	double	dist_x;
	double	dist_y;

	x = 0;
	while (x <= WIN_SIZE_X)
	{
		y = 0;
		while (y <= WIN_SIZE_Y)
		{
			dist_x = x - pi->radius;
			dist_y = y - pi->radius;
			if ((dist_x * dist_x + dist_y * dist_y)
				<= (pi->radius * pi->radius))
				draw_pixel(&pi->img, (int) x, (int) y, pi->color_one);
			else
				draw_pixel(&pi->img, (int) x, (int) y, pi->color_two);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(pi->mlx, pi->win, pi->img.ptr, 0, 0);
}
