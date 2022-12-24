# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrinka <hrinka@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 12:26:19 by hrinka            #+#    #+#              #
#    Updated: 2022/12/24 21:55:55 by hrinka           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
INCLUDE		=  -I include
LIBFT		= libft
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
TESTFLAGS	= -fsanitize=address -fsanitize=undefined
RM			= rm -f
AR			= ar rcs

#Sources

SRC_FILES	=	ft_printf ft_printf_utils ft_print_ptr ft_print_unsigned ft_print_hex


SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

###

OBJF		=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c| $(OBJF)
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) -rf $(OBJ_DIR)
			@make clean -C $(LIBFT)

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(LIBFT)/libft.a

re:			fclean all

test:		re
			@$(CC) $(CFLAGS) $(INCLUDE) $(TESTFLAGS)  $(LIBFT)/libft.a $(OBJ)  -o printf
			./printf

.PHONY:		all clean fclean re
