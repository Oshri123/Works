#include "Worker.h"
#ifndef TEACHER_H
#define TEACHER_H

class Teacher :public Worker 
{
public:
	Teacher ():professions_name(NULL),amount_professions(0){}
	~Teacher ();
	Teacher(const Teacher&obj);
	float return_salary(){ return ( (basic*(1+amount_professions/10)+300*get_seniority() ) ); }// ����� ���-���� ������ ������� �� ����
	bool check_if_outstanding(){return (amount_professions>5);}//����� ���-���� ������ �� ����� �������
	const void print_all_teacher_professions();
	void print_person();
	void set_person();
	void set_professions();

private:

	string* professions_name;
	int amount_professions;
};


#endif



