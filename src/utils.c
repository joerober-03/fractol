/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joerober <joerober@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:16:23 by joerober          #+#    #+#             */
/*   Updated: 2023/01/30 15:23:45 by joerober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s2 != '\0' && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	fractal_get(t_var *v, char *argv)
{
	if (ft_strcmp(argv, "mandelbrot") == 0)
		v->fractal = 1;
	else if (ft_strcmp(argv, "julia") == 0)
		v->fractal = 2;
	else if (ft_strcmp(argv, "Mandelbrot") == 0)
		v->fractal = 1;
	else if (ft_strcmp(argv, "Julia") == 0)
		v->fractal = 2;
	else if (ft_strcmp(argv, "B_ship") == 0)
		v->fractal = 3;
	else if (ft_strcmp(argv, "b_ship") == 0)
		v->fractal = 3;
	else
	{
		ft_printf("\033[0;31m");
		ft_putstr_fd("please enter name of the desired fractal\n", 1);
		ft_printf("\033[0;32m");
		ft_putstr_fd("available fractals: mandelbrot / julia / b_ship\n", 1);
		ft_printf("\033[0;33m");
		ft_putstr_fd("example: ./fractol mandelbrot\n", 1);
		ft_printf("\033[0;37m");
		free(v);
		return (1);
	}
	return (0);
}

void	display_text(void)
{
	ft_putstr_fd("controls:\n", 1);
	ft_putstr_fd("arrows key or mouse left click to move\n", 1);
	ft_putstr_fd("wheel or + to zoom in\n", 1);
	ft_putstr_fd("wheel or - to zoom out\n", 1);
	ft_putstr_fd("P to increase recursion\n", 1);
	ft_putstr_fd("O to decrease recursion\n", 1);
	ft_putstr_fd("Clear to reset fractals\n", 1);
	ft_putstr_fd("C to change colors\n", 1);
	ft_putstr_fd("press 1 to display mandelbrot\n", 1);
	ft_putstr_fd("press 2 to display julia\n", 1);
	ft_putstr_fd("press 3 to display burning_ship\n", 1);
}

int	display_terminal(int n, t_var *v)
{
	if (n == 0)
	{
		ft_printf("\033[0;31m");
		ft_putstr_fd("please enter name of the desired fractal\n", 1);
		ft_printf("\033[0;32m");
		ft_putstr_fd("available fractals: mandelbrot / julia / b_ship\n", 1);
		ft_printf("\033[0;33m");
		ft_putstr_fd("example: ./fractol mandelbrot\n", 1);
		ft_printf("\033[0;37m");
		free(v);
		return (1);
	}
	else if (n == 1)
	{
		display_text();
		return (0);
	}
	return (0);
}

int	close_hook(int button, t_var *v)
{
	(void)button;
	(void)v;
	exit(0);
	return (0);
}
