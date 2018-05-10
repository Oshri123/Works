#include "Date.h"

ostream& operator <<(ostream&out,Date&d)//������� ����� ������ ������ ����
{
	cout<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;
	return out;
}

istream& operator >>(istream&in, Date&d)//������� ��� ������ �������� �� ������
 {
	 in>>d.day>>d.month>>d.year;
	 return in;
 }

 void Date::check_exception(const Date&d)const //����� ������ ������ ������
 {
	 if ((d.day<1 || d.day >31) || (d.month<1 || d.month >12) ||(d.year < 1990) )
		 throw "The date of birth is ilegal!";
 }

