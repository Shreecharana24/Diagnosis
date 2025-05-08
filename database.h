
#ifndef DATABASE_H
#define DATABASE_H

#define MAX_SYMPTOMS 5

typedef struct {
    char disease[50];
    char symptoms[MAX_SYMPTOMS][50];
    int scores[MAX_SYMPTOMS];
    int symptom_count;
} Disease;

extern Disease database[];
extern int DISEASE_COUNT;

#endif
