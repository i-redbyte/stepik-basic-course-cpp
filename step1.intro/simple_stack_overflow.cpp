/**
 * Простой пример переполнения стэка
 * */
#include <iostream>

int hello() {
    std::cout << "Hello stack overflow" << std::endl;
    return -1;
}

int crack() {
    int *a[1];
    a[3] = (int *) &hello;
    return 1;
}

int main() {
    crack();
    return 0;
}