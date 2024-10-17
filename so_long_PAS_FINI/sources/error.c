/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:14:49 by abastian          #+#    #+#             */
/*   Updated: 2024/10/17 16:13:28 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	freegrid(char **grid)
{
	int	i;

	i = 0;
	while(grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	grid = NULL;
}

void	destroy_all(t_game *game)
{
	if (game->p != NULL)
		mlx_destroy_image(game->mlx_ptr, game->p);
	if (game->c != NULL)
		mlx_destroy_image(game->mlx_ptr, game->c);
	if (game->w != NULL)
		mlx_destroy_image(game->mlx_ptr, game->w);
	if (game->f != NULL)
		mlx_destroy_image(game->mlx_ptr, game->f);
	if (game->e != NULL)
		mlx_destroy_image(game->mlx_ptr, game->e);
}

void	error_game(char *message, t_game *game)
{
	ft_printf("Error\n%s\n", message);
	// ft_printf("%s\n", game->map.grid[0]);
	if (game->map.grid != NULL)
		freegrid(game->map.grid);
	if (game->map.grid_clone != NULL)
		freegrid(game->map.grid_clone);
	if (game->map.grid_third != NULL)
		freegrid(game->map.grid_third);
	destroy_all(game);
	//destroy -> fonction pour tout free
	exit(EXIT_FAILURE);
}

void	init_value(t_game *game)
{
	game->map.grid = NULL;
	game->map.grid_clone = NULL;
	game->map.grid_third = NULL;
	game->map.img_size.x = 32;
	game->map.img_size.y = 32;
	game->c = NULL;
	game->f = NULL;
	game->e = NULL;
	game->w = NULL;
	game->p = NULL;
}
