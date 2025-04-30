#include <stdio.h>
#include "diagnosis.h"
#include "advice.h"
#include <string.h>

int main() {
    char symptoms[10][50];
    int count;

    printf("Enter number of symptoms you are experiencing: ");
    scanf("%d", &count);
    getchar(); // to consume newline

    for(int i = 0; i < count; i++) {
        printf("Enter symptom %d: ", i+1);
        fgets(symptoms[i], 50, stdin);
        symptoms[i][strcspn(symptoms[i], "\n")] = 0; // remove newline
    }

    char disease[50];
    char severity[20];

    diagnose(symptoms, count, disease, severity);  // from diagnosis.c

    printf("\nPossible Disease: %s\n", disease);
    printf("Severity Level: %s\n", severity);

    show_advice(disease);  // from advice.c

    return 0;
}
