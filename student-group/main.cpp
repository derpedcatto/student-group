#include <iostream>
#include "Student.h"
#include "Group.h"
using namespace std;

int main()
{
	srand(time(NULL));
	Group a(5);

	a.ShowGroup();
}