/**
Реализуйте функцию копирования элементов copy_n из массива источника типа U* в целевой массив типа T*,
где T и U произвольные типы, для которых определено преобразование из U в T. На вход функция принимает два указателя
и количество элементов, которые необходимо скопировать.

Пример вызова функции copy_n:

int ints[] = {1, 2, 3, 4};
double doubles[4] = {};
copy_n(doubles, ints, 4); // теперь в массиве doubles содержатся элементы 1.0, 2.0, 3.0 и 4.0

 */
#include <iostream>

template<typename T, typename U>
void copy_n(T* target, const U* source, std::size_t count) {
    for (std::size_t i = 0; i < count; ++i) {
        target[i] = static_cast<T>(source[i]);
    }
}

int main() {
    int ints[] = {1, 2, 3, 4};
    double doubles[4] = {};

    copy_n(doubles, ints, 4);

    // Печать элементов в массиве doubles
    for (const auto& value : doubles) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
