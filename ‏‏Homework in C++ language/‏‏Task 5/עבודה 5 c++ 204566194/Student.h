#include "Date.h"
#define SIZE 10
#define NAME_SIZE 20
#define MIN_NAME 5
#define MAX_NAME 20
#ifndef STUDENT_H
#define STUDENT_H

class Student
{
public:
	Student():full_name(NULL),date_of_birth(),average(0){}
	~Student()//בנאי הורס לשחרור הזיכרון של השם של הסטודנט
	{
		if(full_name!=NULL)
			delete[] full_name;
	}
	friend ostream& operator <<(ostream&out, Student&s);
	void Student::operator=(Student&s);
	bool operator > (const Student&s){ if(this->average>s.average) return true; else return false; }
	friend istream& operator >>(istream&in, Student&s);
	void check_exception(const Student&s)const;

private:
	char *full_name;
	char id[SIZE];
	Date date_of_birth;
	float average;
};

#endif // !STUDENT_H
