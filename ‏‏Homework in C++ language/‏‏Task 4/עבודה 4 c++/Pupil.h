#include "Person.h"

#ifndef PUPIL_H
#define PUPIL_H

class Pupil : public Person
{
public:
	Pupil():grade(NULL),amount_grades(0),num_of_class(0){}//בנאי דיפולטיבי
	~Pupil();
	Pupil(const Pupil&obj);
	Pupil* Add_person(Person** p,char _layer,int class_num,int amount_presons);
	float avg_grade();
	bool check_if_outstanding();
	void print_person();
	void input_grades();
	void set_layer(char _layer){layer=_layer;}//פונקצית סט לעדכון שכבה לתלמיד
	void set_num_of_class(int num_c){num_of_class=num_c;}//פונקצית סט לעדכון מספר כיתה לתלמיד

private:
	int *grade;
	int amount_grades;
	char layer;
	int num_of_class;

};

#endif