# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 19:48:26 by kbahrar           #+#    #+#              #
#    Updated: 2022/11/11 18:49:20 by ybenbrai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC =  main.c 
#  mandelbrot.c tools.c 
# mandelbrotTools.c
LIBF = libft/
HEADER = fractol.h

OBJS = $(patsubst %.c, %.o, $(SRC))


all: init $(NAME)

$(NAME): $(OBJS) $(LIBF)libft.a 
	gcc -Wall -Wextra -Werror -g  -o $(NAME) -I /usr/local/include $(OBJS) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -L $(LIBF) -lft 

init:
	make -C libft all

%.o: %.c $(HEADER)
	gcc -Wall -Wextra -Werror -g -c $< -o $@ 
	
clean:
	make clean -C libft/

fclean: clean
	make fclean -C libft/
	rm -rf $(NAME)

re: fclean all