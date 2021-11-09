VECTOR = vector
STACK = stack
MAP = map

VECTOR_STD = vector_std
STACK_STD = stack_std
MAP_STD = map_std


all: $(VECTOR) $(STACK) $(MAP)

$(VECTOR):
	clang++ -Wall -Wextra -Werror tests/vector_ft.cpp -o $(VECTOR)_ft.out
	clang++ -Wall -Wextra -Werror tests/vector_std.cpp -o $(VECTOR_STD).out

$(STACK):
	clang++ -Wall -Wextra -Werror tests/stack_ft.cpp  -o $(STACK)_ft.out
	clang++ -Wall -Wextra -Werror tests/stack_std.cpp -o $(STACK_STD).out

$(MAP):
	clang++ -Wall -Wextra -Werror tests/map_ft.cpp -o $(MAP)_ft.out
	clang++ -Wall -Wextra -Werror tests/map_std.cpp -o $(MAP_STD).out

clean:
	rm -f $(VECTOR) $(STACK) $(MAP)

fclean:
	rm -f $(VECTOR) $(STACK) $(MAP)

re: fclean all