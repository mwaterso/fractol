/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwaterso <mwaterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:47:59 by mwaterso          #+#    #+#             */
/*   Updated: 2019/09/05 19:02:52 by mwaterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int keyboard(int key, t_input *inputs)
{
	if (key == KEY_ESCAPE)
	{
		mlx_destroy_window(inputs->mlx_ad, inputs->win_ad);
		return (0);
	}
	if (key == KEY_PAD_ENTER)
	{
		inputs->mode++;
		if (inputs->mode == 3)
			inputs->mode = 0;
		printf("%d\n", inputs->mode);
	}
	if (key == KEY_C)
	{
		inputs->color = inputs->color1;
		inputs->color1 = inputs->color2;
		inputs->color2 = inputs->color;
	}
    return(keyboard2(key, inputs));
}

int keyboard2(int key, t_input *inputs)
{
	if (key == KEY_PAD_ADD)
	{
		inputs->p1.y += ((inputs->p2.y - inputs->p1.y) / 10);
		inputs->p2.y += ((inputs->p2.y - inputs->p1.y) / 10);
	}
	if (key == KEY_PAD_SUB)
	{
		inputs->p1.y -= ((inputs->p2.y - inputs->p1.y) / 10);
		inputs->p2.y -= ((inputs->p2.y - inputs->p1.y) / 10);
	}
	if (key == 123)
	{
		inputs->p1.x += ((inputs->p2.x - inputs->p1.x) / 10);
		inputs->p2.x += ((inputs->p2.x - inputs->p1.x) / 10);
	}
    return(keyboard3(key, inputs));
}

int keyboard3(int key, t_input *inputs)
{
	if (key == 124)
	{
		inputs->p1.x -= ((inputs->p2.x - inputs->p1.x) / 10);
		inputs->p2.x -= ((inputs->p2.x - inputs->p1.x) / 10);
	}
	if (key == KEY_F)
	{
		inputs->i += 10;
		printf("%d\n", inputs->i);
	}
	if (key == KEY_D)
	{
		if (inputs->i > 10)
			inputs->i -= 10;
		printf("%d\n", inputs->i);
	}
    if (key == KEY_J)
        inputs->fct = &julia;
    if (key == KEY_M)
        inputs->fct = &mandel;
    if (key == KEY_B)
        inputs->fct = &burningship;
	fractol(inputs);
	return (1);
}

int mouse(int butt, int x, int y, t_input *data)
{
	if (butt == 4)
	{
		data->p1.y  -= ((data->p2.y - data->p1.y) / 10);
		data->p2.y  += ((data->p2.y - data->p1.y) / 10);
		data->p1.x  -= ((data->p2.x - data->p1.x) / 10);
		data->p2.x  += ((data->p2.x - data->p1.x) / 10);
	}
	if (butt == 5)
	{
		data->p1.y += ((data->p2.y - data->p1.y) / 10);
		data->p2.y -= ((data->p2.y - data->p1.y) / 10);
		data->p1.x += ((data->p2.x - data->p1.x) / 10);
		data->p2.x -= ((data->p2.x - data->p1.x) / 10);
	}
	fractol(data);
	return(1);
}

int mouse_track(int x, int y, t_input *inputs)
{
	inputs->mouse.x = (double)(x - inputs->win_w / 2)/ (inputs->win_w / 2);
	inputs->mouse.y = (double)(y - inputs->win_h / 2)/ (inputs->win_h / 2);
	fractol(inputs);
	return (1);
}
