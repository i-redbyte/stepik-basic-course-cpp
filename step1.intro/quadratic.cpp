/**
 * Напишите программу для решения квадратных уравнений вида a x^2 + b x + c = 0
 * На вход программа получает три целых числа: a , b и c, соответственно. При этом гарантируется, что a != 0
 * На вывод программа должна вывести два вещественных корня уравнения, разделённые пробелом.
 * Если вещественных корней нет, то программа должна вывести строку "No real roots".
 * Если у уравнения имеется только один корень (кратный корень), то программа должна вывести его дважды.
 * Порядок вывода корней не важен. Ничего, кроме этого, выводить не нужно.
 * Для вычислений с плавающей точкой используйте тип double.
 * При выполнении задания вам может оказаться полезной функция sqrt из заголовочного файла cmath.
 * */
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    int d = (b * b) - 4 * a * c;
    if (d < 0) {
        std::cout << "No real roots" << endl;
    } else if (d == 1) {
        int x = (-b / (2 * a));
        std::cout << x << " " << x << endl;
    } else {
        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);
        std::cout << x1 << " " << x2 << endl;
    }
    return 0;
}