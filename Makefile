NAME := ft_printf

SRCS := main.c ft_printf.c width_and_accuracy.c format_worker.c type_worker.c integer_worker.c base_worker.c

OBJS := $(SRCS:.c=.o)

LFT_INCL = -I libft/

LIBFT_A = libft/libft.a

CC := clang

all: $(NAME)

$(LIBFT_A):
	@make -C libft/

$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(OBJS) -L libft -lft -o $(NAME)

%.o: %.c
	$(CC) $(LFT_INCL) -c $< -o $@

clean:
	@make -C libft/ clean
	/bin/rm -rf $(OBJS)

fclean: clean
	@make -C libft/ fclean
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re
