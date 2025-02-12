/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_v2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-bar <yael-bar@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:36:29 by yael-bar          #+#    #+#             */
/*   Updated: 2025/02/11 13:25:15 by yael-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	len = ft_strlen((char *)s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[len] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		l;
	char	*temp;

	if (!s1 || !s2)
		return (0);
	temp = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (temp == 0)
		return (0);
	i = 0;
	l = 0;
	while (s1[i])
	{
		temp[i] = s1[i];
		i++;
	}
	while (s2[l])
	{
		temp[i] = s2[l];
		i++;
		l++;
	}
	temp[i] = '\0';
	return (free(s1), temp);
}
