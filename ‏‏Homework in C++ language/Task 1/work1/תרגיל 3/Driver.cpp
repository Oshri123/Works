#include "MyMatrix.h"
#define _CRT_SECURE_NO_WARNINGS

void main()
{

	float lab11,lab12,lab21,lab22,num,num2=0;
	int i,j ;

	cout<<"enter 4 float numbers for the first matrix"<<endl;//The first matrix input
	cin>>lab11>>lab12>>lab21>>lab22;
	MyMatrix obj1(lab11,lab12,lab21,lab22);
	cout<<"The first matrix is: "<<endl;
	obj1.print();


	//cout<<"enter another 4 float numbers to change the first matrix"<<endl; //The second matrix input
	//cin>>lab11>>lab12>>lab21>>lab22;
	//MyMatrix obj2(lab11,lab12,lab21,lab22);

	//obj1.set(obj2); //Activation the Function that change matrix 1 with matrix 2
	//cout<<"The matrix after the change is: "<<endl;
	//obj1.print();

	//do {
	//	cout<<"Enter two labs that limit from { 0 < lab < 3 } "<<endl; // Change lab matrix
	//	cin>>i>>j;
	//	cout<<"enter number"<<endl;// input num from the user
	//	cin>>num;
	//	if(obj1.set(i,j,num))  // Activation the Function of change lab
	//	{
	//		cout<<"Its worked corectlly and the matrix after the set is: "<<endl;
	//		obj1.print();
	//	}
	//	else cout<<"Eror! you entered ilegal labs! Try again.."<<endl;
	//} while( !( obj1.set(i,j,num ) ));// Invalid input loop

	//do{
	//	cout<<"Enter two labs that limit from { 0 < lab < 3 } "<<endl; //עדכון מספר למספר מאיברי המטריצה
	//	cin>>i>>j;
	//	if(obj1.get(i,j,num2))// condition that activation the Function that enter number from the matrix to the variable 'num2'
	//		cout<<"Its worked corectlly and the number in the labs { "<<i<<" , "<<j<<" } at the matrix is: "<<num2<<endl;
	//	else 
	//		cout<<"Eror! you entered labs ilegal! Try again.."<<endl; 
	//} while(!( obj1.get(i,j,num2) ) );// Invalid input loop

	cout<<"enter 4 float numbers for matrix 3"<<endl;// The third matrix input
	cin>>lab11>>lab12>>lab21>>lab22 ;
	MyMatrix obj3 (lab11,lab12,lab21,lab22);
	cout<<"The third matrix is:"<<endl;
	obj3.print();
	if(obj1.is_equal(obj3))// condition that activation the Function that check if the matrices are equal
		cout<<"matrix 1 and matrix 3 are equal!"<<endl;
	else cout<<"matrix 1 and matrix 3 are Not equal!"<<endl;

	cout<<"The determinant of matrix 1 is:  "<<obj1.det()<<endl;// activation the Function that Calculates the Determinantes of matrix 1 and matrix 3
	cout<<"******"<<endl<<"The determinant of matrix 3 is:  "<<obj3.det()<<endl;
	cout<<"******"<<endl;

	if(obj1.invertible())// condition that activation the Function that check if matrix 1 is invertible
	{
		cout<<"The first matrix is invertible!"<<endl;

		if(obj1.is_inverse(obj3))// condition that activation the Function that check if the input matrix is the inverse of matrix 1
			cout<<"Matrix 3 is inverse of matrix 1"<<endl;
		else cout<<"Matrix 3 is not inverse of matrix 1"<<endl;
	}
	else cout<<"The first matrix is not invertible\ntherefor, Matrix 3 can't be inverse of matrix 1\n"<<endl;


}