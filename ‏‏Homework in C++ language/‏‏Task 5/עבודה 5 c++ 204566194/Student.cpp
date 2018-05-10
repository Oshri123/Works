#include "Student.h"
#define N 81

ostream& operator <<(ostream&out, Student&s)// ������� ����� ���� ��� ��������� ����� ����� ������ ��� ������ �� ���� ���� ������ ����
{
	out<<"Student name: "<<s.full_name<<endl;//����� ��� �� �������
	out<<"Id: "<<s.id<<endl;//����� ����� ����� �� �������
	out<<"Date of birth: "<<s.date_of_birth.get_day()<<"/"<<s.date_of_birth.get_month()<<"/"<<s.date_of_birth.get_year()<<endl;//����� ����� ����� �� �������
	out<<"Average: "<<s.average<<endl;//����� ������ �� �������
	out<<"---------------------------------\n";
	return out;
}

istream& operator >>(istream&in, Student&s)//������� ���
{
	char temp[N];//����� ������ ��� ������ ��� �� �����
	int j=0;
	in.get(temp[j]);
	do{in.get(temp[j]);//����� �� ��
	j++;
	}while(temp[j-1]!='\n');//����� �� ��� �� ����� ���� ����� ��� ����� ����� ���
	temp[j-1]='\0';

	s.full_name=new char[j];//����� ������� ������� ��� ����� ������ 
	for (int i = 0; i < j; i++)//����� �������� ��������
		s.full_name[i]=temp[i];

	in>>s.id>>s.date_of_birth>>s.average;//����� ������� �� ��.�,����� ����� ������� 

	return in;
}

void Student::operator=(Student&s)//������� ����
{
	int i,j;

	for (i = 0; s.full_name[i]!='\0'; i++);//����� ���� ������ ��� ������� ���
	if(full_name!=NULL)
		delete[] full_name;

	full_name=new char[i+1];//����� �������� ���� ����� ������
	for (i = 0;s.full_name[i]!='\0'; i++)//����� ������� �� �� ������� �������
		full_name[i]=s.full_name[i];
	full_name[i]='\0';

	for ( j = 0; s.id[j]!='\0'; j++)//����� �.�
		id[j]=s.id[j];
	id[j]='\0';

	date_of_birth=s.date_of_birth;//����� ����� �����
	average=s.average;//����� ������
}

void Student::check_exception(const Student&s)const//������� ������ ������ ����� ���������
{

	int i=0,flag=1;
	if(s.full_name[i]<'A' || s.full_name[i]>'Z')
		throw "The first char in the student name not exist big latter!";

	for ( i = 1;s.full_name[i]!='\0'; i++)
	{
		if(i>MAX_NAME)
			throw "the length of the name is too long!";

		if(s.full_name[i]==' ' || s.full_name[i]=='-')
		{
			flag=0;
			if(s.full_name[i+1]<'A' || s.full_name[i+1]>'Z')
				throw "The word does not open with big latter!";
		}
		else 
			if((s.full_name[i]>='A' && s.full_name[i]<= 'Z')&&(s.full_name[i-1]!=' ' && s.full_name[i-1]!='-'))
				throw "There is big latters in the student name!";
	}
	if (i<MIN_NAME)
		throw "the length of the name is too short!";

	if(flag)
		throw "There is no  ' ' OR '-' between the first name and last name";

	for ( i = 0;s.id[i]!='\0'; i++)
		if(s.id[i]<'0' || s.id[i]>'9')
			throw "The id contain latters!";

	if(i<9)
		throw "The id is under 9!";

	s.date_of_birth.check_exception(s.date_of_birth);//����� ������ ������ �����

	if(s.average<0||s.average>100)
		throw "The average is over 100 or under 0!";

}