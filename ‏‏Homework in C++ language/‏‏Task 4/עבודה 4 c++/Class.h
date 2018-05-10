#include "Pupil.h"
#include "Tutor.h"

#define NOT_EXIST -1
#ifndef CLASS_H
#define CLASS_H
class Tutor;
class Class
{
public:
	Class(char layer_n,int class_n);
	~Class();
	Class(const Class&obj);
	int check_if_pupil_exist(Pupil *pl);
	void add_pupil(Pupil *pl);
	Pupil* return_pupil(int location);
	char get_layer_name(){return layer_name;}
	Pupil** get_pupils(){return pupils;}
	int get_amount_pupils(){return amount_pupils;}
	Tutor* get_tutor(){return tutor;}
	void set_tutor(Tutor *t){tutor=t;}
	int get_num_class(){return class_num;}
private:
	char layer_name;
	int class_num;
	Pupil** pupils;
	int amount_pupils;
	Tutor* tutor;
};

#endif


