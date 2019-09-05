/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwaterso <mwaterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 16:38:10 by mwaterso          #+#    #+#             */
/*   Updated: 2019/09/05 18:59:33 by mwaterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

int color(int ite, t_input *inputs)
{
	int dr;
	int dg;
	int db;
	float i;

	ite--;
	if (ite == 1)
		ite--;
	i = (float)(ite) / (float)(inputs->i);
//	printf("%f		%d		%d\n", i, ite, inputs->i);
	//ite = ite % 250;
	//printf("%f\n", i);

	db = ((0xff & (inputs->color1)) - (0xff & inputs->color2));// / inputs->i;
	dg = ((0xff & (inputs->color1 >> 8)) - (0xff & (inputs->color2 >> 8))); // inputs->i;
	dr = ((0xff & (inputs->color1 >> 16)) - (0xff & (inputs->color2 >> 16))); // inputs->i;
	if (dr < 0)
		dr *= -1;
	if (dg < 0)
		dg *= -1;
	if (db < 0)
		db *= -1;
	//i = 0.04;
	//printf("%d\n", i * dr * 65536 + i * dg * 256 + db * i + inputs->color2);
	return (i * dr * 65536 + i * dg * 256 + db * i + inputs->color2);
}

int colorv2(int ite, t_input *inputs)
{
	int dr;
	int dg;
	int db;
	float i;

	ite--;
	inputs->color = inputs->color1 % 65793;

	if (ite == 1)
		ite--;
	i = (float)(ite) / (float)(inputs->i) * 256;
	//printf("colorv2   %d		%d\n", (int)(((i * 65536) - ((int)(i * 65536)) % 65536) + ((i * 256) - ((int)(i * 256)) % 256) + db + inputs->color), ite);
	return ((int)(((i * 65536) - ((int)(i * 65536)) % 65536) + ((i * 256) - ((int)(i * 256)) % 256) + db + inputs->color));
}

int colorv3(int ite, t_input *inputs)
{
	int dr;
	int dg;
	int db;
	int r;
	float i;

	ite--;
	if (ite == 1)
		ite--;
	i = (float)(ite) / (float)(inputs->i);

	db = ((0xff & (inputs->color1)) - (0xff & inputs->color2));// / inputs->i;
	dg = ((0xff & (inputs->color1 >> 8)) - (0xff & (inputs->color2 >> 8))); // inputs->i;
	dr = ((0xff & (inputs->color1 >> 16)) - (0xff & (inputs->color2 >> 16))); // inputs->i;
	if (dr < 0)
		dr *= -1;
	if (dg < 0)
		dg *= -1;
	if (db < 0)
		db *= -1;
	if (dg > db)
	{
		if (dg > dr)
			r = (i * dg * 256) - ((int)(i * dg * 256) % 256);
		else
			r = (i * dr * 65536) - ((int)(i * dr * 65536) % 65536);
	}
	else
	{
		if (db > dr)
			r = (i * db);
		else
			r = (i * dr * 65536) - ((int)(i * dr * 65536) % 65536);
	}
	//printf("colorv3   %d\n", r + inputs->color2);
	return (r + inputs->color2);
}


int fractol(t_input *inputs)
{
	int i;
	t_point zc;
	double dx;
	double dy;

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
		//printf("%d	 %d\n", zc.x, zc.y);
		inputs->im.tab[i] = (inputs->fct(zc.x, zc.y, inputs));
	}
	mlx_put_image_to_window(inputs->mlx_ad, inputs->win_ad, inputs->im.ad, 0, 0);
	return (1);
}

int main(int arc, char **arv)
{
	t_input inputs;
	//inputs.color1 = 0;
	//inputs.color2 = 0x21fd2b;

//	inputs.color1 = 0xff0991;
//	inputs.color2 = 0x000991;

	inputs.color1 = 0xca6300;
	inputs.color1 = 0xca63fe;
	inputs.mode = 1;
	inputs.fct = &burningship;
	// inputs.fct = &mandel;
	var_init(&inputs);
	fractol(&inputs);
	mlx_mouse_hook(inputs.win_ad, &mouse, &inputs);
	mlx_hook(inputs.win_ad, 6, 0, &mouse_track, &inputs);
	mlx_hook(inputs.win_ad, 2, 0, &keyboard, &inputs);
	mlx_loop(inputs.mlx_ad);
}