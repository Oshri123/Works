#include "Manager.h"

void Manager::set_person()//����� ������� �� ����� �� �����
{
	int _seniority;
	Person::set_person();
	cout<<"\nEnter seniority: ";
	cin>>_seniority;//����� ���� ����� �� �����
	cout<<endl;
	set_seniority(_seniority);//����� ���� ���� �� �����
}

void Manager::print_person()//����� ������� �� ����� �� �����
{
	cout<<"~ Manager details:\n";
	Worker::print_person();
}
