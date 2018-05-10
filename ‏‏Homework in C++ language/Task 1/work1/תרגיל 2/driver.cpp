#include "MyString.h"
#define _CRT_SECURE_NO_WARNINGS
char clean_screen();
void main()
{	
	char str[MAX], str2[MAX] , str3[MAX], ch,saction=NULL,*word=NULL,freezing;;
	int  n, digit=0, biglatter=0, lowlatter=0;

	cout << "enter default string please"<<endl;// input the default string
	cin.getline(str,MAX);
	cout << "enter another string please"<<endl;// input another string that will use at the function of the concatenation
	cin.getline(str2,MAX);
	CMyString ms(str),ms2(str2);//Create two objects
	cout << "The default string is:"<<endl;//print the default string
	ms.PrintString();
	cout<<endl;
	cout << "The other string is:"<<endl;//print the other string
	ms2.PrintString();
	cout<<endl<<"**press any key to continue to the manu**"<<endl;
	getchar();//Freezing the screen before the cleen

do	{
	_flushall();
	system("cls");//cleen the screen
	cout<<("***************************************************************")<<endl;
	cout<<("To change the default string press 'a'")<<endl;
	cout<<("To print the default string prss 'p'")<<endl;
	cout<<("To find out the length of the default string prss 'b'")<<endl;
	cout<<("To find out how many times your char appeare at the default string press 'c'")<<endl;
	cout<<("To find out how many words at the default string press 'd'")<<endl;
	cout<<("To find out the 'n' word at the default string press 'e'")<<endl;
	cout<<("To find out how many Digits, Big latters and Small latters at the default string press 'f'")<<endl;
	cout<<("To contain the 'other' string with the default string prss 'g'")<<endl;
	cout<<("To change all the big latters to small latters at the default string press 'h'")<<endl;
	cout<<("To change all the small latters to big latters at the default string press 'i'")<<endl;
	cout<<("To exit prss 'q'")<<endl;
	cout<<("***************************************************************")<<endl;
	cin>>saction;//input User Select
		switch (saction)
		{
		case 'a':
			cout<<"enter string please"<<endl;
			_flushall();
			cin.getline(str3,MAX);//input string
			ms.ChangeString(str3);//Activation function that changes the string
			break;

		case 'b':
			cout<<"The length of the string is: "<<ms.LengthString()<<endl;//Activation function that find the length of the string and print the length
			getchar();//Freezing the screen before the cleen
			break;

		case 'c':
			cout << "enter char please" << endl;
			_flushall();
			cin >> ch;
			cout<<"The char '"<<ch<<"' appeare "<<ms.SumOfBigAndLowLatter(ch)<<" times at the string"<<endl;//Activation the function and print the returned variable
			getchar();//Freezing the screen before the cleen
			break;

		case 'd':
			cout << "There is " << ms.Words() << " words at the string" << endl;//Activation the function and print the returned variable
			getchar();//Freezing the screen before the cleen
			break;

		case 'e':
			cout << "enter number\n";//input from the user
			cin >> n;
			word=ms.TheNword(n);//Activation the function and puts the returned variable at the 'word's string 
			if(word==NULL)//condition if its NULL
			{
				cout<<"EROR! the word number "<<n<<" is not posible!"<<endl;
				getchar();//Freezing the screen before the cleen
				break;
			}
			for (int i = 0; word[i]!='\0'; i++)//loop that print the 'word's string
				cout << word[i];
			cout << endl;
			getchar();//Freezing the screen before the cleen
			break;

		case 'f':
			ms.ByReference(&digit,&biglatter,&lowlatter);//Activation the function and print the variable after they updated
			cout<<"There is "<<digit<<" digits, "<<biglatter<<" Big Lstters and "<<lowlatter<<" Small Latters at the string"<<endl;
			digit=0, biglatter=0, lowlatter=0;//Reset variables for another turn
			getchar();//Freezing the screen before the cleen
			break;

		case 'g':
			ms.Concatenation(ms2);//Activation the function that Concatenation the default string with the other string
			cout<<"the new string is:"<<endl;
			ms.PrintString();//Activation the function that print the default string
			getchar();//Freezing the screen before the cleen
			break;

		case 'h':
			ms.ChangeBigLatter();//Activation the function that change all the big latters in the default string to small latters
			cout<<"the new string is:"<<endl;
			ms.PrintString();//Activation the function that print the default string
			getchar();//Freezing the screen before the cleen
			break;

		case 'i':
			ms.ChangeSmallLatter();//Activation the function that change all the small latters in the default string to big latters
			cout<<"the new string is:"<<endl;
			ms.PrintString();//Activation the function that print the default string
			getchar();//Freezing the screen before the cleen

			break;
		case 'p':
			ms.PrintString();//Activation the function that print the default string
			getchar();//Freezing the screen before the cleen

			break;
		}

		cout<<endl<<"**press any key to continue to the manu**"<<endl;
				//Freezing the screen before the cleen
		getchar();
	}	while(saction!='q');


}
