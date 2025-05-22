#include <stdio.h>
#include <string.h>
#include "diagnosis1.h"

int n;

void intro(struct symptom s0[])
{
    char username[50];
    printf("Enter your name: ");
    scanf("%s", &username); 
    
    printf("Enter number of symptoms: ");
    scanf("%d", &n); 

    for(int i = 0;  i < n; i++)
    {
        printf("Enter symptom %d: ", i+1);
        scanf("%s", s0[i].name);
    }
}

void severity_grader(struct symptom s1[])
{
    for(int i=0;i<n;i++)
    {
        if(strcmp(s1[i].name, "Fever") == 0)        
        {
            int temp;
            printf("Enter the body temp in celsius: ");
            scanf("%d" ,&temp);
            if(temp>37.2 && temp<38)
            {
                s1[i].severity=1;
            }
            else if(temp>38 && temp<38.9)
            {
                s1[i].severity=2;
            }
            else
                s1[i].severity=3;
        }

        if(strcmp(s1[i].name, "Cough") == 0)
        {
            int cough_freq;
            printf("enter the frequency of cough in last 1 hour: ");
            scanf("%d " ,&cough_freq);
            if(cough_freq<5)
                s1[i].severity=1;
            else if(cough_freq>=5 && cough_freq<15)
                s1[i].severity=2;
            else
                s1[i].severity=3;
        }

        if(strcmp(s1[i].name, "Headache") == 0)
        { 
            int pupil;
            printf("enter 4 for discomfort under normal light , 5 for discomfort under bright light , 6 for staying in dark room ");
            scanf("%d" ,&pupil);
            if(pupil==4)
                s1[i].severity=1;
            if(pupil==5)
                s1[i].severity=2;
            if(pupil==6)
                s1[i].severity=3;
            
        }

        if(strcmp(s1[i].name, "Fatigue") == 0)
        {
            double hours;
            printf("enter the no of hours you felt tired : ");
            scanf("%lf" , &hours);
            if(hours<2)
                s1[i].severity=1;
            if(hours>=2 && hours<=5)
                s1[i].severity=2;
            if(hours>5)
                s1[i].severity=3;

        }
        
        if(strcmp(s1[i].name, "Cold") == 0)
        {
            int sneezes;
            printf("Enter the number of times you sneezed in the past hour: ");
            scanf("%d", &sneezes);

            if(sneezes < 3)
                s1[i].severity = 1; // Mild
            else if(sneezes >= 3 && sneezes <= 8)
                s1[i].severity = 2; // Moderate
            else // sneezes > 8
                s1[i].severity = 3; // Severe
        }

        if(strcmp(s1[i].name, "Sore Throat") == 0)
        {
            int throat;
            printf("Enter 4 for slight redness with no swelling,\n");
            printf("5 for red throat with mild swelling,\n");
            printf("6 for bright red throat with swollen tonsils or white patches: ");
            scanf("%d", &throat);

            if(throat == 4)
                s1[i].severity = 1; // Mild
            else if(throat == 5)
                s1[i].severity = 2; // Moderate
            else if(throat == 6)
                s1[i].severity = 3; // Severe
        }
    }


}

int diagnose(struct symptom s2[])
{
    int overall_severity;
    int count_3 = 0, count_2 = 0, count_1 = 0;

    for(int i = 0; i < n; i++) {
        if(s2[i].severity == 3)
            count_3++;
        else if(s2[i].severity == 2)
            count_2++;
        else if(s2[i].severity == 1)
            count_1++;
    }

    if(count_3 >= 1) {
        overall_severity = 3; // Severe
    }
    else if(count_2 >= (2 * n) / 3) {
        overall_severity = 3; // Severe
    }
    else if(count_2 >= 2) {
        overall_severity = 2; // Moderate
    }
    else if(count_2 >= n / 3) {
        overall_severity = 2; // Moderate
    }
    else if(count_1 >= n / 2) {
        overall_severity = 2; // Moderate
    }
    else {
        overall_severity = 1; // Mild
    }

    return overall_severity;
}