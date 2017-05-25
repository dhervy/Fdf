/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 16:27:11 by dhervy            #+#    #+#             */
/*   Updated: 2016/06/25 16:43:02 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_mlx	ft_initsize(t_mlx mlx)
{
	mlx.size = (int*)malloc(sizeof(int) * 2);
	mlx.size[X] = 0;
	mlx.size[Y] = 1;
	return (mlx);
}

t_mlx	ft_initdist(t_mlx mlx)
{
	int	i;

	i = 0;
	if (mlx.size[X] < mlx.size[Y])
		i = mlx.size[Y];
	else
		i = mlx.size[X];
	mlx.dist = (double*)malloc(sizeof(double) * 5);
	mlx.dist[XY] = (LARGEUR / (i * 4)) + 1;
	mlx.dist[Z] = mlx.dist[XY] * 1.5;
	mlx.dist[POSX] = 0;
	mlx.dist[POSY] = 0;
	mlx.dist[RADIAN] = 0.610865;
	return (mlx);
}

t_mlx	ft_initcolor2(t_mlx mlx, int y, int x, int zmax)
{
	y = 0;
	x = 0;
	while (y < mlx.size[Y])
	{
		while (x < mlx.size[X])
		{
			if ((mlx.maps[y][x].z <= zmax && mlx.maps[y][x].z >=
						((zmax / 3) * 2) + 1) && mlx.maps[y][x].color == -1)
				mlx.maps[y][x].color = BLANC;
			else if ((mlx.maps[y][x].z < ((zmax / 3) * 2) && mlx.maps[y][x].z >=
						(zmax / 3)) && mlx.maps[y][x].color == -1)
				mlx.maps[y][x].color = MARRON;
			else if (mlx.maps[y][x].color == -1)
				mlx.maps[y][x].color = VERT;
			x++;
		}
		y++;
		x = 0;
	}
	return (mlx);
}

t_mlx	ft_initcolor(t_mlx mlx)
{
	int	x;
	int	y;
	int	zmax;

	x = 0;
	y = 0;
	zmax = 0;
	while (y < mlx.size[Y])
	{
		while (x < mlx.size[X])
		{
			if (mlx.maps[y][x].z > zmax)
				zmax = mlx.maps[y][x].z;
			x++;
		}
		y++;
		x = 0;
	}
	mlx = ft_initcolor2(mlx, y, x, zmax);
	return (mlx);
}

int		*ft_initline(int *point, t_maps debut, t_maps fin)
{
	point[X0] = debut.xp;
	point[Y0] = debut.yp;
	point[X1] = fin.xp;
	point[Y1] = fin.yp;
	return (point);
}
