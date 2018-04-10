struct dates
{
	int dd;
	int mm;
	int yy;
};

enum Gender
{
	male = 0,
	female = 1
};

struct subject
{
	char nameS[50];
	unsigned short int bal;
};

struct students
{
	char name[20];
	dates date;
	Gender gender;
	subject sub[10];
};