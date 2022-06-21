#include <iostream>

/** Напишите рекурсивную функцию вычисления наибольшего общего делителя
 * двух положительных целых чисел (Greatest Common Divisor, GCD).
 * Для этого воспользуйтесь следующими свойствами:
 * 1. GCD(a, b) = GCD(b, a mod b)
 * 2. GCD(0, a) = aGCD(0,a)=a
 * 3. GCD(a, b) = GCD(b, a)
 * Требования к реализации: в данном задании запрещено пользоваться циклами.
 * Вы можете заводить любые вспомогательные функции, если они вам нужны.*/
unsigned gcd(unsigned a, unsigned b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    std::cout << gcd(8, 16) << std::endl;
    std::cout << gcd(100, 40) << std::endl;
    std::cout << gcd(0, 0) << std::endl;
    return 0;
}