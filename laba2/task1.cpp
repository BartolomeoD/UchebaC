#include <iostream>
#include <cmath>

int main() {
    float x = 0, accuracy = 0, result = 0;
    double loopResult;
    int n = 0;
    printf("\nx = ");
    scanf("%f", &x);
    printf("\naccuracy = ");
    scanf("%f", &accuracy);
    do {
        loopResult = 1 / ((2 * n + 1) * pow(x, 2 * n + 1));
        printf("%f\n",loopResult);
        printf("\n");
        result += loopResult;
        n++;
    } while (loopResult > accuracy);
    printf("%f",2 * result);
    return 0;
}