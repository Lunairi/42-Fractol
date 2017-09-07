/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mizukori250@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 09:00:00 by mlu               #+#    #+#             */
/*   Updated: 2017/08/25 09:00:00 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_color_three(t_draw *draw, int x, int y, int i)
{
	if ((i % 27) == 19)
		draw->pix[x + (y * draw->s_line / 4)] = BLUE;
	else if ((i % 27) == 20)
		draw->pix[x + (y * draw->s_line / 4)] = BLUE_D;
	else if ((i % 27) == 21)
		draw->pix[x + (y * draw->s_line / 4)] = BROWN_L;
	else if ((i % 27) == 22)
		draw->pix[x + (y * draw->s_line / 4)] = BROWN;
	else if ((i % 27) == 23)
		draw->pix[x + (y * draw->s_line / 4)] = BROWN_D;
	else if ((i % 27) == 24)
		draw->pix[x + (y * draw->s_line / 4)] = GRAY_L;
	else if ((i % 27) == 25)
		draw->pix[x + (y * draw->s_line / 4)] = GRAY;
	else if ((i % 27) == 26)
		draw->pix[x + (y * draw->s_line / 4)] = GRAY_D;
	else
		return ;
}

void	draw_color_two(t_draw *draw, int x, int y, int i)
{
	if ((i % 27) == 9)
		draw->pix[x + (y * draw->s_line / 4)] = GOLD_L;
	else if ((i % 27) == 10)
		draw->pix[x + (y * draw->s_line / 4)] = GOLD;
	else if ((i % 27) == 11)
		draw->pix[x + (y * draw->s_line / 4)] = GOLD_D;
	else if ((i % 27) == 12)
		draw->pix[x + (y * draw->s_line / 4)] = PURPLE_L;
	else if ((i % 27) == 13)
		draw->pix[x + (y * draw->s_line / 4)] = PURPLE;
	else if ((i % 27) == 14)
		draw->pix[x + (y * draw->s_line / 4)] = PURPLE_D;
	else if ((i % 27) == 15)
		draw->pix[x + (y * draw->s_line / 4)] = GREEN_L;
	else if ((i % 27) == 16)
		draw->pix[x + (y * draw->s_line / 4)] = GREEN;
	else if ((i % 27) == 17)
		draw->pix[x + (y * draw->s_line / 4)] = GREEN_D;
	else if ((i % 27) == 18)
		draw->pix[x + (y * draw->s_line / 4)] = BLUE_L;
	else
		draw_color_three(draw, x, y, i);
}

void	draw_color(t_draw *draw, int x, int y, int i)
{
	if ((i % 27) == 0)
		draw->pix[x + (y * draw->s_line / 4)] = RED_L;
	else if ((i % 27) == 1)
		draw->pix[x + (y * draw->s_line / 4)] = RED;
	else if ((i % 27) == 2)
		draw->pix[x + (y * draw->s_line / 4)] = RED_D;
	else if ((i % 27) == 3)
		draw->pix[x + (y * draw->s_line / 4)] = PINK_L;
	else if ((i % 27) == 4)
		draw->pix[x + (y * draw->s_line / 4)] = PINK;
	else if ((i % 27) == 5)
		draw->pix[x + (y * draw->s_line / 4)] = PINK_D;
	else if ((i % 27) == 6)
		draw->pix[x + (y * draw->s_line / 4)] = ORANGE_L;
	else if ((i % 27) == 7)
		draw->pix[x + (y * draw->s_line / 4)] = ORANGE;
	else if ((i % 27) == 8)
		draw->pix[x + (y * draw->s_line / 4)] = ORANGE_D;
	else
		draw_color_two(draw, x, y, i);
}

void	draw_reload(t_draw *draw)
{
	draw->img = mlx_new_image(draw->mlx, 1000, 1000);
	draw->pix = (int*)mlx_get_data_addr(draw->img, &(draw->bits),
		&(draw->s_line), &(draw->endian));
	start_draw(draw);
	mlx_put_image_to_window(draw->mlx, draw->win, draw->img, 0, 0);
	draw_controls(draw);
	ft_putstr("Constant R: ");
	ft_putnbr(draw->f->real * 10000000);
	ft_putstr(" - Constant I: ");
	ft_putnbr(draw->f->imaginary * 10000000);
	ft_putstr("\n");
	if (draw->eggplant % 2 == 0)
		eggplant(draw);
	mlx_destroy_image(draw->mlx, draw->img);
}
