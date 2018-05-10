#include "Student.h"
#include <iostream>

#ifndef COURSE_H
#define COURSE_H
class Depertment;
class student;
class Course
{
public:
	Course():Name_C(""),NumOfTheCours(0),registered(NULL),amount_students(0),grade(NULL),dep_course(NULL){};//בנאי דיפולטיבי אינליין
	~Course();
	Course(const Course&c);
	string getNameC(){return Name_C;}//פונקציית גט כדיי לגשת למשתנה הפרייבט
	int* getGrade(){return grade;}//פונקציית גט כדיי לגשת למשתנה הפרייבט
	void setGrade(int location,int his_grade){ grade[location]=his_grade;}//פונקציית סט לעדכון הציון של הסטודנט
	int getNumOfTheCours(){return NumOfTheCours;}//פונקציית גט כדיי לגשת למשתנה הפרייבט
	void setNumOfTheCours(int new_NumOfTheCours){ NumOfTheCours=new_NumOfTheCours; }//פונקציית סט לעדכון כמות הקורסים של הסטודנט
	int getAmount(){return amount_students;}//פונקציית גט כדיי לגשת למשתנה הפרייבט
	student** getRegister(){return registered;}//פונקציית גט כדיי לגשת למשתנה הפרייבט
	Course operator = (const Course&s );
	const bool operator==(const Course&c);
	const bool operator>(const Course&c);
	friend istream& operator>>(istream&in,Course&c);
	friend ostream& operator<<(ostream&out,Course&c);
	student operator[](int location);
	Course& Course::operator+=(student *s);
	Course& Course::operator-=(student *s);
	int check_if_student_exists(student *s);
	float calculation_average();
	Depertment* get_depCourse(){return dep_course;}
	void set_course_dep(Depertment *d);

private:
	string Name_C;
	int NumOfTheCours;
	student **registered;
	int amount_students;
	int *grade;
	Depertment *dep_course;

};
#endif
