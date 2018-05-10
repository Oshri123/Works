#include "Number.h"
#include "Digit.h"
#include <ctime>

Number:: Number()//Ctor that reset the array
{
	for(int i=0;i<4;i++) 
		dig[i].setValue(0);
}
void Number::InputFromUser( int num)// the function take the input number and inesert him to the array 
{
	for(int i=3 ;i>=0 ;i--)
	{
			dig[i].setValue(num%10);
			num/=10; 
		
	}
}
void Number::RandomDigits()//the function draw numbers from the computer and build a number that the user need to guss
{
	srand(time(NULL));
	int flag=0,x ;
	dig[3].setValue(rand()%9+1);

	for(int i=2;i>=0;i--)// the loop build number with the conditions: different digits and without the digit '0'
	{
		x = (rand()%9+1);
		for(int j=3;j>=i;j--)
		{
			if (dig[j].getValue()==x)
			{
				i++;
				flag=1;
				j=-1;
			}
		}
		if(!flag)
		{
			dig[i].setValue(x);
		}
		else flag=0;
	}
}
int Number:: Location(const int i) const//function that get a location of digit and return its value
{

	if( (i<0) && (i>3) )
		return (-1);
	else return (dig[i].getValue());
}
ostream& operator << ( ostream& out, const Number& num)//Print Operator that print the full number
{
	for(int i=0;i<4;i++)
		cout<<num.dig[i].getValue();
	cout<<endl;
	return out;
}
int Number::SameDigits(int num)// function that check if the input from the user is correct
{
	if (num>9999 || num<1000)// check if the number is a 4 digit number
		return 1;

	int num2=num,arr[4];

	for (int i=3;i>=0;i--)// loop that insert the number to array
	{
		arr[i]=num2%10;
		num2=num2/10;
	}
	for (int i=3;i>=0;i--)//loop that check if the number include same digits or if the number include '0'
		for (int j=3;j>=0;j--)
			if(j!=i)
			{
				if( arr[i]==arr[j] ||arr[i]==0)
				return 1;
			}
	return 0;


}
