/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmaps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 21:27:47 by dhervy            #+#    #+#             */
/*   Updated: 2016/06/25 16:29:28 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_checknum(char *tab, int i)
{
	while (!ft_isalnum(tab[i]))
		i++;
	return (i);
}

int		ft_tabtomaps3(char *tab, char *str, int i)
{
	int	k;

	k = 0;
	while (tab[i] != ',' && ft_isalnum(tab[i]))
		str[k++] = tab[i++];
	return (i);
}

t_mlx	ft_tabtomaps2(t_mlx mlx, char *tab, int y, int x)
{
	int		i;
	int		k;
	char	*str;

	i = 0;
	k = 0;
	str = (char*)ft_memalloc(sizeof(char) * 256);
	while (tab[i])
	{
		i = ft_checknum(tab, i);
		i = ft_tabtomaps3(tab, str, i);
		mlx.maps[y][x].z = ft_atoi(str);
		ft_bzero(str, 256);
		if (tab[i] == ',')
		{
			i++;
			while (ft_isalnum(tab[i]))
				str[k++] = tab[i++];
			mlx.maps[y][x].color = ft_hexatoint(str);
			ft_bzero(str, 256);
			k = 0;
		}
		x++;
	}
	return (mlx);
}

t_mlx	ft_tabtomaps(t_mlx mlx, char **tab)
{
	int		y;

	y = 0;
	while (y < mlx.size[Y])
	{
		mlx = ft_tabtomaps2(mlx, tab[y], y, 0);
		y++;
	}
	return (mlx);
}

t_mlx	ft_initmaps(t_mlx mlx)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < mlx.size[Y])
	{
		while (x < mlx.size[X])
		{
			mlx.maps[y][x].x = x;
			mlx.maps[y][x].y = y;
			mlx.maps[y][x].z = 0;
			mlx.maps[y][x].yp = 0;
			mlx.maps[y][x].xp = 0;
			mlx.maps[y][x].color = -1;
			x++;
		}
		y++;
		x = 0;
	}
	return (mlx);
}
