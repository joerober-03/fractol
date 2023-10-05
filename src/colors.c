/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joerober <joerober@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:57:41 by joerober          #+#    #+#             */
/*   Updated: 2023/01/30 14:57:59 by joerober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	shift_color(t_var *v)
{
	v->shift++;
	if (v->shift > 3)
		v->shift = 1;
}

int	trgb_gen(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	color_init(t_var *v)
{
	double	t;
	int		color[4];

	t = (double)v->iter / (double)v->imax;
	color[0] = 0;
	if (v->shift == 1)
	{
		color[1] = (int)(9 * (1 - t) * pow(t, 3) * 255);
		color[2] = (int)(14 * pow((1 - t), 2) * pow(t, 2) * 255);
		color[3] = (int)(8.5 * pow((1 - t), 3) * t * 225);
	}
	if (v->shift == 2)
	{
		color[2] = (int)(9 * (1 - t) * pow(t, 3) * 255);
		color[1] = (int)(13 * pow((1 - t), 2) * pow(t, 2) * 255);
		color[3] = (int)(5 * pow((1 - t), 3) * t * 225);
	}
	if (v->shift == 3)
	{
		color[3] = (int)(9 * (1 - t) * pow(t, 3) * 255);
		color[2] = (int)(12 * pow((1 - t), 2) * pow(t, 2) * 255);
		color[1] = (int)(7 * pow((1 - t), 3) * t * 225);
	}
	return (trgb_gen(color[0], color[1], color[2], color[3]));
}
