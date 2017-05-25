/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traceligne.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 17:32:21 by dhervy            #+#    #+#             */
/*   Updated: 2016/06/25 16:29:54 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_mlx	line(int *p, t_mlx mlx, int color, int pos[6])
{
	pos[DX] = abs(p[X1] - p[X0]);
	pos[SX] = p[X0] < p[X1] ? 1 : -1;
	pos[DY] = abs(p[Y1] - p[Y0]);
	pos[SY] = p[Y0] < p[Y1] ? 1 : -1;
	pos[ERR] = (pos[DX] > pos[DY] ? pos[DX] : -pos[DY]) / 2;
	while (1)
	{
		if (p[Y0] > 0 && p[X0] > 0 && p[Y0] < HAUTEUR && p[X0] < LARGEUR)
			mlx.getaddr[p[Y0] * LARGEUR + p[X0]] = color;
		if (p[X0] == p[X1] && p[Y0] == p[Y1])
			break ;
		pos[E2] = pos[ERR];
		if (pos[E2] > -pos[DX])
		{
			pos[ERR] -= pos[DY];
			p[X0] += pos[SX];
		}
		if (pos[E2] < pos[DY])
		{
			pos[ERR] += pos[DX];
			p[Y0] += pos[SY];
		}
	}
	return (mlx);
}
