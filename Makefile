

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/22 23:12:10 by pbondoer          #+#    #+#              #
#    Updated: 2016/11/23 00:54:14 by lemon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang

NAME = fractol

FLAGS = -Wall -Wextra -Werror -O3

LIBFT = libft

DIR_S = src

DIR_O = obj

DIR_MLX = libmlx

HEADERS = include

SOURCES = 	main.c \
			graphics.c \
			hook.c \
			colors.c \
			utils.c \

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: temporary $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@make -C $(DIR_MLX)
	@$(CC) -g $(FLAGS) -L $(LIBFT) -lft -o $@ $^ -framework OpenGL -framework AppKit -L $(DIR_MLX) -lmlx

temporary:
	@mkdir -p temporary

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADERS)/$(NAME).h
	@$(CC) -g $(FLAGS) -I $(HEADERS) -c -o $@ $<

norme:
	@make norme -C $(LIBFT)
	@echo
	norminette ./$(HEADERS)
	@echo
	norminette ./$(DIR_S)

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT)
	@make clean -C $(DIR_MLX)
	@rm -rf $(/obj/)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@make fclean -C $(DIR_MLX)

re: fclean all

.PHONY: all, temporary, norme, clean, fclean, re