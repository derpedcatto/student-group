#include "Group.h"
#include <iostream>
using namespace std;

/*Добавить алфавитный перебор*/
void Group::ShowGroup() const
{
	cout << "Group name: " << group_name << endl;
	cout << "Specialization: " << group_spec << endl;
	cout << "Group num: " << group_num << endl;

	for (int i = 0; i < group_size; i++)
	{
		cout << "\n\nStudent " << i + 1;
		group[i].ShowStudent();
	}
}

void Group::ChangeInfo()
{
	int choice;
	cout << "\nWhat do you want to change?";
	cout << "\n1 - Name\n2 - Specialisation\n3 - Num/Index";
	cout << "\n-->";
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		char* name = new char[100];
		cout << "--> ";
		cin >> name;

		SetGroupName(name);

		delete[] name;
		break;
	}
	case 2:
	{
		char* name = new char[100];
		cout << "--> ";
		cin >> name;

		SetGroupSpec(name);

		delete[] name;
		break;
	}
	case 3:
	{
		cout << "--> ";
		cin >> group_num;
	}
	}
}

/*Деструктор*/
Group::~Group()
{
	if (group_name != nullptr) delete[] group_name;
	if (group_spec != nullptr) delete[] group_spec;
	if (group != nullptr) delete[] group;
}

/*Сеттеры*/
void Group::SetGroupSize(unsigned int group_size)
{
	this->group_size = group_size;
}
void Group::SetGroupName(const char* group_name)
{
	this->group_name = new char[100];
	strcpy_s(this->group_name, 99, group_name);
}
void Group::SetGroupSpec(const char* group_spec)
{
	this->group_spec = new char[100];
	strcpy_s(this->group_spec, 99, group_spec);
}
void Group::SetGroupNum(int group_num)
{
	this->group_num = group_num;
}

/*Геттеры*/
Student Group::GetStudent(int index) const { return group[index]; }
unsigned int Group::GetGroupSize() const { return group_size; }
char* Group::GetGroupName() const { return group_name; }
char* Group::GetGroupSpec() const { return group_spec; }
int Group::GetGroupNum() const { return group_num; }