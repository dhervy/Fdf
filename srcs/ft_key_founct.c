/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_founct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 16:38:22 by dhervy            #+#    #+#             */
/*   Updated: 2016/06/25 16:29:47 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_key_founct3(int keycode, t_mlx *mlx)
{
	if (keycode == 6)
	{
		mlx->dist[Z] -= 1;
		fdf(1, *mlx);
	}
	else if (keycode == 7)
	{
		mlx->dist[Z] += 1;
		fdf(1, *mlx);
	}
	else if (keycode == 15)
		fdf(0, *mlx);
	return (0);
}

int		ft_key_founct2(int keycode, t_mlx *mlx)
{
	if (keycode == 12)
	{
		mlx->dist[RADIAN] -= 0.087266;
		fdf(1, *mlx);
	}
	else if (keycode == 13)
	{
		mlx->dist[RADIAN] += 0.087266;
		fdf(1, *mlx);
	}
	else if (keycode == 0)
	{
		mlx->dist[XY] -= 1;
		fdf(1, *mlx);
	}
	else if (keycode == 1)
	{
		mlx->dist[XY] += 1;
		fdf(1, *mlx);
	}
	else
		ft_key_founct3(keycode, mlx);
	return (0);
}

int		ft_key_founct(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(1);
	else if (keycode == 126)
	{
		mlx->dist[POSY] -= 10;
		fdf(1, *mlx);
	}
	else if (keycode == 125)
	{
		mlx->dist[POSY] += 10;
		fdf(1, *mlx);
	}
	else if (keycode == 123)
	{
		mlx->dist[POSX] -= 10;
		fdf(1, *mlx);
	}
	else if (keycode == 124)
	{
		mlx->dist[POSX] += 10;
		fdf(1, *mlx);
	}
	else
		ft_key_founct2(keycode, mlx);
	return (0);
}
