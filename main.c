/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mizukori250@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 09:00:00 by mlu               #+#    #+#             */
/*   Updated: 2017/08/25 09:00:00 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			displaymenu(t_draw *draw)
{
	char *str;

	str = ft_memalloc(sizeof(char*));
	ft_putstr("\nPlease enter of of the options below:\n\n");
	ft_putstr("[ ✔ ] Julia\n");
	ft_putstr("[ ✔ ] Mandelbrot\n");
	ft_putstr("[ ✔ ] Lunairi\n");
	ft_putstr("[ ✔ ] Gracia\n");
	ft_putstr("[ ✔ ] Tulip\n");
	ft_putstr("[ ✔ ] Cyra\n");
	ft_putstr("[ ✔ ] Arta\n");
	ft_putstr("[ ✔ ] Poppuri\n\n");
	ft_putstr("You may type exit to quit.\n\n");
	ft_putstr("-> ");
	scanf("%s", str);
	ft_putstr("\n______________________\n");
	if (!(checkname(str, draw)))
		displaymenu(draw);
}

int				mouse_event(int button, int x, int y, t_draw *draw)
{
	if (button == 1 || button == 2)
	{
		draw->f->move_x += (((double)x - 1000 / 2) / 1000 / 2)
						/ draw->zoom * 1.1;
		draw->f->move_y += (((double)y - 1000 / 2) / 1000 / 2)
						/ draw->zoom * 1.1;
	}
	if (button == 5)
	{
		draw->f->move_x += ((((double)x - 1000 / 2) / 1000 / 2)
						/ draw->zoom * 1.1) / 2;
		draw->f->move_y += ((((double)y - 1000 / 2) / 1000 / 2)
						/ draw->zoom * 1.1) / 2;
		draw->zoom *= 1.1;
	}
	else if (button == 4)
	{
		draw->f->move_x -= ((((double)x - 1000 / 2) / 1000 / 2)
						/ draw->zoom * 1.1) / 2;
		draw->f->move_y -= ((((double)y - 1000 / 2) / 1000 / 2)
						/ draw->zoom * 1.1) / 2;
		draw->zoom /= 1.1;
	}
	draw_reload(draw);
	return (0);
}

int				motion_event(int x, int y, t_draw *draw)
{
	if (x >= 0 && y >= 0 && x <= 1000 && y <= 1000
		&& draw->motion == 1)
	{
		draw->f->real = (double)x / (double)1000 * 4 - 2;
		draw->f->imaginary = (double)y / (double)1000 * 4 - 2;
		draw_reload(draw);
	}
	return (0);
}

static int		expose_event(t_draw *draw)
{
	draw_reload(draw);
	return (0);
}

int				main(int ac, char **av)
{
	t_draw *draw;

	if ((draw = ft_memalloc(sizeof(t_draw))) == NULL)
	{
		ft_putstr("Instruction unclear, eggplant stuck in blender.");
		return (0);
	}
	if (ac != 2 || (!(checkname(av[1], draw))))
		displaymenu(draw);
	initialization(draw);
	controls();
	mlx_expose_hook(draw->win, expose_event, draw);
	mlx_mouse_hook(draw->win, mouse_event, draw);
	mlx_hook(draw->win, 3, (1L << 0), hook_event, draw);
	mlx_hook(draw->win, 6, (1L << 6), motion_event, draw);
	mlx_loop(draw->mlx);
	return (0);
}
