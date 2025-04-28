# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 15:13:51 by ltcherep          #+#    #+#              #
#    Updated: 2025/04/28 11:54:14 by tcherepoff       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell

SRCS_EXE		=	srcs/execution/builting/builting_main.c		\
					srcs/execution/builting/echo.c				\
					srcs/libft/ft_strncmp.c						\
					srcs/libft/ft_strdup.c						\
					srcs/libft/ft_strjoin.c						\
					srcs/libft/ft_strlen.c						\
					srcs/libft/ft_atoi.c						\
					srcs/libft/ft_strchr.c						\
					srcs/execution/builting/env.c				\
					srcs/execution/builting/export.c			\
					srcs/libft/ft_strcmp.c						\
					srcs/libft/ft_strdup_equal.c				\
					srcs/execution/builting/export_cpy.c		\
					srcs/libft/ft_isalpha.c						\
					srcs/execution/builting/export_utils.c		\
					srcs/execution/builting/export_utils_2.c	\
					srcs/execution/builting/export_replace.c	\
					srcs/libft/ft_isdigit.c						\


SRCS = $(SRCS_EXE)

OBJS = $(SRCS:.c=.o)

CC = cc
FLAG = -Wall -Werror -Wextra -Iincludes -g3 -fsanitize=address
RM = @rm -f
AR = ar rcs

.c.o:
			@$(CC) $(FLAG) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			@echo Linking Objects
			@$(CC) $(FLAG) $(OBJS) -o $(NAME)
			@echo Done!

all:		$(NAME)

clean:
			@echo Cleaning Objects
			$(RM) $(OBJS)

fclean:		clean
			@echo Cleaning $(NAME)
			$(RM) $(NAME)


re:			fclean all

rebonus: fclean
