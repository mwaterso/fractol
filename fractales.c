/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwaterso <mwaterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:57:56 by mwaterso          #+#    #+#             */
/*   Updated: 2019/09/05 18:58:55 by mwaterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int julia(double x, double y, t_input *inputs)
{
	t_point z;
	int i;
	double tmp;

	i = 0;
	z.x = x;
	z.y = y;

	while (i++ < inputs->i && (z.x * z.x + z.y * z.y) < 4)
	{
		tmp = z.x;
		z.x = z.x * z.x - z.y * z.y + inputs->mouse.x;
		z.y = 2 * tmp * z.y + inputs->mouse.y;
		//printf("Julia \n %d", i);
	}
	if (inputs->mode == 0)
		return (color(i, inputs));
	if (inputs->mode == 1)
		return (colorv2(i, inputs));
	else
		return (colorv3(i, inputs));
}

int burningship(double x, double y, t_input *inputs)
{
	t_point z;
	int i;
	double tmp;

	i = 0;
	z.x = 0;
	z.y = 0;

	while (i++ < inputs->i && (z.x * z.x + z.y * z.y) < 4)
	{
		tmp = z.x;
		z.x = z.x * z.x - z.y * z.y + x;
		z.y = 2 * ABS(tmp * z.y) + y;
	}
	if (inputs->mode == 0)
		return (color(i, inputs));
	if (inputs->mode == 1)
		return (colorv2(i, inputs));
	else
		return (colorv3(i, inputs));
}

int mandel(double x, double y, t_input *inputs)
{
	t_point z;
	int i;
	double tmp;

	i = 0;
	z.x = 0;
	z.y = 0;

	while (i++ < inputs->i && (z.x * z.x + z.y * z.y) < 4)
	{
		tmp = z.x;
		z.x = z.x * z.x - z.y * z.y + x;
		z.y = 2 * tmp * z.y + y;
		/*if ((z.x * z.x + z.y * z.y) > 2)
		{
	//		printf("%d\n", i);
			return(0);
		}*/
	//printf("%d\n", i);
	}
	if (inputs->mode == 0)
		return (color(i, inputs));
	if (inputs->mode == 1)
		return (colorv2(i, inputs));
	else
		return (colorv3(i, inputs));
}