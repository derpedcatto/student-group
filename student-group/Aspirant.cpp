#include "Aspirant.h"

/*CONSTRUCTORS*/
Aspirant::Aspirant()
{
	SetPHDWork("OOP");
}

/*METHODS*/
void Aspirant::ShowStudent() const
{
	cout << "\n=============================================================";
	cout << "\nName: " << GetName();
	cout << "\nLast name: " << GetLastName();
	cout << "\nMiddle name: " << GetMiddleName();
	cout << endl;
	cout << "\nDate of birth: " << GetYear() << "." << GetMonth() << "." << GetDay();
	cout << endl;
	cout << "\nHome address: " << GetAddress();
	cout << "\nPhone number: " << GetPhoneNum();
	cout << endl << endl;

	cout << "\nPHD Work: " << GetPHDWork() << "\n\n";

	cout << "Pass(" << GetPassSize() << "): ";
	for (int i = 0; i < GetPassSize(); i++)
		cout << GetPassElement(i) << " ";

	cout << endl;

	cout << "Course(" << GetCourseSize() << "): ";
	for (int i = 0; i < GetCourseSize(); i++)
		cout << GetCourseElement(i) << " ";

	cout << endl;

	cout << "Exam(" << GetExamSize() << "): ";
	for (int i = 0; i < GetExamSize(); i++)
		cout << GetExamElement(i) << " ";

	cout << "\n=============================================================\n\n";
}

/*DEST-SET-GET*/
Aspirant::~Aspirant()
{
	if (phdwork != nullptr) { delete[] phdwork; }
}
void Aspirant::SetPHDWork(const char* phdwork)
{
	this->phdwork = new char[100];
	strcpy_s(this->phdwork, 99, phdwork);
}
char* Aspirant::GetPHDWork() const
{
	return phdwork;
}