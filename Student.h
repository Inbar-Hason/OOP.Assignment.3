#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include "Course.h"
#include "Menu.h"

using namespace std;

class Course;
class Menu;

class Student
{
private:
	string name_of_student;
	string id_of_student;
	char gender;
	int age;
	int num_of_course_for_student;
	Course** list_of_course_for_student;
public:
	Student();
	Student(string name_of_student, string id_of_student, char gender, int age);
	Student(const Student& sec);
	~Student();
	string get_name_of_student();
	string get_id_of_student();
	char get_gender();
	int get_age();
	void set_name_of_student(string name_of_student);
	void set_id_of_student(string id_of_student);
	void set_gender(char gender);
	void set_age(int age);
	Student& operator = (const Student& obj);
	bool operator != (const Student& obj) const;
	bool operator == (const Student& obj) const;
	void operator += (Course& course);
	friend istream& operator >> (istream& in, Student& obj);
	friend ostream& operator << (ostream& out, const Student& obj);
	void add_course(Course& course);
};
