/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mwaterso <mwaterso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/23 16:38:10 by mwaterso     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 06:29:53 by mwaterso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int	color(int ite, t_input *inputs)
{
	int		dr;
	int		dg;
	int		db;
	float	i;

	ite--;
	if (ite == 1)
		ite--;
	i = (float)(ite) / (float)(inputs->i);
	db = ((0xff & (inputs->color2)) - (0xff & inputs->color3));
	dg = ((0xff & (inputs->color2 >> 8)) - (0xff & (inputs->color3 >> 8)));
	dr = ((0xff & (inputs->color2 >> 16)) - (0xff & (inputs->color3 >> 16)));
	if (dr < 0)
		dr *= -1;
	if (dg < 0)
		dg *= -1;
	if (db < 0)
		db *= -1;
	return (i * dr * 65536 + i * dg * 256 + db * i + inputs->color3);
}

int	colorv2(int ite, t_input *inputs)
{
	int		dr;
	int		dg;
	int		db;
	float	i;

	ite--;
	inputs->color = inputs->color1 % 65793;
	if (ite == 1)
		ite--;
	i = (float)(ite) / (float)(inputs->i) * 256;
	return ((int)(((i * 65536) - ((int)(i * 65536))
	% 65536) + ((i * 256) - ((int)(i * 256)) % 256) + db + inputs->color));
}

int	fractol(t_input *inputs)
{
	int		i;
	t_point	zc;
	double	dx;
	double	dy;

	zc.x = inputs->p1.x;
	zc.y = inputs->p1.y;
	dx = (inputs->p2.x - inputs->p1.x) / inputs->win_w;
	dy = ((inputs->p2.y - inputs->p1.y) / inputs->win_h);
	i = 0;
	clear_image(inputs);
	while (i++ < (inputs->win_h * inputs->win_w))
	{
		if ((i != 0) && (i % inputs->win_w) == 0)
		{
			zc.y += dy;
			zc.x = inputs->p1.x;
		}
		else
			zc.x += dx;
		inputs->im.tab[i] = (inputs->fct(zc.x, zc.y, inputs));
	}
	mlx_put_image_to_window(inputs->mlx_ad, inputs->win_ad,
	inputs->im.ad, 0, 0);
	return (1);
}

int	main(int arc, char **arv)
{
	t_input inputs;

	inputs.color1 = 0;
	inputs.color2 = 0x000991;
	inputs.color3 = 0x9100f7;
	inputs.mode = 1;
	inputs.fct = &mandel;
	var_init(&inputs);
	fractol(&inputs);
	mlx_mouse_hook(inputs.win_ad, &mouse, &inputs);
	mlx_hook(inputs.win_ad, 6, 0, &mouse_track, &inputs);
	mlx_hook(inputs.win_ad, 2, 0, &keyboard, &inputs);
	mlx_loop(inputs.mlx_ad);
}
