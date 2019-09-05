/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mwaterso <mwaterso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/05 19:17:40 by mwaterso     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/05 19:17:41 by mwaterso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef WOLFALGO_H
# define WOLFALGO_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include "keyboard.h"
# include <pthread.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>

# define ABS(x) (x > 0 ? x : -x)

typedef struct  s_fdot
{
   double		x;
   double		y;
   double		z;
}               t_fdot;

typedef struct  s_dot
{
   double		x;
   double		y;
   int		z;
}               t_point;

typedef struct  s_line
{
	t_point		a;
	t_point		b;
}               t_line;

typedef struct	s_wall
{
	double		zmin;
	double		zmax;
}				t_wall;

typedef struct		s_image
{
	void	*ad;
	int 	*tab;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	
}					t_image;

typedef struct		s_input
{
	void	*mlx_ad;
	void	*win_ad;
	void	*button_ad;
	int		win_h;
	int		win_w;
	int 	color;
	int 	color1;
	int 	color2;
	int 	i;
	int		zoom;
	int		mode;
	int 	(*fct)(double, double, struct	s_input *);
	t_point p1;
	t_point p2;
	t_point mouse;
	t_image im;
}					t_input;

typedef struct    s_index
{
    int            i;
    int            j;
}                t_index;

int		parse_file(t_input *data);
int		fractol(t_input *inputs);
int		clear_image(t_input *inputs);
int		var_init(t_input *inputs);
int 	mouse(int butt, int x, int y, t_input *data);
int 	keyboard(int key, t_input *inputs);
int 	keyboard2(int key, t_input *inputs);
int 	mandel(double x, double y, t_input *inputs);
int		julia(double x, double y, t_input *inputs);
int 	burningship(double x, double y, t_input *inputs);
int 	keyboard3(int key, t_input *inputs);
int 	mouse_track(int x, int y, t_input *inputs);
int 	color(int ite, t_input *inputs);
int 	colorv2(int ite, t_input *inputs);
int 	colorv3(int ite, t_input *inputs);
void 	clear_im(t_input *data);
void	print_line(t_point a, t_point b, t_input *inputs);


#endif