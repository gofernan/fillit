# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alanter <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/11 21:05:53 by alanter           #+#    #+#              #
#    Updated: 2017/12/03 22:52:01 by alanter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCLUDE = ./
SRCS_DIR = ./
RM = /bin/rm

FILES = ft_putchar ft_putstr ft_strlen ft_strcmp \
ft_strncmp ft_strdup ft_strcpy ft_strncpy ft_strcat \
ft_strncat ft_memalloc ft_memset ft_isdigit ft_isalpha \
ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower \
ft_isspace ft_putchar_fd ft_putstr_fd ft_putnbr ft_putnbr_fd \
ft_memdel ft_bzero ft_memcpy ft_memmove ft_memccpy ft_memchr \
ft_memcmp ft_strchr ft_strrchr ft_strstr ft_atoi ft_strnew \
ft_strclr ft_strdel ft_striter ft_striteri ft_strmap ft_strequ \
ft_strnequ ft_strsub ft_strjoin ft_strmapi ft_strtrim \
ft_strsplit ft_itoa ft_putendl ft_putendl_fd ft_strlcat \
ft_strnstr ft_lstnew ft_lstdelone ft_lstdel ft_lstadd \
ft_lstiter ft_lstmap ft_islower ft_isupper ft_str_is_lowercase \
ft_str_is_uppercase ft_str_is_numeric ft_str_is_alpha \
ft_isblank ft_strtrimc ft_strndup ft_strnlen

CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

CFILES = $(patsubst %, $(SRCS_DIR)%.c, $(FILES))
OFILES = $(patsubst %, %.o, $(FILES))

all : $(NAME)

$(OFILES):
	gcc $(CFLAGS) -c -I$(INCLUDE) $(CFILES) 

$(NAME): $(OFILES)
	ar -rc $(NAME) $(OFILES)

clean:
	$(RM) -f $(OFILES)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all
