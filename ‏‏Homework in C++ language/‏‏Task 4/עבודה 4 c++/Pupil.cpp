#include "Pupil.h"

Pupil* Pupil::Add_person(Person** p,char _layer,int class_num,int amount_presons)//������� ������� ������� ����� ���� �����
{
	Person::set_person();//����� ���� ������
	set_layer(_layer);
	set_num_of_class(class_num);
	for (int i = 0; i < amount_presons; i++)//����� ������ �� ������ ���� ���� ����
		if(p[i]->get_id()==get_id())
			return this;

	amount_grades=((layer-97)+5);//����� ���� ������� ��� ������ ��� ����� :(�� ������ - 97 ==>��� ���� ����� 97 ��� ���� ����� ����� �����) + 5 �������

	grade=new int[amount_grades];//����� ������ ����� ������� �� ������
	cout<<"Enter "<<amount_grades<<" grades for this pupil\n";
	for (int i = 0; i < amount_grades; i++)//����� ������ �� ������� �� ������
	{
		cout<<"grade number "<<i+1<<": ";
		cin>>grade[i];
	}

	return this;
}

Pupil::~Pupil()//���� ���� ������ ���� �������
{
	if(grade!=NULL)
		delete[] grade;
}

Pupil::Pupil( const Pupil&obj):Person(obj),amount_grades(obj.amount_grades),layer(obj.layer),num_of_class(obj.num_of_class)//���� �����
{
	grade=new int[obj.amount_grades];//����� ������ ��� ����� �������
	for (int i = 0; i < obj.amount_grades; i++)//����� ������� ���������
		grade[i]=obj.grade[i];
}

bool Pupil::check_if_outstanding()// ����� ������ �� ������ ������
{
	float avg=0;
	for (int i = 0; i < amount_grades; i++)//����� ������ �� ������ �� ������ �� ��� �� ����� 65
		if(grade[i]<=65)//����� ��� ����� ���� ���� ���� �65 ������ ���� ������
			return false;
		else avg+=grade[i];

		return ((avg/amount_grades)>85);//�� ����� ������� �� ������ ������ �85 ������ ������
}

void Pupil::print_person()//����� ������ ���� ������
{
	float avg=0;
	cout<<"~ Pupil datails:\n\n";
	Person::print_person();
	cout << "Layer: '" << layer << "' "<<endl;
	cout << "Class number: " << num_of_class << endl;
	cout<<"His grades: ";
	for (int i = 0; i < amount_grades; i++)//����� ������� �� ������ �� ������
	{
		cout<<grade[i]<<", ";
		avg+=grade[i];
	}
	avg/=amount_grades;//����� ����� ������ �� ������
	cout<<"\nThe average of his grades: "<<avg<<endl;//����� ����� ������� �� ������
}

