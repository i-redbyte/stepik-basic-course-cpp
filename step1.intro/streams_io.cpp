#include <iostream>

int main() {
    int i = 42;
    double d = 3.14;
    const char *s = "C-style string";
    bool b = false;
    long l = (-1 & ~(1L << 63));
    std::cout << "This is an integer " << i << "\n";
    std::cout << "This is a double " << d << "\n";
    std::cout << "This is a \"" << s << "\"\n";
    std::cout << "This is a boolean \"" << b << " " << true<< "\"\n";
    std::cout << "This is a Long \"" << l << "\"\n";
    std::cout << "This is a ~0 \"" << ~0 << "\"\n";

    std::cout << "Enter an integer and a double:\n";
    std::cin >> i >> d;
    std::cout << "Your input is " << i << ", " << d << "\n";

    return 0;
}