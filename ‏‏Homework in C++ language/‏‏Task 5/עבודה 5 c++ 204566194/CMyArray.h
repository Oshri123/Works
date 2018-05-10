#include "Student.h"
#include "Empolyee.h"
#include <iostream>
#include <typeinfo>
using namespace std;
#ifndef CMYARRAY_H
#define CMYARRAY_H
template <class T>
class CMyArray
{
public:
	CMyArray(int _size=1):size(_size),arr(new T [_size]){count_CMyArray++; total_length+=_size;}//���� ����� ����� �� ���� ������� ����� ������ �� ����� �� �� �������
	~CMyArray()
	{
		if(arr!=NULL)//����� ������� �����
			delete[] arr;
	}
	T operator [](int location);
	void swap(int location1,int location2);
	void print_element(int location);
	void  print_all();
	void print_max();
	T* get_arr(){return arr;}
	int find_total(){return count_CMyArray;}
	int find_total_length();
	void write_to_file(ofstream &write)const;
	int get_size(){return size;}
private:
	T *arr;
	int size;
	static int count_CMyArray;
	static int total_length;
};

#endif

template <class T>//����� ������ �����
int CMyArray<T>::count_CMyArray=0;

template <class T>//����� ������ �����
int CMyArray<T>::total_length=0;

template <class T>
void CMyArray<T>::swap(int location1,int location2)//����� ������ ��� ������� �� ������ ����� ����� ������� ����� �� �������� �� ������ ������
{
	if((location1-1)<size && (location2-1)<size)//����� �� �������� �� ������ ������
	{
		T temp;//����� ������� ��� ���� �����
		temp=arr[location1-1];//����� ����� ��� ������ ������ �������� ��� ���� ����� �� �������� ���� ������
		arr[location1-1]=arr[location2-1];//����� �������� ������� ������ ������ ����
		arr[location2-1]=temp;//����� �������� ������� ���� ������ ������
	}
	else 
		cout<<"The location are not exist!\n";
};

template <class T>
void CMyArray<T>::print_element(int location)//����� ������ ����� �� ���� ����� ������� ����
{
	if(size>(location-1))//����� �� ������ ������ �� ���� ������
		cout<<arr[location-1];//����� ����� ������� ������
};

template <class T>
void  CMyArray<T>::print_all()//����� ������ �� ����� �����
{
	for (int i = 0; i < size; i++)//���� ������ �� �� ����� ������� �� �� ������� �����
		cout<<arr[i]<<endl;
}

template <class T>
T CMyArray<T>::operator[](int location)
{
	if(size>(location-1))//����� �� ������ ������ �� ���� ������
		return arr[location-1];//����� �������� ��� ������ ������

}

template <class T>
void CMyArray<T>::print_max()//������� ������ �� ������� �� ������ ��� ���� �� �� ����� �� ���� ��� ����
{
	T max;//������ ������� ����� ������ �� �������� ���������
	max=arr[0];//���� ��� ������ ��������
	for (int i = 1; i < size; i++)//���� ������ �� ���� ������ ������ ���� �������� ���������
		if (arr[i]>max)
			max=arr[i];//�� �������� ����� ���� ���� ��������� ��������, ����� �������� ��������� �������� ����
	if( typeid(max)==typeid(Student) )//����� �� �������� ����� ��� ������ �� ���� ������ ����� ������
		cout<<"The student with max average is:\n"<<max<<endl;
	else 
		cout<<"The empolyee with max salary is:\n"<<max<<endl;

};

template <class T>
int CMyArray<T>::find_total_length()//����� ������� �� ���� ������� ����� ��� �������
{
	return total_length;
}

template <class T>
void  CMyArray<T>::write_to_file(ofstream &write)const //����� ������ �� ���� ������ �����
{	
	for (int i = 0; i < size; i++)
		write<<arr[i];
}









