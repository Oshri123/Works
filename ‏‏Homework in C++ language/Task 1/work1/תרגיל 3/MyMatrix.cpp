#include "MyMatrix.h"
#define _CRT_SECURE_NO_WARNINGS

#define ZERO 0.000000 //Global Variable
MyMatrix::MyMatrix():a11(0),a12(0),a21(0),a22(0){}; //making the default Constructor
MyMatrix::MyMatrix(float a,float b,float c,float d) //making the Constructor
{
	a11=a;
	a12=b;
	a21=c;
	a22=d;
}; 
MyMatrix::~MyMatrix(){};
MyMatrix::MyMatrix(const MyMatrix&other){};//Destroying function
void MyMatrix::set(const MyMatrix &m)//making the Copy Constructor
{
	a11=m.a11;
	a12=m.a12;
	a21=m.a21;
	a22=m.a22;
};
bool MyMatrix::set(int i, int j, float num)
{
	bool flag = false;
	int lab = i*10 +j ;//Formula for calculating the matrix element location

	if ( ( i>0 && i<3 ) && ( j>0 && j<3 ) )//Check to see if the labs are propriety
		flag=true;
	else return flag;

	switch (lab)//Placement the value of the Variable 'lab' in the Variable 'num'
	{
	case 11:
		a11=num;
		break;
	case 12:
		a12=num;
		break;
	case 21:
		a21=num;
		break;
	case 22:
		a22=num;
		break;
	}
	return flag;
};
bool MyMatrix::get(int i, int j, float &num) const 
{
	bool flag = false;
	int lab = i*10 +j ;//Formula for calculating the matrix element location

	if ( ( i>0 && i<3 ) && ( j>0 && j<3 ) )//Check to see if the labs are propriety
		flag=true;
	else return flag;

	switch (lab)//Placement the value of the Variable 'num' in the Variable 'lab'
	{
	case 11:
		num=a11;
		break;
	case 12:
		num=a12;
		break;
	case 21:
		num=a21;
		break;
	case 22:
		num=a22;
		break;
	}
	return flag;

};
bool MyMatrix::is_equal(const MyMatrix &m) const
{
	if ((a11==m.a11) && (a12==m.a12) & (a21==m.a21) & (a22==m.a22))//Check to see if the matrices are equal
		return true;
	else return false;
};
void MyMatrix::print() const
{
	cout<<endl<<"************"<<endl;//print the matrix
	cout<<a11<<"\t"<<a12<<endl<<endl<<a21<<"\t"<<a22<<endl;
	cout<<"************"<<endl;
};
float MyMatrix::det() const
{
    float main_diagonal = a11*a22 ;//Doubling main diagonal
	float Secondary_diagonal = a12*a21 ;//Doubling Secondary diagonal
	float determinate=main_diagonal-Secondary_diagonal ;//Determinant calculation

	return determinate;
};
bool MyMatrix::invertible()const
{
	float determinate=det() ;//Determinant calculation

	if (determinate!=ZERO)//Check to see if the determinant different from zero - meaning a coup
		return true;
	else return false;
};
bool MyMatrix::is_inverse(const MyMatrix &m)
{

	float determinate = (1/det()) ;//Using the formula for inverse matrix { [1\(ad-bc)]*(-d,b  }
																	//    {              c,-a) }
	float b11,b12,b21,b22;

	b11 = a22*determinate;//lab1
	b12 = (-a12*determinate);//lab2
	b21 = (-a12*determinate);//lab3
	b22 = a11*determinate;//lab4

	if ((b11==m.a11) && (b12==m.a12) & (b21==m.a21) & (b22==m.a22))//Check to see if the matrix is a matrix coup
		return true;
	else return false;
};
