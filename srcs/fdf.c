/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 17:19:44 by dhervy            #+#    #+#             */
/*   Updated: 2016/06/25 16:28:00 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_checkarg(int argc, char **argv)
{
	char	*str;

	if (argc != 2)
	{
		str = ft_strdup("Usage : ");
		str = ft_strjoinfree(str, argv[0], 0);
		str = ft_strjoinfree(str, " <filename>", 0);
		ft_exiterror(str);
	}
	else if (open(argv[1], O_RDONLY) < 0)
	{
		str = ft_strdup("No file ");
		str = ft_strjoinfree(str, argv[1], 0);
		ft_exiterror(str);
	}
}

void		fdf2(t_mlx mlx, int *point)
{
	int	y;
	int	x;
	int	pos[6];

	y = 0;
	x = 0;
	while (y < mlx.size[Y])
	{
		while (x < mlx.size[X])
		{
			if (x + 1 < mlx.size[X])
			{
				point = ft_initline(point, mlx.maps[y][x], mlx.maps[y][x + 1]);
				mlx = line(point, mlx, mlx.maps[y][x].color, pos);
			}
			if (y + 1 < mlx.size[Y])
			{
				point = ft_initline(point, mlx.maps[y][x], mlx.maps[y + 1][x]);
				mlx = line(point, mlx, mlx.maps[y][x].color, pos);
			}
			x++;
		}
		y++;
		x = 0;
	}
}

void		fdf(int start, t_mlx mlx)
{
	int		*point;

	point = (int*)malloc(sizeof(int) * 4);
	if (start == 0)
	{
		mlx = ft_initmlx(mlx);
		mlx = ft_initdist(mlx);
	}
	mlx = ft_initposition(mlx);
	mlx = ft_initcolor(mlx);
	mlx_destroy_image(mlx.mlx, mlx.img);
	mlx.img = mlx_new_image(mlx.mlx, LARGEUR, HAUTEUR);
	mlx.getaddr = (int*)mlx_get_data_addr(mlx.img, &mlx.bpp
			, &mlx.sizeline, &mlx.endian);
	fdf2(mlx, point);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_hook(mlx.win, 2, (1L << 0), ft_key_founct, &mlx);
	mlx_loop(mlx.mlx);
}

int			main(int argc, char **argv)
{
	int			*size;
	t_maps		**maps;
	char		**tab;
	double		*dist;
	t_mlx		mlx;

	ft_checkarg(argc, argv);
	mlx = ft_initsize(mlx);
	tab = ft_malloctab(mlx.size, argv[1], tab);
	mlx.size[X] = ft_countx(tab[0]);
	ft_checkmaps(tab, mlx);
	mlx = ft_mallocmaps(tab, mlx);
	fdf(0, mlx);
}
