NAME = libftprintf.a
HEAD = ft_printf.h

CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar -rcs

FUNCTIONS = ft_printf.c printers.c
OBJECTS = $(FUNCTIONS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

%.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(BONUSES)

fclean: clean
	rm -f $(NAME)

re: fclean all