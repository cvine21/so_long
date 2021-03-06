/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:35:43 by cvine             #+#    #+#             */
/*   Updated: 2022/02/17 12:13:03 by cvine        ###   ########.fr       */
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
# define X			64
# define Y			64
# define RIGHT		"./assets/rfrog.xpm"
# define RIGHT1		"./assets/rfrog1.xpm"
# define RIGHT2		"./assets/rfrog2.xpm"
# define LEFT		"./assets/lfrog.xpm"
# define LEFT1		"./assets/lfrog1.xpm"
# define LEFT2		"./assets/lfrog2.xpm"
# define WALL		"./assets/box.xpm"
# define GROUND		"./assets/green.xpm"
# define PLAYER		"./assets/rfrog.xpm"
# define COLLECT	"./assets/apple.xpm"
# define EXIT		"./assets/exit.xpm"
# define ENEMY		"./assets/rbat1.xpm"
# define ENEMY1		"./assets/rbat2.xpm"
# define ENEMY2		"./assets/rbat3.xpm"
# define ENEMY3		"./assets/rbat4.xpm"
# define ENEMY4		"./assets/rbat5.xpm"
# define ENEMY5		"./assets/rbat6.xpm"
# define ENEMY6		"./assets/rbat7.xpm"
# define COUNTER	"./assets/Sword.xpm"
# define BANNER1	"./assets/banner1.xpm"
# define BANNER2	"./assets/banner2.xpm"
# define BANNER3	"./assets/banner3.xpm"

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
	int	move_flag;
	int	dir_flag;
}	t_player;

typedef struct s_img
{
	void	*wall;
	void	*player;
	void	*exit;
	void	*ground;
	void	*collectible;
	void	*enemy;
	void	*banner1;
	void	*banner2;
	void	*banner3;
	int		width;
	int		height;
}	t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	t_img		img;
	t_player	hero;
	int			e_num;
	int			p_num;
	int			c_num;
	int			bottom_wall;
	int			wing_flag;
}	t_game;

void	animate_player(t_game *game);
void	animate_enemy(t_game *game);
void	move_enemy(t_game *game, char **map, int i, int j);
int		handle_enemy(t_game *game);
int		key_up(int keysym, t_game *game, int w, int h);

t_game	*game_init(void);
void	move_player(t_game *game, int x, int y);
void	render_map(t_game *game);
int		press_key(int keysym, t_game *game);
int		close_window(t_game *game);
void	terminate(char *errname, int status);
void	check_args(int argc, char **argv);
void	check_map(t_game *map, char *line, int fd);
void	create_map(char *argv, t_game *map);

#endif