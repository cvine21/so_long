/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:35:43 by cvine             #+#    #+#             */
/*   Updated: 2022/02/01 16:05:38 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define W			13
# define A			0
# define S			1
# define D			2
# define ESC		53
# define DESTROY	17
# define PIXEL		64

# include "libft.h"
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_player
{
	int	x;
	int	y;
	int	moves;
}	t_player;

typedef struct	s_img
{
	void	*wall;
	void	*player;
	void	*exit;
	void	*ground;
	void	*collectible;
	int		width;
	int		height;
}	t_img;

typedef struct s_game
{
	t_img		img;
	t_player	hero;
	void		*mlx;
	void		*win;
	char		**map;
	int			e_num;
	int			p_num;
	int			c_num;
	int			end_of_map;
}	t_game;

int		close_window(t_game *game);
int		press_key(int keysym, t_game *game);
void	xmp_to_img(t_game *map, int width, int height);
t_game	*map_init(void);
void	draw_map(t_game *game, int width, int height);

void	terminate(char *errname, int status);
void	check_args(int argc, char **argv);
void	check_map(t_game	*map, char *line, int fd);
void	create_map(char *argv, t_game *map);

#endif