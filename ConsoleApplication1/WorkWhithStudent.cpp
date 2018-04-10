#include<stdlib.h>
#include<stdio.h>

#include "StudentsSett.h"


FILE *file;
void getCharDateFile(dates *date)
{
	fprintf(file, "%2d.%2d.%4d",
		date->dd, date->mm, date->yy);
}

void getCharGenderFile(Gender m)
{
	if (m == male)
		fprintf(file, "Male");
	else
		fprintf(file, "Female");
}

void CreatFileOfStudents(char *fileName, char *mode)
{
	int countStud = 0;
	int minY = 2018, minM = 12, minD = 30;
	students * std = genStud(&countStud);

	if ((file = fopen(fileName, mode)) != NULL)
	{
		fprintf(file, "Count of students: %d\n", countStud);
		for (size_t i = 0; i < countStud; i++)
		{
			fprintf(file, "%s   ", std[i].name);
			getCharDateFile(&std[i].date);
			fprintf(file, "  ");
			getCharGenderFile(std[i].gender);
			fprintf(file, "\n");
		}
		for (size_t i = 0; i < countStud; i++)
		{
			if (std[i].gender == male)
			{
				if ((std[i].date.yy) < minY)
				{
					minY = std[i].date.yy;
					if ((std[i].date.mm) < minM)
					{
						minM = std[i].date.mm;
						if ((std[i].date.dd) < minD)
						{
							minD = std[i].date.dd;
						}
					}
				}
			}

		}
		fprintf(stdout, "Самый молодой студетн: %s  ", std->name);
		getCharDate(&std->date);
		fprintf(stdout, "/n");


		for (size_t i = 0; i < countStud; i++)
		{
			if (std[i].gender == female)
			{
				if ((std[i].date.yy) < minY)
				{
					minY = std[i].date.yy;
					if ((std[i].date.mm) < minM)
					{
						minM = std[i].date.mm;
						if ((std[i].date.dd) < minD)
						{
							minD = std[i].date.dd;
						}
					}
				}
			}
		}
		fprintf(stdout, "Самая молодая студетнка : %s  ", std->name);
		getCharDate(&std->date);
		fprintf(stdout, "/n");
	}
		fclose(file);
	}

	