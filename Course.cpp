#include "Course.h"

Course::Course() :
	name_of_course("non"),
	num_of_course(0),
	num_of_student(0),
	list_of_students_for_course(nullptr),
	grades_of_students_for_course(nullptr)
{
	cout << "Course::d-ctor" << endl;
}
Course::Course(string name_of_course, int num_of_course)
{
	this->name_of_course = name_of_course;
	this->num_of_course = num_of_course;
	this->num_of_student = 0;
	this->list_of_students_for_course = nullptr;
	this->grades_of_students_for_course = nullptr;
	{
		cout << "Course::ctor" << endl;
	}
}
Course::Course(const Course& sec)
{
	*this = sec;
	//this->name_of_course = sec.name_of_course;
	//this->num_of_course = sec.num_of_course;
	//this->num_of_student = sec.num_of_student;
	//if (num_of_student > 0)
	//{
	//	this->list_of_students_for_course = new Student * [num_of_student];
	//	this->grades_of_students_for_course = new int[num_of_student];
	//	for (int i = 0; i < num_of_student; i++)
	//	{
	//		list_of_students_for_course[i] = sec.list_of_students_for_course[i];
	//		grades_of_students_for_course[i] = sec.grades_of_students_for_course[i];
	//	}
	//}
	//else
	//{
	//	list_of_students_for_course = nullptr;
	//	grades_of_students_for_course = nullptr;
	//}
	cout << "Course::c-ctor" << endl;
}
Course::~Course()
{
	if (list_of_students_for_course)
	{
		delete[] list_of_students_for_course;
		cout << "Student** list_of_students_for_course; - delete! " << endl;
	}
	if (grades_of_students_for_course)
	{
		delete[] grades_of_students_for_course;
		cout << "int* grades_of_students_for_course; - delete!" << endl;
	}
	cout << "Course::dtor" << endl;
}
string Course::get_name_of_course() const
{
	return this->name_of_course;
}
int Course::get_num_of_course() const
{
	return this->num_of_course;
}
int Course::get_num_of_student() const
{
	return this->num_of_student;
}
void Course::set_name_of_course(string name_of_course)
{
	this->name_of_course = name_of_course;
}
void Course::set_num_of_course(int num_of_course)
{
	this->num_of_course = num_of_course;
}
void Course::set_num_of_student(int num_of_student)
{
	this->num_of_student = num_of_student;
}
Course& Course::operator = (const Course& obj)
{

	if (this != &obj)
	{
		name_of_course = obj.name_of_course;
		num_of_course = obj.num_of_course;
		num_of_student = obj.num_of_student;

		if (list_of_students_for_course != nullptr)
		{
			delete[] list_of_students_for_course;
			delete[] grades_of_students_for_course;
		}
		if (num_of_student > 0)
		{
			list_of_students_for_course = new Student * [num_of_student];
			grades_of_students_for_course = new int[num_of_student];
			for (int i = 0; i < num_of_student; i++)
			{
				list_of_students_for_course[i] = obj.list_of_students_for_course[i];
				grades_of_students_for_course[i] = obj.grades_of_students_for_course[i];
			}
		}
		else
		{
			list_of_students_for_course = nullptr;
			grades_of_students_for_course = nullptr;
		}
	}
	return *this;
}
bool Course::operator != (const Course& obj) const
{
	if (*this == obj)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool Course::operator == (const Course& obj) const
{
	if (this->num_of_course == obj.num_of_course)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Course::operator += (Student& student)
{
	Student** temp = new Student * [num_of_student + 1];
	int i;
	for (i = 0; i < num_of_student; i++)
	{
		temp[i] = list_of_students_for_course[i];
	}
	temp[i] = &student;
	if (list_of_students_for_course)
	{
		delete[] list_of_students_for_course;
	}
	list_of_students_for_course = temp;
	student.add_course(*this);
	int* temp2 = new int[num_of_student + 1];
	for (i = 0; i < num_of_student; i++)
	{
		temp2[i] = grades_of_students_for_course[i];
	}
	temp2[i] = 0;
	if (grades_of_students_for_course)
	{
		delete[] grades_of_students_for_course;
	}
	grades_of_students_for_course = temp2;
	num_of_student++;
}
istream& operator >> (istream& in, Course& obj)
{
	cout << "Enter course's name: " << endl;
	getline(in, obj.name_of_course);
	cout << "Enter course's id:" << endl;
	in >> obj.num_of_course;
	return in;
}
ostream& operator << (ostream& out, const Course& obj)
{
	cout << "Course name: ";
	out << obj.name_of_course;
	cout << endl;
	cout << "Course ID: ";
	out << obj.num_of_course;
	cout << endl;
	cout << "Number of students in course: ";
	out << obj.num_of_student;
	cout << endl;
	if (obj.num_of_student == 0)
	{
		cout << "No students in this course." << endl;
	}
	else
	{
		cout << "There are " << obj.num_of_student << " students in this course:" << endl;
		for (int i = 0; i < obj.num_of_student ; i++)
		{
			cout << obj.list_of_students_for_course[i]->get_name_of_student() << endl;
			cout << obj.grades_of_students_for_course[i] << endl;
		}
	}
	return out;
}
void Course::add_student(Student& student)
{
	Student** temp = new Student * [num_of_student + 1];
	int i;
	for (i = 0; i < num_of_student; i++)
	{
		temp[i] = list_of_students_for_course[i];
	}
	temp[i] = &student;
	if (list_of_students_for_course)
	{
		delete[] list_of_students_for_course;
	}
	list_of_students_for_course = temp;
	num_of_student++;
}
int Course::find_student_in_course(string id)
{
	bool flag = false; 
	int i = 0;
	for (i; i < num_of_student; i++)
	{
		if (list_of_students_for_course[i]->get_id_of_student() == id)
		{
			flag = true;
			break;
		}
	}
	if (flag == true)
	{
		return i;
	}
	else
	{
		return -1;
	}
}
void Course::grade(int index)
{
	cout << "Enter the garde:" << endl;
	int garde;
	cin >> garde;
	grades_of_students_for_course[index] = garde;
}
