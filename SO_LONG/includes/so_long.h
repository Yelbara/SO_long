/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-bar <yael-bar@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:49:52 by yael-bar          #+#    #+#             */
/*   Updated: 2025/02/11 16:54:16 by yael-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define IMG_WIDTH 32
# define IMG_HEIGHT 32

typedef struct s_img
{
	void	*collectibles;
	void	*exit;
	void	*wall;
	void	*floor;
	void	*player_back;
	void	*player_front;
	void	*player_left;
	void	*player_right;
}			t_img;

typedef struct data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	int		win_width;
	int		win_height;
	int		moves;
	t_img	img;

}			t_data;

typedef struct size
{
	int		x;
	int		y;
}			t_size;

typedef struct s_point
{
	int		exit;
	int		position_start;
	int		collectibles;
	int		new_c;
	int		new_e;
	int		width;
	char	**arr;
	t_size	size;
	t_size	position_s;
	t_data	data;
}			t_point;

/*----------------LIBFT--------------------------------*/
int			ft_strlen(char *s);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char *line, char *buff);
char		*ft_itoa(int n);
void		ft_putnbr(int n);
void		ft_putchar(char c);
/*------------CHEAK_IS_VALID-------------------------------------*/
void		cheak_is_mstatil(t_point *list);
void		cheak_walls(t_point *list);
void		check_is_find(t_point *list);
void		flod_fill(t_point *list, t_size size, t_size postion);
/*---------------------INITIALIZE_MAP--------------------------------*/
void		get_position_start(t_point *list);
void		stock_map(t_point *list, int fd, int line_count);
int			count_line(int fd);
void		clean_free(t_point *list, int i, char c);
void		configure_map(t_point *list, int line_count);
/*------------------MOVE---------------------------*/
void		moving_up(t_point *list);
void		moving_down(t_point *list);
void		moving_left(t_point *list);
void		moving_right(t_point *list);
void		handle_movement(t_point *list, int new_x, int new_y, char dir);
void		update_position(t_point *list, char dir);
/*--------------------READ_MAP--------------------------------------*/
void		setting_img(t_point *list);
void		read_map(t_point *list, char c);
/*--------------FREE--------------------------------*/
void		win(t_point *list);
int			ft_exit(t_point *list);
void		clean(t_point *list, int e);
/*-------------------MAIN------------------------------*/
int			key_handler(int keycode, t_point *list);
void		validate_and_initialize(char *map, t_point *list);
#endif