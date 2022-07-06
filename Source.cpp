//Esther BERGMAN 1503941
#include <iostream>
#include <cstring>
#include <string> 
#include <fstream>
using namespace std;
struct Student
{
	int id;//number of the student
	char  lastName[20];
	char  firstName[20];
	bool c[5];
	Student()//default constructor
	{
		id = 0;
		for (int i = 0; i < 5; i++)
			c[i] = 0;
	}
};
bool ifNotInFile(int _id, fstream& f)//checks if the record exists
{
	Student s;
	f.seekg((_id - 1) * sizeof(Student));
	f.read((char*)&s, sizeof(Student));
	if (s.id == 0)
		return true;
	return false;
}
void add(fstream& f)
{
	Student s;
	cout << "enter id,first name,last name" << endl;
	cin >> s.id;
	cin >> s.firstName >> s.lastName;
	cout << "enter 0 or 1 for the courses" << endl;
	for (int i = 0; i < 5; i++)
		cin >> s.c[i];
	if (ifNotInFile(s.id, f))
	{
		f.seekp((s.id - 1) * sizeof(Student));
		f.write((char*)&s, sizeof(Student));
	}
	else
		cout << "student" << " " << s.id << " " << "exist" << endl;
}
void remove(fstream& f, int _id)
{
	if (!ifNotInFile(_id, f))
	{
		Student s;
		f.seekp((_id - 1) * sizeof(Student));
		f.write((char*)&s, sizeof(Student));
		cout << "student" << " " << _id << " " << "is deleted" << endl;
	}
	else
		cout << "student" << " " << _id << " " << "is empty" << endl;
}
void idkun(fstream& f, int _id)
{
	Student s;
	f.seekg((_id - 1) * sizeof(Student));
	f.read((char*)&s, sizeof(Student));
	if (!ifNotInFile(_id, f))
	{
		cout << "enter 5 values for the courses" << endl;
		for (int i = 0; i < 5; i++)
			cin >> s.c[i];
		f.seekp((_id - 1) * sizeof(Student));
		f.write((char*)&s, sizeof(Student));
	}
	else
		cout << "student" << " " << _id << " " << "is empty" << endl;
}
bool checkCourses(fstream& f, int _id, int i)
{
	if (!ifNotInFile(_id, f))
	{
		Student s;
		f.seekg((_id - 1) * sizeof(Student));
		f.read((char*)&s, sizeof(Student));
		if (s.c[i] == true)
			return true;
		else
			return false;

	}
	return 0;
}
void printStudentData(fstream& f, int _id)
{
	Student s;
	f.seekg((_id - 1) * sizeof(Student));
	f.read((char*)&s, sizeof(Student));
	if (!ifNotInFile(_id, f))
	{
		cout << "data of the student" << " ";
		cout << s.firstName << " " << s.lastName << " ";
		for (int i = 0; i < 5; i++)
		{
			if (s.c[i])
				cout << "Y" << " ";
			else
				cout << "N" << " ";
		}
		cout << endl;
	}
	else
		cout << "the student" << " " << _id << " " << "doesn't exist" << endl;
}
void listInCourse(fstream& f, int numc)
{
	for (int i = 1; i < 100; i++)
	{
		Student s;
		f.seekg((i - 1) * sizeof(Student));
		f.read((char*)&s, sizeof(Student));
		if (s.id != 0)
			if (s.c[numc])
				cout << s.firstName << " " << s.lastName << endl;
	}
}
void createFile()//create a students file
{
	ofstream f1;
	f1.open("Students.data", ios::binary);
	if (!f1)
		throw "cannot open the file";
	Student s;
	for (int i = 0; i < 100; i++)
		f1.write((char*)&s, sizeof(Student));
	f1.close();
}
int main()
{
	fstream f("Students.data", ios::binary | ios::in | ios::out);
	createFile();
	cout << "enter your choice" << endl;
	int choice;
	int id, c;
	cin >> choice;
	while (choice)
	{
		switch (choice)
		{
		case 1://adding a student
			add(f);
			break;
		case 2://removing a student
			cout << "enter the id of the student" << endl;
			cin >> id;
			remove(f, id);
			break;
		case 3://updates the courses of the student
			cout << "enter the id of the student" << endl;
			cin >> id;
			idkun(f, id);
			break;
		case 4://checks if the student is in the course
			cout << "enter id and the number of the course" << endl;
			cin >> id >> c;
			if (checkCourses(f, id, c))
				cout << "true" << endl;
			else
				cout << "false" << endl;
			break;
		case 5://prints the data of the student whose id was sent 
			cout << "enter the id of the student" << endl;
			cin >> id;
			printStudentData(f, id);
			break;
		case 6://prints all the names of the students who are in the course
			cout << "enter the number of the course" << endl;
			cin >> c;
			listInCourse(f, c);
			break;
		default:
			cout << "ERROR" << endl;
			break;
		}
		cout << "enter your choice" << endl;
		cin >> choice;
	}
	f.close();
	return 0;
}
/* example of output
enter your choice
1
enter id,first name,last name
33
rivka
toledano
enter 0 or 1 for the courses
1
1 1 1 1
enter your choice
3
enter the id of the student
33
enter 5 values for the courses
1 0 1 0 1
enter your choice
5
enter the id of the student
33
data of the student rivka toledano Y N Y N Y
enter your choice
6
enter the number of the course
3
enter your choice
8
ERROR
enter your choice
1
enter id,first name,last name
22
david
dor
enter 0 or 1 for the courses
0 0 0 1 1
enter your choice
2
enter the id of the student
22
student 22 is deleted
enter your choice

*/