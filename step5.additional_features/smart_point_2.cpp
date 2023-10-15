/**
Задание повышенной сложности.
Реализуйте класс SharedPtr как описано ранее. Задание немного сложнее, чем кажется на первый взгляд.
Уделите особое внимание "граничным случаям" — нулевой указатель, присваивание самому себе, вызов reset на нулевом
SharedPtr и прочее.
Подсказка: возможно, вам понадобится завести вспомогательную структуру.
Требования к реализации: ваш код не должен вводить или вводить что-либо, реализовывать функцию main не нужно.
*/

#include <iostream>

struct Expression;
struct Number;
struct BinaryOperation;

struct Helper {
    Helper(Expression *ptr = NULL) {
        this->ptr = ptr;
        cnt = 1;
    }

    ~Helper() {
        delete ptr;
    }

    Expression *ptr;
    mutable int cnt;
};

struct SharedPtr {

    explicit SharedPtr(Expression *ptr = 0) {
        if (ptr != 0)
            h = new Helper(ptr);
        else
            h = NULL;
    }

    ~SharedPtr() {
        if (h != NULL) {
            --(h->cnt);
            if (h->cnt == 0)
                delete h;
        }
    }

    SharedPtr(const SharedPtr &other) {
        this->h = other.h;
        if (this->h != NULL && this->h->cnt)
            ++(this->h->cnt);
    }

    SharedPtr &operator=(const SharedPtr &other) {
        if (this != &other) {
            this->~SharedPtr();
            this->h = other.h;
            if (this->h != NULL)
                ++(this->h->cnt);
        }
    }

    Expression *get() const {
        if (this->h != NULL)
            return this->h->ptr;
        else
            return NULL;
    }

    void reset(Expression *ptr = 0) {
        this->~SharedPtr();
        if (ptr != 0)
            h = new Helper(ptr);
        else
            h = NULL;
    }

    Expression &operator*() const {
        if (this->h != NULL)
            return *(this->h->ptr);
        else
            return *(Expression *) NULL;
    }

    Expression *operator->() const {
        if (this->h != NULL)
            return this->h->ptr;
        else
            return NULL;
    }

private:
    Helper *h = NULL;
};



