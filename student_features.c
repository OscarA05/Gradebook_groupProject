#include <stdio.h>
#include "studentinfo.h"

/* 1. UPDATE: Find a student and change their info */
void updateStudent(Student list[], int total) {
    int find, i;
    int found = 0; 

    printf("Enter ID of the student to update: ");
    scanf("%d", &find);

    for (i = 0; i < total; i = i + 1) {
        if (list[i].id == find) {
            
            printf("Student Found! Updating record for: %s\n", list[i].name);
            
            printf("Enter New Name: ");
            scanf(" %49[^\n]", list[i].name);
            
            printf("Enter New Grade: ");
            scanf("%f", &list[i].grade);
            
            printf("Update successful.\n");
            found = 1; 
            break; 
        }
    }
    
    if (found == 0) {
        printf("Error: Student ID not found.\n");
    }
}

/* 2. SORTING */
void sortStudents(Student list[], int total) {
    int i, j, min_idx;

    for (i = 0; i < total - 1; i = i + 1) {
        min_idx = i;
        for (j = i + 1; j < total; j = j + 1) {
            if (list[j].id < list[min_idx].id) {
                min_idx = j;
            }
        }
        Student temp = list[min_idx];
        list[min_idx] = list[i];
        list[i] = temp;
    }
    printf("Gradebook sorted by ID successfully.\n");
}