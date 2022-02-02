#include <iostream>
#include "Student.h"
#include "Group.h"
using namespace std;

int main()
{
	srand(time(NULL));
	Student* b = new Student[3];

	Group a(b, 3);
	a.ShowGroup();
}