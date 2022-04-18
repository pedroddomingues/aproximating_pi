/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:39:21 by pehenriq          #+#    #+#             */
/*   Updated: 2022/04/17 23:21:41 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pi.h"

static int	close_window(void)
{
	exit(0);
	return (0);
}

static void	new_window(t_params *pi, char *name)
{
	pi->win = mlx_new_window(pi->mlx, WIN_SIZE_X, WIN_SIZE_Y, name);
	mlx_hook(pi->win, 17, 0, close_window, pi);
}

static void	init(t_params *pi)
{
	pi->mlx = mlx_init();
	new_window(pi, "aproximating pi - pehenriq");
	pi->color_one = create_trgb(255, 255, 255, 255);
	pi->color_two = create_trgb(40, 255, 255, 0);
	pi->radius = WIN_SIZE_X / 2;
	pi->x = WIN_SIZE_X;
	pi->y = WIN_SIZE_Y;
	pi->img.ptr = mlx_new_image(pi->mlx, WIN_SIZE_X, WIN_SIZE_Y);
	pi->img.addr = mlx_get_data_addr(pi->img.ptr, &pi->img.bits_per_pixel,
			&pi->img.line_length, &pi->img.endian);
}

void	calc(t_params *pi)
{
	unsigned long long	i;
	int					x;
	int					y;
	int					in_circle;

	i = 0;
	in_circle = 0;
	while (i <= ULLONG_MAX)
	{
		x = rand() % WIN_SIZE_X;
		y = rand() % WIN_SIZE_Y;
		if ((x - pi->radius) * (x - pi->radius) + (y - pi->radius)
			* (y - pi->radius) <= (pi->radius * pi->radius))
			in_circle++;
		draw_point(pi, x, y, (double) in_circle / i * 4);
		i++;
	}
}

int	main(void)
{
	t_params			*pi;

	pi = malloc(sizeof(t_params));
	if (!pi)
	{
		perror("Error\n");
		exit(1);
	}
	init(pi);
	draw_circle(pi);
	calc(pi);
	mlx_loop(pi->mlx);
}
