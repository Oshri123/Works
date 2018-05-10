#include "Date.h"

ostream& operator <<(ostream&out,Date&d)//אופרטור הדפסה להדפסת המחלקה דייט
{
	cout<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;
	return out;
}

istream& operator >>(istream&in, Date&d)//אופרטור קלט לקליטת האובייקט של התאריך
 {
	 in>>d.day>>d.month>>d.year;
	 return in;
 }

 void Date::check_exception(const Date&d)const //מתודה לבדיקת חריגות התאריך
 {
	 if ((d.day<1 || d.day >31) || (d.month<1 || d.month >12) ||(d.year < 1990) )
		 throw "The date of birth is ilegal!";
 }

