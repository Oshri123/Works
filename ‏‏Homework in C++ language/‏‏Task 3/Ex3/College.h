#include "Depertment.h"
#include "Course.h"
#include "Student.h"
#define NOT_EXISTS -1//משתנה גלובלי שמשמש לבדיקה אם הקורס/סטונדט/מחלקה קיימים
#define EXIT 11//משתנה גלובלי שמשמש לתנאי יציאה מהתוכנית
#ifndef COLLEGE_H
#define COLLEGE_H
class College
{
public:

	Depertment** get_dep(){return all_dep; }//החזרת הכתובות של רשימת המחלקות
	int get_total_dep(){return total_dep;}//פונקציית גט כדיי לגשת למשתנה הפרייבט
	student** get_StdTotal(){return std_total;}//פונקציית גט כדיי לגשת למשתנה הפרייבט
	int get_total_student(){return total_student;}//פונקציית גט כדיי לגשת למשתנה הפרייבט
	int check_if_dep_exists(int code);
	int check_if_courses_exists(int code,int location);
	int College::check_if_students_exists(student *s ,int location);
	void Add_department();
	void Add_course_to_department();
	void Add_student_to_department();
	void Register_student_to_course();
	void Grading_students_in_course();
	void Print_course_information();
	void Print_student_information();
	void Print_department_information();
	void Find_students_with_bad_academic_status();
	void Remove_student_from_course();
	int menu();

	College():all_dep(NULL),std_total(NULL),total_dep(0),total_student(0){};//בנאי דיפולט
	~College();
	College(const College&c);
private:
	Depertment **all_dep;
	int total_dep;
	student **std_total;
	int total_student;
};




#endif