/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mizukori250@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 09:00:00 by mlu               #+#    #+#             */
/*   Updated: 2017/08/25 09:00:00 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reset(t_draw *draw)
{
	draw->zoom = 1;
	draw->f->move_x = 0;
	draw->f->move_y = 0;
	draw->f->iter = 47;
	reset_draw(draw);
	draw->f->color = 0;
	draw->eggplant = 1;
	if (draw->type == 1)
		draw->motion = 1;
	else
		draw->motion = 0;
}

void	hook_event_final(int key, t_draw *draw)
{
	if (key == 82)
		draw->f->color += 1;
	else if (key == 65 && draw->motion == 0)
		draw->motion = 1;
	else if (key == 65 && draw->motion == 1)
		draw->motion = 0;
	else if (key == 14)
		draw->eggplant += 1;
}

void	hook_event_onemore(int key, t_draw *draw)
{
	if (key == 17)
	{
		draw->type = 5;
		reset(draw);
	}
	else if (key == 8)
	{
		draw->type = 6;
		reset(draw);
	}
	else if (key == 0)
	{
		draw->type = 7;
		reset(draw);
	}
	else if (key == 35)
	{
		draw->type = 8;
		reset(draw);
	}
	else
		hook_event_final(key, draw);
}

void	hook_event_again(int key, t_draw *draw)
{
	if (key == 71)
		reset(draw);
	else if (key == 38)
	{
		draw->type = 1;
		reset(draw);
	}
	else if (key == 46)
	{
		draw->type = 2;
		reset(draw);
	}
	else if (key == 37)
	{
		draw->type = 3;
		reset(draw);
	}
	else if (key == 5)
	{
		draw->type = 4;
		reset(draw);
	}
	else
		hook_event_onemore(key, draw);
}

int		hook_event(int key, t_draw *draw)
{
	if (key == 53)
	{
		mlx_destroy_window(draw->mlx, draw->win);
		exit(EXIT_SUCCESS);
	}
	else if (key == 69)
		draw->zoom *= 1.1;
	else if (key == 78)
		draw->zoom /= 1.1;
	else if (key == 123)
		draw->f->move_x -= 0.05;
	else if (key == 124)
		draw->f->move_x += 0.05;
	else if (key == 126)
		draw->f->move_y -= 0.05;
	else if (key == 125)
		draw->f->move_y += 0.05;
	else if (key == 67)
		draw->f->iter += 27;
	else if (key == 75 && ((draw->f->iter - 27) > 27))
		draw->f->iter -= 27;
	else
		hook_event_again(key, draw);
	draw_reload(draw);
	return (0);
}
