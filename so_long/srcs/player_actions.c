/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:49:24 by msalim            #+#    #+#             */
/*   Updated: 2024/12/12 19:04:40 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

static void  get_player_position(t_map *map, t_player *player)
{
  int i;
  int j;

  i = 0;
  j = 0;
  while (i < map->height)
  {
    j = 0;
    while (j < map->width)
    {
      if (map->array[i][j] == 'P')
      {
        player->x_pos = j;
        player->y_pos = i;
        return;
      }
      j++;
    }
    i++;
  }
}

t_player	*init_player(t_map *map)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
	{
		// free resources;
		perror("error allocating memory for player");
		exit(1);
	}
  get_player_position(map,player);
  if (!player)
  {
    perror("error player init");
    return (NULL);
  }
	return (player);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player->x_pos + dx;
	new_y = game->player->y_pos + dy;
	if (game->map->array[new_y][new_x] != '1')
	{
		game->player->x_pos = new_x;
		game->player->y_pos = new_y;
		if (game->map->array[new_y][new_x] == 'C')
		{
			game->collectibles_left--;
			game->map->array[new_y][new_x] = '0';
		}
		if (game->map->array[new_y][new_x] == 'E')
		{
			if (game->collectibles_left == 0)
			{
				printf("you win !!");
				exit(0);
			}
		}
		redraw_player(game, game->mlx, game->window);
	}
}
