/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mizukori250@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 09:00:00 by mlu               #+#    #+#             */
/*   Updated: 2017/08/25 09:00:00 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>
# include <math.h>

# include "mlx.h"
# include "libft.h"

typedef struct	s_fractal
{
	double		real;
	double		imaginary;
	double		n_real;
	double		n_imag;
	double		o_real;
	double		o_imag;
	double		zoom;
	double		move_x;
	double		move_y;
	int			iter;
	int			color;
}				t_fractal;

/*
** Type 1 = Julia
** Type 2 = Mandelbrot
*/
typedef struct	s_draw
{
	char		*map;
	void		*mlx;
	void		*win;
	void		*img;
	int			*pix;
	int			bits;
	int			s_line;
	int			endian;
	int			type;
	int			motion;
	double		zoom;
	int			eggplant;
	t_fractal	*f;
}				t_draw;

typedef struct	s_vars
{
	int			x;
	int			y;
	int			w;
	int			h;
	int			i;
	int			c;
	int			end;
}				t_vars;

/*
** main.c
*/
void			displaymenu(t_draw *draw);
int				mouse_event(int button, int x, int y, t_draw *draw);
int				motion_event(int x, int y, t_draw *draw);
void			displaymenu(t_draw *draw);

/*
** fractals
*/
int				julia(t_draw *draw, int h, int w);
int				mandelbrot(t_draw *draw, int h, int w);
int				lunairi(t_draw *draw, int h, int w);
int				gracia(t_draw *draw, int h, int w);
int				tulip(t_draw *draw, int h, int w);
int				cyra(t_draw *draw, int h, int w);
int				arta(t_draw *draw, int h, int w);
int				poppuri(t_draw *draw, int h, int w);

/*
** draw.c
*/
void			draw_reload(t_draw *draw);
void			draw_color(t_draw *draw, int x, int y, int i);

/*
** utility.c
*/
int				checkname(char *str, t_draw *draw);
void			draw_controls(t_draw *draw);
void			controls(void);

/*
** initialize.c
*/
void			initialize_draw(t_draw *draw);
void			initialization(t_draw *draw);
int				start_draw(t_draw *draw);
void			reset_draw(t_draw *draw);

/*
** eggplant.c
*/
void			eggplant_ascii(t_draw *draw);
void			eggplant(t_draw *draw);

/*
** hook.c
*/
int				hook_event(int key, t_draw *draw);
void			reset(t_draw *draw);

# define RED_L 0xF08080
# define RED 0xFF0000
# define RED_D 0x8B0000
# define PINK_L 0xFFC0CB
# define PINK 0xFF69B4
# define PINK_D 0xFF1493
# define ORANGE_L 0xFF6347
# define ORANGE 0xFFA500
# define ORANGE_D 0xFF8C00
# define GOLD_L 0xFFE4B5
# define GOLD 0xFFD700
# define GOLD_D 0xBDB76B
# define PURPLE_L 0xE6E6FA
# define PURPLE 0x800080
# define PURPLE_D 0x4B0082
# define GREEN_L 0x90EE90
# define GREEN 0x008000
# define GREEN_D 0x556B2F
# define BLUE_L 0x00FFFF
# define BLUE 0x0000FF
# define BLUE_D 0x191970
# define BROWN_L 0xD2691E
# define BROWN 0xA52A2A
# define BROWN_D 0x8B4513
# define GRAY_L 0xFFFFFF
# define GRAY 0x808080
# define GRAY_D 0x000000

#endif
