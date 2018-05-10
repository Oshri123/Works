#include "Secretary.h"

void Secretary::set_person()//מתודה שמעדכנת את הפרטים של המזכירה 
{
	int _seniority;
	Person::set_person();//עדכון שם ות.ז
	cout<<"\nEnter seniority: ";
	cin>>_seniority;//עדכון  שנות הותק של המזכירה
	set_seniority(_seniority);
	cout<<"\nEnter amount of children that learning at the school: ";
	cin>>amount_child_at_school;//עדכון כמות הילדים של המזכירה הלומדים בבית הספר
}

void Secretary::print_person()//מתודה שמדפיסה את הפרטים של המזכירה
{
	cout<<"~ Secretary details:\n\n";
	Worker::print_person();
	cout<<"children at school: "<<amount_child_at_school<<endl;//הדפסת כמות הילדים של המזכירה שלומדים בבית הספר
}

