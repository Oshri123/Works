#include "School.h"

School::School()
{
	int j=0;
	amount_layers=6;
	layers=new Layer*[amount_layers];

	for(char i='a';i != 'g';i++)
	{
		layers[j]=new Layer(i);
		j++;
	}
	amount_presons=0;
	persons=NULL;
	exist_manager=false;
}

School::~School()
{

	for (int i = 0; i < amount_layers; i++)
		delete layers[i];

	if(layers!=NULL)
		delete[] layers;

	for (int i = 0; i < amount_presons; i++)
	{
		if(persons[i]!=NULL)
			delete persons[i];
	}

	if(persons!=NULL)
		delete[] persons;

}

void School::help_copy(Person *p,int location)//����� ��� ����� ����� ������ ���� ������ �� �� ����� �� �������� ���������
{
	Pupil *help1=dynamic_cast<Pupil*>(p);//����� ��������-���� ���� ������ ������� ���� �����
	Teacher *help2=dynamic_cast<Teacher*>(p);//����� ��������-���� ���� ������ ������� ���� ����
	Tutor *help3=dynamic_cast<Tutor*>(p);//����� ��������-���� ���� ������ ������� ���� ����
	Manager *help4=dynamic_cast<Manager*>(p);//����� ��������-���� ���� ������ ������� ���� ����
	Secretary *help5=dynamic_cast<Secretary*>(p);//����� ��������-���� ���� ������ ������� ���� ������

	if(help1!=NULL)//����� �� �������� ������ ��� �� �����
	{
		for (int i = 0; i < amount_layers; i++)//����� ������ �� �� ������
		{
			for (int j = 0; j < 3; j++)// ����� ������ ������ ��  3 ������ ���� �����
				for(int k=0;k<layers[i]->get_classes()[j]->get_amount_pupils();k++)//����� ������ ������ �� �� �������� ���� ����
				{
					if(layers[i]->get_classes()[j]->get_pupils()[k]->get_id()==help1->get_id())//������ ������ ������� �� �������� ������ �"� �.�
						persons[location]=layers[i]->get_classes()[j]->get_pupils()[k];//�� ���� ������ ���� ������� �� ������ ��� ����� �������� ���� ������ ������ ������
				}
		}
	}
	else if((help2!=NULL)&&(help3==NULL))//����� �� �������� ������ ��� �� ����
		persons[location]=new Teacher(*help2);//����� ������� ��� ������ ����� ��������� ����� �-�������
	else if(help3!=NULL)//����� �� �������� ������ ��� �� ����
		persons[location]=new Tutor(*help3);//����� ������� ��� ������ ����� ��������� ����� �-�������
	else if(help4!=NULL)//����� �� �������� ������ ��� �� ����
		persons[location]=new Manager(*help4);//����� ������� ��� ������ ����� ��������� ����� �-�������
	else if(help5!=NULL)//����� �� �������� ������ ��� �� ������
		persons[location]=new Secretary(*help5);//����� ������� ��� ������ ������� ��������� ����� �-�������
}

School::School(const School&obj):amount_layers(obj.amount_layers),amount_presons(obj.amount_presons),exist_manager(obj.exist_manager)
{
	layers=new Layer*[obj.amount_layers];//����� ������ ��� ����� ������
	for (int i = 0; i < obj.amount_layers; i++)//����� ������ ��������� ������� ���� ����� �� �����
		layers[i]=new Layer(*obj.layers[i]);

	persons=new Person*[obj.amount_presons];//����� ������ ��� ����� ������
	for (int i = 0; i < obj.amount_presons; i++)//����� �������� ��������� ������� ���� ����� ��������� �� ����� ������ ��� ����� �� ���� ����� ���
		help_copy(obj.persons[i],i);
}

void School::add_person( Person *p)
{
	Person **temp=persons;//����� ����� ��� ����� �-�������

	persons=new Person*[amount_presons+1];//����� ���� �-������� ���� ������ �� �� ������ ����
	for (int i = 0; i < amount_presons; i++)//����� ������� �� �� ������ ���� ����� ���� ������ �����
		persons[i]=temp[i];

	persons[amount_presons]=p;//����� ������ ����� �-�������
	amount_presons++;//����� ���� ������ ���� ����

	if(temp!=NULL)//����� ����� ����
		delete[] temp;
}

bool School::check_if_person_exist(int _id)
{
	for (int i = 0; i < amount_presons; i++)
		if(persons[i]->get_id()==_id)
			return true;
	return false;
}

void School::Add_pupil()//������� ������ ����� ���� ����
{
	Pupil *pupil=new Pupil;//����� ������� ����� ���� �����

	char layer_n;
	int class_n;

	do{cout<<"Enter layer: ";
	cin>>layer_n;
	}while((layer_n <'a'||layer_n > 'f') && (cout<<"\nWrong input , try again!\n\n"));//check layer input is from a-f

	do{cout<<"\nEnter class: ";
	cin>>class_n;
	}while(( class_n<1 || class_n>3) && (cout<<"\nWrong input , try again!\n\n"));//check class number input is from 1-3

	pupil=pupil->Add_person(persons,layer_n,class_n,amount_presons);// ����� �������� ������ ������� ����� ���

	if (check_if_person_exist(pupil->get_id()))//����� �� ������ ��� ���� ���� ����
	{
		cout<<"The pupil already exist in the school!\n";
		delete pupil;
		return;
	}
	add_person(pupil);//����� �������� ������� �� ������ ����� �������� ���� ����
	layers[layer_n-97]->get_classes()[class_n-1]->add_pupil(pupil);//����� ������ ����� �������
}

void School::Add_teacher()
{
	Teacher *teacher=new Teacher;//����� ������� ����� ���� ����
	int amount_courses;

	teacher->set_person();//����� �������� ������ ���� �����

	if(check_if_person_exist(teacher->get_id()))//����� ������ �� ����� ��� ����� ���� ����
	{
		delete teacher;
		cout<<"The teacher already exist in the school!\n";
	}
	teacher->set_professions();//����� ������ ������ ������� ������ ����/�
	add_person(teacher);//����� �������� ������� �� ����� ����� �������� ���� ����
}

void School::Add_tutor()
{	
	Tutor *tutor=new Tutor;//����� ������� ����� ���� ����

	char layer_n;
	int amount_courses,class_n;

	do{cout<<"Enter layer: ";
	cin>>layer_n;
	}while((layer_n <'a'||layer_n > 'f') && (cout<<"\nWrong input , try again!\n\n"));//check layer input is from a-f

	do{cout<<"\nEnter class: ";
	cin>>class_n;
	}while(( class_n<1 || class_n>3) && (cout<<"\nWrong input , try again!\n\n"));//check class number input is from 1-3

	if(layers[layer_n-97]->get_classes()[class_n-1]->get_tutor()!=NULL)//����� �� ����� �� ��� ����
	{
		cout<<"The class already have tutor!\n";
		delete tutor;//����� ������� �� ����� ��� ����
		return;
	}

	tutor->set_person();//����� �������� ������ ������ ���� �����

	if(check_if_person_exist(tutor->get_id()))//����� �������� ������ �� ����� ��� ���� ���� ����
	{
		delete tutor;//����� ������� �� ����� ��� ����
		cout<<"The tutor already exist in the school!\n";
		return;
	}

	tutor->set_professions();//����� ������ ������� �����
	layers[layer_n-97]->get_classes()[class_n-1]->set_tutor(tutor);//����� ����� ����� �������
	tutor->set_cls(layers[layer_n-97]->get_classes()[class_n-1]);//����� ����� ������� ����� 
	add_person(tutor);//����� �������� ������� �� ����� ����� �������� ���� ����
}

void School::Add_manager()
{
	if(exist_manager)//����� �� ���� ���� ���� ����
	{
		cout<<"The school already have manager!\n";
		return;
	}
	exist_manager=true;//����� ������ �������� ����

	Manager *manager=new Manager;//����� ������� ����� ���� ����

	manager->set_person();//����� ���� ����� �������
	if(check_if_person_exist(manager->get_id()))//����� �� ���� ��� ���� ���� ����
	{
		delete manager;
		cout<<"The person already exist in the school!\n";
		return;
	}
	add_person(manager);//����� �������� ������� �� ����� ����� �������� ���� ����
}

void School::Add_secretary()
{

	Secretary *secretary=new Secretary;//����� ������� ����� ���� ������
	secretary->set_person();//����� ������� ���� �������

	if(check_if_person_exist(secretary->get_id()))//����� �� ���� ��� ���� ���� ����
	{
		delete secretary;
		cout<<"\nThe secretary already exist in the school!\n";
		return;
	}
	add_person(secretary);//����� �������� ������� �� ������� ����� �������� ���� ����
}

void School::Print_workers_and_pupil_details()//����� ������� �� ���� �� ������ ������ ���� ����
{
	for (int i = 0; i < amount_presons; i++) ///����� ��� ���� ������
	{
		cout<<"******* Person number "<<i+1<<": *******\n";
		persons[i]->print_person();//����� ������������ ������ ���� �� ���� ������
		cout<<endl;
	}
}

void School::Print_outstanding_people()//����� ������� �� �� ������ ���� ���� ���������
{
	int flag=0;
	for (int i = 0; i < amount_presons; i++) ///����� ��� ���� ������
	{
		if(persons[i]->check_if_outstanding())//����� ������������ ������ �������� ������
		{
			flag=1;
			cout<<"*******\n";
			persons[i]->print_person();//����� ������������ ������ ���� �� ������ ���������
			cout<<"*******\n";
		}
	}
	if(!flag)
		cout<<"There is no outstanding persons in the school!\n";
}

void School::Print_tutor_class()//����� ������ ������� ����� ���� ��� ��� �.� �� ���� ��� ������ �� ���� ����� ��� ���� �� ������ ����� �����
{
	int id;
	Tutor *help;//����� ����� ��� ������ ��������-����
	cout<<"Enter tutor id: ";
	cin>>id;//����� �.� �������
	cout<<endl;
	for (int i = 0; i < amount_presons; i++)//����� ������ �� �� ������ ������ �� ����� ����� ����
	{
		if(persons[i]->get_id()==id)//�� �� ����� ������ ����� ������ ������� �������-���� ��� ����
		{
			help=dynamic_cast<Tutor*>(persons[i]);//����� �������-���� ������ ����� ��������
			if(help!=NULL)//����� �� ��� ����
			{
				cout<<"The layer of the tutor is: "<<help->get_cls()->get_layer_name()<<endl;//����� �� ����� ��� ��� ����
				cout<<"The number of his class: "<<help->get_cls()->get_num_class()<<endl;//����� ���� ����� 
				help->print_pupils();//����� ������ �� ����� ������� �� �������
				return;
			}
		}
	}
	cout<<"This id is not a tutor id!\n";
}

void School::Print_worker_details_with_biggest_salary()//����� ������ �� ����� �� ���� ��� ����� ������� �� �����
{
	Worker *help;//����� ����� ��� ������ ��������-����
	int max_salary=0,location;//����� ������ ������ ������� ��� ����� ������� ������ �� ���� ����� �-�������

	for (int i = 0; i < amount_presons; i++)//����� ������ �� �� ������ ����� �-�������
	{
		help=dynamic_cast<Worker*>(persons[i]);//����� �������-���� ������ ����� ��������
		if(help!=NULL)//����� �� ��� ��� ���� ������ �������
			if(help->return_salary()>max_salary)//����� ������� ��� �����
			{
				max_salary=help->return_salary();//����� ������� ������
				location=i;//����� ������ �� ���� ����� �� ������� ������
			}
	}
	if(max_salary)
	{
		cout<<"The details of the person with the max salary is:\n\n";
		persons[location]->print_person();//����� ���� ����� ��� ������� ��� �����
	}
	else
		cout<<"There are no persons with salary at this school!\n";

}

void School::manu()
{

	int choice;
	bool exit=true;
	do{		system("cls");
	cout<<"1 - Add pupil\n";
	cout<<"2 - Add teacher\n";
	cout<<"3 - Add tutor\n";
	cout<<"4 - Add manager\n";
	cout<<"5 - Add secretary\n";
	cout<<"6 - Print workers and pupil details\n";
	cout<<"7 - Print outstanding people\n";
	cout<<"8 - Print tutor's class\n";
	cout<<"9 - Print worker details with biggest salary\n";
	cout<<"10 - Exit\n";
	cout<<"please enter your choice: ";
	cin>>choice;
	cout<<endl;
	switch (choice)//����� ������� �� ����� ������ ������� �� �������� �������
	{
	case 1:
		Add_pupil();//����� ������� ����� 
		break;

	case 2:
		Add_teacher();//����� ������� ���� 
		break;

	case 3:
		Add_tutor();//����� ������� ���� 
		break;

	case 4:
		Add_manager();//����� ������� ���� 
		break;

	case 5:
		Add_secretary();//����� ������� ������ 
		break;

	case 6:
		Print_workers_and_pupil_details();//����� ������� �� ���� ������ ������� ���� ���� 
		break;

	case 7:
		Print_outstanding_people();//����� ������� �� ���� ������ ��������� ����� ����
		break;

	case 8:
		Print_tutor_class();//����� ������ �.� ��� ��� ����� ����� ������ �� ���� �����
		break;

	case 9:
		Print_worker_details_with_biggest_salary();//����� ������� �� ����� �� ����� �� ������� ��� �����
		break;

	case 10:
		exit=false;//����� �������
		break;

	}

	system("pause");//����� ���� ���� �����
	}while(exit);
	cout<<"\nGood-Bye..\n\n";
}