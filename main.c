#include <stdio.h>
#include "gradebook.h"

/* Tell main about the file functions */
int loadFromFile(const char *file, Student list[], int max);
void saveToFile(const char *file, Student list[], int total);

int main(void) {
    Student all_students[100];
    int student_count = loadFromFile("records.txt", all_students, 100);
    int options;

	while(1)
	{
		printf("MENU\n\n");
		printf("1) Add\n2) List\n3) Delete \n4) Update\n5) Sort\n0) Exit\n\n");
		printf("Enter Choice: ");
		scanf("%d", &options);

		switch(options)
		{
			case 1 : add(all_students, &student_count, 100);
				 break;
			case 2 : list(all_students, student_count);
				 break;
			case 3 : deleteStudent(all_students, &student_count);
				 break;
			case 4 : updateStudent(all_students, student_count); 
        		 break;
			case 5 : sortStudents(all_students, student_count); 
         		break;
			case 0 : printf("Exiting...\n");
				 return 0;
			default: printf("Invalid Choice\n\n");
		}

		saveToFile("records.txt", all_students, student_count);
	}
	return 0;
}
