/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-bar <yael-bar@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:40:03 by yael-bar          #+#    #+#             */
/*   Updated: 2025/02/11 13:43:10 by yael-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	setting_img_player(t_point *list)
{
	int	img_width;
	int	img_height;

	list->data.img.player_left = mlx_xpm_file_to_image(list->data.mlx_ptr,
			"textures/player_left.xpm", &img_width, &img_height);
	list->data.img.player_right = mlx_xpm_file_to_image(list->data.mlx_ptr,
			"textures/player_right.xpm", &img_width, &img_height);
	list->data.img.player_back = mlx_xpm_file_to_image(list->data.mlx_ptr,
			"textures/player_back.xpm", &img_width, &img_height);
	list->data.img.player_front = mlx_xpm_file_to_image(list->data.mlx_ptr,
			"textures/player_front.xpm", &img_width, &img_height);
	if (!list->data.img.player_left || !list->data.img.player_right
		|| !list->data.img.player_back || !list->data.img.player_front)
	{
		write(2, "Error\nfile not found", 20);
		clean(list, 1);
	}
}

void	setting_img(t_point *list)
{
	int	img_width;
	int	img_height;

	setting_img_player(list);
	list->data.img.wall = mlx_xpm_file_to_image(list->data.mlx_ptr,
			"textures/wall.xpm", &img_width, &img_height);
	list->data.img.exit = mlx_xpm_file_to_image(list->data.mlx_ptr,
			"textures/exit.xpm", &img_width, &img_height);
	list->data.img.floor = mlx_xpm_file_to_image(list->data.mlx_ptr,
			"textures/floor.xpm", &img_width, &img_height);
	list->data.img.enemy = mlx_xpm_file_to_image(list->data.mlx_ptr,
			"textures/enemy.xpm", &img_width, &img_height);
	list->data.img.collectibles[0] = mlx_xpm_file_to_image(list->data.mlx_ptr,
			"textures/collectibles.xpm", &img_width, &img_height);
	list->data.img.collectibles[1] = mlx_xpm_file_to_image(list->data.mlx_ptr,
			"textures/collectibles_v2.xpm", &img_width, &img_height);
	if (!list->data.img.collectibles[0] || !list->data.img.collectibles[1]
		|| !list->data.img.floor || !list->data.img.exit || !list->data.img.wall
		|| !list->data.img.enemy)
	{
		write(2, "Error\nfile not found", 20);
		clean(list, 1);
	}
}
