#define NAME_SIZE 20
#include <iostream>
using namespace std;
#ifndef EMPOLYEE_H
#define EMPOLYEE_H

class Empolyee
{
public:
	Empolyee():full_name(NULL),empolyer_name(NULL),seniority(0),salary(0){}
	~Empolyee()//בנאי הורס לשחרור הזיכרון של השם ושם המעביד
	{
		if(full_name!=NULL)
			delete[] full_name;
		if(empolyer_name!=NULL)
			delete[] empolyer_name;
	}
	friend ostream& operator <<(ostream&out, Empolyee&e);
	friend istream& operator >>(istream&in,Empolyee&e);
	bool operator > (const Empolyee&e) { if(this->salary>e.salary) return true; else return false; }
	void operator = ( Empolyee&e );
	void check_exception(const Empolyee&e)const;
private:
	char *full_name;
	char *empolyer_name;
	int seniority;
	float salary;
};

#endif // !EMPOLYEE_H
