#include "Student.h"
#include "Empolyee.h"
#include <iostream>
#include <typeinfo>
using namespace std;
#ifndef CMYARRAY_H
#define CMYARRAY_H
template <class T>
class CMyArray
{
public:
	CMyArray(int _size=1):size(_size),arr(new T [_size]){count_CMyArray++; total_length+=_size;}//בנאי העתקה שסופר את כמות המערכים שנבנו וסוכמת את גודלם של כל המערכים
	~CMyArray()
	{
		if(arr!=NULL)//שחרור הזיכרון במערך
			delete[] arr;
	}
	T operator [](int location);
	void swap(int location1,int location2);
	void print_element(int location);
	void  print_all();
	void print_max();
	T* get_arr(){return arr;}
	int find_total(){return count_CMyArray;}
	int find_total_length();
	void write_to_file(ofstream &write)const;
	int get_size(){return size;}
private:
	T *arr;
	int size;
	static int count_CMyArray;
	static int total_length;
};

#endif

template <class T>//איפוס המשתנה הסטטי
int CMyArray<T>::count_CMyArray=0;

template <class T>//איפוס המשתנה הסטטי
int CMyArray<T>::total_length=0;

template <class T>
void CMyArray<T>::swap(int location1,int location2)//מתודה שמקבלת שני מיקומים של איברים במערך הטפלט ומחליפה בינהם אם המיקומים לא חורגים מהמערך
{
	if((location1-1)<size && (location2-1)<size)//בדיקה אם המיקומים לא חורגים מהמערך
	{
		T temp;//יצירת אובייקט עזר מסוג טמפלט
		temp=arr[location1-1];//הכנסת האיבר בעל המיקום הראשון לאובייקט עזר כדיי לשמור על האובייקט לפני ההחלפה
		arr[location1-1]=arr[location2-1];//העברת האובייקט מהמיקום הראשון למיקום השני
		arr[location2-1]=temp;//העברת האובייקט מהמיקום השני למיקום הראשון
	}
	else 
		cout<<"The location are not exist!\n";
};

template <class T>
void CMyArray<T>::print_element(int location)//מתודה שמקבלת מיקום של איבר במערך ומדפיסה אותו
{
	if(size>(location-1))//בדיקה אם המיקום שהתקבל לא חורג מהמערך
		cout<<arr[location-1];//הדפסת האיבר מהמיקום שהתקבל
};

template <class T>
void  CMyArray<T>::print_all()//מתודה להדפסת כל איברי המערך
{
	for (int i = 0; i < size; i++)//לולא שעוברת על כל המערך ומדפיסה את כל האיברים במערך
		cout<<arr[i]<<endl;
}

template <class T>
T CMyArray<T>::operator[](int location)
{
	if(size>(location-1))//בדיקה אם המיקום שהתקבל לא חורג מהמערך
		return arr[location-1];//החזרת האובייקט לפי המיקום המבוקש

}

template <class T>
void CMyArray<T>::print_max()//פונקציה שבודקת את הסטודנט עם הממוצע הכי גבוה או את העובד עם השכר הכי גבוה
{
	T max;//יציירת אובייקט טמפלט שייכיל את האובייקט המקסימאלי
	max=arr[0];//השמת ערך ראשוני באובייקט
	for (int i = 1; i < size; i++)//לולא שעוברת על מערך הטמפלט ובודקת מיהו האובייקט המקסימאלי
		if (arr[i]>max)
			max=arr[i];//אם האובייקט שנבדק גדול יותר מהאובייקט המקסימלי, מוחלף האובייקט המקסימאלי באובייקט החדש
	if( typeid(max)==typeid(Student) )//בדיקה אם האובייקט טמפלט הוא סטודנט או עובד והדפסת הודעה מתאימה
		cout<<"The student with max average is:\n"<<max<<endl;
	else 
		cout<<"The empolyee with max salary is:\n"<<max<<endl;

};

template <class T>
int CMyArray<T>::find_total_length()//מתודה שמחזירה את כמות המערכים מאותו סוג אובייקט
{
	return total_length;
}

template <class T>
void  CMyArray<T>::write_to_file(ofstream &write)const //מתודה שכותבת את מערך התבנית בקובץ
{	
	for (int i = 0; i < size; i++)
		write<<arr[i];
}









