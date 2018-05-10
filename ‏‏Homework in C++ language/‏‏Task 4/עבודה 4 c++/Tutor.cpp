#include "Tutor.h"
#include "Class.h"

const void Tutor::print_pupils()//������� ������ ���� �������� �� �����
{
	cout<<"\n* The details of the tutor's pupils: *\n";
	for (int i = 0; i <cls->get_amount_pupils(); i++)//����� ������� �� ���� �������� �� �����
	{
		cls->get_pupils()[i]->print_person();
		if(cls->get_pupils()[i]->check_if_outstanding())//�� ������ ������ ������ ����� ������
			cout<<"The pupil is outstanding\n";
	}
}

bool Tutor::check_if_outstanding()//����� ������ �� ����� ������
{
	float outstanding_pupils=0;
	float amoun_pupils=cls->get_amount_pupils()/2;
	for (int i = 0; i <cls->get_amount_pupils(); i++)//����� ������ ��� ������� �������� �� �����
	{
		if(cls->get_pupils()[i]->check_if_outstanding())
			outstanding_pupils++;
	}
	if(( outstanding_pupils >= amoun_pupils)&&(amoun_pupils!=0 ))//�� ���� �������� ��������� ����� ����� ���� ����� ������
		return true;
	else
		return false;
}

void Tutor:: print_person()//����� ������ ����� �� ����
{
	cout<<"~ Tutor details:\n\n";
	Teacher::print_person();//����� ������ ����� ���� �����
	cout<<"He is tutor at layer: "<<cls->get_layer_name()<<endl;
	cout<<"He is the tutor of class number: "<<cls->get_num_class()<<endl;
	if(cls->get_amount_pupils() )//����� �� �������� �� ����� (�� ���� ���� 
		print_pupils();
}