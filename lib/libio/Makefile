# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 10:36:16 by aolabarr          #+#    #+#              #
#    Updated: 2024/07/18 11:27:38 by aolabarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libio.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

AR = ar
ARFLAGS = -rc

PRINTF_DIR = ./ftprintf

PRINTF = libftprintf.a
PF_OBJ_DIR = ./ftprintf/obj
PF_OBJ = $(PF_OBJ_DIR)/*.o


all: $(NAME)

$(NAME): sublib
	$(AR) $(ARFLAGS) $(NAME) $(PF_OBJ)
	ranlib $(NAME)

sublib:
	make -C $(PRINTF_DIR)
	ranlib $(PRINTF_DIR)/$(PRINTF) 

clean:
	make clean -C $(PRINTF_DIR)

fclean: clean
	make fclean -C $(PRINTF_DIR)
	rm -f $(NAME) *.out

re: fclean all

.PHONY: all clean fclean re sublib