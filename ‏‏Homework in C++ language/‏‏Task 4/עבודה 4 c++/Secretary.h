#include "Worker.h"
#ifndef SECRETARY_H
#define SECRETARY_H

class Secretary: public Worker
{
public:
	Secretary():amount_child_at_school(0){}//בנאי דיפולטיבי שמאפס את כמות הילדים של המזכירה הלומדים בבית הספר
	~Secretary(){}
	float return_salary(){ return (basic +amount_child_at_school*300); }//מתודה אין-ליין שמחשבת את משכורתה של המזכירה ומחזירה אותה
	bool check_if_outstanding(){return (get_seniority()>10 );}//מתודה איו-ליין שבודקת אם המזכירה מצטיינת -אם יש לה ותק של יותר מ10 שנים
	void set_person();
	void print_person();

private:
	int amount_child_at_school;
};


#endif
