# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youbella <youbella@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/06 22:03:53 by youbella          #+#    #+#              #
#    Updated: 2025/09/11 00:01:44 by youbella         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
FLAGS = -Wall -Wextra -Werror -Imlx -O3 -ffast-math -fsanitize=address -g

NAME = cub3D
NAME_BNS = cub3D_bonus

SRCS = mandatory/cub3d.c mandatory/handle_distroy.c mandatory/key_alph.c mandatory/rotation_key.c mandatory/update_Player.c \
		mandatory/youbella/walls.c mandatory/youbella/parse_player.c mandatory/youbella/get_next_line.c mandatory/youbella/map_data.c
SRCS_BNS = bonus/cub3d_bonus.c bonus/handle_distroy_bonus.c bonus/key_alph_bonus.c bonus/rotation_key_bonus.c bonus/update_Player_bonus.c \
		bonus/youbella/walls_bonus.c bonus/youbella/parse_player_bonus.c bonus/youbella/get_next_line_bonus.c bonus/youbella/map_data_bonus.c bonus/youbella/key_door.c bonus/youbella/draw_dragon.c

OBJS = $(SRCS:.c=.o)
OBJS_BNS = $(SRCS_BNS:.c=.o)

all: $(NAME)
bonus: $(NAME_BNS)

$(NAME): $(OBJS)
		@make -C libft
		$(CC) $(FLAGS) -framework OpenGL -framework AppKit libmlx42.a -Iinclude -lglfw -L"$(shell brew --prefix glfw)/lib" $(OBJS) libft/libft.a -o $(NAME)
$(NAME_BNS): $(OBJS_BNS)
			@make -C libft
			$(CC) $(FLAGS) -framework OpenGL -framework AppKit libmlx42.a -Iinclude -lglfw -L"$(shell brew --prefix glfw)/lib" $(OBJS_BNS) libft/libft.a -o $(NAME_BNS)

mandatory/%.o: mandatory/%.c mandatory/cub3d.h bonus/cub3d_bonus.h
	$(CC) $(FLAGS) -c $< -o $@
bonus/%.o: bonus/%.c bonus/cub3d_bonus.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@make clean -C libft
	rm -f $(OBJS) $(OBJS_BNS)

fclean: clean
		@make fclean -C libft
		rm -f $(NAME) $(NAME_BNS)

re: fclean all
		@make re -C libft

.PHONY: clean
