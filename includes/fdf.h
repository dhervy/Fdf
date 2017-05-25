/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 17:33:25 by dhervy            #+#    #+#             */
/*   Updated: 2017/04/02 20:48:17 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../minilibx_macos/mlx.h"

# define BLANC 0xFFFFFF
# define MARRON 0x9c3f00
# define VERT 0x00d204
# define XY 0
# define Z 1
# define POSX 2
# define POSY 3
# define RADIAN 4
# define Y 0
# define X 1
# define DX 0
# define SX 1
# define DY 2
# define SY 3
# define ERR 4
# define E2 5
# define X0 0
# define X1 1
# define Y0 2
# define Y1 3
# define I 0
# define K 1
# define LARGEUR 2560
# define HAUTEUR 1600

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
	void				*img;
	int					*getaddr;
	int					bpp;
	int					sizeline;
	int					endian;
	double				*dist;
	int					*size;
	struct s_maps		**maps;
}						t_mlx;

typedef struct			s_maps
{
	int					x;
	int					xp;
	int					y;
	int					yp;
	int					z;
	int					color;
	int					end;
}						t_maps;

typedef struct			s_keyhook
{
	double				*dist;
	t_maps				**maps;
	int					*size;
}						t_keyhook;

t_mlx					ft_initmlx(t_mlx mlx);
t_mlx					ft_getmaps(char	*fichier, t_mlx mlx);
t_mlx					ft_countsizetab(char *fichier, t_mlx mlx);
t_mlx					ft_initposition(t_mlx mlx);
t_mlx					line(int *p, t_mlx mlx, int color, int pos[6]);
int						ft_countx(char *str);
void					ft_checkmaps(char **tab, t_mlx mlx);
t_mlx					ft_mallocmaps(char **tab, t_mlx mlx);
t_mlx					ft_initdist(t_mlx mlx);
void					fdf(int start, t_mlx mlx);
t_mlx					ft_initsize(t_mlx mlx);
t_mlx					ft_initdist(t_mlx mlx);
t_mlx					ft_initcolor(t_mlx mlx);
int						*ft_initline(int *point, t_maps debut, t_maps fin);
t_mlx					ft_initmaps(t_mlx mlx);
t_mlx					ft_tabtomaps(t_mlx mlx, char **tab);
int						ft_key_founct(int keycode, t_mlx *mlx);
char					**ft_malloctab(int *size, char *fichier, char **tab);

#endif
