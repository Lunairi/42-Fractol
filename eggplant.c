/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eggplant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mizukori250@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 09:00:00 by mlu               #+#    #+#             */
/*   Updated: 2017/08/25 09:00:00 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	eggplant(t_draw *draw)
{
	mlx_string_put(draw->mlx, draw->win, 300, 400,
		GRAY_D, "                        _             _\n");
	mlx_string_put(draw->mlx, draw->win, 300, 420,
		GRAY_D, "                       | |           | |\n");
	mlx_string_put(draw->mlx, draw->win, 300, 440,
		GRAY_D, "  ___  __ _  __ _ _ __ | | __ _ _ __ | |\n");
	mlx_string_put(draw->mlx, draw->win, 300, 460,
		GRAY_D, " / _ \\/ _` |/ _` | '_ \\| |/ _` | '_ \\| __|\n");
	mlx_string_put(draw->mlx, draw->win, 300, 480,
		GRAY_D, "|  __/ (_| | (_| | |_) | | (_| | | | | |\n");
	mlx_string_put(draw->mlx, draw->win, 300, 500,
		GRAY_D, " \\___|\\__, |\\__, | .__/|_|\\__,_|_| |_|\\__|\n");
	mlx_string_put(draw->mlx, draw->win, 300, 520,
		GRAY_D, "       __/ | __/ | |\n");
	mlx_string_put(draw->mlx, draw->win, 300, 540,
		GRAY_D, "      |___/ |___/|_|\n\n");
}

void	eggplant_ascii(t_draw *draw)
{
	ft_putstr("                        _             _\n");
	ft_putstr("                       | |           | |\n");
	ft_putstr("  ___  __ _  __ _ _ __ | | __ _ _ __ | |\n");
	ft_putstr(" / _ \\/ _` |/ _` | '_ \\| |/ _` | '_ \\| __|\n");
	ft_putstr("|  __/ (_| | (_| | |_) | | (_| | | | | |\n");
	ft_putstr(" \\___|\\__, |\\__, | .__/|_|\\__,_|_| |_|\\__|\n");
	ft_putstr("       __/ | __/ | |\n");
	ft_putstr("      |___/ |___/|_|\n\n");
	displaymenu(draw);
}
