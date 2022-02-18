#pragma once
#include "Student.h"
#include <iostream>
using namespace std;

class Aspirant : public Student
{
private:
	char* phdwork;

public:
	/*CONSTRUCTORS*/
	Aspirant();

	/*METHODS*/
	void ShowStudent() const;

	/*DEST-SET-GET*/
	~Aspirant();
	void SetPHDWork(const char* phdwork);
	char* GetPHDWork() const;
};