#include <iostream>
#include "Student.h"
#include "Group.h"
using namespace std;

int main()
{
	srand(time(NULL));
	Group a(1);
	Group b(2);

	a.ShowGroup();
	
	cout << "bbbbbbbbbbbbbbb\n\n\n\n\n\n\n\n\n";
	
	b.ShowGroup();
	
	a.MergeGroups(b);
	
	cout << "\n\n\n\n\n\n\n\n\n";
	
	a.ShowGroup();
}