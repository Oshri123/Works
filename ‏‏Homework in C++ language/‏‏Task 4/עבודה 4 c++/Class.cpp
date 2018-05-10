#include "Class.h"

Class::Class(char layer_n,int class_n)//���� ������ �� ������ �� ����� ��� ���� ����� ����� �� ������� �� �������� ��� ������ �� ����� ��� ���� �������� �����
{
	layer_name=layer_n;
	class_num=class_n+1;
	pupils=NULL;
	amount_pupils=0;
	tutor=NULL;
}

Class::~Class()//���� ���� ������ �� ������� �� ����� �� ��������
{
	if(pupils!=NULL)
		delete[] pupils;
}

Class::Class(const Class&obj):layer_name(obj.layer_name),class_num(obj.class_num),amount_pupils(obj.amount_pupils),tutor(obj.tutor)//���� �����
{
	pupils=new Pupil*[obj.amount_pupils];//����� ������ ��� �����
	for (int i = 0; i < obj.amount_pupils; i++)//����� ������ ��� ��� �� +����� ����� ���������
		pupils[i]=new Pupil(*obj.pupils[i]);
}

int Class::check_if_pupil_exist(Pupil *pl)//������� ������ �� ������ ���� ����� 
{
	for (int i = 0; i < amount_pupils; i++)//����� ������ �� �� �������� ������ �� ��.� �� ������ ������ ������ �� �������� �����
	{
		if(pupils[i]->get_id()==pl->get_id())
			return i;
	}
	return NOT_EXIST;
}

void Class::add_pupil(Pupil *pl)//����� ������ ����� ������ ������� ���� �����
{
	Pupil **p=pupils;//����� ����� ��� ������ ���� �������� �����

	if(check_if_pupil_exist(pl)!=NOT_EXIST)//����� �� ������ ��� ���� �����
		return;

	pupils=new Pupil*[amount_pupils+1];//����� ������ ���� ������ ��������
	for (int i = 0; i < amount_pupils; i++)//����� �������� ����� ����� ���� ������� �� �������
		pupils[i]=p[i];

	pupils[amount_pupils]=pl;//����� ������ ����� ��������
	amount_pupils++;//����� ���� �������� �����

	if(p!=NULL)//����� ������� �� ����� ����
		delete p;

}

Pupil* Class::return_pupil(int location)//����� ������ ����� �� ����� ������� �� ������ ������
{
	if(location>amount_pupils)//����� �� ������ ������ ����
		return NULL;
	else return pupils[location];//�� ������ ���� ����� ������ ������

}