/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-bar <yael-bar@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:17:20 by yael-bar          #+#    #+#             */
/*   Updated: 2025/02/11 19:02:09 by yael-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	clean_free(t_point *list, int i, char c)
{
	if (i >= 0)
	{
		while (i >= 0)
			free(list->arr[i--]);
		free(list->arr);
	}
	free(list);
	if (c == 'Y')
		write(2, "Error\n", 6);
	exit(1);
}

void	get_position_start(t_point *list)
{
	int	i;
	int	l;

	i = 0;
	while (i < list->size.y)
	{
		l = 0;
		while (l < list->size.x)
		{
			if (list->arr[i][l] == 'P')
			{
				list->position_s.x = l;
				list->position_s.y = i;
				break ;
			}
			l++;
		}
		i++;
	}
}

int	count_line(int fd)
{
	int		line_count;
	char	tmp_buf;

	line_count = 0;
	while (read(fd, &tmp_buf, 1) == 1)
	{
		if (tmp_buf == '\n')
			line_count++;
	}
	if (tmp_buf != '\n')
		line_count++;
	return (line_count);
}

void	stock_map(t_point *list, int fd, int line_count)
{
	int		i;
	char	buffer[2];
	char	*temp;

	i = 0;
	list->arr[i] = ft_strdup("");
	buffer[1] = '\0';
	while (read(fd, buffer, 1) == 1)
	{
		if (buffer[0] != '\n')
		{
			temp = ft_strjoin(list->arr[i], buffer);
			if (!temp)
				clean_free(list, i, 'N');
			list->arr[i] = temp;
		}
		else if (i < line_count - 1)
		{
			i++;
			list->arr[i] = ft_strdup("");
		}
	}
}

void	configure_map(t_point *list, int line_count)
{
	list->width = ft_strlen(list->arr[0]);
	list->size.y = line_count;
	list->size.x = list->width;
	get_position_start(list);
	list->new_c = 0;
	list->new_e = 0;
	cheak_is_mstatil(list);
	cheak_walls(list);
	check_is_find(list);
	flod_fill(list, list->size, list->position_s);
	if (list->new_c != list->collectibles || list->new_e != list->exit)
		clean_free(list, list->size.y, 'Y');
}
