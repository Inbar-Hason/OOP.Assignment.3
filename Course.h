#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include "Student.h"
#include "Menu.h"

using namespace std;

class Student;
class Menu;

class Course
{
private:
	string name_of_course;
	int num_of_course;
	int num_of_student;
	Student** list_of_students_for_course;
	int* grades_of_students_for_course;
public:
	Course();
	Course(string name_of_course, int num_of_course);
	Course(const Course& sec);
	~Course();
	string get_name_of_course() const;
	int get_num_of_course() const;
	int get_num_of_student() const;
	void set_name_of_course(string name_of_course);
	void set_num_of_course(int num_of_course);
	void set_num_of_student(int num_of_student);
	Course& operator = (const Course& obj);
	bool operator != (const Course& obj) const;
	bool operator == (const Course& obj) const;
	void operator += (Student& student);
	friend istream& operator >> (istream& in, Course& obj);
	friend ostream& operator << (ostream& out, const Course& obj);
	void add_student(Student& student);
	int find_student_in_course(string id);
	void grade(int index);
};


