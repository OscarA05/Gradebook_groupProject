
#include <stdio.h>
#include "studentinfo.h"

/* Loads data from the file */
int loadFromFile(const char *filename, Student list[], int max) {
    FILE *fptr = fopen(filename, "r");
    int count = 0;

    if (fptr == NULL) {
        return 0;
    }


    while (count < max && fscanf(fptr, "%d,%49[^,],%f\n",
           &list[count].id, list[count].name, &list[count].grade) == 3) {
        count = count + 1;
    }

    fclose(fptr);
    return count;
}

/* Saves data to the file */
void saveToFile(const char *filename, Student list[], int total) {
    FILE *fptr = fopen(filename, "w");
    int i;

    if (fptr == NULL) {
        printf("can not be saved.\n");
        return;
    }

    for (i = 0; i < total; i = i + 1) {
        fprintf(fptr, "%d,%s,%.2f\n", list[i].id, list[i].name, list[i].grade);
    }

    fclose(fptr);
}
