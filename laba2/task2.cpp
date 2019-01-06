#include <iostream>
#include <cmath>

int main() {
    float x = 0, b = 0;
    double result;
    printf("x = ");
    scanf("%f", &x);
    printf("b = ");
    scanf("%f", &b);
    result = std::log((x + 1) / (x - 1)) + b;
    printf("%f", result);
    system("pause");
    return 0;
}