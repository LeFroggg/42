/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:59:29 by abastian          #+#    #+#             */
/*   Updated: 2024/10/23 17:38:53 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"
# include "../ft_printf/ft_printf.h"
# include "../ft_printf/libft/libft.h"
# include "get_next_line.h"

typedef struct s_vector
{
	int		x;
	int		y;
}				t_vector;

typedef struct s_map
{
	char		**grid;
	char		**grid_clone;
	char		**grid_third;
	int			rows;
	int			columns;
	int			c;
	int			e;
	int			p;
	t_vector	player_pos;
	t_vector	map_size;
	t_vector	img_size;
	t_vector	total_size;
}			t_map;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*w_path;
	char	*p_path;
	char	*e_path;
	char	*c_path;
	char	*f_path;
	void	*w;
	void	*p;
	void	*e;
	void	*c;
	void	*f;
	int		moves;
	t_map	map;
}		t_game;

void	map_parse(char *map, t_game *game, int argc);
void	error_game(char *message, t_game *game);
int		each_line_check(char *getmap, t_game *game);
int		name_check(char *name);
int		is_wrong_data(char data, char *allowed);
void	init_elem(t_game *game);
void	check_elem(t_game *game);
void	init_value(t_game *game);
void	total_check(t_game *game);
void	start_mlx(t_game *game);
void	game_over(t_game *game);

#endif
