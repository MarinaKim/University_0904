#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include<locale.h>
#include<stdint.h>
#include<string.h>
#include "StudentsSett.h"
#include "WorkWithStudent.h"

using namespace std;
int countStud;

void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	
	CreatFileOfStudents("stud.txt", "w");
	difGender("stud.txt", "r");
}
