#include "Teacher.h"

Teacher ::~Teacher ()//���� ���� ������ ���� ������� �� ����
{
	if(professions_name!=NULL)
		delete[] professions_name;
}

Teacher::Teacher(const Teacher&obj):Worker(obj),amount_professions(obj.amount_professions)//���� �����
{
	professions_name=new string[obj.amount_professions];//����� ������ ��� ����� ��������
	for (int i = 0; i < obj.amount_professions; i++)//����� �������� ���������
		professions_name[i]=obj.professions_name[i];
}

void Teacher::set_professions()//����� ������ ����� �� ����
{
	cout<<"\nEnter amount professions (1-10): ";
	cin>>amount_professions;
	professions_name=new string[amount_professions];//����� ������ ����� ����� �������� �� ����
	cout<<"Enter the names of the professions\n";
	for (int i = 0; i < amount_professions; i++)//����� ��� �������� �����
	{
		cout<<"Professions number "<<(i+1)<<": ";
		cin>>professions_name[i];
	}
}

const void Teacher::print_all_teacher_professions()//������� ������ �� �������� �� ����
{
	for (int i = 0; i < amount_professions; i++)
		cout<<professions_name[i]<<", ";

	cout<<endl;
}

void Teacher::print_person()//����� ������ ����� �� ����
{
	//cout<<"~ Teacher details:\n";
	Worker::print_person();
	cout<<"professions: ";
	print_all_teacher_professions();//����� ������� ������� �� �������� ������ ����
	cout<<endl;
}

void Teacher::set_person()//����� ������ ���� �����
{
	int _seniority;
	Person::set_person();
	cout<<"\nEnter seniority: ";
	cin>>_seniority;//����� ���� ���� �� ����
	cout<<endl;
	set_seniority(_seniority);
}
