#include <stdio.h>
#include <stdlib.h>

struct student
{
	int IDNO ;
	int year ;
	int grade[3];
	int course[3];
	struct student *next ;
	struct student *prev ;


};


/**global variables */
struct student *head  ;
struct student *tail ;
int grade [3];
int course[3];
int counter;
int key,i,id,year,flag ;

// prototypes

struct student *creatNode(void);
int addEntry (int id , int year,int *course , int *grade);
void Grades_CoursesEntry (void);
int IsFull(void);
int UsedSize(void);
void DeletEntry (int id);
int ReadEntry (int id);
void GetList (int counter , struct student *ptr);
int IsExist (int id);
void viewList (struct student *ptr );
