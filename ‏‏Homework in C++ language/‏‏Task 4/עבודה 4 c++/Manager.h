#include "Worker.h"
#ifndef MANAGER_H
#define MANAGER_H

class Manager: public Worker
{
public:
	Manager(){}
	~Manager(){}
	float return_salary(){ return (basic*2+get_seniority()*500); }//מתודה אין-ליין שמחשבת את משכורתו של המנהל ומחזירה אותה
	void set_person();
	bool check_if_outstanding(){return (get_seniority()>3);}//מתודה איו-ליין שבודקת אם המנהל מצטיין -אם יש לו ותק של יותר מ3 שנים
	void print_person();

private:

};


#endif
