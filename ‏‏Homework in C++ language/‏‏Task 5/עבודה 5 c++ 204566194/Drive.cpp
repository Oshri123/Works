#include"CMyArray.h"
#include <iostream>
#include <fstream>
#include <vld.h>
#include <string>
using namespace std;
void main()
{
	string input_file,output_file;
	CMyArray<Student>  *stu_arr1;//����� ������ ������ �� ���������
	CMyArray<Student>  *stu_arr2;//����� ������ ���� �� ���������
	CMyArray<Empolyee> *emp_arr1;//����� ������ ������ �� �������
	CMyArray<Empolyee> *emp_arr2;//����� ������ ���� �� �������
	CMyArray<Empolyee> *emp_arr3;//����� ������ ������ �� �������

	int flag=1,location1,location2,size;
	while(flag){
		cout<<"\nEnter the name of the input file: ";
		cin>>input_file;
		ifstream open(input_file,ios::in);//����� ����� ������
		if(open.fail())//����� ������ ���� ������
			cout<<"\n--The file canot be opened!--\n";
		else
		{
			flag=0;
			cout<<"\nThe file opened correctly!\n";
		}
		open.close();//�� �� ���� ����� ������ ����� ���� ������� ���� ����
	}
	ifstream open(input_file,ios::in);//����� ����� ���� ���� ������ ���� �� �����  ����� ����
	cout<<"\nEnter the name of the output file: ";
	cin>>output_file;
	cout<<endl;
	ofstream write(output_file,ios::out);//����� ����� ������
	
	try{
		open>>size;//����� ����� �� �������� ����� ������
		stu_arr1=new CMyArray<Student>(size);//����� ������ �� �������� �����
		for (int i = 0; i < size; i++)//����� ������� ������ ��������
			open>>stu_arr1->get_arr()[i];

		open>>size;//����� ����� �� �������� ����� ������
		stu_arr2=new CMyArray<Student>(size);//����� ������ �� �������� �����
		for (int i = 0; i < size; i++)//����� ������� ������ ��������
			open>>stu_arr2->get_arr()[i];

		open>>size;//����� ����� �� �������� ����� ������
		emp_arr1=new CMyArray<Empolyee>(size);//����� ������ �� �������� �����
		for (int i = 0; i < size; i++)//����� ������� ������ ��������
			open>>emp_arr1->get_arr()[i];

		open>>size;//����� ����� �� �������� ����� ������
		emp_arr2=new CMyArray<Empolyee>(size);//����� ������ �� �������� �����
		for (int i = 0; i < size; i++)//����� ������� ������ ��������
			open>>emp_arr2->get_arr()[i];

		open>>size;//����� ����� �� �������� ����� ������
		emp_arr3=new CMyArray<Empolyee>(size);//����� ������ �� �������� �����
		for (int i = 0; i < size; i++)//����� ������� ������ ��������
			open>>emp_arr3->get_arr()[i];

		for (int i = 0; i < stu_arr1->get_size(); i++)//����� ������ ������ ������ ��������
			stu_arr1->get_arr()[i].check_exception(stu_arr1->get_arr()[i]);

		for (int i = 0; i < stu_arr2->get_size(); i++)//����� ������ ������ ������ ��������
			stu_arr2->get_arr()[i].check_exception(stu_arr2->get_arr()[i]);

		for (int i = 0; i < emp_arr1->get_size(); i++)//����� ������ ������ ������ ��������
			emp_arr1->get_arr()[i].check_exception(emp_arr1->get_arr()[i]);

		for (int i = 0; i < emp_arr2->get_size(); i++)//����� ������ ������ ������ ��������
			emp_arr2->get_arr()[i].check_exception(emp_arr2->get_arr()[i]);

		for (int i = 0; i < emp_arr3->get_size(); i++)//����� ������ ������ ������ ��������
			emp_arr3->get_arr()[i].check_exception(emp_arr3->get_arr()[i]);

		cout<<"\nEnter two location between 1-2 to swap the first array of students\n";
		cout<<"Location 1: ";
		cin>>location1;
		cout<<"\nLocation 2: ";
		cin>>location2;
		stu_arr1->swap(location1,location2);

		cout<<"\nEnter two location between 1-2 to swap the second array of students\n";
		cout<<"Location 1: ";
		cin>>location1;
		cout<<"\nLocation 2: ";
		cin>>location2;
		stu_arr2->swap(location1,location2);

		cout<<"\nEnter two location between 1-2 to swap the first array of empolyee\n";
		cout<<"Location 1: ";
		cin>>location1;
		cout<<"\nLocation 2: ";
		cin>>location2;
		emp_arr1->swap(location1,location2);

		cout<<"\nEnter two location between 1-2 to swap the second array of empolyee\n";
		cout<<"Location 1: ";
		cin>>location1;
		cout<<"\nLocation 2: ";
		cin>>location2;
		emp_arr2->swap(location1,location2);

		cout<<"\nEnter two location between 1-2 to swap the third array of empolyee\n";
		cout<<"Location 1: ";
		cin>>location1;
		cout<<"\nLocation 2: ";
		cin>>location2;
		emp_arr3->swap(location1,location2);

		write<<"---------------------------------\n";
		write<<"The new file\n";
		write<<"---------------------------------\n";

		stu_arr1->write_to_file(write);//����� ������ ������ ����� �� ������� �� ��������
		stu_arr2->write_to_file(write);//����� ������ ������ ����� �� ������� �� ��������
		write<<"amount of CMyArray<Student>: "<<stu_arr1->find_total()<<endl;
		write<<"---------------------------------\n";
		write<<"amount <Student> total_length: "<<stu_arr1->find_total_length()<<endl;
		write<<"---------------------------------\n";
		emp_arr1->write_to_file(write);//����� ������ ������ ����� �� ������� �� ��������
		emp_arr2->write_to_file(write);//����� ������ ������ ����� �� ������� �� ��������
		emp_arr3->write_to_file(write);//����� ������ ������ ����� �� ������� �� ��������
		write<<"amount of CMyArray<Empolyee>: "<<emp_arr3->find_total()<<endl;
		write<<"---------------------------------\n";
		write<<"amount <Empolyee> total_length: "<<emp_arr3->find_total_length()<<endl;
		write<<"---------------------------------\n";

	}
	catch (char* str)//����� ������ �� �����
	{
		cerr<<"*****************************************\n";
		cerr<<str<<endl;
		cerr<<"*****************************************\n";
	}

	//**����� �� ������� �� ������� ���� ������ ������ ������
	if(stu_arr1!=NULL)
		delete stu_arr1;
	if(stu_arr2!=NULL)
		delete stu_arr2;
	if(emp_arr1!=NULL)
		delete emp_arr1;
	if(emp_arr2!=NULL)
		delete emp_arr2;
	if(emp_arr3!=NULL)
		delete emp_arr3;

	open.close();//����� ����� ������
	write.close();//����� ����� ������
}