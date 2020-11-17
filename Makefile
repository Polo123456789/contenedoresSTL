all: test.exe

# ERROR_CHECKS = -Wall -Werror -fsanitize=address -Wextra

test.exe: test.cpp
	clang -std=c++17 ${ERROR_CHECKS} test.cpp -O2 -o test.exe

clean:
	del test.exe test.exp test.lib test.pdb
