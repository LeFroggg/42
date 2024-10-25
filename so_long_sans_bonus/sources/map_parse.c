/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:45:08 by abastian          #+#    #+#             */
/*   Updated: 2024/10/23 17:34:39 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*get_map(char *map, t_game *game)
{
	int		fd;
	char	*line;
	char	*bigline;
	char	*temp;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		error_game("Could not open the map.", game);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), error_game("Given map is empty !", game), NULL);
	bigline = ft_strdup("");
	if (!bigline)
		return (close(fd), free(bigline), error_game("strdup", game), NULL);
	while (line)
	{
		if (line == NULL)
			break ;
		temp = ft_strjoin(bigline, line);
		free(bigline);
		bigline = temp;
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), bigline);
}

void	data_map_check(t_game *game, int i, int j)
{
	init_elem(game);
	while (game->map.grid[i])
	{
		j = 0;
		while (game->map.grid[i][j])
		{
			if (!is_wrong_data(game->map.grid[i][j], "PEC10"))
				error_game("Map is filled with forbidden data", game);
			if (game->map.grid[i][j] == 'P')
			{
				game->map.p += 1;
				game->map.player_pos.y = i;
				game->map.player_pos.x = j;
			}
			if (game->map.grid[i][j] == 'E')
				game->map.e += 1;
			if (game->map.grid[i][j] == 'C')
				game->map.c += 1;
			j++;
		}
		i++;
	}
	check_elem(game);
}

void	ultra_map_check(t_game *game, int i)
{
	int	j;

	j = 0;
	while (game->map.grid[i])
		i++;
	i--;
	game->map.map_size.y = i;
	while (game->map.grid[0][j] && game->map.grid[i][j])
	{
		if ((game->map.grid[0][j] != '1' || game->map.grid[i][j] != '1'))
			error_game("Map is not enclosed by wall", game);
		j++;
	}
	j--;
	game->map.map_size.x = j;
	i = 0;
	while (game->map.grid[i])
	{
		if (game->map.grid[i][0] != '1' || game->map.grid[i][j] != '1')
			error_game("Map is not enclosed by wall", game);
		i++;
	}
	data_map_check(game, 1, 0);
}

void	map_check(t_game *game)
{
	int	i;

	i = 0;
	game->map.columns = (int)ft_strlen(game->map.grid[i]);
	if (!game->map.columns)
		error_game("Failed during map parse", game);
	while (game->map.grid[i])
	{
		if (ft_strlen(game->map.grid[i]) != game->map.columns)
			error_game("Map is not rectangular !", game);
		i++;
	}
	ultra_map_check(game, 0);
}

void	map_parse(char *map, t_game *game, int argc)
{
	char	*getmap;

	init_value(game);
	if (argc != 2)
		error_game("Error\nNo or too many arguments found", game);
	if (!name_check(map))
		error_game("Wrong map format or no file's name (.ber needed).", game);
	getmap = get_map(map, game);
	if (!getmap)
		error_game("Could not get map", game);
	if (each_line_check(getmap, game))
	{
		free(getmap);
		error_game("At least one line is missing", game);
	}
	game->map.grid = ft_split(getmap, '\n');
	game->map.grid_clone = ft_split(getmap, '\n');
	game->map.grid_third = ft_split(getmap, '\n');
	free(getmap);
	if (!game->map.grid || !game->map.grid_clone || !game->map.grid_third)
		error_game("Failed during split process", game);
	map_check(game);
	total_check(game);
}
