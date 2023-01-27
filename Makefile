# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-mekk <yel-mekk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 22:53:04 by yel-mekk          #+#    #+#              #
#    Updated: 2022/11/22 23:59:28 by yel-mekk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =so_long
NAMEB =so_long_bonus
SRC = Manditory/so_long.c Manditory/map_parser.c Manditory/map_parser2.c Manditory/map_parser3.c Manditory/map_creator.c Manditory/movments.c Manditory/movments2.c
SRCB = Bonus/so_long.c Bonus/map_parser.c Bonus/map_parser2.c Bonus/map_parser3.c Bonus/map_creator.c Bonus/movments.c Bonus/movments2.c Bonus/enemymov.c Bonus/movements3.c Bonus/enemymov2.c
flags =-Wall -Wextra -Werror
mlx =-lmlx -framework OpenGL -framework AppKit
OBJ = ${SRC:.c=.o}
OBJB = ${SRCB:.c=.o}

all : ${NAME}
%.o : %.c
	@cc ${flags} -c $< -o $@
${NAME} : ${OBJ}
	@cd ft_printf && make
	@cd libft && make
	@cc ${flags} ${mlx} ${OBJ} ft_printf/libftprintf.a libft/libft.a -o ${NAME}
	@echo "GameCreated"
bonus : ${OBJB}
	@cd ft_printf && make	
	@cd libft && make
	@cc ${flags} ${mlx} ${OBJB} ft_printf/libftprintf.a libft/libft.a -o ${NAMEB}
	@echo "BonusGameCreated"
clean :
	@cd libft && make clean
	@cd ft_printf && make clean
	@rm -rf ${OBJ} ${OBJB}
	@echo "Cleaned"
fclean : clean
	@cd libft && make fclean
	@cd ft_printf && make fclean
	@rm -rf ${NAME} ${NAMEB}
	@echo "FullyCleaned"
re : fclean ${NAME}
