CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = allocfreecraft.c

OSRC = $(SRC:.c=.o)

NAME = allocfreecraft.a

all: $(NAME)

$(NAME): $(OSRC)
	@ar -rc $(NAME) $(OSRC)

%.o: %.c allocfreecraft.h
	@$(CC) $(CFLAGS) -c $<

clean:
	@rm -f $(OSRC) $(OBNS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean 
