# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youbella <youbella@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/06 22:03:53 by youbella          #+#    #+#              #
#    Updated: 2025/10/06 16:16:19 by youbella         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

NAME = cub3D
NAME_BNS = cub3D_bonus

SRCS = mandatory/cub3d.c mandatory/handle_distroy.c mandatory/key_moves.c mandatory/rotation_key.c mandatory/update_Player.c \
		mandatory/youbella/walls.c mandatory/youbella/parse_player.c mandatory/youbella/map_data/get_next_line.c mandatory/youbella/map_data/map_data.c \
		mandatory/youbella/map_data/identifiers.c mandatory/youbella/map_data/get_colors_fc.c mandatory/youbella/map_data/identifiers2.c \
		mandatory/youbella/map_data/check_is_valid_map.c mandatory/draw_floor_sky.c mandatory/youbella/map_data/ft_identifiers_colors.c
SRCS_BNS = bonus/cub3d_bonus.c bonus/handle_distroy_bonus.c bonus/key_moves_bonus.c bonus/rotation_key_bonus.c bonus/update_Player_bonus.c \
		bonus/youbella/walls_bonus.c bonus/youbella/parse_player_bonus.c bonus/youbella/map_data_bonus/get_next_line_bonus.c \
		bonus/youbella/map_data_bonus/map_data_bonus.c bonus/youbella/key_door_bonus.c bonus/youbella/draw_dragon_bonus.c \
		bonus/youbella/draw_knife_hand_bonus.c bonus/rotation_mouse_bonus.c bonus/draw_mini_map_bonus.c bonus/check_wall_door_bonus.c \
		bonus/draw_sky_floor_for_update_bonus.c bonus/alloc_free_bonus.c bonus/youbella/map_data_bonus/identifiers_bonus.c \
		bonus/youbella/map_data_bonus/get_colors_fc_bonus.c bonus/youbella/map_data_bonus/identifiers2_bonus.c bonus/youbella/map_data_bonus/ft_identifiers_colors_bonus.c \
		bonus/youbella/map_data_bonus/check_is_valid_map_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BNS = $(SRCS_BNS:.c=.o)

all: print $(NAME)
	@printf "\n\033[1;32mGame is ready use ./cub3D [map.cub] .\n\033[0m"
bonus: print $(NAME_BNS)
	@printf "\n\033[1;32mGame is ready use ./cub3D_bonus [map.cub] .\n\033[0m"

print: 
	@printf "\033[32m                                    .──,─..─.                  \n\033[0m"
	@sleep 0.1
	@printf "\033[32m  ,────..                          ╱   ╱     '.      ,───,     \n\033[0m"
	@sleep 0.1
	@printf "\033[32m ╱   ╱   ╲                ,───,   ╱ ..╱        ;   .'  .' .╲   \n\033[0m"
	@sleep 0.1
	@printf "\033[32m│   :     :         ,──,,───.'│   ╲ ..╲  ..─    ',───.'     ╲  \n\033[0m"
	@sleep 0.1
	@printf "\033[32m.   │  ;. ╱       ,'_ ╱││   │ :    ╲___╲╱   ╲   :│   │  ..╲  │ \n\033[0m" 
	@sleep 0.1
	@printf "\033[32m.   ; ╱──.   .──. │  │ ::   : :         ╲   :   │:   : │  '  │ \n\033[0m" 
	@sleep 0.1
	@printf "\033[32m;   │ ;    ,'_ ╱│ :  . │:     │,─.      ╱  ╱   ╱ │   ' '  ;  : \n\033[0m" 
	@sleep 0.1
	@printf "\033[32m│   : │    │  ' │ │  . .│   : '  │      ╲  ╲   ╲ '   │ ;  .  │ \n\033[0m" 
	@sleep 0.1
	@printf "\033[31m.   │ '___ │  │ ' │  │ ││   │  ╱ :  ___ ╱   :   ││   │ :  │  ' \n\033[0m" 
	@sleep 0.1
	@printf "\033[31m'   ; : .'│:  │ : ;  ; │'   : │: │ ╱   ╱╲   ╱   :'   : │ ╱  ;  \n\033[0m" 
	@sleep 0.1
	@printf "\033[31m'   │ '╱  :'  :  .──'   ╲   │ '╱ :╱ ,,╱  ',─    .│   │ '. ,╱   \n\033[0m" 
	@sleep 0.1
	@printf "\033[31m│   :    ╱ :  ,      .─.╱   :    │╲ ''╲        ; ;   :  .'     \n\033[0m" 
	@sleep 0.1
	@printf "\033[31m ╲   ╲ .'   .──.────'   ╱    ╲  ╱  ╲   ╲     .'  │   ,.'       \n\033[0m" 
	@sleep 0.1
	@printf "\033[31m  .───.                 .─'────'    .──.─,,─'    '───'         \n\033[0m" 
	@printf "\n\033[36mWait for the game to install in progress...\n\033[0m"

$(NAME): $(OBJS)
		@printf "\033[34mWaiting...\n\033[0m"
		@(cd .MLX42 && cmake -B build) 2> /dev/null 1>&2
		@make -C .MLX42/build 1> /dev/null
		@printf "\033[34mWaiting...\n\033[0m"
		@make -C libft 1> /dev/null
		@printf "\033[34mWaiting...\n\033[0m"
		@make -C AllocFreeCraft 1> /dev/null
		@printf "\033[34mWaiting...\n\033[0m"
		@$(CC) $(FLAGS) -framework OpenGL -framework AppKit .MLX42/build/libmlx42.a -Iinclude -lglfw -L"$(shell brew --prefix glfw)/lib" $(OBJS) libft/libft.a AllocFreeCraft/allocfreecraft.a -o $(NAME)
$(NAME_BNS): $(OBJS_BNS)
		@printf "\033[34mWaiting...\n\033[0m"
		@(cd .MLX42 && cmake -B build) 2> /dev/null 1>&2
		@make -C .MLX42/build 1> /dev/null
		@printf "\033[34mWaiting...\n\033[0m"
		@make -C libft 1> /dev/null
		@make -C AllocFreeCraft 1> /dev/null
		@printf "\033[34mWaiting...\n\033[0m"
		@$(CC) $(FLAGS) -framework OpenGL -framework AppKit .MLX42/build/libmlx42.a -Iinclude -lglfw -L"$(shell brew --prefix glfw)/lib" $(OBJS_BNS) libft/libft.a AllocFreeCraft/allocfreecraft.a -o $(NAME_BNS)

mandatory/%.o: mandatory/%.c mandatory/cub3d.h
	@$(CC) $(FLAGS) -c $< -o $@
bonus/%.o: bonus/%.c bonus/cub3d_bonus.h
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@printf "\033[31mGame files have been deleted.\033[0m\n"
	@rm -rf .MLX42/build
	@make clean -C libft
	@make fclean -C AllocFreeCraft
	@rm -f $(OBJS) $(OBJS_BNS)

fclean: clean
		@printf "\033[31mThe game has been deleted.\033[0m\n"
		@make fclean -C libft
		@make fclean -C AllocFreeCraft
		@rm -f $(NAME) $(NAME_BNS)

re: fclean all
		@make re -C libft
		@make re -C AllocFreeCraft

.PHONY: clean
