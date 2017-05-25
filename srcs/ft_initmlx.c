/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initmlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 18:33:13 by dhervy            #+#    #+#             */
/*   Updated: 2016/06/25 16:29:39 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_mlx	ft_initmlx(t_mlx mlx)
{
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, LARGEUR, HAUTEUR, "Fdf");
	mlx.img = mlx_new_image(mlx.mlx, LARGEUR, HAUTEUR);
	return (mlx);
}
