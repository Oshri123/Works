#include "Depertment.h"
#include "Course.h"
#include "Student.h"

Depertment::~Depertment()//בנאי הורס לשחרור הזכרון של המחלקה
{
	if (crs !=NULL )
		for (int i = 0; i < amount_crs; i++)
			delete crs[i];

	delete crs;

	if (std != NULL)
		for (int i = 0; i < amount_std; i++)
			delete std[i];

	delete std;	

	delete failed_std;

}
Depertment::Depertment(const Depertment&d)//בנאי העתקה
{
	dep_N=d.dep_N;
	code=d.code;
	amount_crs=d.amount_crs;
	crs=new Course*[amount_crs];
	for ( int i=0; i<amount_crs;i++)//לולאה שמעתיקה את רשימת הקורסים
	{
		crs[i]=new Course;
		*crs[i]=*d.crs[i];
	}
	amount_std=d.amount_crs;
	std=new student*[amount_std];
	for ( int i=0; i<amount_std;i++)//לולאה שמעתיקה את רשימת הסטודנטים
	{
		std[i]=new student;
		*std[i]=*d.std[i];
	}
	amount_fstd=d.amount_fstd;
	failed_std=new student*[amount_fstd];
	for ( int i=0; i<amount_fstd;i++)//לולאה שמעתיקה את רשימת הסטונדטים הנכשלים
	{
		failed_std[i]=new student;
		*failed_std[i]=*d.failed_std[i];
	}

}
Depertment Depertment::operator = ( const Depertment&d )//אופרטור השמה, מעתיק את כל פרטי המחלקה למחלקה אחרת
{
	dep_N=d.dep_N;
	code=d.code;
	amount_crs=d.amount_crs;
	delete crs;
	delete std;
	delete failed_std;
	crs=new Course*[amount_crs];
	for ( int i=0; i<amount_crs;i++)//לולאה שמעתיקה את רשימת הקורסים
	{
		crs[i]=new Course;
		*crs[i]=*d.crs[i];
	}
	amount_std=d.amount_crs;
	std=new student*[amount_std];
	for ( int i=0; i<amount_std;i++)//לולאה שמעתיקה את רשימת הסטודנטים
	{
		std[i]=new student;
		*std[i]=*d.std[i];
	}
	amount_fstd=d.amount_fstd;
	failed_std=new student*[amount_fstd];
	for ( int i=0; i<amount_fstd;i++)//לולאה שמעתיקה את רשימת הסטונדטים הנכשלים
	{
		failed_std[i]=new student;
		*failed_std[i]=*d.failed_std[i];
	}
	return d;
}
bool Depertment::operator>(const Depertment&d)//אופרטור שבודק )בודק האם כמות הסטודנטים עם מצב האקדמי תקין גדולה יותר מאשר במחלקה-פרמטר 
{
	return(amount_fstd>d.amount_fstd);
}
ostream& operator << ( ostream&out , Depertment&d)
{
	//	פלט של פרטי המחלקה - האופרטור מדפיס את שם מחלקה, קוד מחלקה ,פרטי הקורסים הניתנים ע"י
	//   המחלקה, את רשימת הסטודנטים הלומדים במחלקה ואת רשימת הסטודנטים עם מצב אקדמי לא 
	//      תקין )אם כבר חושבו)

	out<<"Depatment information:\n";
	out<<"Name: "<<d.dep_N<<"\ncode: "<<d.code<<endl;
	if(d.amount_crs)//הדפסת רשימת הקורסים במחלקה
	{
		out<<" - Courses of department:\n";
		for(int i=0;i<d.amount_crs;i++)
			out<<"Name: "<<d.getCrs()[i]->getNameC()<<", Number: "<<d.getCrs()[i]->getNumOfTheCours()<<endl;
	}

	if(d.amount_std)//הדפסת רשימת הסטודנטים במחלקה
	{
		out<<" - Student in department:\n";
		for(int i=0;i<d.amount_std;i++)
			out<<"Name: "<<d.std[i]->getName()<<", Id: "<<d.std[i]->getID()<<", gender: "<<d.std[i]->getGender()<<", age: "<<d.std[i]->getAge()<<endl;
	}

	if(d.amount_fstd)//הדפסת רשימת הסטונדטים הנכשלים במחלקה אם קיימים
	{
		out<<" - Students with bad status:\n";
		for(int i=0;i<d.amount_fstd;i++)
			out<<"Name: "<<d.failed_std[i]->getName()<<", Id: "<<d.failed_std[i]->getID()<<", gender: "<<d.failed_std[i]->getGender()<<", age: "<<d.failed_std[i]->getAge()<<endl;
	}
	out<<endl;
	return out;
}
istream& operator >> ( istream&in , Depertment&d)//אופרטור קלט של שם המחקלה וקוד המחלקה
{
	cout<<"Please enter department details.\n"<<"Name: ";
	in>>d.dep_N;
	cout<<"Code: ";
	in>>d.code;

	return in;
}
Depertment& Depertment::operator+=( Course *c)//אופרטור הוספת קורס למחלקה
{
	for(int i=0;i<amount_crs;i++)//בדיקה אם הקורס קיים כבר במחלקה
		if(*crs[i] == *c)
		{
			cout<<"Course already exist in some department!\n";
			return *this;
		}


		Course** _c=crs;//יצירת מצביע שמקבל את הכתובת של מערך הקורסים של המחלקה
		amount_crs++;//הגדלת כמות הקורסים

		crs=new Course*[amount_crs];//הקצאת זיכרון חדש בגודל המעודכן
		for(int i=0;i<amount_crs-1;i++)//לולאה שמחזירה את הכתובות למערך המקורי
			crs[i]=_c[i];

		crs[amount_crs-1]=c;//הוספת הקורס לרשימת הקורסים
		return *this;
}
Depertment& Depertment::operator+=( student *s)//אופרטור הוספת סטודנט למחלקה
{
	for(int i=0;i<amount_std;i++)//בדיקה אם הסטודנט קיים כבר במחלקה
		if(*std[i] == *s)
		{
			cout<<"Student already exist in some department!\n";
			return *this;
		}

		student** _s=std;//יצירת מצביע שמקבל את הכתובת של מערך הסטודנטים של המחלקה
		amount_std++;//הגדלת כמות הסטודנטים

		std=new student*[amount_std];//הקצאת זיכרון חדש בגודל המעודכן
		for(int i=0;i<amount_std-1;i++)//לולאה שמחזירה את הכתובות למערך המקורי
			std[i]=_s[i];

		std[amount_std-1]=s;//הוספת הסטודנט לרשימת הסטודנטים
		return *this;

}
void Depertment::setAmou_Failed_Std(student *s,int location)//פונקציה שמעדכנת את רשימת הסטודנטים הנכשלים
{

	student** _failed=failed_std;//יצירת מצביע שמקבל את הכתובת של מערך הסטודנטים הנכשלים של המחלקה
	amount_fstd++;//הגדלת כמות הסטודנטים הנכשלים

	failed_std=new student*[amount_fstd];//הקצאת זיכרון חדש בגודל המעודכן
	for(int i=0;i<amount_fstd-1;i++)//לולאה שמחזירה את הכתובות למערך המקורי
		failed_std[i]=_failed[i];

	failed_std[amount_fstd-1]=s;// הוספת הסטודנט הנכשל לרשימת הסטודנטים הנכשלים

}
void Depertment::reset_fstd()//פונקציה שמאתחלת את המערך של הסטודנטים הנכשלים
{

	if(failed_std!=NULL)
		delete failed_std;

	amount_fstd=0;
	failed_std=NULL;
}