#include "Worker.h"
#ifndef MANAGER_H
#define MANAGER_H

class Manager: public Worker
{
public:
	Manager(){}
	~Manager(){}
	float return_salary(){ return (basic*2+get_seniority()*500); }//����� ���-���� ������ �� ������� �� ����� ������� ����
	void set_person();
	bool check_if_outstanding(){return (get_seniority()>3);}//����� ���-���� ������ �� ����� ������ -�� �� �� ��� �� ���� �3 ����
	void print_person();

private:

};


#endif
