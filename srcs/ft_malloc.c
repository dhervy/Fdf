/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 16:35:21 by dhervy            #+#    #+#             */
/*   Updated: 2016/06/25 16:29:50 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	**ft_malloctab(int *size, char *fichier, char **tab)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(fichier, O_RDONLY);
	tab = (char**)malloc(sizeof(char*) * size[Y]);
	get_next_line(fd, &line);
	tab[i++] = ft_strdup(ft_strtrimi(line, ' '));
	while (get_next_line(fd, &line))
	{
		size[Y]++;
		tab = ft_tabdup(tab, size[Y]);
		tab[i++] = ft_strdup(ft_strtrimi(line, ' '));
	}
	return (tab);
}

t_mlx	ft_mallocmaps(char **tab, t_mlx mlx)
{
	int i;

	i = 0;
	mlx.maps = (t_maps**)malloc(sizeof(t_maps*) * mlx.size[Y]);
	while (i < mlx.size[Y])
		mlx.maps[i++] = (t_maps*)malloc(sizeof(t_maps) * mlx.size[X]);
	mlx = ft_initmaps(mlx);
	mlx = ft_tabtomaps(mlx, tab);
	return (mlx);
}
