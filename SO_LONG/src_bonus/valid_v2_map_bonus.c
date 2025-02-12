/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_v2_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-bar <yael-bar@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:14:55 by yael-bar          #+#    #+#             */
/*   Updated: 2025/02/11 19:03:20 by yael-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_val_char_and_cou_elem(char c, t_point *list)
{
	if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C' && c != 'M'
		&& c != '\n')
		clean_free(list, list->size.y, 'Y');
	if (c == 'P')
		list->position_start++;
	else if (c == 'E')
		list->exit++;
	else if (c == 'C')
		list->collectibles++;
}

void	check_is_find(t_point *list)
{
	int	i;
	int	j;

	i = 0;
	list->position_start = 0;
	list->exit = 0;
	list->collectibles = 0;
	while (i < list->size.y)
	{
		j = 0;
		while (j < list->size.x)
		{
			check_val_char_and_cou_elem(list->arr[i][j], list);
			j++;
		}
		i++;
	}
	if (list->collectibles == 0 || list->position_start != 1 || list->exit != 1)
		clean_free(list, list->size.y, 'Y');
}

static void	claen(int size, char **temp_map)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(temp_map[i]);
		i++;
	}
	free(temp_map);
}

static void	do_flood_fill(char **temp_map, t_point *list, t_size size,
		t_size position)
{
	if (position.y < 0 || position.y >= size.y || position.x < 0
		|| position.x >= size.x || temp_map[position.y][position.x] == '1'
		|| temp_map[position.y][position.x] == 'M')
		return ;
	if (temp_map[position.y][position.x] == 'C')
		list->new_c++;
	else if (temp_map[position.y][position.x] == 'E')
		list->new_e++;
	temp_map[position.y][position.x] = '1';
	do_flood_fill(temp_map, list, size, (t_size){position.x - 1, position.y});
	do_flood_fill(temp_map, list, size, (t_size){position.x + 1, position.y});
	do_flood_fill(temp_map, list, size, (t_size){position.x, position.y - 1});
	do_flood_fill(temp_map, list, size, (t_size){position.x, position.y + 1});
}

void	flod_fill(t_point *list, t_size size, t_size position)
{
	char	**temp_map;
	int		i;

	temp_map = malloc(sizeof(char *) * size.y);
	if (!temp_map)
		return ;
	i = 0;
	while (i < size.y)
	{
		temp_map[i] = ft_strdup(list->arr[i]);
		if (temp_map[i] == NULL)
		{
			while (i > 0)
			{
				free(temp_map[i]);
				i--;
			}
			free(temp_map);
			return ;
		}
		i++;
	}
	do_flood_fill(temp_map, list, size, position);
	claen(size.y, temp_map);
}
