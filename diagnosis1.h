#ifndef DIAGNOSIS1_H
#define DIAGNOSIS1_H

struct symptom{
    char name[10];
    int severity;
};

void intro(struct symptom s0[]);
void severity_grader(struct symptom s1[]);
int diagnose(struct symptom s2[]);

#endif