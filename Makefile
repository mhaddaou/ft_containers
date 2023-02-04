# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 16:05:06 by mhaddaou          #+#    #+#              #
#    Updated: 2023/02/04 17:20:54 by mhaddaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers
FLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address,undefined,integer
SRC = src/main.cpp src/iter.cpp
CC = c++
HEADER = includes/iter.hpp
RM = rm -rf


%.o: %.cpp
	$(CC) $(FLAGS) -c -o $@ $<

OBJ = $(SRC:%.cpp=%.o)

all: ${NAME}

${NAME} : ${OBJ} ${HEADER}
	${CC} ${FLAGS} ${OBJ} -o ${NAME}  

clean:
	${RM} ${OBJ}
	
fclean: clean
	${RM} ${NAME}

re : fclean all