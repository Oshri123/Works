#include "Worker.h"
#ifndef SECRETARY_H
#define SECRETARY_H

class Secretary: public Worker
{
public:
	Secretary():amount_child_at_school(0){}//���� ��������� ����� �� ���� ������ �� ������� ������� ���� ����
	~Secretary(){}
	float return_salary(){ return (basic +amount_child_at_school*300); }//����� ���-���� ������ �� ������� �� ������� ������� ����
	bool check_if_outstanding(){return (get_seniority()>10 );}//����� ���-���� ������ �� ������� ������� -�� �� �� ��� �� ���� �10 ����
	void set_person();
	void print_person();

private:
	int amount_child_at_school;
};


#endif
