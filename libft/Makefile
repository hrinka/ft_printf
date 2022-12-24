# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrinka <hrinka@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 17:01:44 by hrinka            #+#    #+#              #
#    Updated: 2022/12/24 20:35:10 by hrinka           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= libft.a
INCLUDES	=	../include
SRCS_DIR 	=	src/
OBJS_DIR	=	obj/
SRC_FILES			=	ft_isalnum ft_isprint ft_memcmp \
					ft_strlcat ft_strncmp ft_substr ft_isalpha \
					ft_memcpy ft_strchr  ft_strlcpy \
					ft_strnstr ft_tolower ft_bzero   ft_isascii \
					ft_memmove ft_strdup  ft_strlen  ft_strrchr \
					ft_toupper ft_calloc  ft_isdigit ft_memchr  ft_memset  \
					ft_strjoin ft_strtrim ft_atoi ft_split ft_itoa\
					ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd\
					ft_putendl_fd ft_putnbr_fd



CC				= cc
RM				= rm -f
AR				= ar rcs
CFLAGS			= -Wall -Wextra -Werror -I

SRCS 		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS 		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJSF		=	.cache_exists

all:			$(NAME)

$(NAME):	$(OBJS)
			@$(AR) $(NAME) $(OBJS)
			@ranlib $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c | $(OBJSF)
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJSF):
			@mkdir -p $(OBJS_DIR)

clean:
			@$(RM) -rf $(OBJS_DIR)
			@$(RM) -f $(OBJSF)

fclean:			clean
				$(RM) -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
