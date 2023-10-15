struct Rational {
    Rational(int numerator = 0, int denominator = 1);

    void add(Rational rational);

    void sub(Rational rational);

    void mul(Rational rational);

    void div(Rational rational);

    void neg();

    void inv();

    double to_double() const;

    Rational &operator+=(Rational rational);

    Rational &operator-=(Rational rational);

    Rational &operator*=(Rational rational);

    Rational &operator/=(Rational rational);

    Rational operator-() const;

    Rational operator+() const;

    bool operator==(Rational const &b) {
        return (numerator_ * b.denominator_ == b.numerator_ * denominator_);
    }

    bool operator==(int b) {
        return numerator_ == (double)b * denominator_;
    }

    bool operator!=(Rational const &b) {
        return !(*this == b);
    }

    bool operator>(Rational const &b) {
        return (numerator_ * b.denominator_ > b.numerator_ * denominator_);
    }

    bool operator>(int b) {
        return numerator_ > (double)b * denominator_;
    }

    bool operator<=(Rational const &b) {
        return !(*this > b);
    }

    bool operator<=(int b) {
        return !(*this > b);
    }

    bool operator<(Rational const &b) {
        return (numerator_ * b.denominator_ < b.numerator_ * denominator_);
    }

    bool operator<(int b) {
        return (numerator_ < (double)b * denominator_);
    }

    bool operator>=(Rational const &b) {
        return !(*this < b);
    }

    bool operator>=(int b) {
        return !(*this < b);
    }

public:
    int numerator_;
    int denominator_;
};

Rational operator+(Rational lhs, Rational rhs);

Rational operator-(Rational lhs, Rational rhs);

Rational operator*(Rational lhs, Rational rhs);

Rational operator/(Rational lhs, Rational rhs);

bool operator==(int a, Rational const &b) {
    return (b.numerator_ == a * b.denominator_);
}

bool operator!=(int a, Rational const &b) {
    return !(a == b);
}

bool operator>(int a, Rational const &b) {
    return (b.numerator_ < (double)a * b.denominator_);
}

bool operator<=(int a, Rational const &b) {
    return !(a > b);
}

bool operator<(int a, Rational const &b) {
    return (b.numerator_ > (double)a * b.denominator_);
}

bool operator>=(int a, Rational const &b) {
    return !(a < b);
}