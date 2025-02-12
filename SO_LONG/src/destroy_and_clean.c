/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_and_clean.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-bar <yael-bar@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 23:08:04 by yael-bar          #+#    #+#             */
/*   Updated: 2025/02/11 11:27:32 by yael-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_image(t_point *list)
{
	mlx_destroy_image(list->data.mlx_ptr, list->data.img.player_left);
	mlx_destroy_image(list->data.mlx_ptr, list->data.img.player_right);
	mlx_destroy_image(list->data.mlx_ptr, list->data.img.player_back);
	mlx_destroy_image(list->data.mlx_ptr, list->data.img.player_front);
	mlx_destroy_image(list->data.mlx_ptr, list->data.img.wall);
	mlx_destroy_image(list->data.mlx_ptr, list->data.img.exit);
	mlx_destroy_image(list->data.mlx_ptr, list->data.img.floor);
	mlx_destroy_image(list->data.mlx_ptr, list->data.img.collectibles);
}

void	clean(t_point *list, int e)
{
	int	i;

	destroy_image(list);
	mlx_destroy_window(list->data.mlx_ptr, list->data.win_ptr);
	mlx_destroy_display(list->data.mlx_ptr);
	free(list->data.mlx_ptr);
	i = 0;
	while (i < list->size.y)
	{
		if (list->arr[i])
			free(list->arr[i]);
		i++;
	}
	free(list->arr);
	free(list);
	exit(e);
}

void	win(t_point *list)
{
	write(1, "	......CONGRATULATIONS......	\n		You WIN", 39);
	clean(list, 0);
}

int	ft_exit(t_point *list)
{
	write(2, "	....Try again....	\n	You gave up", 32);
	clean(list, 1);
	return (1);
}
