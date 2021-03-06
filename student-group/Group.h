#pragma once
#include "Student.h"

class Group
{
private:
	Student* group;
	unsigned int group_size;
	char* group_name;
	char* group_spec;
	int group_num;

public:
	/*Конструкторы*/
	Group()
	{
		SetGroupName("SPU121");
		SetGroupSpec("Programming");
		SetGroupSize(4);
		SetGroupNum(1);
		group = new Student[group_size];
	}

	Group(unsigned int group_size) : Group("SPU121", "Programming", group_size, 1) { }

	Group(const Group& tmp)
	{
		group_name = new char[100];
		strcpy_s(group_name, 99, tmp.group_name);
		group_spec = new char[100];
		strcpy_s(group_spec, 99, tmp.group_spec);

		group_size = tmp.group_size;
		group_num = tmp.group_num;

		group = new Student[group_size];

		for (int i = 0; i < group_size; i++)
		{
			group[i].CopyStudentDataFrom(tmp.group[i]);
		}
	}

	Group(Student* studentarray, int size)
	{
		SetGroupName("SPU121");
		SetGroupSpec("Programming");
		SetGroupSize(size);
		SetGroupNum(1);
		group = studentarray;
	}

	Group(const char* group_name, const char* group_spec, unsigned int group_size, int group_num)
	{
		SetGroupName(group_name);
		SetGroupSpec(group_spec);
		SetGroupSize(group_size);
		SetGroupNum(group_num);
		group = new Student[group_size];
	}

	/*Деструктор*/
	~Group();

	/*Методы*/
	void ShowGroup() const;
	void AddStudent();
	void TransferStudent(Group& dest);
	void ExpellBadStudents();
	void ExpellWorstStudent();
	void MergeGroups(Group& tmp);
	void ChangeInfo();

	/*Операторы перегрузки*/
	Group& operator+=(const Student& newstudent);
	bool operator>(const Group& other);
	bool operator<(Group& other);
	bool operator==(const Group& other);
	bool operator!=(const Group& other);
	Group& operator=(const Group& other);
	friend ostream& operator<<(ostream& output, const Group& src);
	friend istream& operator>>(istream& input, Group& src);
	Group& operator() (const char* name);
	operator Student* ();

	/*SET-GET*/	
	void SetGroupSize(unsigned int group_size);
	void SetGroupName(const char* group_name);
	void SetGroupSpec(const char* group_spec);
	void SetGroupNum(int group_num);

	Student GetStudent(int index) const;
	unsigned int GetGroupSize() const;
	char* GetGroupName() const;
	char* GetGroupSpec() const;
	int GetGroupNum() const;
};


/*
Реализовать класс Group, который работает с массивом студентов (Student*).

Обязательные поля:
+ Указатель на массив студентов,
+ Количество человек в группе,
+ Название группы,
+ Специализация группы,
+ Номер курса.

Обязательные методы:
+ Конструктор по умолчанию (пустая группа),
+ Конструктор с одним параметром типа unsigned int
(задаётся произвольное количество студентов -
предусмотреть автоматическую генерацию фамилий,
имён, возрастов и других данных),
+ Конструктор с параметром типа Group
(создаётся точная копия группы).

Реализовать следующие методы:
+- Показ всех студентов группы
(сначала - название и специализация группы,
затем - порядковые номера, фамилии в алфавитном порядке
и имена студентов).
+ Добавления студента в группу,
+ Редактирования данных о группе,
+ Слияния двух групп,
+ Перевода студента из одной группы в другую,
+ Отчисления всех не сдавших (один любой) экзамен студентов,
+ Отчисления одного самого неуспевающего студента.
*/

/*
+ «+=» Student
+ «>»
+ «<» 
+ «==» 
+ «!=»
+ «>>»
+ «<<»
+ «( )»
+ «=»
+ «[ ]» (возврат студента по индексу)
+ предусмотреть конструктор преобразования из типа Student*
+ перегрузить операцию преобразования типа из Group в Student*.
*/