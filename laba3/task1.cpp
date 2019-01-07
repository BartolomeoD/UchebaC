#include <stdio.h>
#include <limits.h>
#include <cstdlib>

int Min(int first, int second) {
    if (first < second)
        return first;
    if (second < first)
        return second;
    return 0;
}

int MAX(int first, int second) {
    if (first > second)
        return first;
    if (second > first)
        return second;
    return 0;
}

int main(void) {
    double dataArray[100];
    int n, i;
    printf("digit count n = ");
    scanf("%d", &n);
    if (n > (sizeof dataArray) / sizeof(double)) {
        printf("Too much digits "
               "\n");
        return 0;
    }
    for (i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%lf", &dataArray[i]);
    }

    int maxElementIndex = 0, minElementIndex = 0;
    double maxElementValue = INT_MIN,
            minElementValue = INT_MIN;

    double negativeDigitsSum = 0;

    for (i = 0; i < n; i++) {
        if (dataArray[i] > maxElementValue) {
            maxElementIndex = i;
            maxElementValue = dataArray[i];
        }

        if (dataArray[i] < minElementValue) {
            minElementIndex = i;
            minElementValue = dataArray[i];
        }

        if (dataArray[i] < 0) {
            negativeDigitsSum += dataArray[i];
        }
    }

    printf("Res:%f\n", negativeDigitsSum);

    double multiplicationResult = 1;

    for (i = Min(maxElementIndex, minElementIndex) + 1; i < MAX(maxElementIndex, minElementIndex); i++) {
        multiplicationResult *= dataArray[i];
    }

    printf("Res:%f\n", multiplicationResult);
    system("pause");
    return 0;
}

