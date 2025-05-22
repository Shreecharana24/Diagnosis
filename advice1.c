#include <stdio.h>
#include "diagnosis1.h"

void advice(int final)
{
    if(final == 1) // 🟢 Mild Severity
    {
        printf("🟢 Mild Severity (overall_severity = 1)\n");
        printf("Advice:\n");
        printf("- Get adequate rest and stay hydrated.\n");
        printf("- Monitor your symptoms for any changes.\n");
        printf("- Maintain a light diet and avoid stress.\n");
        printf("- Over-the-counter medication (like paracetamol) may help, if needed.\n");
        printf("- No immediate need for a doctor, but follow up if symptoms worsen.\n");
    }
    else if(final == 2) // 🟡 Moderate Severity
    {
        printf("🟡 Moderate Severity (overall_severity = 2)\n");
        printf("Advice:\n");
        printf("- Take proper rest and avoid physical or mental exertion.\n");
        printf("- Continue to stay hydrated and eat nutritious food.\n");
        printf("- You may need prescribed medication — consult a general physician.\n");
        printf("- Avoid self-medication beyond basic symptom relief.\n");
        printf("- Keep a close watch on your symptoms for escalation.\n");
    }
    else // 🔴 Severe Severity
    {
        printf("🔴 Severe Severity (overall_severity = 3)\n");
        printf("Advice:\n");
        printf("- Seek immediate medical attention.\n");
        printf("- Do not rely on home remedies or over-the-counter medication.\n");
        printf("- Avoid travel or exertion until cleared by a doctor.\n");
        printf("- Inform family or caretaker of your condition.\n");
        printf("- Be prepared for possible tests or hospitalization depending on symptoms.\n");
    }
       

}