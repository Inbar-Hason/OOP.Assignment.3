#include "Menu.h"

Menu::Menu() :
	list_of_course(nullptr),
	num_of_course(0),
	list_of_student(nullptr),
	num_of_student(0)
{
	cout << "Menu::d-ctor" << endl;
}
Menu::~Menu()
{
	if (list_of_course)
	{
		for (int i = 0; i < num_of_course; i++)
		{
			delete list_of_course[i];
		}
		delete[] list_of_course;
	}
	if (list_of_student)
	{
		for (int i = 0; i < num_of_student; i++)
		{
			delete list_of_student[i];
		}
		delete[] list_of_student;
	}
	cout << "Menu::dtor" << endl;
}
void Menu::Run() 
{
	int choice;
	while (1) 
	{
		fflush(stdin);
		cout << "*************************************************************************\n";
		cout << "*************************************************************************\n";
		cout << "*************************************************************************\n";
		cout << "Welcome to Softtware Engineering Depatment\n";
		cout << "What would you like to do?\n";
		cout << "*************************************************************************\n";
		cout << "[1] - Add a new course to the Depatment.\n";
		cout << "[2] - Add a new student to the Depatment.\n";
		cout << "[3] - Register a student to a course.\n";
		cout << "[4] - Grade for a student in the course.\n";
		cout << "[5] - Print a course's information.\n";
		cout << "[6] - Print a student's information.\n";
		cout << "[7] - Exit.\n";

		cout << "*************************************************************************\n";
		cin >> choice;

		switch (choice) {
		case 1:
			add_course();
			break;
		case 2:
			add_student();
			break;
		case 3:
			register_student_to_course();
			break;
		case 4:
			grade_student_in_course();
			break;
		case 5:
			print_course();
			break;
		case 6:
			print_student();
			break;
		case 7:
			cout << "Thank you, goodbye.";
			return;
		default:
			cout << "No such option , sorry. Choose again please.\n";
			break;
		}
	}
}
int Menu::find_course(int number)
{
	bool flag = false; 
	int i = 0;
	for (i; i < num_of_course; i++)
	{
		if (list_of_course[i]->get_num_of_course() == number)
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
void Menu::add_course()
{
	if (num_of_course == 0) 
	{
		list_of_course = new Course * [1];
		cout << "Enter the number of new course:" << endl;
		int number_course;
		cin >> number_course;
		cout << "Enter the name of new course:" << endl;
		string name_course;
		cin.ignore();
		getline(cin, name_course);

		list_of_course[0] = new Course(name_course, number_course);
		num_of_course++;
	}
	else
	{
		cout << "Enter the number of new course:" << endl;
		int number_course;
		cin >> number_course;
		int temp = find_course(number_course);
		if (temp == -1) 
		{
			cout << "Enter the name for a new course:" << endl;
			string name_course;
			getline(cin, name_course);
			Course* new_course = new Course(name_course, number_course);
			Course** temp = new Course* [num_of_course + 1];
			int i = 0;
			for ( i ; i < num_of_course; i++)
			{
				temp[i] = list_of_course[i];
			}
			temp[i] = new_course;
			if (list_of_course)
			{
				delete[] list_of_course;
			}
			list_of_course = temp;
			num_of_course++;
		}
		else
			cout << "The Course is already exists!" << endl;
	}
}
int Menu::find_student(string id) 
{
	bool flag = false;
	int i = 0;
	for (i; i < num_of_student; i++)
	{
		if (list_of_student[i]->get_id_of_student() == id)
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
void Menu::add_student()
{
	if (num_of_student == 0)
	{
		list_of_student = new Student * [1];
		cout << "Enter the id for a new student:" << endl;
		string id_student;
		cin.ignore();
		getline(cin, id_student);
		cout << "Enter the name for a new student:" << endl;
		string name_student;
		cin.ignore();
		getline(cin, name_student);
		cout << "Enter student's gender: <F-female/M-male>" << endl;
		char gender;
		cin >> gender;
		while (gender != 'F' && gender != 'M')
		{
			cout << "Enter student's gender: <F-female/M-male>" << endl;
			cin >> gender;
		}
		cout << "Enter student's age:" << endl;
		int age;
		cin >> age;
		while (age < 1 || age > 120)
		{
			cout << "Error! Enter student's age:" << endl;
			cin >> age;
		}
		list_of_student[0] = new Student(name_student,id_student,gender,age);
		num_of_student++;
	}
	else 
	{
		cout << "Enter the id for a new student:" << endl;
		string id_student;
		cin.ignore();
		int temp = find_student(id_student);
		if (temp == -1) 
		{
			cout << "Enter the name for a new student:" << endl;
			string name_student;
			cin.ignore();
			getline(cin, name_student);
			cout << "Enter student's gender: <F-female/M-male>" << endl;
			char gender;
			cin >> gender;
			while (gender != 'F' && gender != 'M')
			{
				cout << "Enter student's gender: <F-female/M-male>" << endl;
				cin >> gender;
			}
			cout << "Enter student's age:" << endl;
			int age;
			cin >> age;
			while (age < 1 || age > 120)
			{
				cout << "Error! Enter student's age:" << endl;
				cin >> age;
			}
			Student* new_Student = new Student(name_student,id_student,gender,age);
			Student** temp = new Student * [num_of_student + 1];
			int i = 0;
			for ( i ; i < num_of_student; i++)
			{
				temp[i] = list_of_student[i];
			}
			temp[i] = new_Student;
			if (list_of_student)
			{
				delete[] list_of_student;
			}
			list_of_student = temp;
			num_of_student++;
		}
		else
			cout << "The Student is already exists!" << endl;
	}
}
void Menu::print_course() 
{
	if (num_of_course == 0)
	{
		cout << "There is no courses!" << endl;
		return;
	}
	cout << "Enter the code for the course:" << endl;
	int number_course;
	cin >> number_course;
	int temp = find_course(number_course);
	if (temp == -1) 
	{
		cout << "Course does not exist." << endl;
	}
	else
	{
		cout << *list_of_course[temp];
	}
}
void Menu::print_student() 
{
	if (num_of_student == 0)
	{
		cout << "There is no students!" << endl;
		return;
	}
	cout << "Enter the id for the student:" << endl;
	string id;
	cin >> id;
	int temp = find_student(id);
	if (temp == -1) 
	{
		cout << "Student does not exist." << endl;
	}
	else
	{
		cout << *list_of_student[temp];
	}
}
void Menu::register_student_to_course()
{
	if (num_of_course == 0)
	{
		cout << "There is no courses!" << endl;
		return;
	}
	if (num_of_student == 0) 
	{
		cout << "There is no students!" << endl;
		return;
	}
	cout << "Enter the code for the course:" << endl;
	int number_course;
	cin >> number_course;
	int temp = find_course(number_course);
	if (temp == -1) 
	{
		cout << "Course does not exist." << endl;
	}
	else 
	{
		cout << "Enter id for the student:" << endl;
		string id_student;
		cin >> id_student;
		int x = find_student(id_student);
		int y = list_of_course[temp]->find_student_in_course(id_student);

		if (x == -1)
		{
			cout << "There's no students with this id!" << endl;
		}	
		else if (x != -1 && y == -1)
		{
			*list_of_course[temp] += *list_of_student[x];
		}
		else {
			cout << "Student exists in this course." << endl;
		}
	}
}
void Menu::grade_student_in_course() 
{
	if (num_of_course == 0)
	{
		cout << "There is no courses!" << endl;
		return;
	}
	if (num_of_student == 0)
	{
		cout << "There is no students!" << endl;
		return;
	}
	cout << "Enter the code for the course:" << endl;
	int number_course;
	cin >> number_course;
	int temp = find_course(number_course);
	if(temp == -1)
	{
		cout << "Course does not exist." << endl;
	}
	else 
	{
		cout << "Enter id for the student:" << endl;
		string id_student;
		cin >> id_student;
		int x = find_student(id_student);
		int	y = list_of_course[temp]->find_student_in_course(id_student);
		if (x == -1)
		{
			cout << "There's no students with this id!" << endl;
		}
		else if (x != -1 && y == -1)
		{
			cout << "Student is not exist in this course." << endl;
		}
		else 
		{
			list_of_course[temp]->grade(y);
		}
	}
}


