#include "Depertment.h"
#include "Course.h"
#include "Student.h"
Course::~Course()//���� ���� ������ ������ ������ ����
{
	if (registered!=NULL)
		delete registered;

	if(grade!=NULL)
		delete grade;

	/*if(dep_course!=NULL)
	delete dep_course;*/
}
Course::Course(const Course&c)//���� �����
{
	Name_C=c.Name_C;
	NumOfTheCours=c.NumOfTheCours;
	amount_students=c.amount_students;
	dep_course=c.dep_course;
	registered=new student*[c.amount_students];//����� ������ ������ ��������� ����� �����
	grade=new int[c.amount_students];//����� ������ ����� ������� ����� �����

	for (int i = 0; i < amount_students; i++)//����� ������� �� ������� �� ����� �� �������� ������ �� ���� �������
	{
		registered[i]=new student;
		*registered[i]=*c.registered[i];
		grade[i]=c.grade[i];
	}
}
void Course::set_course_dep(Depertment *d)
{
	dep_course=d;
}
Course Course::operator = (const Course&c )//������� ����, ����� �� �� ���� ����� ������ ������ ������� ����� �����
{
	Name_C=c.Name_C;
	NumOfTheCours=c.NumOfTheCours;
	amount_students=c.amount_students;
	dep_course=c.dep_course;
	delete registered;
	delete grade;
	registered=new student*[c.amount_students];//����� ������ ������ ��������� ����� �����
	grade=new int[c.amount_students];//����� ������ ����� ������� ����� �����

	for (int i = 0; i < amount_students; i++)//����� ������� �� ������� �� ����� �� �������� ������ �� ���� �������
	{
		registered[i]=new student;
		*registered[i]=*c.registered[i];
		grade[i]=c.grade[i];
	}

	return c;
}
const bool Course::operator==(const Course&c )//������� ������ ��� ����� ����
{
	if (NumOfTheCours==c.NumOfTheCours)
		return 1;
	else return 0;

}
const bool Course::operator>(const Course&c)//������� ����� �� �� ���� �������� �����
{
	return(amount_students>c.amount_students);
}
istream& operator>>(istream&in,Course&c)//������� ��� �� ���� ����� ���� �������� ��������
{
	cout<<"Please enter course details.\n"<<"Name: ";
	in>>c.Name_C;
	cout<<"Number: ";
	in>>c.NumOfTheCours;

	return in;
}
ostream& operator<<(ostream&out,Course&c)//������� ��� �� ���� �����
{
	out<<"Name: "<<c.Name_C<<endl;
	out<<"Number: "<<c.NumOfTheCours<<endl;
	if(c.amount_students)//����� ������� �� ���� ��������� ������� ����� �� ����
	{
		out<<"Students:\n";
		for (int i = 0; i < c.amount_students; i++)
		{
			out<<"Name: "<<c.registered[i]->getName()<<", Id: "<<c.registered[i]->getID()<<", gender: "<<c.registered[i]->getGender()<<", age: "<<c.registered[i]->getAge();
			if(c.grade[i] != -1)
				out<<" Grade: "<<c.grade[i]<<endl;
			else
				out<<endl;
		}
	}

	return out;
}
student Course::operator[](int location)// ������� ������ ������ ������� - ���� �� ����� ������� ������ ������ �� ������� ������ ������ ��
{
	return ( *registered[location] );
}
Course& Course::operator+=(student *s)//������� ������ ������ �����
{

	if(!check_if_student_exists(s))//����� ������� ������ �� ������� ��� ���� �����
	{
		student **_registered =registered;//����� ����� ����� �� ������ �� ���� ��������� �� �����
		int *_grade=grade;//����� ����� ����� �� ������ �� ���� �������
		amount_students++;//����� ���� ���������

		registered =new student*[amount_students];//����� ������ ��� ����� �������
		grade=new int[amount_students];//����� ������ ��� ����� �������
		for (int i = 0; i < amount_students-1; i++)//����� ������� �� ������� ������� ��������
		{
			registered[i]=_registered[i];
			grade[i]=_grade[i];
		}
		registered[amount_students-1]=s;//����� ������� �����
		grade[amount_students-1]=-1;//����� ���� �������
	}
	return *this;
}
Course& Course::operator-=(student *s)//������� ������ ������ ������
{

	int j=0;
	for(int i=0;i<amount_students;i++)//����� ������ �� ������� ���� �����
		if ( *registered[i]==*s )
		{
			registered[i]=NULL;//����� ������ �� ������� ���� ����� null
			break;
		}

		student **_registered=registered;//����� ����� ����� �� ������ �� ���� ��������� �� �����
		int *_grade=grade;//����� ����� ����� �� ������ �� ���� �������

		amount_students--;//����� ���� ��������� �����


		registered=new student*[amount_students];//����� ������ ��� ����� �������
		grade=new int[amount_students];//����� ������ ��� ����� �������

		for(int i=0;i<amount_students+1;i++)//����� ������ ����� ����� ��� ������� ������ ���� �������
		{
			if(_registered[i]==NULL)
				continue;
			else
			{
				registered[j]=_registered[i];
				grade[j]=_grade[i];
				j++;
			}
		}

		return *this;
}
int Course::check_if_student_exists(student *s)//������� ��� ������ �� ������ ���� �����
{
	for (int i = 0; i < s->getAmountC(); i++)
		if(s->getCourses()[i] == this)
			return 1;

	return 0;
}
float Course::calculation_average()//�������� ��� ������ �� ����� �� �������� �����
{
	float average=0;
	if (amount_students==0)//�� ��� ������� ����� -1
		return -1;
	else
	{
		for (int i = 0; i < amount_students ; i++)// ����� ������ �� ����� ��������� �� ��� ���� ��������
		{
			if (grade[i]==-1)
				return -1;
			else average+=grade[i];
		}
	}
	return (average/amount_students);//����� ����� �������
}