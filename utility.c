/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mizukori250@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 09:00:00 by mlu               #+#    #+#             */
/*   Updated: 2017/08/25 09:00:00 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	controls(void)
{
	ft_putstr("\nControls for your viewing pleasures\n\n");
	ft_putstr("[K][E][Y][B][O][A][R][D]\n");
	ft_putstr("[ + or - ] Zoom in or out");
	ft_putstr("\n[ * or / ] Add or remove interation\n");
	ft_putstr("[ NUM PAD 0 ] Change Color\n");
	ft_putstr("[ CLEAR ] Reset fractal \n");
	ft_putstr("[ ESC ] To exit program\n");
	ft_putstr("[ Arrow Keys ] Move left, right, up or down\n");
	ft_putstr("[ J, M, L, G, T, C, A, P ] Change fractal type\n");
	ft_putstr("[ NUM PAD . ] Toggle Mouse Movement (Except Mandelbrot)\n");
	ft_putstr("\n[M][O][U][S][E]");
	ft_putstr("\n[ Mouse Wheel ] Zoom in or out");
	ft_putstr("\nClick anywhere in the window to move in that direction\n");
}

void	draw_controls(t_draw *draw)
{
	mlx_string_put(draw->mlx, draw->win, 5, 20,
		GRAY_D, "Zoom: [ + , - , Mouse Wheel ]");
	mlx_string_put(draw->mlx, draw->win, 5, 0,
		GRAY_D, "Move: [ Arrow Key, Mouse Click ]");
	mlx_string_put(draw->mlx, draw->win, 5, 40,
		GRAY_D, "Mouse Effect: [ Num Pad . ]");
	mlx_string_put(draw->mlx, draw->win, 5, 60,
		GRAY_D, "Iteration: [ * , / ]");
	mlx_string_put(draw->mlx, draw->win, 5, 100,
		GRAY_D, "Reset: [ Clear ]");
	mlx_string_put(draw->mlx, draw->win, 5, 120,
		GRAY_D, "Exit: [ ESC ]");
	mlx_string_put(draw->mlx, draw->win, 5, 80,
		GRAY_D, "Color: [ Num Pad 0 ]");
	mlx_string_put(draw->mlx, draw->win, 5, 935,
		GRAY_D, "Fractal List Change: Tulip [ T ] - Julia [ J ]");
	mlx_string_put(draw->mlx, draw->win, 5, 955,
		GRAY_D, "Mandelbrot [ M ] - Cyra [ C]] - Arta [ A ]");
	mlx_string_put(draw->mlx, draw->win, 5, 975,
		GRAY_D, "Gracia [ G ] - Lunairi [ L ] - Poppuri [ P ]");
}

int		checkname_final(char *str, t_draw *draw)
{
	if (ft_strucmp(str, "gracia"))
	{
		draw->type = 4;
		return (1);
	}
	else if (ft_strucmp(str, "tulip"))
	{
		draw->type = 5;
		return (1);
	}
	else if (ft_strucmp(str, "cyra"))
	{
		draw->type = 6;
		return (1);
	}
	else
		return (0);
}

int		checkname_again(char *str, t_draw *draw)
{
	if (ft_strucmp(str, "arta"))
	{
		draw->type = 7;
		return (1);
	}
	else if (ft_strucmp(str, "poppuri"))
	{
		draw->type = 8;
		return (1);
	}
	else if (ft_strucmp(str, "eggplant"))
	{
		eggplant_ascii(draw);
		return (1);
	}
	else if (checkname_final(str, draw))
		return (1);
	else
		return (0);
}

int		checkname(char *str, t_draw *draw)
{
	if (ft_strucmp(str, "julia"))
	{
		draw->type = 1;
		return (1);
	}
	else if (ft_strucmp(str, "mandelbrot"))
	{
		draw->type = 2;
		return (1);
	}
	else if (ft_strucmp(str, "lunairi"))
	{
		draw->type = 3;
		return (1);
	}
	else if (ft_strucmp(str, "exit"))
		exit(EXIT_SUCCESS);
	else if (checkname_again(str, draw))
		return (1);
	else
		return (0);
}
