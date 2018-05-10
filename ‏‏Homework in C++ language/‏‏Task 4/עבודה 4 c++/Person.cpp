#include "Person.h"


void Person::set_person()//מתודה וירטואלית לקליטת נתונים עבור כל יורש של פרסון
{
	cout<<"\nEnter first name: ";
	cin>>F_name;
	cout<<"\nEnter last name: ";
	cin>>L_name;
	cout<<"\nEnter id: ";
	cin>>id;
}

void Person::print_person()//מתודה וירטואלית להדפסת נתונים של כל פרסון
{ 
	cout<<"Name: "<<F_name<<" "<<L_name<<endl;
	cout<<"Id: "<<id<<endl;
}