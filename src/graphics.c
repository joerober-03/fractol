/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joerober <joerober@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:25:23 by joerober          #+#    #+#             */
/*   Updated: 2023/01/30 15:44:56 by joerober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_var *v)
{
	v->hy = 0;
	while (v->hy <= WIN_H)
	{
		v->hx = 0;
		while (v->hx <= WIN_W)
		{
			v->cx = (F(v->hx) / F(WIN_W) - 0.5) / v->z * 3.0 - (v->s);
			v->cy = (F(v->hy) / F(WIN_H) - 0.5) / v->z * 3.0 - (v->t);
			v->x = 0.0;
			v->y = 0.0;
			v->iter = 0;
			while (v->iter++ < v->imax && (v->x * v->x + v->y * v->y) < 4)
			{
				v->xx = v->x;
				v->x = v->x * v->x - v->y * v->y + v->cx;
				v->y = 2.0 * (v->xx * v->y) + v->cy;
			}
			my_mlx_pixel_put(v, v->hx, v->hy, color_init(v));
			v->hx++;
		}
		v->hy++;
	}
}

void	julia(t_var *v)
{
	v->hy = 0;
	while (v->hy <= WIN_H)
	{
		v->hx = 0;
		while (v->hx <= WIN_W)
		{
			v->cx = (F(v->hx) / F(WIN_W) - 0.5) / v->z * 4.5 - (v->s - 0.6);
			v->cy = (F(v->hy) / F(WIN_H) - 0.5) / v->z * 4.5 - (v->t - 0.1);
			v->x = v->cx;
			v->y = v->cy;
			v->iter = 0;
			while (v->iter++ < v->imax && (v->x * v->x + v->y * v->y) < 4)
			{
				v->xx = v->x;
				v->x = (v->x * v->x - v->y * v->y) + v->j1;
				v->y = (2.0 * v->xx * v->y) + v->j2;
			}
			my_mlx_pixel_put(v, v->hx, v->hy, color_init(v));
			v->hx++;
		}
		v->hy++;
	}
}

void	tricorn(t_var *v)
{
	v->hy = 0;
	while (v->hy <= WIN_H)
	{
		v->hx = 0;
		while (v->hx <= WIN_W)
		{
			v->cx = (F(v->hx) / F(WIN_W) - 0.5) / v->z * 5 - (v->s - 0.7);
			v->cy = (F(v->hy) / F(WIN_H) - 0.5) / v->z * 5 - (v->t - 0.2);
			v->x = 0.0;
			v->y = 0.0;
			v->iter = 0;
			while (v->iter++ < v->imax && (v->x * v->x + v->y * v->y) < 4)
			{
				v->xx = v->x;
				v->x = v->x * v->x - v->y * v->y + v->cx;
				v->y = v->r * v->xx * v->y + v->cy;
			}
			my_mlx_pixel_put(v, v->hx, v->hy, color_init(v));
			v->hx++;
		}
		v->hy++;
	}
}

void	burning_ship(t_var *v)
{
	v->hy = 0;
	while (v->hy <= WIN_H)
	{
		v->hx = 0;
		while (v->hx <= WIN_W)
		{
			v->cx = (F(v->hx) / F(WIN_W) - 0.5) / v->z * 3.5 - (v->s - 0.3);
			v->cy = (F(v->hy) / F(WIN_H) - 0.5) / v->z * 3.5 - (v->t + 0.5);
			v->x = 0.0;
			v->y = 0.0;
			v->iter = 0;
			while (v->iter++ < v->imax && (v->x * v->x + v->y * v->y) < 4)
			{
				v->xx = v->x;
				v->x = v->x * v->x - v->y * v->y + v->cx;
				v->y = 2.0 * fabs(v->xx * v->y) + v->cy;
			}
			my_mlx_pixel_put(v, v->hx, v->hy, color_init(v));
			v->hx++;
		}
		v->hy++;
	}
}

void	my_mlx_pixel_put(t_var *v, int x, int y, int color)
{
	char	*dst;

	if (x < WIN_W && y < WIN_H)
	{
		dst = v->addr + (y * v->len + x * (v->bpp / 8));
		*(unsigned int *)dst = color;
	}
}
