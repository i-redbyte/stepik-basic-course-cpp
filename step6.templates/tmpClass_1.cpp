#include <cstddef>
/**
 Реализуйте шаблонную версию класса Array. Список всех операций, которые должен поддерживать класс Array, приведен в шаблоне кода.
#include <cstddef>

template <typename T>
class Array
{
    // Список операций:
    //
    // explicit Array(size_t size = 0, const T& value = T())
    //   конструктор класса, который создает
    //   Array размера size, заполненный значениями
    //   value типа T. Считайте что у типа T есть
    //   конструктор, который можно вызвать без
    //   без параметров, либо он ему не нужен.
    //
    // Array(const Array &)
    //   конструктор копирования, который создает
    //   копию параметра. Считайте, что для типа
    //   T определен оператор присваивания.
    //
    // ~Array()
    //   деструктор, если он вам необходим.
    //
    // Array& operator=(...)
    //   оператор присваивания.
    //
    // size_t size() const
    //   возвращает размер массива (количество
    //                              элементов).
    //
    // T& operator[](size_t)
    // const T& operator[](size_t) const
    //   две версии оператора доступа по индексу.
};
 *
 * */
template<typename T>
class Array {
private:
    T *data;       // Указатель на массив данных
    size_t size_;   // Размер массива

public:
    explicit Array(size_t size = 0, const T &value = T()) : size_(size) {
        data = new T[size_];
        for (size_t i = 0; i < size_; ++i)
            data[i] = value;
    }

    Array(const Array &other) : size_(other.size_) {
        data = new T[size_];
        for (size_t i = 0; i < size_; ++i)
            data[i] = other.data[i];
    }

    ~Array() {
        delete[] data;
    }

    Array &operator=(const Array &other) {
        if (this != &other) {
            delete[] data;
            size_ = other.size_;
            data = new T[size_];
            for (size_t i = 0; i < size_; ++i)
                data[i] = other.data[i];
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
