/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mizukori250@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 09:00:00 by mlu               #+#    #+#             */
/*   Updated: 2017/08/25 09:00:00 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reset_draw(t_draw *draw)
{
	if (draw->type == 3)
	{
		draw->f->real = 0.488;
		draw->f->imaginary = 0.692;
	}
	else if (draw->type == 4)
	{
		draw->f->real = 0.399;
		draw->f->imaginary = 0.092;
	}
	else if (draw->type == 7)
	{
		draw->f->real = 0.3159;
		draw->f->imaginary = -1.476;
	}
	else
	{
		draw->f->real = -0.7;
		draw->f->imaginary = 0.27015;
	}
}

void	initialize_draw(t_draw *draw)
{
	if (!(draw->mlx = mlx_init()))
	{
		ft_putstr("Instructions unclear, eggplant generated instead of map.");
		return ;
	}
	draw->win = mlx_new_window(draw->mlx, 1000, 1000, "Kill me please");
	draw->img = mlx_new_image(draw->mlx, 1000, 1000);
	draw->pix = (int*)mlx_get_data_addr(draw->img,
		&(draw->bits), &(draw->s_line), &(draw->endian));
	start_draw(draw);
}

void	initialization(t_draw *draw)
{
	draw->zoom = 1;
	if ((draw->f = (t_fractal*)ft_memalloc(sizeof(t_fractal))) == NULL)
		return ;
	draw->f->move_x = 0;
	draw->f->move_y = 0;
	draw->f->iter = 47;
	reset_draw(draw);
	draw->eggplant = 1;
	if (draw->type == 1)
		draw->motion = 1;
	else
		draw->motion = 0;
	initialize_draw(draw);
}

int		start_draw(t_draw *draw)
{
	if (draw->type == 1)
		julia(draw, 1000, 1000);
	else if (draw->type == 2)
		mandelbrot(draw, 1000, 1000);
	else if (draw->type == 3)
		lunairi(draw, 1000, 1000);
	else if (draw->type == 4)
		gracia(draw, 1000, 1000);
	else if (draw->type == 5)
		tulip(draw, 1000, 1000);
	else if (draw->type == 6)
		cyra(draw, 1000, 1000);
	else if (draw->type == 7)
		arta(draw, 1000, 1000);
	else if (draw->type == 8)
		poppuri(draw, 1000, 1000);
	return (0);
}
