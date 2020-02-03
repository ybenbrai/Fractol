# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 19:48:26 by kbahrar           #+#    #+#              #
#    Updated: 2020/02/03 17:54:59 by ybenbrai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC =  src/main.c src/tools.c src/mandelbrot.c src/core.c
LIBF = libft/

OBJS = $(patsubst %.c, %.o, $(SRC))


$(NAME): libft $(OBJS)
	gcc -Wall -Wextra -Werror -g  -o $(NAME) -I /usr/local/include $(OBJS) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -L $(LIBF) -lft 

libft:
	@make -C libft re

%.o: %.c
	gcc -Wall -Wextra -Werror -g -c $^ -o $@ 
	
clean:
	make clean -C libft/

fclean: clean
	make fclean -C libft/
	rm -rf $(NAME)

re: fclean all