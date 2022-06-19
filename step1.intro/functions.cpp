#include "iostream"
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
    return 0;
}