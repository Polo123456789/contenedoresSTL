all: test.exe

ifdef BUILD_TARGET
    TARGET=${BUILD_TARGET}
else
    TARGET=test.cpp
endif

ifdef SANITIZE_ADDRESS
    ADDRESS_SANITIZER=-fsanitize=address
else
    ADDRESS_SANITIZER=
endif

test.exe: test.cpp
	clang -std=c++17 -Wall -Werror -Wextra -I../include \
	    ${TARGET} ${ADDRESS_SANITIZER} -O2 -o test.exe 

clean:
	del test.exe test.exp test.lib test.pdb
