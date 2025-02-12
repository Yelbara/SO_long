/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-bar <yael-bar@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:21:40 by yael-bar          #+#    #+#             */
/*   Updated: 2025/02/11 16:51:54 by yael-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_position(t_point *list, char dir)
{
	read_map(list, dir);
	list->data.moves++;
	ft_putnbr(list->data.moves);
	ft_putchar('\n');
}

static void	handle_exit_case(t_point *list, int new_x, int new_y, char dir)
{
	if (list->collectibles == 0)
		win(list);
	list->arr[list->position_s.y][list->position_s.x] = '0';
	list->position_s.x = new_x;
	list->position_s.y = new_y;
	list->arr[new_y][new_x] = 'P';
	update_position(list, dir);
}

static void	update_player_position(t_point *list, int new_x, int new_y,
		int *exit_flag)
{
	if (*exit_flag == -1)
	{
		list->arr[list->position_s.y][list->position_s.x] = 'E';
		*exit_flag = 0;
	}
	else
		list->arr[list->position_s.y][list->position_s.x] = '0';
	list->arr[new_y][new_x] = 'P';
	list->position_s.x = new_x;
	list->position_s.y = new_y;
}

void	handle_movement(t_point *list, int new_x, int new_y, char dir)
{
	static int	exit_flag = 0;

	if (list->arr[new_y][new_x] == 'C')
		list->collectibles--;
	if (list->arr[new_y][new_x] == 'E')
	{
		handle_exit_case(list, new_x, new_y, dir);
		exit_flag = -1;
		return ;
	}
	update_player_position(list, new_x, new_y, &exit_flag);
}
