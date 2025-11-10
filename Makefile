main:
	@rm -rf build/
	@mkdir -p build
	@g++ src/main.cpp -o build/myedit -Wall -Wextra -Wpedantic -std=c++23
