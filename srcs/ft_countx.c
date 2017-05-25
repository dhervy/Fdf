/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 20:28:20 by dhervy            #+#    #+#             */
/*   Updated: 2016/06/25 16:28:19 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_checkmaps(char **tab, t_mlx mlx)
{
	int		i;

	i = 1;
	while (i < mlx.size[Y])
	{
		if (ft_countx(tab[i]) < mlx.size[X])
			ft_exiterror("Found wrong line length. Exiting.");
		i++;
	}
}

int		ft_countx(char *str)
{
	int		i;
	int		space;

	i = 0;
	space = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			space++;
		i++;
	}
	return (space + 1);
}
