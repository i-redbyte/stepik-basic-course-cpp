#include "iostream"
/* присваивает r максимум из x и y */
#define MAX(x, y, r)  \
{                     \
int xx = x;           \
int yy = y;           \
r = xx > yy?xx:yy;    \
}

// определите только функцию power_recurion, где
//    x - число, которое нужно возвести в степень
//    p - степень, в которую нужно возвести x
//
int power(int x, unsigned p) {
    if (p == 0) return 1;
    int answer = x;
    for (int i = 1; i < p; i++) answer *= x;
    return answer;
}

int power_recurion(int x, unsigned p) {
    if (p == 0) return 1;
    return x * power_recurion(x, p - 1);

}

int main() {
    std::cout << "power_recurion(3,3) == " << power_recurion(3, 3) << std::endl;
    std::cout << "power_recurion(13,0) == " << power_recurion(13, 0) << std::endl;
    std::cout << "power(5,3) == " << power_recurion(5, 3) << std::endl;
    std::cout << "power(4,4) == " << power_recurion(4, 4) << std::endl;
    int a = 10;
    int b = 20;
    int c = 0;
    MAX(a, b, c);
    std::cout << "C == " << c << std::endl;
    MAX(a += b, b, c);
    std::cout << "C == " << c << std::endl;
    return 0;
}