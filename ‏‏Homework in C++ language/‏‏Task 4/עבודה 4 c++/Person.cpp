#include "Person.h"


void Person::set_person()//����� ��������� ������ ������ ���� �� ���� �� �����
{
	cout<<"\nEnter first name: ";
	cin>>F_name;
	cout<<"\nEnter last name: ";
	cin>>L_name;
	cout<<"\nEnter id: ";
	cin>>id;
}

void Person::print_person()//����� ��������� ������ ������ �� �� �����
{ 
	cout<<"Name: "<<F_name<<" "<<L_name<<endl;
	cout<<"Id: "<<id<<endl;
}