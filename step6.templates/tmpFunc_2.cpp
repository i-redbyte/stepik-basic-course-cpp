/**
Реализуйте шаблонную функцию minimum, которая находит минимальный элемент, который хранится в экземпляре шаблонного
класса Array, при этом типовой параметр шаблона Array может быть произвольным. Чтобы сравнивать объекты произвольного
типа, на вход функции также будет передаваться компаратор, в качестве компаратора может выступать функция или объект
класса с перегруженным оператором "()". Примеры вызова функции minimum:

bool less(int a, int b) { return a < b; }
struct Greater { bool operator()(int a, int b) const { return b < a; } };
Array<int> ints(3);
ints[0] = 10;
ints[1] = 2;
ints[2] = 15;
int min = minimum(ints, less); // в min должно попасть число 2
int max = minimum(ints, Greater()); // в max должно попасть число 15
 */

#include <iostream>

template<typename T>
class Array {
public:
    explicit Array(size_t size = 0, const T &value = T());

    Array(const Array &other);

    ~Array();

    Array &operator=(Array other);

    void swap(Array &other);

    size_t size() const;

    T &operator[](size_t idx);

    const T &operator[](size_t idx) const;

private:
    size_t size_;
    T *data_;
};
template <typename T>
Array<T>::Array(size_t size, const T& value) : size_(size), data_(new T[size_]) {
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = value;
    }
}

template <typename T>
Array<T>::Array(const Array& other) : size_(other.size_), data_(new T[size_]) {
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
}

template <typename T>
Array<T>::~Array() {
    delete[] data_;
}

template <typename T>
Array<T>& Array<T>::operator=(Array other) {
    swap(other);
    return *this;
}

template <typename T>
void Array<T>::swap(Array& other) {
    std::swap(size_, other.size_);
    std::swap(data_, other.data_);
}

template <typename T>
size_t Array<T>::size() const {
    return size_;
}

template <typename T>
T& Array<T>::operator[](size_t idx) {
    if (idx >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[idx];
}

template <typename T>
const T& Array<T>::operator[](size_t idx) const {
    if (idx >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[idx];
}

template<typename T, typename Compare>
T minimum(const Array<T> &arr, Compare cmp) {
    if (arr.size() == 0) {
        throw std::out_of_range("Array is empty");
    }

    T min = arr[0];

    for (size_t i = 1; i < arr.size(); ++i) {
        if (cmp(arr[i], min)) {
            min = arr[i];
        }
    }

    return min;
}

bool less(int a, int b) {
    return a < b;
}

struct Greater {
    bool operator()(int a, int b) const {
        return b < a;
    }
};

int main() {
    Array<int> ints(3);
    ints[0] = 10;
    ints[1] = 2;
    ints[2] = 15;

    int min = minimum(ints, less);
    int max = minimum(ints, Greater());

    std::cout << "Minimum: " << min << std::endl; // Output: Minimum: 2
    std::cout << "Maximum: " << max << std::endl; // Output: Maximum: 15

    return 0;
}
