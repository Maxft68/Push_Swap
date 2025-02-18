# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 17:23:35 by mdsiurds          #+#    #+#              #
#    Updated: 2025/02/18 18:58:38 by mdsiurds         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = ft_lst.c	sa_sb_ss.c	clear_all.c main.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LIBFT_DIR = ./libft
LIBFT_LIB = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB)
		@echo "\nCompiling Push_swap..."
		@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) -o $(NAME)
		@echo "Push_swap successfully compiled."

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_LIB): 
	@echo	"Compiling libft..."
	@make -C $(LIBFT_DIR) >/dev/null 2>&1
	@echo "Libft successfully compiled."
clean:
	@echo	"Cleaning Libft and Push_swap..."
	@rm -rf $(OBJ)
	@make -C $(LIBFT_DIR) clean >/dev/null 2>&1
	@echo	"Libft and Push_swap successfully cleaned !\n"

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean >/dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re 