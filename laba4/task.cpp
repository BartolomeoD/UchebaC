
#include <cstdio>
#include <cstring>
#include "Auto.h"

void AddElement(Auto autos[], int *elementCounts) {
    printf("Adding new auto \n");
    struct Auto a{};
    printf("Model \n");
    scanf("%s", a.ModelName);
    printf("Manufacturer \n");
    scanf("%s", a.ManufacturerName);
    printf("Horse power\n");
    scanf("%i", &a.HorsePowers);
    printf("Years issue\n");
    scanf("%i", &a.YearsIssue);
    autos[*elementCounts] = a;
    *elementCounts += 1;
}

void RemoveElement(Auto autos[], int *elementsCount, int itemIndex) {
    int last_index = *elementsCount - 1;
    for (int i = itemIndex; i < last_index; i++) {
        autos[i] = autos[i + 1];
    }
    *elementsCount -= 1;
}

void EditElement(Auto *a) {
    printf("Editing");
    printf("Model \n");
    scanf("%s", a->ModelName);
    printf("Manufacturer \n");
    scanf("%s", a->ManufacturerName);
    printf("Horse power\n");
    scanf("%i", &a->HorsePowers);
    printf("Years issue\n");
    scanf("%i", &a->YearsIssue);
}

void PrintElement(Auto *a) {
    printf("Model: %s\n", a->ModelName);
    printf("Manufacturer: %s\n", a->ManufacturerName);
    printf("Horse powers: %d\n", a->HorsePowers);
    printf("Year issue: %d\n", a->YearsIssue);
}

int main() {
    struct Auto autos[100];
    int elementCount = 0;
    int action = 0;
    while (action != -1) {
        printf(" 1 - add\n2-edit\n3-show all\n4-show by Manufacturer\n5 - delete\n");
        scanf("%i", &action);
        switch (action) {
            case 1:
                AddElement(autos,&elementCount);
                break;
            case 2:
                char model[256];
                scanf("%s", model);
                for (int i = 0; i < elementCount; i++) {
                    if (strcmp(autos[i].ModelName, model) == 0) {
                        EditElement(&autos[i]);
                    }
                }
                break;
            case 3:
                for (int i = 0; i < elementCount; i++) {
                    PrintElement(&autos[i]);
                }
                break;
            case 4:
                char manufacturer[256];
                scanf("%s", manufacturer);
                for (int i = 0; i < elementCount; i++) {
                    if (strcmp(autos[i].ManufacturerName, manufacturer) == 0)
                    PrintElement(&autos[i]);
                }
                break;
            case 5:
                char deleteModel[256];
                scanf("%s", deleteModel);
                for (int i = 0; i < elementCount; i++) {
                    if (strcmp(autos[i].ModelName, deleteModel) == 0)
                        RemoveElement(autos,&elementCount, i);
                }
                break;
        }
    }
}