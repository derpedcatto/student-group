#include "Group.h"

/*???*/
// AddStudent
// Operator Student* ()


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

void Group::AddStudent()
{
	Student tmp;
	group.push_back(tmp);
}	

void Group::TransferStudent(Group& dest) //destination
{
	int choice;
	do
	{
		printf("Enter student number(1-%d): ", group_size);
		cin >> choice;

	} while (choice < 1 || choice > group_size);

	choice--;	//для обращения с массивом

	group.push_back(dest.group[choice]);
	dest.group.pop_back();
}

void Group::ExpellBadStudents()
{
	bool copyStudents = true;
	int min_mark = 4;
	int exp_count = 0;

	/*индексация неуспевающих студентов*/
	/*0 - ОК, 1 - Отчисление*/
	int* expell = new int[group_size];
	for (int i = 0; i < group_size; i++)
	{
		expell[i] = 0;
	}

	for (int i = 0; i < group_size; i++)
	{
		bool Expell = false;
		for (int j = 0; j < group[i].GetPassSize(); j++)
		{
			if (group[i].GetPassElement(j) < min_mark)
			{
				Expell = true;
				exp_count++;
				expell[i] = 1;
				break;
			}
		}

		if (Expell)
			continue;

		for (int j = 0; j < group[i].GetCourseSize(); j++)
		{
			if (group[i].GetCourseElement(j) < min_mark)
			{
				Expell = true;
				exp_count++;
				expell[i] = 1;
				break;
			}
		}

		if (Expell)
			continue;

		for (int j = 0; j < group[i].GetExamSize(); j++)
		{
			if (group[i].GetExamElement(j) < min_mark)
			{
				Expell = true;
				exp_count++;
				expell[i] = 1;
				break;
			}
		}
	}
  
  	/*Если все студенты отчислены*/
  	if (exp_count == group_size)
  {
  	cout << "All students are expelled! Adding one student to group...";
  	group_size = 1;
  	Student tmp;
  	group.clear();
  	group.push_back(tmp);
  }
  	else
	{
		group_size -= exp_count;
	}

	int count = 0;
	if (copyStudents)
	{
		for (int i = 0; i < group_size + exp_count; i++)
		{
			if (expell[i] == 0)
			{
				group[count].CopyStudentDataFrom(group[i]);
				count++;
			}
		}
	}
}

void Group::ExpellWorstStudent()
{
	double* expell = new double[group_size];

	for (int i = 0; i < group_size; i++)
	{
		double markPass = 0;
		double markCourse = 0;
		double markExam = 0;

		for (int j = 0; j < group[i].GetPassSize(); j++)
		{
			markPass += group[i].GetPassElement(j);
		}
		for (int j = 0; j < group[i].GetCourseSize(); j++)
		{
			markCourse += group[i].GetCourseElement(j);
		}
		for (int j = 0; j < group[i].GetExamSize(); j++)
		{
			markExam += group[i].GetExamElement(j);
		}

		markPass /= group[i].GetPassSize();
		markCourse /= group[i].GetCourseSize();
		markExam /= group[i].GetExamSize();

		expell[i] = (markPass + markCourse + markExam) / 3;

		printf("Student %d average: %0.1f\n", i + 1, expell[i]);
	}

		int lowest = 0;
		for (int i = 0; i < group_size - 1; i++)
	{
		if (expell[lowest] > expell[i + 1])
		{
			lowest = i + 1;
		}
	}

	cout << "\n\nLowest: " << lowest + 1;

	//group_size--;
	//group.erase(group.begin() + lowest);
}

void Group::MergeGroups(Group& tmp)
{
	group.resize(group_size + tmp.GetGroupSize());

	int count = group_size;
	for (int i = 0; i < tmp.GetGroupSize(); i++)
	{
		group[count].CopyStudentDataFrom(tmp.group[i]);
		count++;
	}

	group_size += tmp.GetGroupSize();
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
}

/*Операторы перегрузки*/

Group& Group::operator+=(const Student& newstudent)
{
	AddStudent();
	group[group_size - 1].CopyStudentDataFrom(newstudent);
	return *this;
}
bool Group::operator>(const Group& other)
{
	if (group_size > other.group_size)
		return true;
	else
		return false;
}
bool Group::operator<(Group& other)
{
	return other > *this;
}
bool Group::operator==(const Group& other)
{
	if (group_size == other.group_size)
		return true;
	else
		return false;
}
bool Group::operator!=(const Group& other)
{
	return !(*this == other);
}
Group& Group::operator=(const Group& other)
{
	SetGroupName(other.group_name);
	SetGroupSpec(other.group_spec);

	group_size = other.group_size;
	group_num = other.group_num;

	group = other.group;
	return *this;
}

ostream& operator<<(ostream& output, const Group& src)
{
	src.ShowGroup();
	return output;
}
istream& operator>>(istream& input, Group& src)
{
	char* name = new char[50];
	input >> name;

	src.SetGroupName(name);

	delete[] name;
	name = nullptr;

	return input;
}

Group& Group::operator() (const char* name)
{
	SetGroupName(name);
	return *this;
}


//Group::operator Student* ()
//{
//	return group;
//}

/*Сеттеры*/
void Group::SetGroupSize(unsigned int group_size)
{
	this->group_size = group_size;
}
void Group::SetGroupName(const char* group_name)
{
	delete[] this->group_name;
	this->group_name = new char[100];
	strcpy_s(this->group_name, 99, group_name);
}
void Group::SetGroupSpec(const char* group_spec)
{
	delete[] this->group_spec;
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