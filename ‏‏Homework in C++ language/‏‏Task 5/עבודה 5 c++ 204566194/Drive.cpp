#include"CMyArray.h"
#include <iostream>
#include <fstream>
#include <vld.h>
#include <string>
using namespace std;
void main()
{
	string input_file,output_file;
	CMyArray<Student>  *stu_arr1;//בניית המצביע הראשון של הסטודנטים
	CMyArray<Student>  *stu_arr2;//בניית המצביע השני של הסטודנטים
	CMyArray<Empolyee> *emp_arr1;//בניית המצביע הראשון של העובדים
	CMyArray<Empolyee> *emp_arr2;//בניית המצביע השני של העובדים
	CMyArray<Empolyee> *emp_arr3;//בניית המצביע השלישי של העובדים

	int flag=1,location1,location2,size;
	while(flag){
		cout<<"\nEnter the name of the input file: ";
		cin>>input_file;
		ifstream open(input_file,ios::in);//פתיחת הקובץ לקריאה
		if(open.fail())//בדיקה שהקובץ נפתח בהצלחה
			cout<<"\n--The file canot be opened!--\n";
		else
		{
			flag=0;
			cout<<"\nThe file opened correctly!\n";
		}
		open.close();//אם לא נפתח הקובץ בהצלחה הקובץ נסגר ופותחים אותו מחדש
	}
	ifstream open(input_file,ios::in);//פתיחת הקובץ מחדש אחרי הבדיקה שהשם של הקובץ  שנקלט תקין
	cout<<"\nEnter the name of the output file: ";
	cin>>output_file;
	cout<<endl;
	ofstream write(output_file,ios::out);//פתיחת הקובץ לכתיבה
	
	try{
		open>>size;//קליטת הגודל של האובייקט תבנית מהקובץ
		stu_arr1=new CMyArray<Student>(size);//הקצאת דינמית של האובייקט תבנית
		for (int i = 0; i < size; i++)//קליטת הנתונים מהקובץ לאובייקט
			open>>stu_arr1->get_arr()[i];

		open>>size;//קליטת הגודל של האובייקט תבנית מהקובץ
		stu_arr2=new CMyArray<Student>(size);//הקצאת דינמית של האובייקט תבנית
		for (int i = 0; i < size; i++)//קליטת הנתונים מהקובץ לאובייקט
			open>>stu_arr2->get_arr()[i];

		open>>size;//קליטת הגודל של האובייקט תבנית מהקובץ
		emp_arr1=new CMyArray<Empolyee>(size);//הקצאת דינמית של האובייקט תבנית
		for (int i = 0; i < size; i++)//קליטת הנתונים מהקובץ לאובייקט
			open>>emp_arr1->get_arr()[i];

		open>>size;//קליטת הגודל של האובייקט תבנית מהקובץ
		emp_arr2=new CMyArray<Empolyee>(size);//הקצאת דינמית של האובייקט תבנית
		for (int i = 0; i < size; i++)//קליטת הנתונים מהקובץ לאובייקט
			open>>emp_arr2->get_arr()[i];

		open>>size;//קליטת הגודל של האובייקט תבנית מהקובץ
		emp_arr3=new CMyArray<Empolyee>(size);//הקצאת דינמית של האובייקט תבנית
		for (int i = 0; i < size; i++)//קליטת הנתונים מהקובץ לאובייקט
			open>>emp_arr3->get_arr()[i];

		for (int i = 0; i < stu_arr1->get_size(); i++)//הפעלת המתודה שבודקת חריגות באובייקט
			stu_arr1->get_arr()[i].check_exception(stu_arr1->get_arr()[i]);

		for (int i = 0; i < stu_arr2->get_size(); i++)//הפעלת המתודה שבודקת חריגות באובייקט
			stu_arr2->get_arr()[i].check_exception(stu_arr2->get_arr()[i]);

		for (int i = 0; i < emp_arr1->get_size(); i++)//הפעלת המתודה שבודקת חריגות באובייקט
			emp_arr1->get_arr()[i].check_exception(emp_arr1->get_arr()[i]);

		for (int i = 0; i < emp_arr2->get_size(); i++)//הפעלת המתודה שבודקת חריגות באובייקט
			emp_arr2->get_arr()[i].check_exception(emp_arr2->get_arr()[i]);

		for (int i = 0; i < emp_arr3->get_size(); i++)//הפעלת המתודה שבודקת חריגות באובייקט
			emp_arr3->get_arr()[i].check_exception(emp_arr3->get_arr()[i]);

		cout<<"\nEnter two location between 1-2 to swap the first array of students\n";
		cout<<"Location 1: ";
		cin>>location1;
		cout<<"\nLocation 2: ";
		cin>>location2;
		stu_arr1->swap(location1,location2);

		cout<<"\nEnter two location between 1-2 to swap the second array of students\n";
		cout<<"Location 1: ";
		cin>>location1;
		cout<<"\nLocation 2: ";
		cin>>location2;
		stu_arr2->swap(location1,location2);

		cout<<"\nEnter two location between 1-2 to swap the first array of empolyee\n";
		cout<<"Location 1: ";
		cin>>location1;
		cout<<"\nLocation 2: ";
		cin>>location2;
		emp_arr1->swap(location1,location2);

		cout<<"\nEnter two location between 1-2 to swap the second array of empolyee\n";
		cout<<"Location 1: ";
		cin>>location1;
		cout<<"\nLocation 2: ";
		cin>>location2;
		emp_arr2->swap(location1,location2);

		cout<<"\nEnter two location between 1-2 to swap the third array of empolyee\n";
		cout<<"Location 1: ";
		cin>>location1;
		cout<<"\nLocation 2: ";
		cin>>location2;
		emp_arr3->swap(location1,location2);

		write<<"---------------------------------\n";
		write<<"The new file\n";
		write<<"---------------------------------\n";

		stu_arr1->write_to_file(write);//הפעלת המתודה שכותבת לקובץ את הנתונים של האובייקט
		stu_arr2->write_to_file(write);//הפעלת המתודה שכותבת לקובץ את הנתונים של האובייקט
		write<<"amount of CMyArray<Student>: "<<stu_arr1->find_total()<<endl;
		write<<"---------------------------------\n";
		write<<"amount <Student> total_length: "<<stu_arr1->find_total_length()<<endl;
		write<<"---------------------------------\n";
		emp_arr1->write_to_file(write);//הפעלת המתודה שכותבת לקובץ את הנתונים של האובייקט
		emp_arr2->write_to_file(write);//הפעלת המתודה שכותבת לקובץ את הנתונים של האובייקט
		emp_arr3->write_to_file(write);//הפעלת המתודה שכותבת לקובץ את הנתונים של האובייקט
		write<<"amount of CMyArray<Empolyee>: "<<emp_arr3->find_total()<<endl;
		write<<"---------------------------------\n";
		write<<"amount <Empolyee> total_length: "<<emp_arr3->find_total_length()<<endl;
		write<<"---------------------------------\n";

	}
	catch (char* str)//תפיסת החריגה אם קיימת
	{
		cerr<<"*****************************************\n";
		cerr<<str<<endl;
		cerr<<"*****************************************\n";
	}

	//**שחרור כל הזיכרון של המערכים מסוג התבנית שנוצרו בתכנית
	if(stu_arr1!=NULL)
		delete stu_arr1;
	if(stu_arr2!=NULL)
		delete stu_arr2;
	if(emp_arr1!=NULL)
		delete emp_arr1;
	if(emp_arr2!=NULL)
		delete emp_arr2;
	if(emp_arr3!=NULL)
		delete emp_arr3;

	open.close();//סגירת הקובץ לקריאה
	write.close();//סגירת הקובץ לכתיבה
}