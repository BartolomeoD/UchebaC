#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>


double recursive(double accuracy, double start, double end, int *iterations) {
    double x = (start + end) / 2, res, startRes;
    if (fabs(start - end) <= accuracy)
        return x;
    *iterations += 1;
    res = pow(x, 2) - 2;
    startRes = pow(start, 2) - 2;
    if (startRes * res < 0)
        return recursive(accuracy, start, x, iterations);
    else
        return recursive(accuracy, x, end, iterations);
}

int main() {

    clock_t startTime = clock();
    double accuracy = 0.000000000000001, start = 0, end = 5, x = 0, res = 0, startRes;
    int iterations = 0;
    while (fabs(start - end) > accuracy) {
        iterations += 1;
        x = (start + end) / 2;
        res = pow(x, 2) - 2;
        startRes = pow(start, 2) - 2;
        if (startRes * res < 0)
            end = x;
        else
            start = x;

    }
    res = (start + end) / 2;

    clock_t endTime = clock();
    double time_spent = (double) (endTime - startTime) / CLOCKS_PER_SEC;
    printf("%f\n", res);
    printf("%i\n", iterations);
    printf("%f\n", time_spent);

    clock_t startTime2 = clock();

    double start2 = 0, end2= 5, res2;
    int iterations2 = 0;
    res2 = recursive(accuracy, start2, end2, &iterations2);
    clock_t endTime2 = clock();
    double time_spent2 = (double) (endTime2 - startTime2) / CLOCKS_PER_SEC;

    printf("%f\n", res2);
    printf("%i\n", iterations2);
    printf("%f\n", time_spent2);

    system("pause");
    return 0;
}
