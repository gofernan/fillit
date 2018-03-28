# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alanter <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/06 17:28:03 by alanter           #+#    #+#              #
#    Updated: 2018/01/22 18:40:40 by gofernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

INCLUDE = ./fillit_dir/includes/
SRCS_DIR = ./fillit_dir/srcs/
OBJ_DIR = ./fillit_dir/
RM = /bin/rm
CFLAGS = -Wall -Wextra -Werror
LIB = -L./libft -lft

LIB_PATH = libft/libft.a

FILES = main printsq ft_ors checksq checktetri fillsq initlist initializesq filleach

CFILES = $(patsubst %, $(SRCS_DIR)%.c, $(FILES))
OFILES = $(patsubst %, $(OBJ_DIR)%.o, $(FILES))

.PHONY : all clean fclean re

all : $(NAME)

$(LIB_PATH):
	$(MAKE) -C ./libft/

$(OFILES):
	 gcc $(CFLAGS) -c -I$(INCLUDE) $(CFILES)
	 mv *.o $(OBJ_DIR)

$(NAME): $(LIB_PATH) $(OFILES)
	 gcc $(CFLAGS) -o $(NAME) $(OFILES) $(LIB)

clean :
	-rm $(OFILES)
	-rm -f ./libft/*.o

fclean : clean
	-rm $(NAME)
	-rm ./libft/*.a

re : fclean all
