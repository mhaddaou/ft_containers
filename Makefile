# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaddaou < mhaddaou@student.1337.ma>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 08:08:04 by mhaddaou          #+#    #+#              #
#    Updated: 2023/02/05 10:18:38 by mhaddaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = f
FLAGS = -Wall -Wextra -Werror -std=c++98 
# -g -fsanitize=address,undefined,integer
SRC = src/main.cpp src/vector/ra_iterator.cpp
CC = c++
HEADER = includes/vector/ra_iterator.hpp
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