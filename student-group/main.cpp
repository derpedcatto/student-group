#include <iostream>
#include "Student.h"
#include "Group.h"
using namespace std;

int main()
{
	srand(time(NULL));
	Group a(4);

	a.ShowGroup();
	a.ExpellWorstStudent();
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	a.ShowGroup();
}