/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-bar <yael-bar@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 22:31:28 by yael-bar          #+#    #+#             */
/*   Updated: 2025/02/11 13:42:12 by yael-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_image(t_point *list, void *img, int w, int h)
{
	mlx_put_image_to_window(list->data.mlx_ptr, list->data.win_ptr, img, w, h);
}

static void	read_player(t_point *list, int w, int h)
{
	if (list->data.direction == 'L')
		put_image(list, list->data.img.player_left, w, h);
	else if (list->data.direction == 'R')
		put_image(list, list->data.img.player_right, w, h);
	else if (list->data.direction == 'F')
		put_image(list, list->data.img.player_front, w, h);
	else if (list->data.direction == 'B')
		put_image(list, list->data.img.player_back, w, h);
}

static void	draw_tile(t_point *list, char tile, int pos[2], int timer)
{
	if (tile == '0')
		put_image(list, list->data.img.floor, pos[0], pos[1]);
	else if (tile == '1')
		put_image(list, list->data.img.wall, pos[0], pos[1]);
	else if (tile == 'C')
		put_image(list, list->data.img.collectibles[timer], pos[0], pos[1]);
	else if (tile == 'E')
		put_image(list, list->data.img.exit, pos[0], pos[1]);
	else if (tile == 'M')
		put_image(list, list->data.img.enemy, pos[0], pos[1]);
	else if (tile == 'P')
		read_player(list, pos[0], pos[1]);
}

static void	draw_line(t_point *list, int y, int timer)
{
	int	x;
	int	pos[2];

	x = 0;
	pos[0] = 0;
	pos[1] = y * IMG_HEIGHT;
	while (x < list->size.x)
	{
		draw_tile(list, list->arr[y][x], pos, timer);
		pos[0] += IMG_WIDTH;
		x++;
	}
}

void	read_map(t_point *list, char direction, int timer)
{
	int	y;

	y = 0;
	list->data.direction = direction;
	while (y < list->size.y)
	{
		draw_line(list, y, timer);
		y++;
	}
}
