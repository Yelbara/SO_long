/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_v1_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-bar <yael-bar@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:15:31 by yael-bar          #+#    #+#             */
/*   Updated: 2025/02/11 16:27:18 by yael-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cheak_is_mstatil(t_point *list)
{
	int	i;

	i = 0;
	while (i < list->size.y)
	{
		if (list->width != (ft_strlen(list->arr[i])))
			clean_free(list, list->size.y, 'Y');
		i++;
	}
}

void	cheak_walls(t_point *list)
{
	int	i;

	i = 0;
	while (i < list->size.x)
	{
		if ((list->arr[0][i] != '1') || (list->arr[list->size.y - 1][i] != '1'))
			clean_free(list, list->size.y, 'Y');
		i++;
	}
	i = 0;
	while (i < list->size.y)
	{
		if ((list->arr[i][0] != '1') || (list->arr[i][list->size.x - 1] != '1'))
			clean_free(list, list->size.y, 'Y');
		i++;
	}
}
