CC = cc 
FLAGS = -Wall -Wextra -Werror -Imlx -Ofast
NAME = cub3D

SRCS = cub3d.c handle_distroy.c key_alph.c parse_player.c rotation_key.c update_Player.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(FLAGS) -framework OpenGL -framework AppKit libmlx42.a -Iinclude -lglfw -L"$(shell brew --prefix glfw)/lib" $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: clean
