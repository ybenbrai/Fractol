# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 19:48:26 by kbahrar           #+#    #+#              #
#    Updated: 2022/11/13 15:16:17 by ybenbrai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC =  main.c checker.c mlx.c fractols.c mandelbrot.c colors.c  keys.c
LIBF = libft/
HEADER = fractol.h

OBJS = $(SRC:.c=.o)


all: init $(NAME)

$(NAME): $(OBJS) $(LIBF)libft.a 
	gcc -Wall -Wextra -Werror -g  -o $(NAME) -I /usr/local/include $(OBJS) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -L $(LIBF) -lft 

init:
	make -C libft all

%.o: %.c $(HEADER)
	gcc -Wall -Wextra -Werror -g -c $< -o $@ 
	
clean:
	make clean -C libft/
	rm -rf $(OBJS)

fclean: clean
	make fclean -C libft/
	rm -rf $(NAME)

re: fclean all