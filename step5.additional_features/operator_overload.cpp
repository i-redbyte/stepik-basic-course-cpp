/**
Вам дан класс Rational, который описывает рациональное число.
В нем определены методы add, sub, mul и div, которые прибавляют к нему число, отнимают число, умножают на число
и делят на число соответственно. Кроме того в нем определен метод neg, который меняет знак на противоположный.
Вам нужно определить операторы +=, -=, *=, /= для класса Rational так, чтобы они могли принимать в качестве аргументов
и объекты типа Rational и целые числа.
Кроме того вам необходимо определить операторы унарного минуса и плюса для класса Rational.

Требования к реализации: ваш код не должен вводить или вводить что-либо, реализовывать функцию main не нужно.
Кроме того, нельзя (это совершенно не нужно) использовать динамическую память или подключать какие-либо библиотеки.
*/

struct Rational {
    Rational(int numerator = 0, int denominator = 1);

    void add(Rational rational);

    void sub(Rational rational);

    void mul(Rational rational);

    void div(Rational rational);

    void neg();

    void inv();

    double to_double() const;

    Rational &operator+=(const Rational &rational) {
        this->add(rational);
        return *this;
    }

    Rational &operator+=(int d) {
        this->add(Rational(d));
        return *this;
    }

    Rational &operator-=(const Rational &rational) {
        this->sub(rational);
        return *this;
    }

    Rational &operator-=(int d) {
        this->sub(Rational(d));
        return *this;
    }

    Rational &operator*=(const Rational &rational) {
        this->mul(rational);
        return *this;
    }

    Rational &operator*=(int d) {
        this->mul(Rational(d));
        return *this;
    }

    Rational &operator/=(const Rational &rational) {
        this->div(rational);
        return *this;
    }

    Rational &operator/=(int d) {
        this->div(Rational(d));
        return *this;
    }

    Rational operator-() const {
        Rational r(this->numerator_, this->denominator_);
        r.neg();
        return r;
    }

    Rational operator+() const {
        Rational r(this->numerator_, this->denominator_);
        return r;
    }

private:
    int numerator_;
    unsigned denominator_;
};