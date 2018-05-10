#include "Person.h"
#ifndef WORKER_H
#define WORKER_H
#define basic 5000
class Worker: public Person
{
public:
	Worker(): seniority(0){}
	virtual ~Worker(){}
	//Worker(const Worker&obj):Person(obj),seniority(obj.seniority){}//בנאי העתקה//העתקת כל הפרטים +העתקת שנות הוותק מהאובייקט
	virtual  float return_salary()=0;
	void print_person();
	void set_seniority(int _seniority){seniority=_seniority;}//פונקצית סט לעדכון שנות הותק של העובד
	int get_seniority(){return seniority;}// פונקציית גט לגשת למשתנה של שנות הותק
	
private:
	int seniority;
};




#endif