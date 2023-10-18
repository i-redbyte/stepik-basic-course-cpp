/**
Реализуйте функцию array_size, которая возвращает размер массива, переданного в качестве параметра.
Функция должна работать только для массивов! Т. е. если функции передать указатель, должна произойти ошибка компиляции.
Примеры:

int ints[] = {1, 2, 3, 4};
int *iptr = ints;
double doubles[] = {3.14};
array_size(ints); // вернет 4
array_size(doubles); // вернет 1
array_size(iptr); // тут должна произойти ошибка компиляции

Hint: в одной из первых недель мы вам показывали трюк с передачей массивов только заданного размера в функцию
(передача массива по ссылке), совместите его с вашими знаниями о шаблонах.

 */

#include <cstddef>
#include <iostream>
template <typename T, std::size_t N>
constexpr std::size_t array_size(T (&)[N]) {
    return N;
}

int main() {
    int ints[] = {1, 2, 3, 4};
    double doubles[] = {3.14};

    // Печать размеров массивов
    std::cout << "Size of ints: " << array_size(ints) << std::endl;       // вернет 4
    std::cout << "Size of doubles: " << array_size(doubles) << std::endl; // вернет 1

    int *iptr = ints;
    // Следующая строка вызовет ошибку компиляции, как ожидается
    // std::cout << "Size of iptr: " << array_size(iptr) << std::endl;

    return 0;
}
