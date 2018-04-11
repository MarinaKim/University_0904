#include<stdlib.h>
#include<stdio.h>

#include "StudentsSett.h"
#include"WorkWithStudent.h"

int countStud;
FILE *file;
void getCharDateFile(dates *date)
{
	fprintf(file, "%2d.%2d.%4d\n",
		date->dd, date->mm, date->yy);
}

void getCharGenderFile(Gender m)
{
	if (m == male)
		fprintf(file, "Male\n");
	else
		fprintf(file, "Female\n");
}

void CreatFileOfStudents(char *fileName, char *mode)
{

	int minY = 2018, minM = 12, minD = 30;
	students * std = genStud(&countStud);

	if ((file = fopen(fileName, mode)) != NULL)
	{
		printf("Count of students: %d\n", countStud);
		for (size_t i = 0; i < countStud; i++)
		{
			fprintf(file, "%s\n", std[i].name);
			fprintf(file, "%d\n", std[i].date.dd);
			fprintf(file, "%d\n", std[i].date.mm);
			fprintf(file, "%d\n", std[i].date.yy);
			/*getCharDateFile(&std[i].date);*/
			/*fprintf(file, "  ");*/
			getCharGenderFile(std[i].gender);
			/*fprintf(file, "\n");*/

			for (int j = 0; j < 10; j++)
			{
				fprintf(file, "%s ", std[i].sub[j].nameS);
				if (i == countStud - 1 && j == 10 - 1)
					fprintf(file, "%d", std[i].sub[j].bal);
				else
					fprintf(file, "%d\n", std[i].sub[j].bal);
			}
		}
	}
	fclose(file);
}
void setCharDateRead(dates *date)
{
	scanf("%2d.%2d.%4d", date->dd, date->mm, date->yy);
}
void difGender(char *fileName, char *mode)
{
	int i = 0;
	char g[8];
	students *stud = (students*)malloc(countStud * sizeof(students));
	if (stud != NULL)
	{
		if ((file = fopen(fileName, mode)) != NULL)
		{
			printf("Students:\n");
			while (feof(file) == 0)
			{
				if (i > 0)
					fgetc(file);
				fgets(stud[i].name, 20, file);
				printf("%s", stud[i].name);
				///*setCharDateRead(&stud[i].date);*/
				//fgets(stud[i].date.dd, 5, file);
				fscanf(file, "%d", &stud[i].date.dd);
				fscanf(file, "%d", &stud[i].date.mm);
				fscanf(file, "%d", &stud[i].date.yy);
				printf("%2d.%2d.%4d\n", stud[i].date.dd, stud[i].date.mm, stud[i].date.yy);
				fgetc(file);
				fgets(g, 8, file);
				/*fgets(stud[i].gender, 10, file);*/
				/*fscanf(file, "%s", &g);*/

				if (g == "Male\n")
				{
					stud[i].gender = male;
					printf("Male\n");
				}
				else if (g == "Female\n")
				{
					stud[i].gender = female;					
					printf("Female\n");
				}
				for (int j = 0; j < 10; j++)
				{
					fscanf(file, "%s", &stud[i].sub[j].nameS);
					/*fgets(stud[i].sub[j].nameS, 20, file);*/
					fscanf(file, "%d", &stud[i].sub[j].bal);
					printf("%s-%d\n", stud[i].sub[j].nameS, stud[i].sub[j].bal);
				}
				i++;
			}
		}
		fclose(file);
		/*olderStud(stud, countStud, male);
		olderStud(stud, countStud, female);*/
	}
}

void olderStud(students *stud, int countStud, Gender gender)
{
	int maxY = 2080, maxM = 12, maxD = 30;
	int ind;
	if (gender == male)
	{
		for (int i = 0; i < countStud; i++)
		{
			if (stud[i].date.yy < maxY)
				maxY = stud[i].date.yy;
		}
		for (int i = 0; i < countStud; i++)
		{
			if (stud[i].date.yy == maxY && stud[i].date.mm < maxM)
				maxM = stud[i].date.mm;
		}
		for (int i = 0; i < countStud; i++)
		{
			if (stud[i].date.yy == maxY && stud[i].date.mm == maxM&&stud[i].date.dd < maxD)
			{
				maxD = stud[i].date.dd;
				ind = i;
			}
		}
		printf(" Самый взрослый студент: %s %2d.%2d.%4d\n", stud[ind].name, stud[ind].date.dd, stud[ind].date.mm, stud[ind].date.yy);
	}
	else
	{
		for (int i = 0; i < countStud; i++)
		{
			if (stud[i].date.yy < maxY)
				maxY = stud[i].date.yy;
		}
		for (int i = 0; i < countStud; i++)
		{
			if (stud[i].date.yy == maxY && stud[i].date.mm < maxM)
				maxM = stud[i].date.mm;
		}
		for (int i = 0; i < countStud; i++)
		{
			if (stud[i].date.yy == maxY && stud[i].date.mm == maxM&&stud[i].date.dd < maxD)
			{
				maxD = stud[i].date.dd;
				ind = i;
			}
		}
		printf(" Самый взрослая студентка: %s %2d.%2d.%4d\n", stud[ind].name, stud[ind].date.dd, stud[ind].date.mm, stud[ind].date.yy);
	}


}
