
#define SIZE 81
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
using namespace std;

class Depertment;
class Course;
class student
{
public:
	student();
	~student();
	student(const student &s);
	void setName( string name)// פונקצית סט לעדכון השם של הסטודנט
	{ 
		NameStu=name;
	}  
	string getName(){return NameStu;}//פונקציית גט כדיי לגשת למשתנה הפרייבט

	void setID (int _id) { id=_id;}// פונקצית סט לעדכון הת.ז של הסטודנט
	int getID(){ return id;}//פונקציית גט כדיי לגשת למשתנה הפרייבט

	void setGender(char _gender)// פונקצית סט לעדכון המין של הסטודנט
	{
		gender=_gender;
	}
	char getGender() { return gender;}//פונקציית גט כדיי לגשת למשתנה הפרייבט

	void setAge(int _age){ age=_age; }// פונקצית סט לעדכון הגיל של הסטודנט
	int getAge(){ return age;}//פונקציית גט כדיי לגשת למשתנה הפרייבט

	void setAmountC(int _amount_courses){ amount_courses=_amount_courses; }// פונקצית סט לעדכון כמות הקורסים של הסטודנט
	int getAmountC(){ return amount_courses;}//פונקציית גט כדיי לגשת למשתנה הפרייבט

	Depertment* get_dep(){return student_dep;}
	void set_dep( Depertment *d);

	Course** getCourses(){return courses;}
	student operator = (const student& s );
	const bool student::operator==(const student&s );
	const bool student::operator >(const student&s);
	friend ostream& operator<< (ostream&out, const student&s);
	friend istream& operator>>(istream&in, student&s);
	student& student::operator+=(Course *c);
	student& student::operator-=(Course *c);
	Course student::operator[](int location);
	int student::check_if_course_exists(Course *c);
	float alculation_average_all_courses();
private:
	string NameStu;
	int id;
	char gender;
	int age;
	Course **courses;
	int amount_courses;
	Depertment *student_dep;

};




#endif