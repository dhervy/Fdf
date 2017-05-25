/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initposition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 15:50:39 by dhervy            #+#    #+#             */
/*   Updated: 2016/06/25 16:43:20 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_mlx	ft_modifposition(t_mlx mlx)
{
	int y;
	int x;
	int initx;
	int inity;

	y = 0;
	x = 0;
	inity = abs(mlx.maps[0][mlx.size[X] - 1].yp);
	while (y < mlx.size[Y])
	{
		while (x < mlx.size[X])
		{
			mlx.maps[y][x].yp += (inity + mlx.dist[POSY]);
			x++;
		}
		y++;
		x = 0;
	}
	return (mlx);
}

t_mlx	ft_initposition(t_mlx mlx)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < mlx.size[Y])
	{
		while (x < mlx.size[X])
		{
			mlx.maps[y][x].x = (mlx.dist[XY] * x);
			mlx.maps[y][x].y = (mlx.dist[XY] * y);
			mlx.maps[y][x].xp = (cos(mlx.dist[RADIAN]) * (mlx.maps[y][x].x +
					mlx.maps[y][x].y)) + mlx.dist[POSX];
			mlx.maps[y][x].yp = (sin(mlx.dist[RADIAN]) * ((mlx.maps[y][x].y -
					(mlx.maps[y][x].z * mlx.dist[Z])) - mlx.maps[y][x].x)) +
					mlx.dist[POSY];
			++x;
		}
		++y;
		x = 0;
	}
	return (mlx);
}
