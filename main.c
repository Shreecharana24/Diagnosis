#include <stdio.h>
#include "diagnosis.h"
#include "advice.h"
#include <string.h>
#include "symptom.h"

int main() {
    int selected[10], scores[10], count;
    char disease[50];
    char severity[20];

    // Step 1: Let user select symptoms from categories
    select_symptoms(selected, scores, &count);

    // Step 2: Predict disease and severity
    diagnose(selected, scores, count, disease, severity);


    // Step 3: Show result
    printf("\nPossible Disease: %s\n", disease);
    printf("Severity Level: %s\n", severity);

    // Step 4: Show advice
    show_advice(disease);

    return 0;
}
