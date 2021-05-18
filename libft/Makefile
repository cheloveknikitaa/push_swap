# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 18:32:18 by caugusta          #+#    #+#              #
#    Updated: 2021/05/12 19:20:00 by caugusta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRC =		ft_atoi.c		ft_isalpha.c		ft_itoa.c\
			ft_memcpy.c		ft_putendl_fd.c		ft_strdup.c\
			ft_strmapi.c	ft_tolower.c		ft_bzero.c\
			ft_isascii.c	ft_memccpy.c		ft_memmove.c\
			ft_putnbr_fd.c	ft_strlcat.c		ft_strncmp.c\
			ft_toupper.c	ft_calloc.c			ft_isdigit.c\
			ft_memchr.c		ft_memset.c			ft_putstr_fd.c\
			ft_strlcpy.c	ft_strnstr.c		ft_isalnum.c\
			ft_isprint.c	ft_memcmp.c			ft_putchar_fd.c\
			ft_strchr.c		ft_strlen.c			ft_strrchr.c\
			ft_substr.c		ft_strjoin.c		get_next_line.c\
			ft_split.c		ft_strtrim.c\
			ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c\
			ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c\
			ft_lstclear.c	ft_lstiter.c		ft_lstmap.c\

OBJ_DIR		= object/
OBJ			= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
D_FILES		= $(wildcard $(OBJ_DIR)*.d)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.PHONY : 	all sub_directory clean fclean re bonus

all : sub_directory $(NAME)

sub_directory :
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : %.c $(HEADER)
	$(CC) -c -MMD $(FLAGS) $< -o $@

$(NAME) : $(OBJ)
	ar rcs $(NAME) $?

bonus : all

clean :
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
