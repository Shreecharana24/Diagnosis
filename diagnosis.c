#include <string.h>
#include "diagnosis.h"

typedef struct {
    char disease[50];
    char symptoms[5][50];
    int scores[5];
    int symptom_count;
} Disease;

void diagnose(char input_symptoms[][50], int input_count, char* out_disease, char* out_severity) {
    Disease db[] = {
        {"Common Cold", {"Sneezing", "Runny Nose", "Sore Throat"}, {3, 2, 4}, 3},
        {"Flu", {"Fever", "Body Aches", "Fatigue"}, {7, 6, 5}, 3},
        {"Dengue", {"Fever", "Joint Pain", "Headache"}, {9, 8, 7}, 3},
        {"Malaria", {"Chills", "Fever", "Sweating"}, {7, 9, 5}, 3}
    };

    int best_score = 0;
    char best_disease[50] = "";
    int high_symptom = 0;

    for(int i = 0; i < 4; i++) {
        int score = 0, matches = 0;
        for(int j = 0; j < db[i].symptom_count; j++) {
            for(int k = 0; k < input_count; k++) {
                if(strcasecmp(db[i].symptoms[j], input_symptoms[k]) == 0) {
                    score += db[i].scores[j];
                    matches++;
                    if (db[i].scores[j] >= 8) high_symptom = 1;
                }
            }
        }

        int total_score = (matches * 2) + (score / 2) + (high_symptom ? 3 : 0);
        if (total_score > best_score) {
            best_score = total_score;
            strcpy(best_disease, db[i].disease);
        }
    }

    strcpy(out_disease, best_disease);

    if (best_score >= 15)
        strcpy(out_severity, "Severe");
    else if (best_score >= 10)
        strcpy(out_severity, "Moderate");
    else
        strcpy(out_severity, "Mild");
}
