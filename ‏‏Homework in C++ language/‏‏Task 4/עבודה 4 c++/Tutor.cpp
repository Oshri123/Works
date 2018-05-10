#include "Tutor.h"
#include "Class.h"

const void Tutor::print_pupils()//פונקציה להדפסת פרטי התלמידים של המחנך
{
	cout<<"\n* The details of the tutor's pupils: *\n";
	for (int i = 0; i <cls->get_amount_pupils(); i++)//לולאה שמדפיסה את פרטי התלמידים של המחנך
	{
		cls->get_pupils()[i]->print_person();
		if(cls->get_pupils()[i]->check_if_outstanding())//אם התלמיד מצטיין מודפסת הודעה מתאימה
			cout<<"The pupil is outstanding\n";
	}
}

bool Tutor::check_if_outstanding()//מתודה שבודקת אם המחנך מצטיין
{
	float outstanding_pupils=0;
	float amoun_pupils=cls->get_amount_pupils()/2;
	for (int i = 0; i <cls->get_amount_pupils(); i++)//לולאה שבודקת כמה תלמידים מצטיינים יש למחנך
	{
		if(cls->get_pupils()[i]->check_if_outstanding())
			outstanding_pupils++;
	}
	if(( outstanding_pupils >= amoun_pupils)&&(amoun_pupils!=0 ))//אם כמות התלמידים המצטיינים בכיתה גדולה מחצי המחנך מצטיין
		return true;
	else
		return false;
}

void Tutor:: print_person()//מתודה להדפסת פרטים של מחנך
{
	cout<<"~ Tutor details:\n\n";
	Teacher::print_person();//הדפסת המתודה שמחנך יורש ממורה
	cout<<"He is tutor at layer: "<<cls->get_layer_name()<<endl;
	cout<<"He is the tutor of class number: "<<cls->get_num_class()<<endl;
	if(cls->get_amount_pupils() )//הדפסת כל התלמידים של המחנך (אם ישנם כאלה 
		print_pupils();
}