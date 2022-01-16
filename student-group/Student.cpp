#include "Student.h"

void Student::ShowStudent() const
{
	cout << "\n=============================================================";
	cout << "\nName: " << name;
	cout << "\nLast name: " << lastname;
	cout << "\nMiddle name: " << middlename;
	cout << endl;
	cout << "\nDate of birth: " << year << "." << month << "." << day;
	cout << endl;
	cout << "\nHome address: " << address;
	cout << "\nPhone number: " << phonenum;
	cout << endl << endl;

	cout << "Pass(" << pass_size << "): ";
	for (int i = 0; i < pass_size; i++)
		cout << pass[i] << " ";

	cout << endl;

	cout << "Course(" << course_size << "): ";
	for (int i = 0; i < course_size; i++)
		cout << course[i] << " ";

	cout << endl;

	cout << "Exam(" << exam_size << "): ";
	for (int i = 0; i < exam_size; i++)
		cout << exam[i] << " ";

	cout << "\n=============================================================\n\n";
}

void Student::ChangeRatingElement(int arr_type, int index, int value)
{
	switch (arr_type)
	{
	case 1:
	{
		SetPassElement(--index, value);
		break;
	}
	case 2:
	{
		SetCourseElement(--index, value);
		break;
	}
	case 3:
	{
		SetExamElement(--index, value);
		break;
	}
	}
}

void Student::CopyStudentDataFrom(const Student& src)
{
	SetFullName(src.GetName(), src.GetLastName(), src.GetMiddleName());
	SetDate(src.GetYear(), src.GetMonth(), src.GetDay());
	SetAddress(src.GetAddress());
	SetPhoneNum(src.GetPhoneNum());
	
	for (int i = 0; i < pass_size; i++)
		SetPassElement(i, src.GetPassElement(i));
	
	for (int i = 0; i < course_size; i++)
		SetCourseElement(i, src.GetCourseElement(i));
	
	for (int i = 0; i < exam_size; i++)
		SetExamElement(i, src.GetExamElement(i));
}

/*Деструктор*/
Student::~Student()
{
	if (name != nullptr) delete[] name;
	if (lastname != nullptr) delete[] lastname;
	if (middlename != nullptr) delete[] middlename;
	if (pass != nullptr) delete[] pass;
	if (course != nullptr) delete[] course;
	if (exam != nullptr) delete[] exam;
	if (address != nullptr) delete[] address;
	if (phonenum != nullptr) delete[] phonenum;
}

/*Сеттеры*/
void Student::SetFullName(const char* name, const char* lastname, const char* middlename)
{
	this->name = new char[100];
	this->lastname = new char[100];
	this->middlename = new char[100];
	strcpy_s(this->name, 99, name);
	strcpy_s(this->lastname, 99, lastname);
	strcpy_s(this->middlename, 99, middlename);
}
void Student::SetDate(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}

void Student::SetAddress(const char* address)
{
	this->address = new char[100];
	strcpy_s(this->address, 99, address);
}
void Student::SetPhoneNum(const char* phonenum)
{
	this->phonenum = new char[phonenum_size];
	strcpy_s(this->phonenum, phonenum_size, phonenum);
}

void Student::SetPassElement(int index, int value) { pass[index] = value; }
void Student::SetCourseElement(int index, int value) { course[index] = value; }
void Student::SetExamElement(int index, int value) { exam[index] = value; }

/*Геттеры*/
char* Student::GetName() const { return name; }
char* Student::GetLastName() const { return lastname; }
char* Student::GetMiddleName() const { return middlename; }

char* Student::GetAddress() const { return address; }
char* Student::GetPhoneNum() const { return phonenum; }

int Student::GetYear() const { return year; }
int Student::GetMonth() const { return month; }
int Student::GetDay() const { return day; }

int Student::GetPassSize() const { return pass_size; }
int Student::GetCourseSize() const { return course_size; }
int Student::GetExamSize() const { return exam_size; }
int Student::GetPassElement(int index) const { return pass[index]; }
int Student::GetCourseElement(int index) const { return course[index]; }
int Student::GetExamElement(int index) const { return exam[index]; }