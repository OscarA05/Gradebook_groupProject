#include <stdio.h>
#include <string.h>
#include "gradebook.h"

void printStudent(const Student s)
{
	printf("ID: %d | Name: %s | Grade: %.1f\n", s.id, s.name, s.grade);
}

void add(Student list[], int count, int max)
{
	if(count < max)
	{
		printf("Enter ID: ");
		scanf("%d", &list[count].id);
		printf("Enter Name: ");
		scanf(" %50[^\n]", %list[count].name);
		printf("Enter Grade: ");
		scanf("%f", &list[count].grade);

		count++;
		printf("Sudent add successfully.\n");
	}
	else
	{
		printf("Error: Gradebook is full!\n");
	}
}

void list(Student list[], int count)
{
	if(count == 0)
		printf("The gradebook is empty.\n");
	for(int i = 0; i < count; i++)
		printStudent(&list[i]);
}

void deleteStudent(Student list[], int count)
{
	int find, i, j;
	printf("Enter ID of student: ");
	scanf("%d", find);

	for(i = 0; i < count; i++)
	{
		if(list[i].id == find)
		{
			for(j = i; j < count-1; j++)
				list[j] = list [j+1];

			count--;
			printf("Student removed from list.\n");
			return;
		}
	}
	printf("Student not found.\n");
}
