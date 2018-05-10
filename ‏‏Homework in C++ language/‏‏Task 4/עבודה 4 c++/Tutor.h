#include "Teacher.h"
#ifndef TUTOR_H
#define TUTOR_H
class Class;
class Tutor : public Teacher
{
public:
	Tutor():cls(NULL){}
	~Tutor(){}
	Tutor(const Tutor&obj):Teacher(obj),cls(obj.cls){}//העתקת כל הפרטים של המחנך דרך בנאי ההעתקה של מורה+ העתקת הכיתה מהאובייקט באמצעות בנאי העתקה של כיתה
	float return_salary(){ return ( Teacher::return_salary() + 1000 ) ; }//מתודה אין-ליין שמחשבת את משכורתו של המחנך ומחזירה אותו
	const void print_pupils();
	bool check_if_outstanding();
	void print_person();
	Class* get_cls(){return cls;}//פונקציית גט לקבל את המצביע לכיתה של המחנך
	void set_cls(Class *c){cls=c;}
	void set_person(){ Teacher::set_person();}//מתודה שמעדכנת את פרטיו של המחנך
	
private:
	Class* cls;
};



#endif