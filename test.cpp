#include <iostream>
#include "utility.hpp"

void g(const int&)
{
    std::cout << "const int&\n";
}

void g(int&)
{
    std::cout << "int&\n";
}

void g(int&&)
{
    std::cout << "int&&\n";
}

template <typename T>
void f(T&& a)
{
    g(psg::forward<T>(a));
}

int main()
{
    std::cout << "f(1)\n";
    f(1);
    int a = 2;
    std::cout << "f(a)\n";
    f(a);
    const int b = 3;
    std::cout << "f(const b)\n";
    f(b);
    std::cout << "f(a * b)\n";
    f(a * b);
}
