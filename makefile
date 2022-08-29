all:
				clang main.c handle.c node.c control.c tree.c
				valgrind --leak-check=full ./a.out
