#include <stdio.h>
#include "gradebook.h"

int loadFromFile(const char* file, Student list[], int max);
//test comment

int main(void)
{
	Student allStudents[100];
	int studentCount = loadFromFile("records.txt", allStudents, 100);
	int option;

	while(1)
	{
		printf("MENU\n\n");
		printf("1) Add\n2) List\n3) Delete\n0) Exit\n\n");
		printf("Enter Choice: ");
		scanf("%d", &option);

		switch(option)
		{
			case 1 : add(allStudents, &studentCount, 100);
				 break;
			case 2 : list(allStudents, studentCount);
				 break;
			case 3 : deleteStudent(allStudents, &studentCount);
				 break;
			case 0 : printf("Exiting...\n");
				 return 0;
			default: printf("Invalid Choice\n\n");
		}

		saveToFile("records.txt", allStudents, studentCount);
	}
	return 0;
}
