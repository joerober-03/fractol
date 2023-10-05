/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joerober <joerober@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:58:36 by joerober          #+#    #+#             */
/*   Updated: 2023/02/01 11:23:55 by joerober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	update(t_var *v)
{
	v->img = mlx_new_image(v->mlx, WIN_W, WIN_H);
	v->addr = mlx_get_data_addr(v->img, &v->bpp, &v->len, &v->end);
	if (v->fractal == 1)
		mandelbrot(v);
	else if (v->fractal == 2)
		julia(v);
	else if (v->fractal == 3)
		burning_ship(v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_var *v)
{
	if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
	{
		if (button == 1)
		{
			v->s = v->s +((D(MID_W + v->s) - D(x)) * (4 / v->z) / 1000);
			v->t = v->t + ((D(MID_H + v->t) - D(y)) * (4 / v->z) / 1000);
		}
		else if (button == 5)
		{
			v->s = v->s +((D(MID_W + v->s) - D(x)) * (1.35 / v->z) / 1000);
			v->t = v->t + ((D(MID_H + v->t) - D(y)) * (1.35 / v->z) / 1000);
		}
		if (button == 5)
		{
			v->z += (v->z * 0.30);
		}
		if (button == 4 || button == 2)
			v->z -= (v->z * 0.30);
		mlx_destroy_image(v->mlx, v->img);
		mlx_clear_window(v->mlx, v->win);
		update(v);
	}
	return (0);
}

int	small_keycodes(t_var *v, int r, int keycode)
{
	if (keycode == 13 && ++r > 0)
		v->j2 += 0.02;
	else if (keycode == 0 && ++r > 0)
		v->j1 += 0.02;
	else if (keycode == 1 && ++r > 0)
		v->j2 -= 0.02;
	else if (keycode == 2 && ++r > 0)
		v->j1 -= 0.02;
	else if (keycode == 8 && ++r > 0)
		shift_color(v);
	else if (keycode == 35 && ++r > 0)
		v->imax += 1;
	else if (keycode == 31 && ++r > 0 && v->imax > 0)
		v->imax -= 1;
	else if (keycode == 78 && ++r > 0)
		v->z -= (v->z * 0.30);
	else if (keycode == 71 && ++r > 0)
		reinitiate_values(v);
	else if (keycode == 69 && ++r > 0)
		v->z += (v->z * 0.30);
	else if (keycode == 12 && ++r > 0)
		v->r -= 0.1;
	else if (keycode == 14 && ++r > 0)
		v->r += 0.1;
	return (r);
}

int	big_keycodes(t_var *v, int r, int keycode)
{
	if (keycode == 123 && ++r > 0)
		v->s += 0.1 / v->z;
	else if (keycode == 124 && ++r > 0)
		v->s -= 0.1 / v->z;
	else if (keycode == 126 && ++r > 0)
		v->t += 0.1 / v->z;
	else if (keycode == 125 && ++r > 0)
		v->t -= 0.1 / v->z;
	else if (keycode == 83 && ++r > 0 && v->fractal != 1)
	{
		v->fractal = 1;
		reinitiate_values(v);
	}
	else if (keycode == 84 && ++r > 0 && v->fractal != 2)
	{
		v->fractal = 2;
		reinitiate_values(v);
	}
	else if (keycode == 85 && ++r > 0 && v->fractal != 3)
	{
		v->fractal = 3;
		reinitiate_values(v);
	}
	return (r);
}

int	keys_hook(int keycode, t_var *v)
{
	int		r;

	r = 0;
	if (keycode == 53)
	{
		mlx_destroy_image(v->mlx, v->img);
		mlx_destroy_window(v->mlx, v->win);
		free (v);
		exit(0);
	}
	else
	{
		if (keycode >= 0 && keycode <= 78)
			r = small_keycodes(v, r, keycode);
		else
			r = big_keycodes(v, r, keycode);
		{
			mlx_destroy_image(v->mlx, v->img);
			mlx_clear_window(v->mlx, v->win);
			update(v);
		}
	}
	return (0);
}
