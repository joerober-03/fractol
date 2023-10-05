/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joerober <joerober@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:14:23 by joerober          #+#    #+#             */
/*   Updated: 2023/01/30 15:15:50 by joerober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initiate_values(t_var *v)
{
	v->s = 0.7;
	v->t = 0.2;
	v->z = 1.0;
	v->imax = 100.;
	v->shift = 1;
	v->j1 = -0.8;
	v->j2 = 0.18;
	v->r = -2;
}

void	reinitiate_values(t_var *v)
{
	v->s = 0.7;
	v->t = 0.2;
	v->z = 1.0;
	v->j1 = -0.8;
	v->j2 = 0.18;
	v->imax = 100.;
	v->r = -2;
}

void	initiate_window(t_var *v)
{
	display_terminal(1, v);
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, -1, -1, WIN_W, WIN_H, "fractol");
	update(v);
	mlx_hook(v->win, 17, 0, close_hook, v);
	mlx_hook(v->win, 2, 0, keys_hook, v);
	mlx_mouse_hook(v->win, mouse_hook, v);
	mlx_loop(v->mlx);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_var	*v;

	v = (t_var *)malloc(sizeof(t_var));
	if (argc != 2)
	{
		display_terminal(0, v);
		return (0);
	}
	else if (argc == 2 && fractal_get(v, argv[1]) == 0)
	{
		initiate_values(v);
		initiate_window(v);
	}
	return (0);
}
