#include <stdio.h>
#include <stdlib.h>
#include "simpleDb.h"

/** function to create a new node  */

struct student *creatNode(void)
	{
		struct student *ptr ;
		ptr = malloc(sizeof(struct student));
		if (ptr)
		{
			ptr ->next =ptr->prev=NULL ;
		}
		return ptr ;
	}
int addEntry (int id , int year,int *course , int *grade)
{
	int i ;

	struct student *ptr= NULL ;
	ptr = creatNode() ;

	while(ptr)
	{

		if (head==NULL)
		{
			ptr->IDNO = id ;
			ptr->year= year ;
			for (i=0 ; i<3 ; i++)
			{
				ptr->course[i]=*course++ ;
				ptr->grade[i] =*grade++ ;
			}

			head = tail =ptr ;
			ptr->next = ptr->prev =NULL ;
		}
		else
		{
			tail->next=ptr ;
			ptr->prev = tail ;
			tail = ptr ;
			ptr->IDNO = id ;
			ptr->year= year ;
			for (i=0 ; i<3 ; i++)
			{
				ptr->course[i]=*course++ ;
				ptr->grade[i] =*grade++ ;
			}
		}

		return 1 ;

	}

}
void Grades_CoursesEntry (void)
{
	int i ;
	int courses ;
	int grades;
	printf("Enter the courses IDs \n");
	for (i=0 ;i<3 ;i++)
	{
		printf("Course(%d) ID:",i+1);
		scanf("%d",&courses);
		course[i]=courses ;
	}
	printf("Enter the courses grades \n");
	for (i=0 ;i<3 ;i++)
	{
		printf("Course(%d) grade:",i+1);
		scanf("%d",&grades);
		course[i]=grades ;
	}


}

int IsFull(void)
{
	if (counter==10)
	{
		return 1 ;
	}
	else
	{
		return 0 ;
	}
}
int UsedSize(void)
{
	return counter+1 ;
}
void DeletEntry (int id)
{
	struct student *pcur ;
	pcur =head ;
	while(pcur)
	{
		if (pcur->IDNO == id)
		{
			if (head == tail)
			{

				free(head);
                head = tail = NULL;
			}
			else if (pcur == head)
			{
				head = pcur->next ;
				free(pcur);
				head->prev =NULL ;
			}
			else if (pcur == tail)
			{
				tail= pcur->prev ;
				free(pcur);
				tail->next = NULL ;
			}
			else
			{
				pcur->next->prev=pcur->prev ;
				pcur->prev->next=pcur->next ;
				free(pcur);
			}
		}

		pcur=pcur->next ;
	}

}

int ReadEntry (int id)
{
	int i ;
	struct student *pcur ;
	pcur = head ;
	while(pcur)
	{
		if (pcur->IDNO == id)
		{
			printf("Student ID :%d\n",pcur->IDNO);
			printf("Student Year :%d\n",pcur->year);
			for (i=0 ; i<3 ; i++)
			{
				printf("Student Subject ID :%d\n",pcur->course[i]);
				printf("Student Subject Grade :%d\n",pcur->grade[i]);
			}
		 }

			pcur = pcur->next ;

	}
}

void GetList (int counter , struct student *ptr)
{

	struct student *pcur ;
	pcur = ptr ;
	while (pcur )
	{

			printf("The ID of student -->%d\n", pcur->IDNO);
			pcur=pcur->next ;


	}
}
int IsExist (int id)
{
	struct student *pcur ;
	pcur = head ;
	while(pcur)
	{
		if (pcur->IDNO == id)
		{
			return 1 ;
		}
		pcur= pcur->next ;
	}
	return 0 ;
}
void viewList (struct student *ptr )
{
	struct student *pcur ;
	pcur = ptr ;
	while(pcur)
	{
		printf("student ID: %d\n",pcur->IDNO);

		printf("student year:%d\n",pcur->year);


		for (i=0 ; i<3 ; i++)
		{
			printf("course (%d) ID : %d\n",i+1,pcur->course[i]);

			printf("course (%d) Grade : %d\n",i+1,pcur->grade[i]);

		}
		pcur = pcur->next ;
		printf("\n\n");

	}
}














































































