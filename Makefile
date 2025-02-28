# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 17:23:35 by mdsiurds          #+#    #+#              #
#    Updated: 2025/02/28 10:42:25 by mdsiurds         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = ft_lst.c	sa_sb_ss.c	clear_all.c	main.c	pa_pb.c	ra_rb_rr.c	\
rra_rrb_rrr.c	control_algo.c	ft_index.c	algo_three.c algo_five.c	\
cost.c big_algo.c
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
OBJ_DIR = ./temp
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LIBFT_DIR = ./libft
LIBFT_LIB = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB)
		@echo "Compiling Push_swap..."
		@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) -o $(NAME)
		@echo "Push_swap successfully compiled.\n"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT_LIB): 
	@echo	"Compiling libft..."
	@make -C $(LIBFT_DIR) >/dev/null 2>&1
	@echo "Libft successfully compiled."
clean:
	@echo	"Cleaning..."
	@rm -rf $(OBJ)
	@make -C $(LIBFT_DIR) clean >/dev/null 2>&1
	@echo	"Successfully cleaned !\n"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean >/dev/null 2>&1
	
re: fclean all

.PHONY: all clean fclean re 