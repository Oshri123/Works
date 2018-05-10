#include "Worker.h"

void Worker::print_person()//מתודה להדפסת פרטי העובד שכוללים ,שם מלא,ת.ז ושנות וותק
{
	Person::print_person();
	cout<<"Seniority: "<<seniority<<endl;
	cout<<"Salary: "<<return_salary()<<endl;
}

