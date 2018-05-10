#include "Manager.h"

void Manager::set_person()//מתודה שמעדכנת את פרטיו של המנהל
{
	int _seniority;
	Person::set_person();
	cout<<"\nEnter seniority: ";
	cin>>_seniority;//קליטת שנות הוותק של המנהל
	cout<<endl;
	set_seniority(_seniority);//עדכון שנות הותק של המנהל
}

void Manager::print_person()//מתודה שמדפיסה את פרטיו של המנהל
{
	cout<<"~ Manager details:\n";
	Worker::print_person();
}
