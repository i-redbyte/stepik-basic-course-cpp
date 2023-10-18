/**
В первом уроке вы реализовали простой шаблон ValueHolder, в этом задании мы используем его чтобы написать класс Any
(интересно, что не шаблонный), который позволяет хранить значения любого типа!
Например, вы сможете  создать массив объектов типа Any, и сохранять в них int-ы, double-ы или даже объекты Array.
Подробности в шаблоне кода.

Hint: в нешаблонном классе Any могут быть шаблонные методы, например, шаблонный конструктор.

Для реализации вам может потребоваться оператор dynamic_cast.
С++ предоставляет и более простой способ узнать конкретный класс по указателю (или ссылке) на базовый класс.
Для этого можно использовать оператор dynamic_cast. Например, если у вас есть указатель Expression *,
и вы хотите узнать, указывает ли этот указатель на самом деле на объект Number, то сделать это можно так:

Expression *expression = parse(code);
Number *number = dynamic_cast<Number *>(expression);
if (number)
    std::cout << "It's a number" << std::endl;
else
    std::cout << "It is not a number" << std::endl;

Если expression действительно указывает на объект Number (или на один из его наследников, но в нашем примере их нет),
то оператор dynamic_cast<Number *> вернет правильный указатель. Если expression указывает не на класс Number,
то будет возвращен нулевой указатель. Т. е. если в переменной number хранится нулевой указатель, значит expression
не указывает на Number на самом деле.

Для правильной работы оператора dynamic_cast в нашем примере требуется, чтобы класс Expression был полиморфным,
т. е. в нем должна быть как минимум одна виртуальная функция (например, деструктор).
Стандарт определяет работу dynamic_cast и с не полиморфными типами, но в этом случае никаких проверок типа времени
исполнения выполняться не будет - часто, это не то, что требуется.

Если передать оператору dynamic_cast нулевой указатель, то он просто вернет нулевой указатель нужного типа, поэтому
проверять указатель перед передачей в dynamic_cast не нужно.
*/

#include <iostream>

struct ICloneable {
    virtual ICloneable *clone() const = 0;

    virtual ~ICloneable() = default;
};

template<typename T>
struct ValueHolder : public ICloneable {
    T data_;

    ValueHolder(const T &data) : data_(data) {}

    ICloneable *clone() const override {
        return new ValueHolder(data_);
    }
};

class Any {
private:
    ICloneable *content_;

public:
    Any() : content_(nullptr) {}

    template<typename T>
    Any(const T &value) : content_(new ValueHolder<T>(value)) {}

    Any(const Any &other) : content_(other.content_ ? other.content_->clone() : nullptr) {}

    Any &operator=(const Any &other) {
        if (this == &other)
            return *this;

        delete content_;
        content_ = (other.content_ ? other.content_->clone() : nullptr);
        return *this;
    }

    ~Any() {
        delete content_;
    }

    template<typename T>
    T *cast() const {
        ValueHolder<T> *holder = dynamic_cast<ValueHolder<T> *>(content_);
        if (holder)
            return &(holder->data_);
        else
            return nullptr;
    }
};

int main() {
    Any empty;
    Any i(10);
    const Any& copy(i);

    int *iptr = i.cast<int>();
    if (iptr) {
        std::cout << "i contains: " << *iptr << std::endl;
    }
    char *cptr = i.cast<char>();
    if (cptr) {
        std::cout << "i contains a char!" << std::endl;
    } else {
        std::cout << "i does not contain a char." << std::endl;
    }
    Any empty2;
    int *p = empty2.cast<int>();
    if (p) {
        std::cout << "empty2 contains: " << *p << std::endl;
    } else {
        std::cout << "empty2 is empty." << std::endl;
    }

    return 0;
}
