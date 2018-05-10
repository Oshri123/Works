#include "Class.h"

Class::Class(char layer_n,int class_n)//בנאי שמעדכן את השיכבה של הכיתה ואת מספר הכיתה ומאפס את המערכים של התלמידים ואת המצביע של המחנך ואת כמות התלמידים בכיתה
{
	layer_name=layer_n;
	class_num=class_n+1;
	pupils=NULL;
	amount_pupils=0;
	tutor=NULL;
}

Class::~Class()//בנאי הורס שמשחרר את הזיכרון של המערך של התלמידים
{
	if(pupils!=NULL)
		delete[] pupils;
}

Class::Class(const Class&obj):layer_name(obj.layer_name),class_num(obj.class_num),amount_pupils(obj.amount_pupils),tutor(obj.tutor)//בנאי העתקה
{
	pupils=new Pupil*[obj.amount_pupils];//הקצאת זיכרון חדש למערך
	for (int i = 0; i < obj.amount_pupils; i++)//הקצאת זיכרון חדש לכל תא +העתקת התאים מהאובייקט
		pupils[i]=new Pupil(*obj.pupils[i]);
}

int Class::check_if_pupil_exist(Pupil *pl)//פונקציה שבודקת אם התלמיד נמצא בכיתה 
{
	for (int i = 0; i < amount_pupils; i++)//לולאה שעוברת על כל התלמידים ומשווה את הת.ז של התלמיד שהתקבל כפרמטר עם התלמידים בכיתה
	{
		if(pupils[i]->get_id()==pl->get_id())
			return i;
	}
	return NOT_EXIST;
}

void Class::add_pupil(Pupil *pl)//מתודה שמקבלת תלמיד כפרמטר ומוסיפה אותו לכיתה
{
	Pupil **p=pupils;//יצירת מצביע עזר לשמירת מערך התלמידים בכיתה

	if(check_if_pupil_exist(pl)!=NOT_EXIST)//בדיקה אם התלמיד כבר קיים בכיתה
		return;

	pupils=new Pupil*[amount_pupils+1];//הקצאת זיכרון חדשה לרשימת התלמידים
	for (int i = 0; i < amount_pupils; i++)//העתקת התלמידים שלמדו בכיתה לפני שהגדלנו את הזיכרון
		pupils[i]=p[i];

	pupils[amount_pupils]=pl;//הוספת התלמיד למאגר התלמידים
	amount_pupils++;//הגדלת מספר התלמידים בכיתה

	if(p!=NULL)//שחרור הזיכרון של מצביע העזר
		delete p;

}

Pupil* Class::return_pupil(int location)//מתודה שמבבלת מיקום של תלמיד ומחזירה את המצביע לתלמיד
{
	if(location>amount_pupils)//בדיקה אם המיקום שהתקבל תקין
		return NULL;
	else return pupils[location];//אם המיקום תקין מוחזר המצביע לתלמיד

}