# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 22:20:54 by caugusta          #+#    #+#              #
#    Updated: 2021/06/24 06:10:47 by caugusta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= push_swap
LIBFT_NAME			= libft.a

CC					= gcc
CFLAGS				= #-Wall -Wextra -Werror

OBJ_DIR				= object/
SOURCE_DIR			= source/
SOURCE				= push_swap.c	parser.c

LIBFT				= libft/$(LIBFT_NAME)
LIBFT_DIR			= libft/

OBJ					= $(addprefix $(OBJ_DIR), $(SOURCE:.c=.o))
D_FILES				= $(wildcard $(OBJ_DIR)*.d)

.PHONY : all sub_directory clean fclean re bonus

all : sub_directory $(NAME)
	@echo COMPLETE

sub_directory :
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SOURCE_DIR)%.c
	@$(CC) -c -MMD $(CFLAGS) -I includes $< -o $@

$(NAME) : $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $@

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

re : fclean all
