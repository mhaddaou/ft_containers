# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaddaou <mhaddaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 08:08:04 by mhaddaou          #+#    #+#              #
#    Updated: 2023/02/06 20:25:31 by mhaddaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ft_containers
FLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address,undefined,integer
SRC = src/main.cpp  
# src/vector/vector.cpp
CC = c++
HEADER = includes/vector/ra_iterator.hpp includes/vector/vector.hpp
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
