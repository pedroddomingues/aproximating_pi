/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:08:08 by pehenriq          #+#    #+#             */
/*   Updated: 2022/04/17 23:19:23 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pi.h"

void	draw_point(t_params *pi, int x, int y, double pi_value)
{
	char	*str;

	str = ft_ftoa(pi_value, 5);
	if (x >= 0 && x < WIN_SIZE_X && y >= 0 && y < WIN_SIZE_Y)
		draw_pixel(&pi->img, x, y, 51564);
	mlx_put_image_to_window(pi->mlx, pi->win, pi->img.ptr, 0, 0);
	mlx_string_put(pi->mlx, pi->win, 10, 30, 0x000000, str);
	usleep(50);
}
