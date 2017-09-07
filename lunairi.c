/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunairi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mizukori250@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 09:00:00 by mlu               #+#    #+#             */
/*   Updated: 2017/08/25 09:00:00 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	lunairi_set(t_draw *draw)
{
	draw->f->o_real = draw->f->n_real;
	draw->f->o_imag = draw->f->n_imag;
	draw->f->n_real = draw->f->o_real * draw->f->o_real
		- draw->f->o_imag * draw->f->o_imag + draw->f->real;
	draw->f->n_imag = draw->f->o_real * draw->f->o_imag
		+ draw->f->imaginary;
}

void	lunairi_init(t_draw *draw, t_vars v, int h, int w)
{
	draw->f->n_real = 0.5 * (v.x - w)
		/ (0.15 * draw->zoom * w) + (draw->f->move_x + 1.7);
	draw->f->n_imag = 0.5 * (v.y - h)
		/ (0.15 * draw->zoom * h) + (draw->f->move_y + 1.7);
}

int		lunairi(t_draw *draw, int h, int w)
{
	t_vars v;

	while (v.end != 1)
	{
		v.y = -1;
		while (++v.y < h)
		{
			v.x = -1;
			while (++v.x < w)
			{
				lunairi_init(draw, v, h, w);
				v.i = -1;
				while (++v.i < draw->f->iter)
				{
					lunairi_set(draw);
					if ((draw->f->n_real * draw->f->n_real
						+ draw->f->n_imag * draw->f->n_imag) > 4)
						break ;
				}
				draw_color(draw, v.x, v.y, (v.i + draw->f->color));
			}
		}
		v.end = 1;
	}
	return (0);
}
