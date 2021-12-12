# ************************************************************************************************** #
#                                                                                                    #
#                                                         :::   ::::::::   ::::::::  :::::::::::     #
#    Makefile                                          :+:+:  :+:    :+: :+:    :+: :+:     :+:      #
#                                                       +:+         +:+        +:+        +:+        #
#    By: mamoussa <mamoussa@student.1337.ma>           +#+      +#++:      +#++:        +#+          #
#                                                     +#+         +#+        +#+      +#+            #
#    Created: Invalid date        by                 #+#  #+#    #+# #+#    #+#     #+#              #
#    Updated: 2021/08/10 17:14:13 by mamoussa     ####### ########   ########      ###.ma            #
#                                                                                                    #
# ************************************************************************************************** #

COMPILER = clang++
FLAGS = --std=c++98 -Wall -Wextra -Werror -g3
FSANITIZE = -fsanitize=address

vector:
	@$(COMPILER) $(FLAGS)	Vector_tests.cpp -o vector.out

map:
	@$(COMPILER) $(FLAGS)	Map_tests.cpp -o map.out 

stack:
	@$(COMPILER) $(FLAGS)	Stack_tests.cpp -o stack.out 

set:
	@$(COMPILER) $(FLAGS)	Set_tests.cpp -o set.out 

vector_sanitize:
	@$(COMPILER) $(FLAGS) $(FSANITIZE)	Vector_tests.cpp -o vector.out

map_sanitize:
	@$(COMPILER) $(FLAGS) $(FSANITIZE)	Map_tests.cpp -o map.out 

stack_sanitize:
	@$(COMPILER) $(FLAGS) $(FSANITIZE)	Stack_tests.cpp -o stack.out 

set_sanitize:
	@$(COMPILER) $(FLAGS) $(FSANITIZE)	Set_tests.cpp -o set.out 

clean:
	rm -rf vector.out map.out stack.out set.out vector.out.dSYM map.out.dSYM stack.out.dSYM set.out.dSYM
