#include "MyString.h"
#define _CRT_SECURE_NO_WARNINGS
CMyString::CMyString() : str(NULL), length(0){}//default constructor
CMyString::CMyString(char *str2)//patam constructor
{
	int i,n=0;
	for (i = 0; str2[i] != '\0'; i++);//counting the size of the string

	str = new char[i + 1]; //String space allocation
	for (i = 0; str2[i] != '\0'; i++)//copy the string
		str[i] = str2[i];

	length = i; //the length is i
	str[i] = '\0'; //put \0 at the end of the string
}
CMyString::~CMyString() //destructor
{
	if(str)
		delete[] str;
}
CMyString::CMyString(const CMyString& other) //copy constructor
{
	length=other.length; //change the length
	str = new char[other.length+1]; //String space allocation
	for (int i = 0; i < other.length; i++) //copy the string
		str[i] = other.str[i];
	str[other.length]='\0'; //put \0 at the end
}
void CMyString::PrintString()//print the string
{
	for (int i = 0; str[i]!= '\0'; i++) //print the string
		cout << str[i];
	cout << endl;
}
void CMyString::ChangeString(char *str3)
{
	int i;
	for(i=0;str3[i]!='\0';i++);//counting the size of the string
	delete[] str;
	str=new char[i+1]; //String space allocation

	for(i=0;str3[i]!='\0';i++) //copy the string
		str[i]=str3[i];
	str[i]='\0'; //put \0 at the end of the string
	length=i;//the length is i

}
int CMyString::LengthString()
{
	int i;
	for (i = 0; str[i] != '\0'; i++);//counting the size of the string
	length = i; //change the length
	return length;
}
int CMyString::SumOfBigAndLowLatter(char latter)
{
	int sum = 0; 
	for (int i = 0;str[i]!='\0'; i++)
		if (str[i] == latter || ((str[i] == (latter + 32))&&(str[i] < 123)) || ((str[i] == (latter - 32))&&(str[i] > 64)))//check if there is latter in the string acording to code ascii
			sum++;
	return sum;
}
int CMyString::Words()//The function counts the number of words in the string
{
	int count,n=0;

	if (str[length-1] == ' ' || str[length-1] == ',' || str[length-1] == '.')//Check to see if the last element at the string is " " or "." or ","
		count=0;//if the condition correct , its mean we need to beginnig the counting from 0
	else count=1;// else its mean we need to beginnig the counting from 1

	while(str[n] == ' ' || str[n] == ',' || str[n] == '.')// condition if the string didn't started with word
		n++;

	for ( int i = n; str[i] != '\0'; i++)// loop that count how many words at the string
		if (str[i] == ' ' || str[i] == ',' || str[i] == '.')
			if (str[i + 1] != ' ' && str[i + 1] != ',' && str[i + 1] != '.')
				count++;
	return count;//Returns the number of words
}
char* CMyString::TheNword(int n)
{
	char *word; int i,start_of_n_word,length_of_n_word = 0, count = 1;

	if (n > Words() || n == 0)// condition if the string have enougth words or, if the input at n is 0
	{
		word = NULL;
		return word;
	}

	for ( i = 0; str[i] != '\0'; i++)// Loop counts the words in the string
	{
		if (str[i] == ' ' || str[i] == ',' || str[i] == '.')// condition when we counting word
			if (str[i + 1] != ' ' && str[i + 1] != ',' && str[i + 1] != '.')
			{
				count++;
			}

			if (count == n)//If we got the 'n' word 
			{
				if(n!=1)//if 'n' is not the first word its mean we need to promote the variable i Because its on ' ' or '.' or ','
					i++;

				start_of_n_word = i;//Saving the initial position of the 'n' word
				while (str[i] != ' ' && str[i] != ',' && str[i] != '.' && str[i] != '\0')//Loop counts the length of the 'n' word
				{
					length_of_n_word++;
					i++;
				}
				break;// exit from the loop
			}
	}

	word = new char[length_of_n_word + 1];//String space allocation
	for (i = 0; i < length_of_n_word; i++)//Copy the 'n' word to new string
	{
		word[i] = str[start_of_n_word];
		start_of_n_word++;
	}
	word[length_of_n_word] = '\0';
	return word;//returning the word

}
void CMyString::ByReference(int *digit,int *biglatter,int *lowlatter)
{
	for(int i=0;str[i]!='\0';i++)//Loop passes on the string
	{
		if((str[i]>47) && (str[i]<58))//check if there is numbers in the string acording to code ascii
			*digit=*digit+1;//counting by reference
		else if((str[i]>64) && (str[i]<91))//check if there is big latter in the string acording to code ascii
			*biglatter=*biglatter+1;//counting by reference
		else if((str[i]>96) && (str[i]<123))//check if there is small latter in the string acording to code ascii
			*lowlatter=*lowlatter+1;//counting by reference
	}

}
void CMyString::Concatenation(CMyString ms3)
{
	int i;
	char Newstr[MAX];//create new str 

	for ( i = 0; str[i] != '\0'; i++)//Loop that copies the default string with another string
		Newstr[i] = str[i];

	for ( i = 0; ms3.str[i] != '\0'; i++)//Loop that Concatenation the other string with the new string 
	{
		Newstr[length] = ms3.str[i];
		length++;
	}

	Newstr[length]='\0';

		delete[] str;//Release Memory of str

	str = new char[length+1];////String space allocation

	for(i=0;Newstr[i]!='\0';i++)
		str[i]=Newstr[i];////Loop that copies the Concatenation string to the default string
	str[i]='\0';

}
void CMyString::ChangeBigLatter()
{
	for (int i=0;str[i]!='\0';i++)//loop that check if there is big latter in the string acording to code ascii
		if((str[i]>64) && (str[i]<91))
			str[i]=str[i]+32;//change the latter from big to amall 
}
void CMyString::ChangeSmallLatter()
{
	for (int i=0;str[i]!='\0';i++)//loop that check if there is small latter in the string acording to code ascii
		if((str[i]>96) && (str[i]<123))
			str[i]=str[i]-32;//change the latter from small to big 

}


