main:
	@gcc -c src/main.c -o myedit.o -Wall -Wextra -Wpedantic -std=c23
	@gcc -c src/mode.c -o mode.o -Wall -Wextra -Wpedantic -std=c23

	@gcc myedit.o mode.o -o myedit
