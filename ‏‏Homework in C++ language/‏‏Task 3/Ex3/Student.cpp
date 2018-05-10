#include "Student.h"
#include "Course.h"
#include "Depertment.h"

student::student()//הפעלת בנאי דיפולטיבי שמאתחל את כל המשתנים
{
	courses=NULL;
	amount_courses=0;
	id=0;
	gender=NULL;
	age=0;
	NameStu="";
	student_dep=NULL;
}
student::~student()//הפעלת ההורס שמשחרר את הזיכרון 
{
	if(courses!=NULL)
		delete[] courses;
}
void student::set_dep( Depertment*d)
{
	student_dep=d;

}
student::student(const student&s)//בנאי העתקה
{
	NameStu=s.NameStu;
	id=s.id;
	gender=s.gender;
	age=s.age;
	amount_courses=s.amount_courses;
	student_dep=s.student_dep;
	courses=new Course*[amount_courses];//הקצאת זיכרון לרשימת הקורסים בגודל הרצוי
	for (int i = 0; i < amount_courses; i++)//לולאה שמעתיקה את הכתובות של המערך של הקורסים 
	{
		courses[i]=new Course;
		*courses[i]=*s.courses[i];
	}
}
student student::operator = (const student&s )//אופרטור השמה, מעתיק את כל פרטי הסטודנט מהסטודנט שהתקבל כפרטמטר לסטודנט הקיים
{

	NameStu=s.NameStu;
	id=s.id;
	gender=s.gender;
	age=s.age;
	amount_courses=s.amount_courses;
	student_dep=s.student_dep;
	delete courses;
	courses=new Course*[amount_courses];//הקצאת זיכרון לרשימת הקורסים בגודל הרצוי
	for (int i = 0; i < amount_courses; i++)//לולאה שמעתיקה את הכתובות של המערך של הקורסים 
	{
		courses[i]=new Course;
		*courses[i]=*s.courses[i];
	}
	return s;
}
const bool student::operator==(const student &s )//אופרטור השוואה בין ת.ז של סטודנט שהתקבל כפרטמר לסטונדט קיים
{
	if (id == s.id)
		return 1;
	else return 0;

}
const bool student::operator >(const student&s)//אופרטור שבודק האם הממוצע ציונים של הסטודנט גדול יותר מהממוצע של הסטודנט-פרמטר
{
	float average=0,_average=0;
	for(int i=0;i<amount_courses;i++)//לולאה חיצונית שעוברת על על הקורסים של הסטונדט הקיים
	{
		for(int j=0;j<courses[i]->getAmount();j++)//לולאה פנימית שעוברת על כל קורס ומחשבת את הציון שלו
		{
			if( ( *courses[i]->getRegister()[j] ) == *this)//מציאת מיקום הסטודנט ברשימת הקורסים
				if(courses[i]->getGrade()[j]!= -1)
					average+=courses[i]->getGrade()[j];//סכימת כל הציונים כל עוד הציון מעודכן
		}
	}

	for(int i=0;i<s.amount_courses;i++)//לולאה חיצונית שעוברת על על הקורסים של הסטונדט פרמטר
	{
		for(int j=0;j<s.courses[i]->getAmount();j++)//לולאה פנימית שעוברת על כל קורס ומחשבת את הציון שלו
		{
			if( (*(s.courses[i]->getRegister())[j]) == *this)//מציאת מיקום הסטודנט ברשימת הקורסים
				if(s.courses[i]->getGrade()[j]!= -1)
					_average+=courses[i]->getGrade()[j];//סכימת כל הציונים כל עוד הציון מעודכן
		}
	}

	average=average/amount_courses;
	_average=_average/s.amount_courses;

	if(average >_average)//בדיקה איזה ממוצע גדול יותר
		return true;
	else 
		return false;

}
ostream& operator<<(ostream&out, const student&s)//אופרטור פלט של פרטי הסטודנט
{
	out<<"Name: "<<s.NameStu<<", Id: "<<s.id<<", gender: "<<s.gender<<", age: "<<s.age<<endl;
	if(s.amount_courses)
	{
		cout<<"Courses:\n";
		for (int i = 0; i < s.amount_courses; i++)//לולאה שמדפיסה את פרטי הקורסים שהסטודנט רשום אליהם אם ישנם
			out<<"Name: "<<s.courses[i]->getNameC()<<", Number: "<<s.courses[i]->getNumOfTheCours()<<endl;
	}

	return out;
}
istream& operator>>(istream&in, student&s)//אופרטור קלט של פרטי סטודנט 
{
	cout<<"Please enter student details.\n"<<"Name: ";	
	in>>s.NameStu;
	cout<<"Id: ";
	in>>s.id;
	cout<<"Gender: ";
	in>>s.gender;
	cout<<"Age: ";
	in>>s.age;

	return in;

}
student& student::operator+=(Course *c) //אופרטור שמוסיף קורס לסטודנט
{

	if(!check_if_course_exists(c))//הפעלת פונקציה שבודקת אם הקורס כבר קיים אצל הסטודנט
	{
		Course **_courses=courses;//יצירת מצביע שמקבל את הכתובת של מערך הקורסים של הסטודנט

		amount_courses++;//עדכון כמות הקורסים של הסטודנט

		courses=new Course*[amount_courses];//הקצאת זיכרון חדש בגודל המעודכן

		for(int i=0;i< amount_courses-1;i++)//לולאה שמחזירה את הכתובות למערכך המקורי
			courses[i]=_courses[i];

		courses[amount_courses-1]=c;//הוספת הקורס לרשימת הקורסים
	}
	return *this;
}
student& student::operator-=(Course *c)//אופרטור שמוריד קורס מהסטודנט
{


	int j=0;
	for(int i=0;i<amount_courses;i++)//לולאה שבודקת אם הקורס קיים אצל הסטודנט
		if ( *courses[i]==*c )
		{
			courses[i]=NULL;//מוכנס לכתובת אם הקורס קיים אצל הסטודנט null
			break;
		}

		Course **_courses=courses;//יצירת מצביע שמקבל את הכתובת של מערך הקורסים של הסטודנט
		amount_courses--;//עדכון כמות הקורסים של הסטודנט

		courses=new Course*[amount_courses];//הקצאת זיכרון חדש בגודל המעודכן

		for(int i=0;i<amount_courses+1;i++)//לולאה שבודקת באיזה מיקום היה הקורס ומוחקת אותו מהרשימה
		{
			if(courses[i]==NULL)
				continue;
			else
			{
				_courses[j]=courses[i];
				j++;
			}
		}

		return *this;
}
Course student::operator[]( int location )//אופרטור שמחזיר את הקורס באינדקס - מקבל את מיקום הקורס ברשימה ומחזיר את הקורס הממוקם במיקום זה
{
	return *courses[location];
}
int student::check_if_course_exists(Course *c)//פונקציה חיצונית שבודקת אם הקורס קיים ברשימת הקורסים של הסטודנט
{
	for(int i=0;i<amount_courses;i++)
		if ( *courses[i]==*c )
			return 1;

	return 0;
}
float student::alculation_average_all_courses()//פונקצית עזר שמחשבת את ממוצע הציונים של כל הקורסים של הסטודנט
{
	float average_all_courses=0;
	for(int i=0;i<amount_courses;i++)//לולאה חיצונית שעוברת על כל הקורסים של התלמיד
	{
		for(int j=0;j<courses[i]->getAmount();j++)//לולאה פנימית שעוברת על כל התלמידים ומוצאת את הציון של התלמיד 
		{
			if( ( *courses[i]->getRegister()[j] ) == *this)
				if(courses[i]->getGrade()[j]!= -1)
					average_all_courses+=courses[i]->getGrade()[j];
		}
	}
	return (average_all_courses/amount_courses);//החזרת ממוצע הציונים של הסטודנט בכל הקורסים
}