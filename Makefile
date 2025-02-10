GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
END=\033[0m

NAME = libftprintf.a

SRCS = ft_printf.c \
		ft_printf_utils.c \
		ft_printf_hex.c \
		ft_printf_ptr.c

PATH_OBJS = ./objs/
OBJS = $(SRCS:%.c=$(PATH_OBJS)%.o)

PATH_INCLS = ./
INCLS = -I $(PATH_INCLS)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $@ $^
	@echo "$(GREEN)Compiled!$(END)"

$(PATH_OBJS)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLS) -c $< -o $@

clean:
	@rm -rf $(PATH_OBJS)
	@echo "$(RED)Cleaned.$(END)"

fclean: clean
	@rm -rf $(NAME) teste

re: fclean all

.PHONY: all clean fclean re
