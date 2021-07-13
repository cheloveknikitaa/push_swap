# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nikita <nikita@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 22:20:54 by caugusta          #+#    #+#              #
#    Updated: 2021/07/13 10:03:48 by nikita           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= push_swap
LIBFT_NAME			= libft.a

CC					= gcc
CFLAGS				= -Wall -Wextra -Werror -MMD -g

OBJ_DIR				= object/
SOURCE_DIR			= source/
SOURCE				= main.c	parser.c	push_swap.c		reverse_rotate.c	rotate.c	stack_utils.c	processor.c	algoritm.c	utils.c	algoritm_utils.c

LIBFT				= libft/$(LIBFT_NAME)
LIBFT_DIR			= libft/

OBJ					= $(addprefix $(OBJ_DIR), $(SOURCE:.c=.o))
D_FILES				= $(wildcard $(OBJ_DIR)%.d)

.PHONY : all sub_directory clean fclean re bonus

all : sub_directory $(LIBFT) $(NAME)
	@echo COMPLETE

sub_directory :
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SOURCE_DIR)%.c
	@$(CC) $(CFLAGS) -c -o $@ $< -I ./includes/

$(NAME) : $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $^ -I ./includes/

$(LIBFT) :
	@$(MAKE) -C $(LIBFT_DIR) --silent
	@cp $(LIBFT_DIR)/libft.h ./includes
	@echo LIBFT OK

include $(D_FILES)

bonus : all

clean :
	@$(MAKE) clean -C $(LIBFT_DIR) --silent
	@echo CLEAN LIBFT
	@rm -rf $(OBJ_DIR)

fclean : clean
	@$(MAKE) fclean -C $(LIBFT_DIR) --silent
	@echo FCLEAN COMPLETE
	@rm -rf $(NAME)
	@rm -rf includes/libft.h
	@rm -rf includes/ft_printf.h

re : fclean all
