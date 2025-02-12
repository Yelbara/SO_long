/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-bar <yael-bar@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:01:03 by yael-bar          #+#    #+#             */
/*   Updated: 2025/02/11 11:14:24 by yael-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	git_size(long i)
{
	int	size;

	size = 0;
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i = i / 10;
		size++;
	}
	return (size);
}

static void	git_dex(long i, char **arr, int *n)
{
	if (i >= 10)
		git_dex(i / 10, arr, n);
	arr[0][(*n)] = (i % 10) + '0';
	(*n)++;
}

char	*ft_itoa(int n)
{
	int		size;
	int		i;
	long	nb;
	char	*ptr;

	size = 0;
	i = 0;
	nb = n;
	if (nb < 0)
	{
		size += 1;
		nb *= -1;
	}
	size += git_size(nb);
	ptr = malloc((size + 1));
	if (ptr == NULL)
		return (0);
	if (size > 0 && n < 0)
		ptr[i++] = '-';
	git_dex(nb, &ptr, &i);
	ptr[size] = '\0';
	return (ptr);
}
