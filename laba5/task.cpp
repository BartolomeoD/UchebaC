#include <limits.h>
#include <cstdio>
#include <cstdlib>

void ReplaceTo0(int array[], int length) {
    int maxIndex = 0, maxValue = INT_MIN;
    for (int i = 0; i < length; i++) {
        if (array[i] > maxValue) {
            maxValue = array[i];
            maxIndex = i;
        }
    }

    for (int i = 0; i < maxIndex; i++) {
        array[i] = 0;
    }
}

void ShowPositiveNumberCount(int array[], int length) {
    int positiveNumbersCount = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] > 0) {
            positiveNumbersCount += 1;
        }
    }
    printf("%i", positiveNumbersCount);
}

void Negotiator(int array[100][100], void (*function)(int[], int), int height, int width) {
    for (int i = 0; i < width; ++i) {
        if (array[i][0] % 2 == 0)
            function(array[i], height);
    }
}

void FillArray(int width, int height, int array[100][100]) {

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; ++j) {
            printf("[%d][%d] = ", i, j);
            scanf("%i", &array[i][j]);
        }
    }
}

void ShowArray(int width, int height, int array[100][100]) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; ++j) {
            printf("%i\t",array[j][i]);
        }
        printf("\n");
    }
}

int main() {
    int array1[100][100], array2[100][100];
    int x1, y1;
    printf("digit count x = ");
    scanf("%d", &x1);
    printf("digit count y = ");
    scanf("%d", &y1);
    FillArray(x1, y1, array1);
    ShowArray(x1, y1, array1);

    int x2, y2;
    printf("digit count x = ");
    scanf("%d", &x2);
    printf("digit count y = ");
    scanf("%d", &y2);
    FillArray(x2, y2, array2);
    ShowArray(x2, y2, array2);
    Negotiator(array1, ReplaceTo0, x1, y1);
    Negotiator(array2, ShowPositiveNumberCount, x2, y2);
    printf("array replace 0: \n");
    ShowArray(x1, y1, array1);
    printf("array show positive: \n");
    ShowArray(x2, y2, array2);

    system("pause");
    return 0;
}