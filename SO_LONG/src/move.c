/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-bar <yael-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:08:00 by yael-bar          #+#    #+#             */
/*   Updated: 2025/02/06 22:18:28 by yael-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moving_up(t_point *list)
{
	int	x;
	int	y;

	get_position_start(list);
	x = list->position_s.x;
	y = list->position_s.y;
	if (y - 1 >= 0 && list->arr[y - 1][x] != '1')
		handle_movement(list, x, y - 1, 'B');
	update_position(list, 'B');
}

void	moving_down(t_point *list)
{
	int	x;
	int	y;

	get_position_start(list);
	x = list->position_s.x;
	y = list->position_s.y;
	if (y + 1 < list->size.y && list->arr[y + 1][x] != '1')
		handle_movement(list, x, y + 1, 'F');
	update_position(list, 'F');
}

void	moving_left(t_point *list)
{
	int	x;
	int	y;

	get_position_start(list);
	x = list->position_s.x;
	y = list->position_s.y;
	if (x - 1 >= 0 && list->arr[y][x - 1] != '1')
		handle_movement(list, x - 1, y, 'L');
	update_position(list, 'L');
}

void	moving_right(t_point *list)
{
	int	x;
	int	y;

	get_position_start(list);
	x = list->position_s.x;
	y = list->position_s.y;
	if (x + 1 < list->size.x && list->arr[y][x + 1] != '1')
		handle_movement(list, x + 1, y, 'R');
	update_position(list, 'R');
}
