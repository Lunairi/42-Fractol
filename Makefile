#* ************************************************************************** */
#*                                                                            */
#*    Makefile               _             _              :::      ::::::::   */
#*    By: mlu               | |           | |           :+:      :+:    :+:   */
#*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
#*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +#+  +:+       +#+        */
#*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +#+#+#+#+#+   +#+           */
#*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        #+#    #+#             */
#*          __/ | __/ | |                             ###   ########.fr       */
#*         |___/ |___/|_|                                                     */
#* ************************************************************************** */

#* I'm bad at makefiles, but I'm good at grilling eggplants

NAME	= fractol

SRC		= main.c \
			julia.c \
			mandelbrot.c \
			hook.c \
			utility.c \
			draw.c \
			initialize.c \
			eggplant.c \
			lunairi.c \
			gracia.c \
			tulip.c \
			cyra.c \
			arta.c \
			poppuri.c

OBJ		= $(patsubst src/%.c,obj/%.o,$(SRC))
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc -Wall -Wextra -Werror -L minilibx ./libft/libft.a -lmlx -framework OpenGL -framework AppKit -I minilibx -I libft $(SRC) -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Created fractol"

obj/%.o: src/%.c
	mkdir -p obj
	gcc -Wall -Wextra -Werror -c $< -o $@
	printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

clean:
	/bin/rm -rf obj/
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Cleaned fractol"

fclean: clean
	/bin/rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fcleaned fractol"

re: fclean all

all: $(NAME)
.PHONY: clean fclean re all