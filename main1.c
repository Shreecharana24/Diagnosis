#include <stdio.h>
#include "diagnosis1.h"
#include "advice1.h"

int main() {
    struct symptom s[6];

    intro(s);
    severity_grader(s);
    int level = diagnose(s);
    advice(level);
    return 0;
}
