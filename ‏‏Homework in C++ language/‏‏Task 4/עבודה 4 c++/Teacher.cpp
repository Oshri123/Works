#include "Teacher.h"

Teacher ::~Teacher ()//בנאי הורס לשחרור מערך הציונים של מורה
{
	if(professions_name!=NULL)
		delete[] professions_name;
}

Teacher::Teacher(const Teacher&obj):Worker(obj),amount_professions(obj.amount_professions)//בנאי העתקה
{
	professions_name=new string[obj.amount_professions];//הקצאת זיכרון חדש למערך המקצועות
	for (int i = 0; i < obj.amount_professions; i++)//העתקת המקצועות מהאובייקט
		professions_name[i]=obj.professions_name[i];
}

void Teacher::set_professions()//מתודה לעדכון פרטים של מורה
{
	cout<<"\nEnter amount professions (1-10): ";
	cin>>amount_professions;
	professions_name=new string[amount_professions];//הקצאת זיכרון מתאים למערך המקצועות של מורה
	cout<<"Enter the names of the professions\n";
	for (int i = 0; i < amount_professions; i++)//לולאת קלט למקצועות המורה
	{
		cout<<"Professions number "<<(i+1)<<": ";
		cin>>professions_name[i];
	}
}

const void Teacher::print_all_teacher_professions()//פונקציה להדפסת כל המקצועות של מורה
{
	for (int i = 0; i < amount_professions; i++)
		cout<<professions_name[i]<<", ";

	cout<<endl;
}

void Teacher::print_person()//מתודה להדפסת פרטים של מורה
{
	//cout<<"~ Teacher details:\n";
	Worker::print_person();
	cout<<"professions: ";
	print_all_teacher_professions();//הפעלת פונקציה שמדפיסה את המקצועות שהמורה מלמד
	cout<<endl;
}

void Teacher::set_person()//מתודה לקליטת פרטי המורה
{
	int _seniority;
	Person::set_person();
	cout<<"\nEnter seniority: ";
	cin>>_seniority;//קליטת שנות הותק של מורה
	cout<<endl;
	set_seniority(_seniority);
}
