#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include"Students.h"

students *stud;
int randStud = 0;

void CreatName(char *a)
{
	char lName[10][30] = { "Reginald", "Woods","Montgomery","Campbell","Gardner","Wilson","Hawkins","Douglas","Martin","Jensen" };
	char name[10][5] = { "B.V.","C.K.","M.D.","C.V.","A.M.","O.P.","K.N.","I.Y.","G.F.","A.C." };

	int rnd = rand() % 9;
	strcat(a, lName[rnd]);
	strcat(a, " ");
	rnd = rand() % 9;
	strcat(a, name[rnd]);
}

void generateDate(dates *date)
{
	date->dd = 1 + rand() % 30;
	date->mm = 1 + rand() % 11;
	date->yy = 1980 + rand() % 20;
}

Gender genGender()
{
	return (Gender)(0 + rand() % 2);
}

void genSub(subject *sub)
{
	char subNum[5];
	strcpy(sub->nameS, "subject #");
	itoa(rand() % 30, subNum, 10);
	strcat(sub->nameS, subNum);

	sub->bal = rand() % 100;
}

void getCharDate(dates *date)
{
	printf("%2d.%2d.%4d",
		date->dd, date->mm, date->yy);
}

void getCharGender(Gender m)
{
	if (m == male)
		printf("Male");
	else
		printf("Female");
}

void printStud(students *stud)
{
	printf("%s - ", stud->name);

	getCharDate(&stud->date);
	printf(" - ");
	getCharGender(stud->gender);
	printf("\n");
}

students * genStud(int * randStud)
{
	char name[30];
	*randStud = 10 + rand() % 30;

	stud = (students*)calloc(*randStud, sizeof(students));

	if (stud != NULL)
	{
		for (int i = 0; i < *randStud; i++)
		{
			CreatName(stud[i].name);
			generateDate(&stud[i].date);
			stud[i].gender = genGender();
			for (int j = 0; j < 10; j++)
			{
				genSub(&stud[i].sub[j]);
			}
			//printStud(&stud[i]);
		}
	}

	return stud;
}