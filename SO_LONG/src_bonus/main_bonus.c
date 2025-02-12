/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-bar <yael-bar@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 23:12:34 by yael-bar          #+#    #+#             */
/*   Updated: 2025/02/11 13:42:40 by yael-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_handler(int keycode, t_point *list)
{
	if (keycode == XK_Escape)
		ft_exit(list);
	else if (keycode == XK_w || keycode == XK_Up)
		moving_up(list);
	else if (keycode == XK_s || keycode == XK_Down)
		moving_down(list);
	else if (keycode == XK_a || keycode == XK_Left)
		moving_left(list);
	else if (keycode == XK_d || keycode == XK_Right)
		moving_right(list);
	return (0);
}

void	validate_and_initialize(char *map, t_point *list)
{
	int	line_count;
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		clean_free(list, -1, 'N');
	line_count = count_line(fd);
	close(fd);
	list->arr = (char **)malloc(sizeof(char *) * (line_count + 1));
	if (!list->arr)
		clean_free(list, -1, 'N');
	list->arr[line_count] = NULL;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		clean_free(list, 0, 'N');
	stock_map(list, fd, line_count);
	close(fd);
	configure_map(list, line_count);
}

int	main(int ac, char *av[])
{
	t_point	*list;

	list = malloc(sizeof(t_point));
	if (!list)
		return (1);
	if (ac != 2)
		return (1);
	validate_and_initialize(av[1], list);
	list->data.mlx_ptr = mlx_init();
	if (list->data.mlx_ptr == NULL)
		return (1);
	list->data.win_width = list->size.x * IMG_WIDTH;
	list->data.win_height = list->size.y * IMG_HEIGHT;
	list->data.win_ptr = mlx_new_window(list->data.mlx_ptr,
			list->data.win_width, list->data.win_height, "SO_LONG");
	if (list->data.win_ptr == NULL)
		clean(list, 1);
	setting_img(list);
	list->data.moves = 0;
	mlx_key_hook(list->data.win_ptr, key_handler, list);
	mlx_hook(list->data.win_ptr, 17, 0, ft_exit, list);
	read_map(list, 'F', 0);
	mlx_loop_hook(list->data.mlx_ptr, update_animation, list);
	mlx_loop(list->data.mlx_ptr);
	return (0);
}
