#include "Student.h"

Student::Student() :
	name_of_student("non"),
	id_of_student("0000"),
	gender('F'),
	age(0),
	num_of_course_for_student(0),
	list_of_course_for_student(nullptr)
{
	cout << "Student::d-ctor()" << endl;
}
Student::Student(string name_of_student, string id_of_student, char gender, int age)
{
	this->name_of_student = name_of_student;
	this->id_of_student = id_of_student;
	this->gender = gender;
	this->age = age;
	this->num_of_course_for_student = 0;
	this->list_of_course_for_student = NULL;
	cout << "Student::ctor" << endl;
}
Student::Student(const Student& sec)
{
	*this = sec;
	//this->name_of_student = sec.name_of_student;
	//this->id_of_student = sec.id_of_student;
	//this->gender = sec.gender;
	//this->age = sec.age;
	//this->num_of_course_for_student = sec.num_of_course_for_student;

	//if (this->num_of_course_for_student > 0)
	//{
	//	this->list_of_course_for_student = new Course * [num_of_course_for_student];
	//	for (int i = 0; i < num_of_course_for_student; i++)
	//	{
	//		this->list_of_course_for_student[i] = sec.list_of_course_for_student[i];
	//	}
	//}
	//else
	//{
	//	this->list_of_course_for_student = nullptr;
	//}

	cout << "Student::c-ctor" << endl;
}
Student::~Student()
{
	if (list_of_course_for_student)
	{
		delete[] list_of_course_for_student;
		cout << "Course** list_of_course_for_student; - delete!" << endl;
	}
	cout << "Student::d-tor" << endl;
}
string Student::get_name_of_student()
{
	return this->name_of_student;
}
string Student::get_id_of_student()
{
	return this->id_of_student;
}
char Student::get_gender()
{
	return this->gender;
}
int Student::get_age()
{
	return this->age;
}
void Student::set_name_of_student(string name_of_student)
{
	this->name_of_student = name_of_student;
}
void Student::set_id_of_student(string id_of_student)
{
	this->id_of_student = id_of_student;
}
void Student::set_gender(char gender)
{
	this->gender = gender;
}
void Student::set_age(int age)
{
	this->age = age;
}
Student& Student::operator = (const Student& obj)
{
	{
		this->name_of_student = obj.name_of_student;
		this->id_of_student = obj.id_of_student;
		this->gender = obj.gender;
		this->age = obj.age;
		this->num_of_course_for_student = obj.num_of_course_for_student;

		if (this->num_of_course_for_student > 0)
		{
			this->list_of_course_for_student = new Course * [num_of_course_for_student];
			for (int i = 0; i < num_of_course_for_student; i++)
			{
				this->list_of_course_for_student[i] = obj.list_of_course_for_student[i];
			}
		}
		else
		{
			this->list_of_course_for_student = nullptr;
		}
	}
	return *this;
}
bool Student::operator != (const Student& obj) const
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
bool Student::operator == (const Student& obj) const
{
	if (this->id_of_student == obj.id_of_student)
	{
		return true;
	}
	else
	{
		return false;
	}
}
istream& operator >> (istream& in, Student& obj)
{
	cout << "Enter student's name:" << endl;
	getline(in, obj.name_of_student);
	cout << "Enter student's id:" << endl;
	getline(in, obj.id_of_student);
	cout << "Enter student's gender: <F-female/M-male>" << endl;
	in >> obj.gender;
	while (obj.gender != 'F' && obj.gender != 'M')
	{
		cout << "Enter student's gender: <F-female/M-male>" << endl;
		in >> obj.gender;
	}
	cout << "Enter student's age:" << endl;
	in >> obj.age;
	while (obj.age < 1 || obj.age > 120)
	{
		cout << "Error! Enter student's age:" << endl;
		in >> obj.age;
	}
	return in;
}
ostream& operator << (ostream& out, const Student& obj)
{
	cout << "Name: ";
	out << obj.name_of_student << endl;
	cout << "ID: ";
	out << obj.id_of_student << endl;
	cout << "Gender: ";
	out << obj.gender << endl;
	cout << "Age: ";
	out << obj.age << endl;

	if (obj.num_of_course_for_student == 0)
	{
		cout << "The student is not regisrered to any courses." << endl;
	}
	else
	{
		cout << "There are " << obj.num_of_course_for_student << " courses to this student:" << endl;
		for (int i = 0; i < obj.num_of_course_for_student; i++)
		{
			cout << obj.list_of_course_for_student[i]->get_name_of_course() << endl;
		}
	}
	return out;
}
void Student::add_course(Course& course)
{
	Course** temp = new Course * [num_of_course_for_student + 1];
	int i;
	for (i = 0; i < num_of_course_for_student; i++)
	{
		temp[i] = list_of_course_for_student[i];
	}
	temp[i] = &course;
	if (list_of_course_for_student)
	{
		delete[] list_of_course_for_student;
	}
	list_of_course_for_student = temp;
	num_of_course_for_student++;
}
void Student::operator += (Course& course)
{
	Course** temp = new Course * [num_of_course_for_student + 1];
	int i;
	for (i = 0; i < num_of_course_for_student; i++)
	{
		temp[i] = list_of_course_for_student[i];
	}
	temp[i] = &course;
	if (list_of_course_for_student)
	{
		delete[] list_of_course_for_student;
	}
	list_of_course_for_student = temp;
	course.add_student(*this);

	num_of_course_for_student++;
}
