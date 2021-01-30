#include <stdio.h>
#include <stdlib.h>
#include "simpleDb.h"
counter = 0 ;
int main()
{
	int CoursID[3];
	int CoursGrad[3];
	int *ptrID,*ptrGrad;
	ptrID = CoursID ;
	ptrGrad=CoursGrad;

	while(1)
	{

	printf("Instructions\n(1)to enter a new entry\n");
	printf("(2)to delete an entry\n");
	printf("(3)to read an entry\n");
	printf("(4)to Get the list of entered IDs of all student\n");
	printf("(5)to search an ID\n");
	printf("(6)to find used size\n");
	printf("(7)to End\n");
	scanf("%d",&key);
	if (key == 1)
	{
		++counter  ;
		printf("Enter student ID \n");
		scanf("%d",&id);
		printf("Enter student year \n");
		scanf("%d",&year);

		for (i=0 ; i<3 ; i++)
		{
			printf("Enter course (%d) ID-->",i+1);
			scanf("%d",&CoursID[i]);
			printf("Enter course (%d) Grade-->",i+1);
			scanf("%d",&CoursGrad[i]);
		}
		addEntry ( id ,  year, ptrID , ptrGrad);
		printf("\n\n");
		printf("The list of all Eateries \n");
		viewList(head);
		printf("\n\n");

	}

    if (key == 2)
	{
		printf("Enter the ID you want to delete \n");
		scanf("%d",&id);
		DeletEntry ( id) ;
        viewList(head);
	}

	if (key == 3)
	{
		printf("Enter the ID you want to read \n");
		scanf("%d",&id);
		ReadEntry(id) ;

	}
	if (key == 4)
	{
		GetList(counter,head);
	}

	if (key == 5)
	{
		printf("Enter the ID you want to search \n");
		scanf("%d",&id);
		flag = IsExist ( id) ;
		if (flag == 1)
		{
			printf("The ID exists \n");
		}
		else
		{
			printf("The ID does not exist \n") ;
		}
	}
	if (key == 6)
	{
		printf("The used size = %d\n",counter);
	}
	if (key == 7)
	{
		break ;
	}
	}
    return 0;
}
