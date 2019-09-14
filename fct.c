/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fct.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mwaterso <mwaterso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/05 19:13:18 by mwaterso     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/14 16:30:52 by mwaterso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int		tall_no_min(int a, int b)
{
	int e;
	int r;

	e = a;
	r = b;
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a >= b)
		return (a);
	return (b);
}

int		clear_image(t_input *inputs)
{
	mlx_destroy_image(inputs->mlx_ad, inputs->im.ad);
	inputs->im.ad = mlx_new_image(inputs->mlx_ad, inputs->win_h, inputs->win_w);
	inputs->im.tab = (int *)mlx_get_data_addr(inputs->im.ad,
	&(inputs->im.bits_per_pixel), &(inputs->im.size_line),
	&(inputs->im.endian));
	return (1);
}

void	print_line(t_point a, t_point b, t_input *inputs)
{
	float	dx;
	float	dy;
	float	tall;
	int		i;

	i = 0;
	dx = a.x - b.x;
	dy = a.y - b.y;
	tall = tall_no_min(dx, dy);
	dx /= tall;
	dy /= tall;
	while (i++ < tall)
	{
		if ((i * dx + b.x) >= 0 && (i * dx + b.x) < inputs->win_w &&
	(i * dy + b.y) < inputs->win_h && (i * dy + b.y) >= 0)
			inputs->im.tab[((int)(i * dx + b.x) +
	(int)(i * dy + b.y) * (inputs->im.size_line / 4))] = inputs->color;
	}
}

int		var_init(t_input *inputs)
{
	inputs->win_h = 1000;
	inputs->win_w = 1000;
	inputs->zoom = 1;
	inputs->i = 50;
	inputs->p1.x = -2;
	inputs->p1.y = 2;
	inputs->p2.x = 2;
	inputs->p2.y = -2;
	inputs->block = 0;
	inputs->mlx_ad = mlx_init();
	inputs->win_ad = mlx_new_window(inputs->mlx_ad, inputs->win_h,
	inputs->win_w, "Fractol");
	inputs->im.ad = mlx_new_image(inputs->mlx_ad, inputs->win_h, inputs->win_w);
	inputs->im.tab = (int *)mlx_get_data_addr(inputs->im.ad,
	&(inputs->im.bits_per_pixel), &(inputs->im.size_line),
	&(inputs->im.endian));
	return (1);
}
