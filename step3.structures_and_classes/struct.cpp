#include <cstddef>
#include <cstring>
#include <iostream>


/** В этой и последующих задачах мы создадим свой простой аналог стандартного класса string для удобной работы со строками.
 * Начнем мы с написания конструктора. В этой задаче вам требуется реализовать конструктор,
 * который принимает на вход C-style строку, вычисляет ее размер (без учета завершающего 0 символа)
 * и сохраняет его в поле size, кроме того, конструктор должен аллоцировать память достаточную для хранения копии
 * переданной строки (вместе с завершающим 0 символом), копирует переданную строку в выделенную память и сохраняет
 * указатель на начало этой области памяти в поле str. Т.е. в результате работы конструктора в поле str должен оказаться
 * указатель на C-строку c копией исходной строки, а в поле size — длина строки без учета завершающего нулевого символа.*/
struct String {

    String(const char *str = "") : size(strlen(str)) {
        this->str = new char[size + 1];
        strcpy(this->str, str);
    }
/** Конструкторов у структуры может быть несколько. Для строки может оказаться полезным заполняющий конструктор
 * (например, чтобы создать строку пробелов). Заполняющий конструктор принимает число и символ, и создает строку с
 * заданным количеством повторений переданного символа. Условия налагаемые на реализацию конструктора те же самые
 * (в поле size размер без учета завершающего 0 символа, в поле str C-style строка, т.е. с завершающим 0 символом).
 * Кроме конструктора в этой задаче вам нужно также реализовать и деструктор, который освободит выделенную память.*/
    /* Реализуйте этот конструктор */
    String(size_t n, char c) {
        if (n < 0) return;
        this->str = new char[n + 1];
        for (size_t i = 0; i < n; ++i) {
            this->str[i] = c;
        }
        this->str[n] = '\0';
        this->size = n;
    }

    /* и деструктор */
    ~String() {
        delete[] str;
    }

    size_t size;
    char *str;

/** Реализованные в предыдущих заданиях конструкторы и деструктор берут на себя работу по управлению ресурсами.
 *  Теперь можно дополнить структуру String различными полезными методами.
 *  Для работы со строками можно придумать множество полезных методов (подумайте, какие методы пригодились бы вам,
 *  и чего вам не хватает для их реализации). Примером такого метода может послужить метод append — он добавляет копию
 *  строки-аргумента в конец текущей строки (т.е. в конец строки, у которой он был вызван).
    String s1("Hello,");
    String s2(" world!");
    s1.append(s2); // теперь s1 хранит "Hello, world!"

 * Ваша задача реализовать метод append.
 * При выполнении задания будьте аккуратны при работе с памятью — при вызове метода не должно возникать утечек памяти.
 * Кроме того, не забудьте, что size хранит размер без учета завершающего 0 символа.
 * Кроме того, ваша реализация должна корректно работать в следующем тесте:
        String s("Hello");
        s.append(s); // теперь s хранит "HelloHello"
 * */
    void append(String &other) {
        size_t new_size = size + other.size;
        char* new_ptr = new char [new_size + 1];
        strcpy(new_ptr, str);
        strcat(new_ptr + size, other.str);
        new_ptr[new_size] = '\0';
        delete[] str;
        str = new_ptr;
        size = strlen(str);

//        size_t new_size = this->size + other.size;
//        char *new_str = new char[new_size];
//        for (size_t i = 0; i < this->size; ++i) new_str[i] = this->str[i];
//        for (size_t i = 0; i < other.size; ++i) new_str[this->size + i] = other.str[i];
//        delete[] this->str;
//        this->str = new char[new_size + 1];
//        strcpy(this->str, new_str);
//        this->str[new_size] = '\0';
//        this->size = new_size;
//        delete[] new_str;
    }
};

int main() {
    String s("Stroustrup");
    std::cout << "Length = " << s.size << " for string: " << s.str << std::endl;
    String s1(5, '*');
    std::cout << "String for symbol: " << s1.str << std::endl;
    s1.append(s1);
    std::cout << "s1 == " << s1.str << std::endl;
    s1.append(s);
    std::cout << "s1 == " << s1.str << std::endl;
    s1.append(s1);
    std::cout << "s1 == " << s1.str << std::endl;
    String s2("");
    std::cout << "s2 == " << s2.str << std::endl;
    s2.append(s2);
    std::cout << "s2 == " << s2.str << std::endl;
    String ss("Hello");
    ss.append(ss);
    std::cout << "ss == " << ss.str << std::endl;
    return 0;
}