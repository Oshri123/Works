#include "Student.h"
#include "Course.h"
#include "Depertment.h"

student::student()//����� ���� ��������� ������ �� �� �������
{
	courses=NULL;
	amount_courses=0;
	id=0;
	gender=NULL;
	age=0;
	NameStu="";
	student_dep=NULL;
}
student::~student()//����� ����� ������ �� ������� 
{
	if(courses!=NULL)
		delete[] courses;
}
void student::set_dep( Depertment*d)
{
	student_dep=d;

}
student::student(const student&s)//���� �����
{
	NameStu=s.NameStu;
	id=s.id;
	gender=s.gender;
	age=s.age;
	amount_courses=s.amount_courses;
	student_dep=s.student_dep;
	courses=new Course*[amount_courses];//����� ������ ������ ������� ����� �����
	for (int i = 0; i < amount_courses; i++)//����� ������� �� ������� �� ����� �� ������� 
	{
		courses[i]=new Course;
		*courses[i]=*s.courses[i];
	}
}
student student::operator = (const student&s )//������� ����, ����� �� �� ���� ������� �������� ������ ������� ������� �����
{

	NameStu=s.NameStu;
	id=s.id;
	gender=s.gender;
	age=s.age;
	amount_courses=s.amount_courses;
	student_dep=s.student_dep;
	delete courses;
	courses=new Course*[amount_courses];//����� ������ ������ ������� ����� �����
	for (int i = 0; i < amount_courses; i++)//����� ������� �� ������� �� ����� �� ������� 
	{
		courses[i]=new Course;
		*courses[i]=*s.courses[i];
	}
	return s;
}
const bool student::operator==(const student &s )//������� ������ ��� �.� �� ������ ������ ������ ������� ����
{
	if (id == s.id)
		return 1;
	else return 0;

}
const bool student::operator >(const student&s)//������� ����� ��� ������ ������ �� ������� ���� ���� ������� �� �������-�����
{
	float average=0,_average=0;
	for(int i=0;i<amount_courses;i++)//����� ������� ������ �� �� ������� �� ������� �����
	{
		for(int j=0;j<courses[i]->getAmount();j++)//����� ������ ������ �� �� ���� ������ �� ����� ���
		{
			if( ( *courses[i]->getRegister()[j] ) == *this)//����� ����� ������� ������ �������
				if(courses[i]->getGrade()[j]!= -1)
					average+=courses[i]->getGrade()[j];//����� �� ������� �� ��� ����� ������
		}
	}

	for(int i=0;i<s.amount_courses;i++)//����� ������� ������ �� �� ������� �� ������� �����
	{
		for(int j=0;j<s.courses[i]->getAmount();j++)//����� ������ ������ �� �� ���� ������ �� ����� ���
		{
			if( (*(s.courses[i]->getRegister())[j]) == *this)//����� ����� ������� ������ �������
				if(s.courses[i]->getGrade()[j]!= -1)
					_average+=courses[i]->getGrade()[j];//����� �� ������� �� ��� ����� ������
		}
	}

	average=average/amount_courses;
	_average=_average/s.amount_courses;

	if(average >_average)//����� ���� ����� ���� ����
		return true;
	else 
		return false;

}
ostream& operator<<(ostream&out, const student&s)//������� ��� �� ���� �������
{
	out<<"Name: "<<s.NameStu<<", Id: "<<s.id<<", gender: "<<s.gender<<", age: "<<s.age<<endl;
	if(s.amount_courses)
	{
		cout<<"Courses:\n";
		for (int i = 0; i < s.amount_courses; i++)//����� ������� �� ���� ������� �������� ���� ����� �� ����
			out<<"Name: "<<s.courses[i]->getNameC()<<", Number: "<<s.courses[i]->getNumOfTheCours()<<endl;
	}

	return out;
}
istream& operator>>(istream&in, student&s)//������� ��� �� ���� ������ 
{
	cout<<"Please enter student details.\n"<<"Name: ";	
	in>>s.NameStu;
	cout<<"Id: ";
	in>>s.id;
	cout<<"Gender: ";
	in>>s.gender;
	cout<<"Age: ";
	in>>s.age;

	return in;

}
student& student::operator+=(Course *c) //������� ������ ���� �������
{

	if(!check_if_course_exists(c))//����� ������� ������ �� ����� ��� ���� ��� �������
	{
		Course **_courses=courses;//����� ����� ����� �� ������ �� ���� ������� �� �������

		amount_courses++;//����� ���� ������� �� �������

		courses=new Course*[amount_courses];//����� ������ ��� ����� �������

		for(int i=0;i< amount_courses-1;i++)//����� ������� �� ������� ������ ������
			courses[i]=_courses[i];

		courses[amount_courses-1]=c;//����� ����� ������ �������
	}
	return *this;
}
student& student::operator-=(Course *c)//������� ������ ���� ��������
{


	int j=0;
	for(int i=0;i<amount_courses;i++)//����� ������ �� ����� ���� ��� �������
		if ( *courses[i]==*c )
		{
			courses[i]=NULL;//����� ������ �� ����� ���� ��� ������� null
			break;
		}

		Course **_courses=courses;//����� ����� ����� �� ������ �� ���� ������� �� �������
		amount_courses--;//����� ���� ������� �� �������

		courses=new Course*[amount_courses];//����� ������ ��� ����� �������

		for(int i=0;i<amount_courses+1;i++)//����� ������ ����� ����� ��� ����� ������ ���� �������
		{
			if(courses[i]==NULL)
				continue;
			else
			{
				_courses[j]=courses[i];
				j++;
			}
		}

		return *this;
}
Course student::operator[]( int location )//������� ������ �� ����� ������� - ���� �� ����� ����� ������ ������ �� ����� ������ ������ ��
{
	return *courses[location];
}
int student::check_if_course_exists(Course *c)//������� ������� ������ �� ����� ���� ������ ������� �� �������
{
	for(int i=0;i<amount_courses;i++)
		if ( *courses[i]==*c )
			return 1;

	return 0;
}
float student::alculation_average_all_courses()//������� ��� ������ �� ����� ������� �� �� ������� �� �������
{
	float average_all_courses=0;
	for(int i=0;i<amount_courses;i++)//����� ������� ������ �� �� ������� �� ������
	{
		for(int j=0;j<courses[i]->getAmount();j++)//����� ������ ������ �� �� �������� ������ �� ����� �� ������ 
		{
			if( ( *courses[i]->getRegister()[j] ) == *this)
				if(courses[i]->getGrade()[j]!= -1)
					average_all_courses+=courses[i]->getGrade()[j];
		}
	}
	return (average_all_courses/amount_courses);//����� ����� ������� �� ������� ��� �������
}