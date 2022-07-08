/** (Задание повышенной сложности) Предполагаемое решение этого задания не переносимо с точки зрения стандарта,
 * однако оно проверено на различных версиях компиляторов g++/clang++/msvc.
 * Решение этого задания не обязательно для получения диплома по этому курсу, однако мы считаем его полезным,
 * чтобы лучше понять как устроены виртуальные функции внутри.
 * Вам требуется реализовать функцию, которая принимает на вход два указателя на базовый класс Expression,
 * и возвращает true, если оба указателя указывают на самом деле на объекты одного и того же класса,
 * и false в противном случае (т.е. если оба указателя указывают на BinaryOperation, то возвращается true,
 * а если один из них указывает на Number, а второй на BinaryOperation, то false).

*/

struct Expression {
    virtual double evaluate() const = 0;

    virtual ~Expression() {}
};

struct Number : Expression {
    Number(double value)
            : value(value) {}

    double evaluate() const {
        return value;
    }

private:
    double value;
};

struct BinaryOperation : Expression {
    /*
      Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям,
      которые вам нужно реализовать.
     */
    BinaryOperation(Expression const *left, char op, Expression const *right)
            : left(left), op(op), right(right) {}

    ~BinaryOperation() {
        delete left;
        delete right;
    }

    double evaluate() const {
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

private:
    Expression const *left;
    Expression const *right;
    char op;
};

bool check_equals(Expression const *left, Expression const *right) {
    return *((int *) left) == *((int *) right);
}
