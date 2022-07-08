/**На прошлом степе вы познакомились с реализацией паттерна посетитель.
 * Теперь пришло время воспользоваться этими знаниями. Ваш класс должен печатать (используя std::cout)
 * текстовое представление арифметического выражения. Т.е. для объекта класса Number он должен напечатать число,
 * которое в нем хранится, а для объекта класса BinaryOperation он должен напечатать левый операнд, затем операцию,
 * а затем правый операнд.Учтите, что операции + и - имеют меньший приоритет, чем операции * и /, т. е. возможно
 * вам придется печатать дополнительные круглые скобки, чтобы сохранить правильный порядок операций.
 * Классы иерархии Expression и абстрактный класс Visitor приведены в комментарии в шаблоне для удобства.
 * При проверке задания лишние пробелы или лишние скобки будут игнорироваться,
 * т.е. вывод "1+2" эквивалентен выводу "( ( 1 )  +   ( 2 ) )", а вот вывод "1 + 2 * 3"
 * не эквивалентен выводу "((1 + 2) * 3)".
 * Вы можете попытаться минимизировать количество скобок в выводе, но это не требуется.*/

struct Number;
struct BinaryOperation;

struct Visitor {
    virtual void visitNumber(Number const *number) = 0;

    virtual void visitBinaryOperation(BinaryOperation const *operation) = 0;

    virtual ~Visitor() = default;
};

struct Expression {
    virtual double evaluate() const = 0;

    virtual void visit(Visitor *vistitor) const = 0;

    virtual ~Expression() = default;
};

struct Number : Expression {
    explicit Number(double value) : value(value) {};

    double evaluate() const override {
        return value;
    }

    double get_value() const { return value; }

    void visit(Visitor *visitor) const override { visitor->visitNumber(this); }

private:
    double value;
};

struct BinaryOperation : Expression {
    BinaryOperation(Expression const *left, char op, Expression const *right) : left(left), op(op), right(right) {};

    ~BinaryOperation() override {
        delete left;
        delete right;
    }

    double evaluate() const override {
        switch (op) {
            case '+':
                return left->evaluate() + right->evaluate();
            case '-':
                return left->evaluate() - right->evaluate();
            case '*':
                return left->evaluate() * right->evaluate();
            case '/':
                return left->evaluate() / right->evaluate();
            default:
                return -1;
        }
    }

    Expression const *get_left() const { return left; }

    Expression const *get_right() const { return right; }

    char get_op() const { return op; }

    void visit(Visitor *visitor) const override { visitor->visitBinaryOperation(this); }

private:
    Expression const *left;
    Expression const *right;
    char op;
};

#include <iostream>

/* Этот класс вам нужно реализовать */
struct PrintVisitor : Visitor {
    void visitNumber(Number const *number) override {
        std::cout << number->get_value();
    }

    void visitBinaryOperation(BinaryOperation const *bop) override {
        std::cout <<"(";
        bop->get_left()->visit(this);
        std::cout << bop->get_op();
        bop->get_right()->visit(this);
        std::cout <<")";
    }
};

int main() {
    auto *n32 = new Number(32.0);
    auto *n16 = new Number(16.0);
    auto *n42 = new Number(42.0);
    auto *n3 = new Number(3);
    auto *minus = new BinaryOperation(n32, '-', n16);
    auto *bs2 = new BinaryOperation(minus, '*', n42);
    auto *ns33 = new BinaryOperation(n3, '/', bs2);
    Visitor *visitor = new PrintVisitor();
    ns33->visit(visitor);
    return 0;
}