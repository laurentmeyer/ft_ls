CC = 		gcc
CFLAGS =	-Wall -Wextra -Werror
BINARY =	ft_ls
SOURCEDIR =	srcs
HEADERDIR = includes

SRCFILES =	main.c				\
			directory.c			\
			display.c			\
			errors.c			\
			ft_ls.c				\
			get_options.c		\
			libgen.c			\
			sort.c				\
			t_file.c

CCHEADERS = -I./$(HEADERDIR)				\
			-I$(LIBFT)/libft/includes		\
			-I$(LIBFT)/ft_printf/includes

LIBFT = 	./libft
CCLIBS = 	-L$(LIBFT) -lft

SOURCES = 	$(SRCFILES:%.c=$(SOURCEDIR)/%.c)
OBJECTS =	$(SOURCES:$(SOURCEDIR)/%.c=$(SOURCEDIR)/%.o)

.PHONY: all clean fclean re

all : $(BINARY)

$(BINARY) : $(OBJECTS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CCHEADERS) $(CCLIBS) $(OBJECTS) -o $(BINARY)

$(SOURCEDIR)/%.o : $(SOURCEDIR)/%.c
	$(CC) $(CFLAGS) $(CCHEADERS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT) clean
	rm -f $(OBJECTS)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(BINARY)

re: fclean all

getopt : re
	$(MAKE) -C $(LIBFT)/libft/tests/getopt/ test
