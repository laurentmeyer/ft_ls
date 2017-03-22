CC = 		gcc
CFLAGS =	-Wall -Wextra -Werror

BINARY =	getopt_cmp
SRCS =		./main.c

LIBFT = 	../../..
CCLIBS = 	-L$(LIBFT) -lft

CCHEADERS = -I$(LIBFT)/libft/includes		\
			-I$(LIBFT)/ft_printf/includes

.PHONY: all clean fclean re

all : $(BINARY)

$(BINARY) :
	$(CC) $(CCHEADERS) $(CCLIBS) $(SRCS) -o $(BINARY)

clean:

fclean: clean
	rm -f $(BINARY)

re: fclean all
