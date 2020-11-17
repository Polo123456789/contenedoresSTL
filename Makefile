all: test.exe

test.exe: test.cpp
	clang -std=c++17 -Wall -Werror -Wextra test.cpp -O2 -o test.exe

#clang -std=c++17 test.cpp -o test.exe

clean:
	del test.exe test.exp test.lib test.pdb
