#include "Layer.h"

Layer::Layer(char layer_n)//בנאי שמקבל שם של שיכבה ויוצר לשיכבה 3 כיתות
{
	layer_name=layer_n;
	amount_classes=3;
	classes=new Class*[amount_classes];//הקצאת זיכרון למערך הכיתות בגודל של כמות הכיתות

	for (int i = 0; i < amount_classes; i++)//הקצאת זיכרון פנימי לכל מצביע לכיתה
		classes[i]=new Class(layer_name,i);
}

Layer::~Layer()//בנאי הורס לשחרור הזיכרון
{
	for (int i = 0; i < amount_classes; i++)//לולאה שמשחררת את כל הכיתות של השיכבה
		delete classes[i];

	if(classes!=NULL)//שחרור המצביע של המצביעים
		delete[] classes;
}

Layer::Layer(const Layer&obj):layer_name(obj.layer_name),amount_classes(obj.amount_classes)//בנאי העתקה
{
	classes=new Class*[obj.amount_classes];//הקצאת זיכרון חדש למערך
	for (int i = 0; i < obj.amount_classes; i++)//הקצאת זיכרון + העתקת התוכן מהאובייקט
		classes[i]=new Class(*obj.classes[i]);
}

Class* Layer::return_class(int location)//מתודה שמקבלת מיקום של כיתה בשכבה ומחזירה את המצביע אליה
{
	if( location < 0 || location >= 3 )//בדיקה שהמיקום שהתקבל תקין
		return classes[0];
	else return classes[location];
}
