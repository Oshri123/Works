#include "College.h"
College::~College()//���� ���� ������ ������� �� ����� ����
{
	if(all_dep!=NULL)
		for(int i=0;i<total_dep;i++)
			delete all_dep[i];

	if(std_total!=NULL)
		delete std_total;
}
College::College(const College&c)//���� �����
{
	total_dep=c.total_dep;
	total_student=c.total_student;
	delete all_dep;
	delete std_total;
	all_dep=new Depertment*[total_dep];//����� ������ ������ ������� ����� �����
	std_total=new student*[total_student];//����� ������ ������ ��������� ����� �����

	for(int i=0;i<total_dep;i++)//����� ������� �� ���� ������� �� ������ ����� �����
	{
		all_dep[i]=new Depertment;
		*all_dep[i]=*c.all_dep[i];
	}

	for (int i = 0; i < total_student; i++)//����� ������� �� ���� ��������� �� ������ ����� �����
	{
		std_total[i]=new student;
		*std_total[i]=*c.std_total[i];
	}
}
void College::Add_department()//����� ����� ���� 
{
	Depertment **new_dep=all_dep;//����� ����� ��� ������ �� ������ �� ������ �� �������
	Depertment *_d=new Depertment();//����� ����� ����
	cin>>*_d;//��� ���� ������

	if(check_if_dep_exists(_d->getCode())==NOT_EXISTS)//����� �� ������ ����� ���
	{
		all_dep=new Depertment*[total_dep+1];//����� ������ ������ ������ �����
		for(int i=0;i<total_dep;i++)//����� ������� �� �����
			all_dep[i]=	new_dep[i];

		all_dep[total_dep]=new Depertment;
		all_dep[total_dep]=_d;//����� ����� ���� ������ �������
		total_dep++;

	}
	else 
		cout<<"Department already exists!\n";

}
int College::check_if_dep_exists(int code)//�������� ��� ������ �� ������ ����� ������ �������
{
	for(int i=0; i<total_dep;i++)
		if(code == all_dep[i]->getCode())//�� ��� ����� ����� ������ ��� �����
		{
			return i;
		}

		return NOT_EXISTS;//���� ����� ����� ������ ������ ������� �� �����
}
int College::check_if_courses_exists(int code,int location)//�������� ��� ������ �� ����� ����� ������ �������
{
	for(int i=0; i<all_dep[location]->getAmou_Crs(); i++)
		if(code == all_dep[location]->getCrs()[i]->getNumOfTheCours())//�� ��� ����� ����� ������ ��� �����
		{
			return i;
		}
		return NOT_EXISTS;//���� ����� ����� ������ ������ ������ �� ����
}
int College::check_if_students_exists(student *s ,int location)//�������� ��� ������ �� ������ ����� ������ �������
{
	for(int i=0; i<all_dep[location]->getAmou_Std(); i++)
		if( *(all_dep[location]->getStd()[i]) == *s)//�� ��� ���� ����� ������ ��� �����
		{
			return i;
		}
		return NOT_EXISTS;//���� ����� ����� ������ ������ �������� �� �����
}
void College::Add_course_to_department()//������� ������� ���� ������
{
	Course *_c=new Course;//����� ����� ��� ���� ����
	int dep_location,dep_code;
	cout<<"Enter department code: ";
	cin>>dep_code;
	dep_location=check_if_dep_exists(dep_code);

	if(dep_location!=NOT_EXISTS )//����� �� ������ �����
	{
		cin>>*_c;//����� ���� �����
		for(int i=0; i<all_dep[dep_location]->getAmou_Crs(); i++)//����� �� ����� ���� ��� ������
			if( *(all_dep[dep_location]->getCrs()[i] )== *_c)
			{
				cout<<"Course already exists in some department!\n";
				return;
			}
			*(all_dep[dep_location])+= _c;//�� �� ���� ��� ������ ������ �������
			_c->set_course_dep(all_dep[dep_location]);
	}
	else 
		cout<<"Department does not exists!\n";
}
void College::Add_student_to_department()
{
	student *_s=new student; //����� ����� ���� ������
	int dep_location,dep_code;
	cout<<"Enter department code: ";
	cin>>dep_code;
	dep_location=check_if_dep_exists(dep_code);

	if(dep_location!=NOT_EXISTS )//����� �� ������ �����
	{
		cin>>*_s;//����� ���� �������
		for(int i=0;i<all_dep[dep_location]->getAmou_Std();i++)
			if( *_s == *(all_dep[dep_location]->getStd()[i]) )
			{
				cout<<"Student already exists in some department!\n";
				return;
			}
			//total_student++;//����� ���� ��������� ������
			*(all_dep[dep_location])+= _s;//������ ������� ������

			student **new_std=std_total;//����� ������ ������
			std_total=new student*[total_student+1];
			for (int i = 0; i < total_student; i++)
				std_total[i]=new_std[i];

			std_total[total_student]=_s;
			std_total[total_student]->set_dep( all_dep[dep_location] );// ����� ������ �������

			total_student++;//����� ���� ��������� ������

	}
	else 	cout<<"Department already exists!\n";

}
void College::Register_student_to_course()//�������� ������ ������ ������� �����
{
	student *selected_stu=NULL,s;
	Course *selected_crs=NULL;
	int dep_code;
	int num_of_course;
	int id;
	cout<<"Enter department code, course number and id of student:\n";
	cin>>dep_code>>num_of_course>>id;
	s.setID(id);
	int dep_location=check_if_dep_exists(dep_code);
	int course_location=check_if_courses_exists(num_of_course,dep_location);
	int student_location=check_if_students_exists(&s,dep_location);
	if(dep_location==NOT_EXISTS)//����� �� ������ �����
		cout<<"Depertment does not exist!\n";
	else if(course_location==NOT_EXISTS)//����� �� ����� ����
		cout<<"Course does not exist!\n";
	else if(student_location==NOT_EXISTS)//����� �� ������� ����
		cout<<"Student does not exist!\n";
	else {
		selected_stu=all_dep[dep_location]->getStd()[student_location];
		selected_crs=all_dep[dep_location]->getCrs()[course_location];

		*selected_crs+=selected_stu;//����� ������� �����
		*selected_stu+=selected_crs;//����� ����� ������ ������� �� �������
	}


}
void College::Print_course_information()//����� ����� �� ����
{
	int course_number,course_location;
	Course *c=NULL,_c;
	cout<<"Enter course number: ";
	cin>>course_number;
	cout<<endl;
	for (int i = 0; i < total_dep; i++)
	{
		course_location=check_if_courses_exists(course_number,i);//����� ����� ����� ������
		if(course_location!=NOT_EXISTS)
		{
			c=all_dep[i]->getCrs()[course_location];
			break;
		}
		else if(i==total_dep)
		{
			cout<<"Course does not exist!\n";
			return;
		}
	}
	cout<<"The course was found in the following department:\n";
	cout<<"Name: "<<c->get_depCourse()->getDep_N()<<"\ncode: "<<c->get_depCourse()->getCode()<<endl;
	cout<<"Course information:\n"<<*c;

	if(c->calculation_average()!=-1)//����� �������� ������ ����� ����
		cout<<"The course average  is: "<<c->calculation_average()<<endl;//����� ����� ����� �� ��� ��������� ����� �� ����
}
void College::Grading_students_in_course()//������� ������ ���� ��������� �����
{
	int course_number,course_location,dep_location,grade;
	cout<<"Enter course number: ";
	cin>>course_number;
	for (int i = 0; i < total_dep; i++)//����� ����� ����� ������
	{
		course_location=check_if_courses_exists(course_number,i);
		if(course_location!=NOT_EXISTS)
		{
			dep_location=i;
			break;
		}
		else if(i==total_dep)
		{
			cout<<"Course does not exist!\n";
			return;
		}
	}
	int num_std=all_dep[dep_location]->getCrs()[course_location]->getAmount();//����� ���� ��������� ����� ������ ���
	cout<<"Please enter grades for the following students (ids).\n";
	for (int i = 0; i < num_std; i++)//����� ������ �.� �� ������� ������ ��� �� �������
	{
		cout<<all_dep[dep_location]->getCrs()[course_location]->getRegister()[i]->getID()<<": ";
		cin>>grade;
		all_dep[dep_location]->getCrs()[course_location]->setGrade(i,grade);
		cout<<endl;
	}
	cout<<"Finished grading students.\n";
}
void College::Print_student_information()//����� ����� �� ������
{
	student *s=NULL,_s;
	int id;
	cout<<"Enter student id: ";
	cin>>id;
	cout<<endl;
	_s.setID(id);//����� ��.� �� ������� �������� ���� ������ �������� ������ ��� ������
	for (int i = 0; i < total_student; i++)//����� ������� ����� ���� �� ��������� 
	{
		if(*std_total[i]==_s)//����� �� ����� �� ������� �����
		{
			s=std_total[i];
			cout<<"The course was found in the following department:\n";
			cout<<"Name: "<<s->get_dep()->getDep_N()<<"\ncode: "<<s->get_dep()->getCode()<<endl;//����� ���� �������
			cout<<"Student information:\n"<<*s;
			return;
		}
	}
	cout<<"Student does not exist!\n";
}
void College::Print_department_information()//����� ����� �� �����
{
	int dep_location,dep_code;
	cout<<"Enter department code: ";
	cin>>dep_code;
	cout<<endl;
	dep_location=check_if_dep_exists(dep_code);
	if (dep_location==NOT_EXISTS)//����� �� ������ �����
	{
		cout<<"Department does not exists!\n";
		return;
	}
	cout<<*(all_dep[dep_location]);//����� ������� ������ �� ������ �� ������ �������
}
void College::Find_students_with_bad_academic_status()//�������� ������ �������� �� ������ ����� �65
{
	student *s=NULL;
	int dep_location,dep_code,j=0;
	cout<<"Enter department code: ";
	cin>>dep_code;
	cout<<endl;
	dep_location=check_if_dep_exists(dep_code);//����� �� ������ �����
	if (dep_location==NOT_EXISTS)
	{
		cout<<"Department does not exists!\n";
		return;
	}

	all_dep[dep_location]->reset_fstd();//����� ����� �� �������� ������� ���� �� ����� ���� ��������
	int amount_s=all_dep[dep_location]->getAmou_Std();//����� ���� �������� ������ ���
	for (int i = 0; i <amount_s ; i++)//����� ������ �� �� �������� ������ ������� �������� ��� �� ���������� ���� ������� ���� �����
	{
		if( (all_dep[dep_location]->getStd()[i]->alculation_average_all_courses()>=0 ) && ( all_dep[dep_location]->getStd()[i]->alculation_average_all_courses()<=65) )
		{
			s=all_dep[dep_location]->getStd()[i];
			all_dep[dep_location]->setAmou_Failed_Std(s,j);
		}
	}
}
void College::Remove_student_from_course()//������� ����� ������ ����� 
{
	student *selected_stu=NULL,s;
	Course *selected_crs=NULL;
	int id, course_location, student_location,course_dep_location,student_dep_location,num_of_course;
	cout<<"Enter course number and id of student:\n";
	cin>>num_of_course>>id;
	s.setID(id);

	for(int i=0;i<total_dep;i++)//����� �� ����� ����
	{
		for (int j = 0; j < all_dep[i]->getAmou_Crs(); j++)
		{
			course_location=check_if_courses_exists(num_of_course,i);
			if(course_location!=NOT_EXISTS)
			{
				course_dep_location=i;
				break;
			}
		}
	}

	for(int i=0;i<total_dep;i++)//����� �� ������� ���� �����
	{
		for (int j = 0; j < all_dep[i]->getAmou_Std(); j++)
		{
			student_location=check_if_students_exists(&s,i);
			if(student_location!=NOT_EXISTS)
			{
				student_dep_location=i;
				break;
			}
		}
	}

	if(course_location==NOT_EXISTS)
		cout<<"Course does not exist!\n";
	else if(student_location==NOT_EXISTS)
		cout<<"Student does not exist!\n";
	else
	{
		selected_stu=all_dep[student_dep_location]->getStd()[student_location];
		selected_crs=all_dep[course_dep_location]->getCrs()[course_location];

		*selected_crs-=selected_stu;//���� ������ ������ �������
		*selected_stu-=selected_crs;//���� ����� ������ ������� �� �������
	}

}
int College::menu()//�������� ������ 
{
	int choice;

	do{		system("cls");
	cout<<"1 - add department\n";
	cout<<"2 - Add course to department\n";
	cout<<"3 - Add student to department\n";
	cout<<"4 - Register student to course\n";
	cout<<"5 - Grading students in course\n";
	cout<<"6 - Print course information\n";
	cout<<"7 - Print student information\n";
	cout<<"8 - Print department information\n";
	cout<<"9 - Find students with bad academic status\n";
	cout<<"10 - Remove student from course\n";
	cout<<"11 - Exit\n";
	cout<<"please enter your choice: ";
	cin>>choice;
	cout<<endl;
	switch (choice)//����� ������� �� ����� ������ ������� �� �������� �������
	{
	case 1:
		Add_department();
		break;

	case 2:
		Add_course_to_department();
		break;

	case 3:
		Add_student_to_department();
		break;

	case 4:
		Register_student_to_course();
		break;

	case 5:
		Grading_students_in_course();
		break;

	case 6:
		Print_course_information();
		break;

	case 7:
		Print_student_information();
		break;

	case 8:
		Print_department_information();
		break;

	case 9:
		Find_students_with_bad_academic_status();
		break;

	case 10:
		Remove_student_from_course();
		break;

	}


	system("pause");//����� ���� ���� �����
	}while(choice!=EXIT);

	return 0;
}

