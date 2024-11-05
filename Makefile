LIBFT = ./libft/libft.a
NAME = libftprintf.a

SRCS =	ft_print_chr.c \
		ft_print_hex.c \
		ft_print_int.c \
		ft_print_pointer.c \
		ft_print_str.c \
		ft_print_uns.c \
 		ft_printf.c

CC = cc
FLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)

# Regra principal
all: $(NAME)

# Regra para criar a biblioteca final
$(NAME): $(OBJS)
	# Gera a libft.a primeiro
	$(MAKE) -C ./libft
	# Copia a libft.a para combinar com o ft_printf
	cp $(LIBFT) $(NAME)
	# Adiciona os objetos de ft_printf à biblioteca final
	ar -rcs $(NAME) $(OBJS)

# Limpa os arquivos objeto de ft_printf
clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

# Limpa tudo, incluindo a biblioteca final
fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

# Recompila tudo
re: fclean all

.PHONY: all clean fclean re
