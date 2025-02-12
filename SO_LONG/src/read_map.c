/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-bar <yael-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 22:31:28 by yael-bar          #+#    #+#             */
/*   Updated: 2025/02/06 23:38:17 by yael-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	setting_img_player(t_point *list)
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
	list->data.img.collectibles = mlx_xpm_file_to_image(list->data.mlx_ptr,
			"textures/collectibles.xpm", &img_width, &img_height);
	if (!list->data.img.collectibles || !list->data.img.floor
		|| !list->data.img.exit || !list->data.img.wall)
	{
		write(2, "Error\nfile not found", 20);
		clean(list, 1);
	}
}

static void	read_player(t_point *list, char c, int w, int h)
{
	if (c == 'L')
		mlx_put_image_to_window(list->data.mlx_ptr, list->data.win_ptr,
			list->data.img.player_left, w, h);
	else if (c == 'R')
		mlx_put_image_to_window(list->data.mlx_ptr, list->data.win_ptr,
			list->data.img.player_right, w, h);
	else if (c == 'F')
		mlx_put_image_to_window(list->data.mlx_ptr, list->data.win_ptr,
			list->data.img.player_front, w, h);
	else if (c == 'B')
		mlx_put_image_to_window(list->data.mlx_ptr, list->data.win_ptr,
			list->data.img.player_back, w, h);
}

static void	my_read(t_point *list, char c, int y, int h)
{
	int	x;
	int	w;

	w = 0;
	x = 0;
	while (x < list->size.x)
	{
		if (list->arr[y][x] == '0')
			mlx_put_image_to_window(list->data.mlx_ptr, list->data.win_ptr,
				list->data.img.floor, w, h);
		else if (list->arr[y][x] == '1')
			mlx_put_image_to_window(list->data.mlx_ptr, list->data.win_ptr,
				list->data.img.wall, w, h);
		else if (list->arr[y][x] == 'C')
			mlx_put_image_to_window(list->data.mlx_ptr, list->data.win_ptr,
				list->data.img.collectibles, w, h);
		else if (list->arr[y][x] == 'E')
			mlx_put_image_to_window(list->data.mlx_ptr, list->data.win_ptr,
				list->data.img.exit, w, h);
		else if (list->arr[y][x] == 'P')
			read_player(list, c, w, h);
		w += IMG_WIDTH;
		x++;
	}
}

void	read_map(t_point *list, char c)
{
	int	h;
	int	y;

	y = 0;
	h = 0;
	while (y < list->size.y)
	{
		my_read(list, c, y, h);
		h += IMG_HEIGHT;
		y++;
	}
}
