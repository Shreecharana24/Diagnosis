#include <string.h>
#include <string.h> // for strcasecmp
#include "database.h"

extern Disease database[];
extern int DISEASE_COUNT;

void diagnose(char symptoms[][50], int scores[], int count, char* out_disease, char* out_severity) {
    int best_match_score = 0;
    char best_disease[50] = "";

    for (int i = 0; i < DISEASE_COUNT; i++) {
        int match_score = 0;
        int matched_scores[5] = {0};
        int matched_count = 0;

        for (int j = 0; j < database[i].symptom_count; j++) {
            for (int k = 0; k < count; k++) {
                if (strcasecmp(symptoms[k], database[i].symptoms[j]) == 0) {
                    match_score += database[i].scores[j];
                    matched_scores[matched_count++] = database[i].scores[j];
                }
            }
        }

        if (match_score > best_match_score) {
            best_match_score = match_score;
            strcpy(best_disease, database[i].disease);
        }
    }

    strcpy(out_disease, best_disease);

    // Severity logic
    if (count == 0) {
        strcpy(out_severity, "Mild");
        return;
    }

    // Calculate severity level using your rules
    int severe = 0, moderate = 0;

    for (int i = 0; i < count; i++) {
        if (scores[i] >= 8) severe++;
        else if (scores[i] == 7) moderate++;
        else if (scores[i] == 6) moderate++;
        else if (scores[i] == 5) moderate++;
    }

    if (severe >= 1 || moderate >= (2 * count / 3))
        strcpy(out_severity, "Severe");
    else if (moderate >= (count / 2))
        strcpy(out_severity, "Moderate");
    else
        strcpy(out_severity, "Mild");
}
