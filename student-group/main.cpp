#include <iostream>
#include "Student.h"
#include "Group.h"
using namespace std;

int main()
{
	srand(time(NULL));
	Group a;
	Group b;
	a.TransferStudent(b);
	cout << a;
}