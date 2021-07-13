# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nikita <nikita@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 22:20:54 by caugusta          #+#    #+#              #
#    Updated: 2021/07/13 18:33:15 by nikita           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= push_swap
NAME_BONUS			= checker
LIBFT_NAME			= libft.a

CC					= gcc
CFLAGS				= -Wall -Wextra -Werror -MMD -g

OBJ_DIR				= object/
OBJ_BONUS_DIR		= obj_bonus/
SOURCE_DIR			= source/
SOURCE				= main.c  parser.c  push_swap.c  reverse_rotate.c  rotate.c  stack_utils.c  processor.c  algoritm.c  utils.c  algoritm_utils.c
BONUS_DIR			= source_bonus/
BONUS				= main.c  parser.c  push_swap.c  reverse_rotate.c  rotate.c  stack_utils.c

LIBFT				= libft/$(LIBFT_NAME)
LIBFT_DIR			= libft/

OBJ					= $(addprefix $(OBJ_DIR), $(SOURCE:.c=.o))
OBJ_BONUS			= $(addprefix $(OBJ_BONUS_DIR), $(BONUS:.c=.o))
D_FILES				= $(wildcard $(OBJ_DIR)%.d)

.PHONY : all sub_directory dir_bonus clean fclean re bonus

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
	@cp $(LIBFT_DIR)/libft.h ./$(BONUS_DIR)
	@echo LIBFT OK

include $(D_FILES)

bonus : dir_bonus $(LIBFT) $(NAME_BONUS)
	@echo COMPLETE

dir_bonus :
	@mkdir -p $(OBJ_BONUS_DIR)

$(OBJ_BONUS_DIR)%.o : $(BONUS_DIR)%.c
	@$(CC) $(CFLAGS) -c -o $@ $< -I $(BONUS_DIR)

$(NAME_BONUS) : $(OBJ_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $^ -I $(BONUS_DIR)

clean :
	@$(MAKE) clean -C $(LIBFT_DIR) --silent
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_BONUS_DIR)
	@echo CLEAN COMPLETE

fclean : clean
	@$(MAKE) fclean -C $(LIBFT_DIR) --silent
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@rm -rf includes/libft.h
	@rm -rf $(BONUS_DIR)/libft.h
	@echo FCLEAN COMPLETE

re : fclean all
