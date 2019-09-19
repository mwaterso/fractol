/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractales.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mwaterso <mwaterso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/11 18:05:26 by mwaterso     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/19 14:45:24 by mwaterso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int	julia(double x, double y, t_input *inputs)
{
	t_point	z;
	int		i;
	double	tmp;

	i = 0;
	z.x = x;
	z.y = y;
	while (i++ < inputs->i && (z.x * z.x + z.y * z.y) < 4)
	{
		tmp = z.x;
		z.x = z.x * z.x - z.y * z.y + inputs->mouse.x;
		z.y = 2 * tmp * z.y + inputs->mouse.y;
	}
	if (inputs->mode == 0)
		return (color(i, inputs));
	else
		return (colorv2(i, inputs));
}

int	burningship(double x, double y, t_input *inputs)
{
	t_point	z;
	int		i;
	double	tmp;

	i = 0;
	z.x = 0;
	z.y = 0;
	while (i++ < inputs->i && (z.x * z.x + z.y * z.y) < 4)
	{
		tmp = z.x;
		z.x = z.x * z.x - z.y * z.y + x;
		z.y = -2 * ABS(tmp * z.y) + y;
	}
	if (inputs->mode == 0)
		return (color(i, inputs));
	else
		return (colorv2(i, inputs));
}

int	mandel(double x, double y, t_input *inputs)
{
	t_point	z;
	int		i;
	double	tmp;

	i = 0;
	z.x = 0;
	z.y = 0;
	while (i++ < inputs->i && (z.x * z.x + z.y * z.y) < 4)
	{
		tmp = z.x;
		z.x = z.x * z.x - z.y * z.y + x;
		z.y = 2 * tmp * z.y + y;
	}
	if (inputs->mode == 0)
		return (color(i, inputs));
	else
		return (colorv2(i, inputs));
}
