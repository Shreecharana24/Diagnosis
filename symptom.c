#include <stdio.h>
#include "symptom.h"

char* general[] = {"Fever", "Fatigue", "Body Pain"};
char* respiratory[] = {"Cough", "Sore Throat", "Runny Nose"};
char* digestive[] = {"Nausea", "Diarrhea", "Vomiting"};

void display_category(char* symptoms[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d. %s\n", i + 1, symptoms[i]);
    }
}

void select_symptoms(int selected[], int scores[], int *n) {
    int choice;
    int count = 0;

    printf("Select a category:\n");
    printf("1. General\n2. Respiratory\n3. Digestive\n");
    scanf("%d", &choice);

    char** symptoms;
    int size;

    switch (choice) {
        case 1: symptoms = general; size = 3; break;
        case 2: symptoms = respiratory; size = 3; break;
        case 3: symptoms = digestive; size = 3; break;
        default: printf("Invalid choice\n"); return;
    }

    display_category(symptoms, size);

    printf("How many symptoms do you have? ");
    scanf("%d", n);

    for (int i = 0; i < *n; i++) {
        printf("Enter symptom number %d: ", i + 1);
        scanf("%d", &selected[i]);

        int idx = selected[i] - 1;
        printf("Enter severity for %s (1–10): ", symptoms[idx]);
        scanf("%d", &scores[i]);
    }
}
