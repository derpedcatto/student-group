#pragma once
#include <iostream>
using namespace std;

class Student
{
private:
	const int phonenum_size = 13; //учитывая нуль-деструктор

	char* name;
	char* lastname;
	char* middlename;

	int year;
	int month;
	int day;

	char* address;
	char* phonenum;

	int pass_size = 6;
	int course_size = 5;
	int exam_size = 4;
	int* pass;
	int* course;
	int* exam;

public:
	/*Конструкторы*/
	Student() : Student("Alexander", "Vannovskiy", "Alexandrovich", 27, 12, 2002, "Chornomorskaya 46", "380980461387") { }

	Student(const char* name, const char* lastname, const char* middlename)
		: Student(name, lastname, middlename, 27, 12, 2002, "Chornomorskaya 46", "380980461387") { }

	Student(const char* name, const char* lastname, const char* middlename, int year, int month, int day)
		: Student(name, lastname, middlename, year, month, day, "Chornomorskaya 46", "380980461387") { }

	Student(const char* name, const char* lastname, const char* middlename,
		int year, int month, int day, const char* address, const char* phonenum)
	{
		SetFullName(name, lastname, middlename);
		SetDate(year, month, day);
		SetAddress(address);
		SetPhoneNum(phonenum);

		pass = new int[pass_size];
		course = new int[course_size];
		exam = new int[exam_size];

		for (int i = 0; i < pass_size; i++)
			pass[i] = 1 + rand() % 11;
		for (int i = 0; i < course_size; i++)
			course[i] = 1 + rand() % 11;
		for (int i = 0; i < exam_size; i++)
			exam[i] = 1 + rand() % 11;
	}

	/*Методы*/
	void ShowStudent() const;
	void ChangeRatingElement(int arr_type, int index, int value);
	void CopyStudentDataFrom(const Student& tmp);

	/*Деструктор*/
	~Student();

	/*Сеттеры*/
	void SetFullName(const char* name, const char* lastname, const char* middlename);
	void SetDate(int year, int month, int day);

	void SetAddress(const char* address);
	void SetPhoneNum(const char* phonenum);

	void SetPassElement(int index, int value);
	void SetCourseElement(int index, int value);
	void SetExamElement(int index, int value);

	/*Геттеры*/
	char* GetName() const;
	char* GetLastName() const;
	char* GetMiddleName() const;

	char* GetAddress() const;
	char* GetPhoneNum() const;

	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;

	int GetPassSize() const;
	int GetCourseSize() const;
	int GetExamSize() const;
	int GetPassElement(int index) const;
	int GetCourseElement(int index) const;
	int GetExamElement(int index) const;
};


/*
Реализовать класс Student, который содержит поля:
имени,
фамилии,
отчества,
даты рождения,
домашнего адреса,
телефонного номера.

Также за каждым студентом закреплены 3 динамических массива оценок –
зачёты,
курсовые работы,
экзамены.

Обязательные методы:
2 - 3 версии конструктора с параметрами,
геттеры и сеттеры для всех полей,
показ всех данных о студенте.
*/