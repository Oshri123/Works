#include "Worker.h"

void Worker::print_person()//����� ������ ���� ����� ������� ,�� ���,�.� ����� ����
{
	Person::print_person();
	cout<<"Seniority: "<<seniority<<endl;
	cout<<"Salary: "<<return_salary()<<endl;
}

