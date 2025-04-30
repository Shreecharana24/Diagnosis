#include <stdio.h>
#include <string.h>

void show_advice(char* disease) {
    if (strcasecmp(disease, "Dengue") == 0) {
        printf("Advice: Stay hydrated, avoid painkillers like aspirin, and consult a doctor immediately.\n");
    } else if (strcasecmp(disease, "Flu") == 0) {
        printf("Advice: Take rest, stay warm, drink fluids, and consider antiviral medication.\n");
    } else if (strcasecmp(disease, "Malaria") == 0) {
        printf("Advice: Seek immediate medical attention. Anti-malarial drugs required.\n");
    } else {
        printf("Advice: Take rest, stay hydrated, and monitor your symptoms.\n");
    }
}
