# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youbella <youbella@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/06 22:03:53 by youbella          #+#    #+#              #
#    Updated: 2025/09/08 16:16:53 by youbella         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
FLAGS = -Wall -Wextra -Werror -Imlx -O3 -ffast-math -fsanitize=address -g
NAME = cub3D

SRCS = cub3d.c handle_distroy.c key_alph.c rotation_key.c update_Player.c \
		youbella/walls.c youbella/parse_player.c youbella/get_next_line.c youbella/map_data.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		@make -C libft
		$(CC) $(FLAGS) -framework OpenGL -framework AppKit libmlx42.a -Iinclude -lglfw -L"$(shell brew --prefix glfw)/lib" $(OBJS) libft/libft.a -o $(NAME)

%.o: %.c cub3d.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@make clean -C libft
	rm -f $(OBJS)

fclean: clean
		@make fclean -C libft
		rm -f $(NAME)

re: fclean all
		@make re -C libft

.PHONY: clean
