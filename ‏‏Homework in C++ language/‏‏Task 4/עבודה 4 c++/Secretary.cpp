#include "Secretary.h"

void Secretary::set_person()//����� ������� �� ������ �� ������� 
{
	int _seniority;
	Person::set_person();//����� �� ��.�
	cout<<"\nEnter seniority: ";
	cin>>_seniority;//�����  ���� ���� �� �������
	set_seniority(_seniority);
	cout<<"\nEnter amount of children that learning at the school: ";
	cin>>amount_child_at_school;//����� ���� ������ �� ������� ������� ���� ����
}

void Secretary::print_person()//����� ������� �� ������ �� �������
{
	cout<<"~ Secretary details:\n\n";
	Worker::print_person();
	cout<<"children at school: "<<amount_child_at_school<<endl;//����� ���� ������ �� ������� ������� ���� ����
}

