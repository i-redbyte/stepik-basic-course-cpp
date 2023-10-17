/**
В предыдущей версии предполагается, что для типа T определены оператор присваивания и конструктор по умолчанию.
При создании шаблонных классов контейнеров (вроде Array и не только) разумно стараться минимизировать требования к типам
шаблонных параметров. Поэтому усложним задачу, реализуйте класс Array не полагаясь на то, что для типа T определен
оператор присваивания и конструктор по умолчанию. Конструктор копирования у типа T есть.

Hints: используйте placement new и явный вызов деструктора (смотрите урок 3.4), чтобы создавать и уничтожать объекты,
аллоцировать правильно выровненную память можно с помощью new char[N * sizeof(T)], где N - количество элементов массива.
 * */

#include <cstddef>
#include <memory>

template<typename T>
class Array {
private:
    T *data;        // Указатель на массив данных
    size_t size_;    // Размер массива

public:
    explicit Array(size_t size, const T &value = T()) : size_(size) {
        // Выделяем память с учетом выравнивания
        data = reinterpret_cast<T *>(new char[size_ * sizeof(T)]);
        for (size_t i = 0; i < size_; ++i) {
            // Используем placement new для создания объектов
            new(data + i) T(value);
        }
    }

    Array() : size_(0), data(nullptr) {}

    Array(const Array &other) : size_(other.size_) {
        // Выделяем память с учетом выравнивания
        data = reinterpret_cast<T *>(new char[size_ * sizeof(T)]);
        for (size_t i = 0; i < size_; ++i) {
            // Используем placement new для создания объектов
            new(data + i) T(other.data[i]);
        }
    }

    ~Array() {
        // Явно вызываем деструкторы объектов
        for (size_t i = 0; i < size_; ++i) {
            data[i].~T();
        }

        // Освобождаем память
        delete[] reinterpret_cast<char *>(data);
    }

    Array &operator=(const Array &other) {
        if (this != &other) {
            // Выделяем новую память с учетом выравнивания
            T *new_data = reinterpret_cast<T *>(new char[other.size_ * sizeof(T)]);

            // Явно вызываем деструкторы объектов
            for (size_t i = 0; i < size_; ++i) {
                data[i].~T();
            }

            // Копируем элементы и используем placement new
            for (size_t i = 0; i < other.size_; ++i) {
                new(new_data + i) T(other.data[i]);
            }

            // Освобождаем старую память
            delete[] reinterpret_cast<char *>(data);

            // Обновляем указатель и размер
            data = new_data;
            size_ = other.size_;
        }
        return *this;
    }

    size_t size() const {
        return size_;
    }

    T &operator[](size_t index) {
        return data[index];
    }

    const T &operator[](size_t index) const {
        return data[index];
    }
};
