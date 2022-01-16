#include <iostream>
#include "Student.h"
#include "Group.h"
using namespace std;

int main()
{
	Student a1("a", "b", "c");
	Student b2("1", "2", "3");

	a1.ShowStudent();
	b2.ShowStudent();

	a1.CopyStudentDataFrom(b2);

	cout << "sssssssssssssssssssssssssssssssssssssssssssssssss\n";
	cout << "sssssssssssssssssssssssssssssssssssssssssssssssss\n";

	a1.ShowStudent();
}