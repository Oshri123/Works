#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	Person():F_name(""),L_name(""),id(0){}
	virtual ~Person(){}
	virtual void print_person();
	virtual void set_person();
	virtual bool check_if_outstanding() = 0;
	int get_id(){return id;}
private:

	string F_name;
	string L_name;
	int id;
};

#endif