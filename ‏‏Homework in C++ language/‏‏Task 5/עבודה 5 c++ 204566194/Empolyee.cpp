#include "Empolyee.h"
#define MIN_NAME 5
#define MAX_NAME 20
#define N 81

ostream& operator <<(ostream&out, Empolyee&e)//������� ���
{
	out<<"Empolyee name: "<<e.full_name<<endl;//����� ��� �� �����
	out<<"Empolyer name: "<<e.empolyer_name<<endl;//����� ��� �� ������
	out<<"Seniority: "<<e.seniority<<endl;//����� ����� �� �����
	out<<"Salary: "<<e.salary<<endl;//����� ������� �� �����
	out<<"---------------------------------\n";
	return out;
}

istream& operator >>(istream&in,Empolyee&e)//������� ���
{
	char temp[N];//����� ������ ��� ������ ��� �� �����
	int j=0;
	in.get(temp[j]);//����� �� ��
	do{in.get(temp[j]);
	j++;
	}while(temp[j-1]!='\n');//����� �� ��� �� ����� ���� ����� ��� ����� ����� ���
	temp[j-1]='\0';
	e.full_name=new char[j];//����� ������� ������� ��� ����� ������ 
	for (int i = 0; i < j; i++)//����� �������� ��������
		e.full_name[i]=temp[i];

	j=0;

	do{in.get(temp[j]);//����� �� �� ������� ������
	j++;
	}while(temp[j-1]!='\n');
	temp[j-1]='\0';
	e.empolyer_name=new char[j];//����� ������� ��� ������ ����� ������
	for (int i = 0; i < j; i++)
		e.empolyer_name[i]=temp[i];//����� ��� ��������

	in>>e.seniority>>e.salary;//����� ������� �� ���� ��������
	return in;
}

void Empolyee::operator=(Empolyee&e)
{
	int i,j;

	for (i = 0; e.full_name[i]!='\0'; i++);
	if(full_name!=NULL)
		delete[] full_name;
	full_name=new char[i+1];
	for (i = 0;e.full_name[i]!='\0'; i++)
		full_name[i]=e.full_name[i];
	full_name[i]='\0';

	for (j = 0; e.empolyer_name[j]!='\0'; j++);
	if(empolyer_name!=NULL)
		delete[] empolyer_name;
	empolyer_name=new char[j+1];
	for (j = 0; e.empolyer_name[j]!='\0'; j++)
		empolyer_name[j]=e.empolyer_name[j];
	empolyer_name[j]='\0';

	seniority=e.seniority;
	salary=e.salary;
}

void Empolyee::check_exception(const Empolyee&e)const //������� ������ ������ ����� �������
{
	int i=0,flag=1;
	if(e.full_name[i]<'A' || e.full_name[i]>'Z')
		throw "The word does not open with big latter!";

	for ( i = 1;e.full_name[i]!='\0'; i++)
	{
		if(i>MAX_NAME)
			throw "the length of the name is too long!";

		if(e.full_name[i]==' ' || e.full_name[i]=='-')
		{
			flag=0;
			if(e.full_name[i+1]<'A' || e.full_name[i+1]>'Z')
				throw "The word does not open with big latter!";
		}
		else 
			if((e.full_name[i]>='A' && e.full_name[i]<= 'Z')&&(e.full_name[i-1]!=' ' && e.full_name[i-1]!='-'))
				throw "There is big latters in the empolyee name!";
	}
	if (i<MIN_NAME)
		throw "the length of the name is too short!";

	if(flag)
		throw "There is no  ' ' OR '-' between the first name and last name";

	if(e.seniority<0||e.seniority>50)
		throw "The seniority is over 50 or under 0!";

	if(e.salary<0)
		throw "The salary is negative";
}