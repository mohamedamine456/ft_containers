VECTOR = vector
STACK = stack
MAP = map
SET = set

CC = clang++
FLAGS = -Wall -Wextra -Werror
FSANITIZE = -fsanitize=address

all: $(VECTOR) $(STACK) $(MAP)

$(VECTOR):
	$(CC) $(FLAGS) tester/vector_tests.cpp -o $(VECTOR)

$(STACK):
	$(CC) $(FLAGS) tester/stack_tests.cpp -o $(STACK)

$(MAP):
	$(CC) $(FLAGS) tester/map_tests.cpp -o $(MAP)

$(SET):
	$(CC) $(FLAGS) tester/set_tests.cpp -o $(SET)

vector_sanitize:
	$(CC) $(FLAGS) $(FSANITIZE)	tester/vector_tests.cpp -o vector.out

map_sanitize:
	$(CC) $(FLAGS) $(FSANITIZE)	tester/map_tests.cpp -o map.out 

stack_sanitize:
	$(CC) $(FLAGS) $(FSANITIZE)	tester/stack_tests.cpp -o stack.out 

set_sanitize:
	$(CC) $(FLAGS) $(FSANITIZE)	tester/set_tests.cpp -o set.out 

clean:
	rm -f $(VECTOR) $(STACK) $(MAP)

fclean:
	rm -f $(VECTOR) $(STACK) $(MAP) $(SET)

re: fclean all

bonus: $(SET)

clean_bonus:
	rm -f $(SET)