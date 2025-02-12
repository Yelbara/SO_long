/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-bar <yael-bar@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:40:16 by yael-bar          #+#    #+#             */
/*   Updated: 2025/02/11 18:54:09 by yael-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define IMG_WIDTH 32
# define IMG_HEIGHT 32

typedef struct s_img
{
	void	*collectibles[2];
	void	*exit;
	void	*wall;
	void	*floor;
	void	*player_back;
	void	*player_front;
	void	*player_left;
	void	*player_right;
	void	*enemy;
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
	char	direction;
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

void		win(t_point *list);
int			ft_exit(t_point *list);
void		clean(t_point *list, int e);
/*----------------LIBFT--------------------------------*/
int			ft_strlen(char *s);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_itoa(int n);
/*------------CHEAK_IS_VALID-------------------------------------*/
void		cheak_is_mstatil(t_point *list);
void		cheak_walls(t_point *list);
void		check_is_find(t_point *list);
void		flod_fill(t_point *list, t_size size, t_size postion);
/*------------------------------------------------------------------*/
void		get_position_start(t_point *list);
void		stock_map(t_point *list, int fd, int line_count);
int			count_line(int fd);
void		clean_free(t_point *list, int i, char c);
void		configure_map(t_point *list, int line_count);
void		validate_and_initialize(char *map, t_point *list);
/*------------------MOVE---------------------------*/
void		moving_up(t_point *list);
void		moving_down(t_point *list);
void		moving_left(t_point *list);
void		moving_right(t_point *list);
void		update_position(t_point *list, char dir);
void		handle_movement(t_point *list, int new_x, int new_y, char dir);
/*---------------------HELPER---------------------------------------*/
void		setting_img_player(t_point *list);
void		setting_img(t_point *list);
void		read_map(t_point *list, char direction, int timer);
int			update_animation(t_point *list);
#endif