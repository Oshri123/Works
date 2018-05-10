#include "Depertment.h"
#include "Course.h"
#include "Student.h"
Course::~Course()//בנאי הורס לשחרור הזכרון ממחקלת קורס
{
	if (registered!=NULL)
		delete registered;

	if(grade!=NULL)
		delete grade;

	/*if(dep_course!=NULL)
	delete dep_course;*/
}
Course::Course(const Course&c)//בנאי העתקה
{
	Name_C=c.Name_C;
	NumOfTheCours=c.NumOfTheCours;
	amount_students=c.amount_students;
	dep_course=c.dep_course;
	registered=new student*[c.amount_students];//הקצאת זיכרון לרשימת הסטודנטים בגודל הרצוי
	grade=new int[c.amount_students];//הקצאת זיכרון למערך הציונים בגודל הרצוי

	for (int i = 0; i < amount_students; i++)//לולאה שמעתיקה את הכתובות של המערך של הסטודטים והמערך של מערך הציונים
	{
		registered[i]=new student;
		*registered[i]=*c.registered[i];
		grade[i]=c.grade[i];
	}
}
void Course::set_course_dep(Depertment *d)
{
	dep_course=d;
}
Course Course::operator = (const Course&c )//אופרטור השמה, מעתיק את כל פרטי הקורס מהקורס שהתקבל כפרטמטר לקורס הקיים
{
	Name_C=c.Name_C;
	NumOfTheCours=c.NumOfTheCours;
	amount_students=c.amount_students;
	dep_course=c.dep_course;
	delete registered;
	delete grade;
	registered=new student*[c.amount_students];//הקצאת זיכרון לרשימת הסטודנטים בגודל הרצוי
	grade=new int[c.amount_students];//הקצאת זיכרון למערך הציונים בגודל הרצוי

	for (int i = 0; i < amount_students; i++)//לולאה שמעתיקה את הכתובות של המערך של הסטודטים והמערך של מערך הציונים
	{
		registered[i]=new student;
		*registered[i]=*c.registered[i];
		grade[i]=c.grade[i];
	}

	return c;
}
const bool Course::operator==(const Course&c )//אופרטור השוואה בין מספרי קורס
{
	if (NumOfTheCours==c.NumOfTheCours)
		return 1;
	else return 0;

}
const bool Course::operator>(const Course&c)//אופרטור שבודק אם יש יותר סטודנטים בקורס
{
	return(amount_students>c.amount_students);
}
istream& operator>>(istream&in,Course&c)//אופרטור קלט של פרטי הקורס מלבד סטודנטים והציונים
{
	cout<<"Please enter course details.\n"<<"Name: ";
	in>>c.Name_C;
	cout<<"Number: ";
	in>>c.NumOfTheCours;

	return in;
}
ostream& operator<<(ostream&out,Course&c)//אופרטור פלט של פרטי הקורס
{
	out<<"Name: "<<c.Name_C<<endl;
	out<<"Number: "<<c.NumOfTheCours<<endl;
	if(c.amount_students)//לולאה שמדפיסה את פרטי הסטודנטים שקיימים בקורס אם ישנם
	{
		out<<"Students:\n";
		for (int i = 0; i < c.amount_students; i++)
		{
			out<<"Name: "<<c.registered[i]->getName()<<", Id: "<<c.registered[i]->getID()<<", gender: "<<c.registered[i]->getGender()<<", age: "<<c.registered[i]->getAge();
			if(c.grade[i] != -1)
				out<<" Grade: "<<c.grade[i]<<endl;
			else
				out<<endl;
		}
	}

	return out;
}
student Course::operator[](int location)// אופרטור שמחזיר סטודנט באינדקס - מקבל את מיקום הסטודנט ברשימה ומחזיר את הסטודנט הממוקם במיקום זה
{
	return ( *registered[location] );
}
Course& Course::operator+=(student *s)//אופרטור שמוסיף סטודנט לקורס
{

	if(!check_if_student_exists(s))//הפעלת פונקציה שבודקת אם הסטודנט כבר רשום לקורס
	{
		student **_registered =registered;//יצירת מצביע שמקבל את הכתובת של מערך הסטודנטים של הקורס
		int *_grade=grade;//יצירת מצביע שמקבל את הכתובת של מערך הציונים
		amount_students++;//הגדלת כמות הסטודנטים

		registered =new student*[amount_students];//הקצאת זיכרון חדש בגודל המעודכן
		grade=new int[amount_students];//הקצאת זיכרון חדש בגודל המעודכן
		for (int i = 0; i < amount_students-1; i++)//לולאה שמחזירה את הכתובות למערכים המקוריים
		{
			registered[i]=_registered[i];
			grade[i]=_grade[i];
		}
		registered[amount_students-1]=s;//הוספת הסטודנט למערך
		grade[amount_students-1]=-1;//עדכון ציון לסטונדט
	}
	return *this;
}
Course& Course::operator-=(student *s)//אופרטור שמוריד סטודנט מהקורס
{

	int j=0;
	for(int i=0;i<amount_students;i++)//לולאה שבודקת אם הסטודנט רשום בקורס
		if ( *registered[i]==*s )
		{
			registered[i]=NULL;//מוכנס לכתובת אם הסטודנט רשום לקורס null
			break;
		}

		student **_registered=registered;//יצירת מצביע שמקבל את הכתובת של מערך הסטודנטים של הקורס
		int *_grade=grade;//יצירת מצביע שמקבל את הכתובת של מערך הציונים

		amount_students--;//עדכון כמות הסטודנטים בקורס


		registered=new student*[amount_students];//הקצאת זיכרון חדש בגודל המעודכן
		grade=new int[amount_students];//הקצאת זיכרון חדש בגודל המעודכן

		for(int i=0;i<amount_students+1;i++)//לולאה שבודקת באיזה מיקום היה הסטונדט ומוחקת אותו מהרשימה
		{
			if(_registered[i]==NULL)
				continue;
			else
			{
				registered[j]=_registered[i];
				grade[j]=_grade[i];
				j++;
			}
		}

		return *this;
}
int Course::check_if_student_exists(student *s)//פונקצית עזר שבודקת אם הסטודט רשום לקורס
{
	for (int i = 0; i < s->getAmountC(); i++)
		if(s->getCourses()[i] == this)
			return 1;

	return 0;
}
float Course::calculation_average()//פונקציית עזר שמחשבת את ציוני כל התלמידים בקורס
{
	float average=0;
	if (amount_students==0)//אם אין סטודטים מוחזר -1
		return -1;
	else
	{
		for (int i = 0; i < amount_students ; i++)// לולאה שמחשבת את ציוני הסטודנטים כל עוד כולם מעודכנים
		{
			if (grade[i]==-1)
				return -1;
			else average+=grade[i];
		}
	}
	return (average/amount_students);//החזרת ממוצע הציונים
}