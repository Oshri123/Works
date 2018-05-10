#include "Empolyee.h"
#define MIN_NAME 5
#define MAX_NAME 20
#define N 81

ostream& operator <<(ostream&out, Empolyee&e)//אופרטור פלט
{
	out<<"Empolyee name: "<<e.full_name<<endl;//הדפסת השם של העובד
	out<<"Empolyer name: "<<e.empolyer_name<<endl;//הדפסת השם של המעביד
	out<<"Seniority: "<<e.seniority<<endl;//הדפסת הוותק של העובד
	out<<"Salary: "<<e.salary<<endl;//הדפסת המשכורת של העובד
	out<<"---------------------------------\n";
	return out;
}

istream& operator >>(istream&in,Empolyee&e)//אופרטור קלט
{
	char temp[N];//יצירת מחרוזת עזר לקליטת השם של העובד
	int j=0;
	in.get(temp[j]);//קליטת תו תו
	do{in.get(temp[j]);
	j++;
	}while(temp[j-1]!='\n');//בדיקת כל עוד לא ירדנו שורה בקובץ ולא נגמרה קליטת השם
	temp[j-1]='\0';
	e.full_name=new char[j];//הקצאת הזיכרון למחרוזת השם בגודל המדויק 
	for (int i = 0; i < j; i++)//העתקת המחרוזרת לאובייקט
		e.full_name[i]=temp[i];

	j=0;

	do{in.get(temp[j]);//קליטת תו תו למחרוזת המעביד
	j++;
	}while(temp[j-1]!='\n');
	temp[j-1]='\0';
	e.empolyer_name=new char[j];//הקצאת הזיכרון לשם המעביד בגודל המדויק
	for (int i = 0; i < j; i++)
		e.empolyer_name[i]=temp[i];//העתקת השם לאובייקט

	in>>e.seniority>>e.salary;//קליטת המשתנים של הותק והמשכורת
	return in;
}

void Empolyee::operator=(Empolyee&e)
{
	int i,j;

	for (i = 0; e.full_name[i]!='\0'; i++);
	if(full_name!=NULL)
		delete[] full_name;
	full_name=new char[i+1];
	for (i = 0;e.full_name[i]!='\0'; i++)
		full_name[i]=e.full_name[i];
	full_name[i]='\0';

	for (j = 0; e.empolyer_name[j]!='\0'; j++);
	if(empolyer_name!=NULL)
		delete[] empolyer_name;
	empolyer_name=new char[j+1];
	for (j = 0; e.empolyer_name[j]!='\0'; j++)
		empolyer_name[j]=e.empolyer_name[j];
	empolyer_name[j]='\0';

	seniority=e.seniority;
	salary=e.salary;
}

void Empolyee::check_exception(const Empolyee&e)const //פונקציה שבודקת חריגות במערך העובדים
{
	int i=0,flag=1;
	if(e.full_name[i]<'A' || e.full_name[i]>'Z')
		throw "The word does not open with big latter!";

	for ( i = 1;e.full_name[i]!='\0'; i++)
	{
		if(i>MAX_NAME)
			throw "the length of the name is too long!";

		if(e.full_name[i]==' ' || e.full_name[i]=='-')
		{
			flag=0;
			if(e.full_name[i+1]<'A' || e.full_name[i+1]>'Z')
				throw "The word does not open with big latter!";
		}
		else 
			if((e.full_name[i]>='A' && e.full_name[i]<= 'Z')&&(e.full_name[i-1]!=' ' && e.full_name[i-1]!='-'))
				throw "There is big latters in the empolyee name!";
	}
	if (i<MIN_NAME)
		throw "the length of the name is too short!";

	if(flag)
		throw "There is no  ' ' OR '-' between the first name and last name";

	if(e.seniority<0||e.seniority>50)
		throw "The seniority is over 50 or under 0!";

	if(e.salary<0)
		throw "The salary is negative";
}