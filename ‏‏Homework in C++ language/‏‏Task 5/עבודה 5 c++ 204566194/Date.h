#include <iostream>
using namespace std;

#ifndef DATE_H
#define DATE_H

class Date
{
public:
	Date(int _year=0,int _month=0,int _day=0):year(_year),month(_month),day(_day){}
	~Date(){};
	friend ostream& operator <<(ostream&out,Date&d);
	friend istream& operator >>(istream&in, Date&d);
	void check_exception(const Date&d)const;
	int get_day(){return day;}
	int get_month(){return month;}
	int get_year(){return year;}

private:
	int day;
	int month;
	int year;
};

#endif // !DATE_H
