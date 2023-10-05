/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joerober <joerober@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:47:55 by joerober          #+#    #+#             */
/*   Updated: 2023/01/30 14:56:54 by joerober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "../libmlx/includes/mlx.h" 
# include "../libft/libft.h"

# define WIN_W 750
# define WIN_H 750

# define MID_W 375
# define MID_H 375

# define D (double)
# define F (float)

typedef struct s_var
{
	int			len;
	int			bpp;
	int			end;
	double		z;
	double		imax;
	void		*img;
	void		*mlx;
	void		*win;
	char		*addr;
	double		s;
	double		t;
	double		r;
	int			shift;
	int			iter;
	int			fractal;
	double		j1;
	double		j2;
	double		x;
	double		xx;
	double		y;
	double		cx;
	double		cy;
	int			hx;
	int			hy;
}				t_var;

int		mouse_hook(int button, int x, int y, t_var *v);
int		keys_hook(int keycode, t_var *v);
int		close_hook(int button, t_var *v);
int		update(t_var *v);
void	initiate_window(t_var *v);
void	reinitiate_values(t_var *v);
void	my_mlx_pixel_put(t_var *v, int x, int y, int color);
void	mandelbrot(t_var *v);
void	julia(t_var *v);
void	tricorn(t_var *v);
void	burning_ship(t_var *v);
int		color_init(t_var *v);
void	shift_color(t_var *v);
int		fractal_get(t_var *v, char *argv);
int		display_terminal(int n, t_var *v);

#endif
