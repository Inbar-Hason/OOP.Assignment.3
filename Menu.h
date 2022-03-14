#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include "Course.h"
#include "Student.h"

using namespace std;

class Course;
class Student;

class Menu
{
private:
	Course** list_of_course;
	int num_of_course;
	Student** list_of_student;
	int num_of_student;
public:
	Menu();
	~Menu();
	void Run();
	int find_course(int number);
	void add_course();
	int find_student(string id);
	void add_student();
	void print_course();
	void print_student();
	void register_student_to_course();
	void grade_student_in_course(); 
};
