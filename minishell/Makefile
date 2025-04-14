# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltcherep <ltcherep@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 15:13:51 by ltcherep          #+#    #+#              #
#    Updated: 2025/04/08 15:15:59 by ltcherep         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell

SRCS_EXE		=	srcs/execution/builting/builting_main.c	\
					srcs/execution/builting/echo.c			\
					srcs/libft/ft_strncmp.c					\

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
