# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 19:48:26 by kbahrar           #+#    #+#              #
#    Updated: 2019/12/04 04:54:10 by ybenbrai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC =  src/main.c src/tools.c
LIBF = libft/
all:$(NAME)

$(NAME):
	make -C libft/
	gcc -Wall -Wextra -Werror -g -I /usr/local/include $(SRC) -L /usr/local/lib -lmlx -L $(LIBF) -lft -framework OpenGL -framework AppKit -o $(NAME)

clean:
	make clean -C libft/

fclean: clean
	make fclean -C libft/
	rm -rf $(NAME)

re: fclean all