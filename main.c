#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void readInt(int *num, char *text);

int main() {
    int ages[10] = { 19, 25, 20, 21, 22, 21, 24, 19, 26, 25 };
    int upperBound;
    int lowerBound;
    bool isSuccessful;

    printf("Az egyetemi hallgatók életkora 18-28 között van.\n");

    do {
        readInt(&lowerBound, "Kérem adja meg a tartomány alsó értékét");
        readInt(&upperBound, "Kérem adja meg a tartomány felső értékét");

        if (upperBound > 18 && upperBound < 29 && lowerBound > 17 && lowerBound < 28 && lowerBound < upperBound) {
            isSuccessful = true;
        } else {
            printf("Kérem határozzon meg 18 és 28 közötti tartományt.\n");
        }
    } while (!isSuccessful);

    int sum = 0;
    int count = 0;

    printf("A tartományba eső életkorok: ");
    for (int i = 0; i < sizeof(ages) / sizeof(int); i++) {
        int age = ages[i];
        if (age >= lowerBound && age <= upperBound) {
            sum += age;
            count++;
            printf("%d ", ages[i]);
        }
    }

    int avg = (int)round(sum / count);

    printf("\nAz életkorok átlaga: %d\n", avg);

    for (int i = 0; i < sizeof(ages) / sizeof(int); i++) {
        int age = ages[i];
        if (age == avg) {
            printf("A %d. hallgató életkora megfelel az átlagnak.\n", i + 1);
        }
    }

    return EXIT_SUCCESS;
}

void readInt(int *num, char *text) {
    bool isReadingSuccessful;
    char ch;

    do {
        isReadingSuccessful = true;
        printf("%s: ", text);
        if (scanf("%d", num) != 1) {
            printf("Beolvasási hiba\n");
            isReadingSuccessful = false;
            while ((ch = getchar()) != '\n');
        }
    } while (!isReadingSuccessful);
}
