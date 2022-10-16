# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccottin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 12:16:24 by ccottin           #+#    #+#              #
#    Updated: 2022/10/16 07:31:33 by ccottin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	BureaucratsWithSpecificsForms

SRCS	=	Bureaucrat.cpp main.cpp Form.cpp ShrubberyCreationForm.cpp

CC		= c++

OBJS	= $(SRCS:.cpp=.o)

DEPS	= $(SRCS:.cpp=.d)

CFLAGS	= -Wall -Wextra -Werror -std=c++98 -g3 -MMD

all	:	$(NAME)

%.o	:	%.cpp
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $@

clean	:
		rm -rf $(OBJS)
		rm -rf $(DEPS)

fclean	:	clean
		rm -rf $(NAME)

re	:	fclean
		make

-include $(DEPS)

.PHONY	:	all fclean clean re
