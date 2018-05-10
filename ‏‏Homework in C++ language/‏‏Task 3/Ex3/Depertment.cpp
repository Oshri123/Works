#include "Depertment.h"
#include "Course.h"
#include "Student.h"

Depertment::~Depertment()//���� ���� ������ ������ �� ������
{
	if (crs !=NULL )
		for (int i = 0; i < amount_crs; i++)
			delete crs[i];

	delete crs;

	if (std != NULL)
		for (int i = 0; i < amount_std; i++)
			delete std[i];

	delete std;	

	delete failed_std;

}
Depertment::Depertment(const Depertment&d)//���� �����
{
	dep_N=d.dep_N;
	code=d.code;
	amount_crs=d.amount_crs;
	crs=new Course*[amount_crs];
	for ( int i=0; i<amount_crs;i++)//����� ������� �� ����� �������
	{
		crs[i]=new Course;
		*crs[i]=*d.crs[i];
	}
	amount_std=d.amount_crs;
	std=new student*[amount_std];
	for ( int i=0; i<amount_std;i++)//����� ������� �� ����� ���������
	{
		std[i]=new student;
		*std[i]=*d.std[i];
	}
	amount_fstd=d.amount_fstd;
	failed_std=new student*[amount_fstd];
	for ( int i=0; i<amount_fstd;i++)//����� ������� �� ����� ��������� �������
	{
		failed_std[i]=new student;
		*failed_std[i]=*d.failed_std[i];
	}

}
Depertment Depertment::operator = ( const Depertment&d )//������� ����, ����� �� �� ���� ������ ������ ����
{
	dep_N=d.dep_N;
	code=d.code;
	amount_crs=d.amount_crs;
	delete crs;
	delete std;
	delete failed_std;
	crs=new Course*[amount_crs];
	for ( int i=0; i<amount_crs;i++)//����� ������� �� ����� �������
	{
		crs[i]=new Course;
		*crs[i]=*d.crs[i];
	}
	amount_std=d.amount_crs;
	std=new student*[amount_std];
	for ( int i=0; i<amount_std;i++)//����� ������� �� ����� ���������
	{
		std[i]=new student;
		*std[i]=*d.std[i];
	}
	amount_fstd=d.amount_fstd;
	failed_std=new student*[amount_fstd];
	for ( int i=0; i<amount_fstd;i++)//����� ������� �� ����� ��������� �������
	{
		failed_std[i]=new student;
		*failed_std[i]=*d.failed_std[i];
	}
	return d;
}
bool Depertment::operator>(const Depertment&d)//������� ����� )���� ��� ���� ��������� �� ��� ������ ���� ����� ���� ���� ������-����� 
{
	return(amount_fstd>d.amount_fstd);
}
ostream& operator << ( ostream&out , Depertment&d)
{
	//	��� �� ���� ������ - �������� ����� �� �� �����, ��� ����� ,���� ������� ������� �"�
	//   ������, �� ����� ��������� ������� ������ ��� ����� ��������� �� ��� ����� �� 
	//      ���� )�� ��� �����)

	out<<"Depatment information:\n";
	out<<"Name: "<<d.dep_N<<"\ncode: "<<d.code<<endl;
	if(d.amount_crs)//����� ����� ������� ������
	{
		out<<" - Courses of department:\n";
		for(int i=0;i<d.amount_crs;i++)
			out<<"Name: "<<d.getCrs()[i]->getNameC()<<", Number: "<<d.getCrs()[i]->getNumOfTheCours()<<endl;
	}

	if(d.amount_std)//����� ����� ��������� ������
	{
		out<<" - Student in department:\n";
		for(int i=0;i<d.amount_std;i++)
			out<<"Name: "<<d.std[i]->getName()<<", Id: "<<d.std[i]->getID()<<", gender: "<<d.std[i]->getGender()<<", age: "<<d.std[i]->getAge()<<endl;
	}

	if(d.amount_fstd)//����� ����� ��������� ������� ������ �� ������
	{
		out<<" - Students with bad status:\n";
		for(int i=0;i<d.amount_fstd;i++)
			out<<"Name: "<<d.failed_std[i]->getName()<<", Id: "<<d.failed_std[i]->getID()<<", gender: "<<d.failed_std[i]->getGender()<<", age: "<<d.failed_std[i]->getAge()<<endl;
	}
	out<<endl;
	return out;
}
istream& operator >> ( istream&in , Depertment&d)//������� ��� �� �� ������ ���� ������
{
	cout<<"Please enter department details.\n"<<"Name: ";
	in>>d.dep_N;
	cout<<"Code: ";
	in>>d.code;

	return in;
}
Depertment& Depertment::operator+=( Course *c)//������� ����� ���� ������
{
	for(int i=0;i<amount_crs;i++)//����� �� ����� ���� ��� ������
		if(*crs[i] == *c)
		{
			cout<<"Course already exist in some department!\n";
			return *this;
		}


		Course** _c=crs;//����� ����� ����� �� ������ �� ���� ������� �� ������
		amount_crs++;//����� ���� �������

		crs=new Course*[amount_crs];//����� ������ ��� ����� �������
		for(int i=0;i<amount_crs-1;i++)//����� ������� �� ������� ����� ������
			crs[i]=_c[i];

		crs[amount_crs-1]=c;//����� ����� ������ �������
		return *this;
}
Depertment& Depertment::operator+=( student *s)//������� ����� ������ ������
{
	for(int i=0;i<amount_std;i++)//����� �� ������� ���� ��� ������
		if(*std[i] == *s)
		{
			cout<<"Student already exist in some department!\n";
			return *this;
		}

		student** _s=std;//����� ����� ����� �� ������ �� ���� ��������� �� ������
		amount_std++;//����� ���� ���������

		std=new student*[amount_std];//����� ������ ��� ����� �������
		for(int i=0;i<amount_std-1;i++)//����� ������� �� ������� ����� ������
			std[i]=_s[i];

		std[amount_std-1]=s;//����� ������� ������ ���������
		return *this;

}
void Depertment::setAmou_Failed_Std(student *s,int location)//������� ������� �� ����� ��������� �������
{

	student** _failed=failed_std;//����� ����� ����� �� ������ �� ���� ��������� ������� �� ������
	amount_fstd++;//����� ���� ��������� �������

	failed_std=new student*[amount_fstd];//����� ������ ��� ����� �������
	for(int i=0;i<amount_fstd-1;i++)//����� ������� �� ������� ����� ������
		failed_std[i]=_failed[i];

	failed_std[amount_fstd-1]=s;// ����� ������� ����� ������ ��������� �������

}
void Depertment::reset_fstd()//������� ������� �� ����� �� ��������� �������
{

	if(failed_std!=NULL)
		delete failed_std;

	amount_fstd=0;
	failed_std=NULL;
}