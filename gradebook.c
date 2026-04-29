#include <stdio.h>
#include <string.h>
#include "gradebook.h"


void printStudent(const Student *s) {
    /* %d for integer, %s for string, %.2f for float with 2 decimals */
    printf("ID: %d | Name: %s | Grade: %.1f\n", s->id, s->name, s->grade);
}

/* Adds a new student to the array */
void add(Student *students, int *count, int max) {
    /* Check if there is space in the array */
    if (*count < max) {
        printf("Enter ID: ");
        scanf("%d", &students[*count].id);
        printf("Enter Name: ");
        /* this part is basically reading the names in which is 60 characteres per name including the spaces  */
        scanf(" %49[^\n]", students[*count].name);

        printf("Enter Grade: ");

        scanf("%f", &students[*count].grade);

        /* increase the number of the students */
        (*count)++;
        printf("Student added successfully.\n");
    } else {
        printf("Error: Gradebook is full!\n");
    }
}

/* for loop to show the student if there is no students will show the empty message */
void list(Student *students, int count) {
    int i;
    if (count == 0) {
        printf("The gradebook is empty.\n");
    }

    for (i = 0; i < count; i = i + 1) {
        printStudent(&students[i]);
    }
}

/* Remove a student  */
void deleteStudent(Student *students, int *count) {
    int find;
    int i;
    int j;
    printf("Enter ID of the student: ");
    scanf("%d", &find);

    for (i = 0; i < *count; i = i + 1) {
        /* If we find the ID we want to delete */
        if (students[i].id == find) {
            for (j = i; j < *count - 1; j = j + 1) {
                students[j] = students[j + 1];
            }
            /* decrease total */
            (*count)--;
            printf("Student removed from the list.\n");
            return;
        }
    }
    printf("Student not found.\n");
}

