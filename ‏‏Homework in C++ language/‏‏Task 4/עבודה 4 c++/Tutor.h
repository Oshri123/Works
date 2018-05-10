#include "Teacher.h"
#ifndef TUTOR_H
#define TUTOR_H
class Class;
class Tutor : public Teacher
{
public:
	Tutor():cls(NULL){}
	~Tutor(){}
	Tutor(const Tutor&obj):Teacher(obj),cls(obj.cls){}//����� �� ������ �� ����� ��� ���� ������ �� ����+ ����� ����� ��������� ������� ���� ����� �� ����
	float return_salary(){ return ( Teacher::return_salary() + 1000 ) ; }//����� ���-���� ������ �� ������� �� ����� ������� ����
	const void print_pupils();
	bool check_if_outstanding();
	void print_person();
	Class* get_cls(){return cls;}//�������� �� ���� �� ������ ����� �� �����
	void set_cls(Class *c){cls=c;}
	void set_person(){ Teacher::set_person();}//����� ������� �� ����� �� �����
	
private:
	Class* cls;
};



#endif