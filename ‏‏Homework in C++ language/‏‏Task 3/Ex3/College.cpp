#include "College.h"
College::~College()//בנאי הורס לשחרור הזיכרון של מחלקה קולג
{
	if(all_dep!=NULL)
		for(int i=0;i<total_dep;i++)
			delete all_dep[i];

	if(std_total!=NULL)
		delete std_total;
}
College::College(const College&c)//בנאי העתקה
{
	total_dep=c.total_dep;
	total_student=c.total_student;
	delete all_dep;
	delete std_total;
	all_dep=new Depertment*[total_dep];//הקצאת זיכרון לרשימת המחלקות בגודל הרצוי
	std_total=new student*[total_student];//הקצאת זיכרון לרשימת הסטודנטים בגודל הרצוי

	for(int i=0;i<total_dep;i++)//לולאה שמעתיקה את מערך המחלקות של הפרטמר למערך הקיים
	{
		all_dep[i]=new Depertment;
		*all_dep[i]=*c.all_dep[i];
	}

	for (int i = 0; i < total_student; i++)//לולאה שמעתיקה את מערך הסטודנטים של הפרטמר למערך הקיים
	{
		std_total[i]=new student;
		*std_total[i]=*c.std_total[i];
	}
}
void College::Add_department()//הוספת מחלקה חדשה 
{
	Depertment **new_dep=all_dep;//יצירת מצביע חדש שמצביע על הכתובת של הרשימה של המחלקות
	Depertment *_d=new Depertment();//יצירת מחלקה חדשה
	cin>>*_d;//קלט פרטי המחלקה

	if(check_if_dep_exists(_d->getCode())==NOT_EXISTS)//בדיקה אם המחלקה קיימת כבר
	{
		all_dep=new Depertment*[total_dep+1];//הקצאה זיכרון להוספת המחלקה החדשה
		for(int i=0;i<total_dep;i++)//לולאה שמעתיקה את הכתוב
			all_dep[i]=	new_dep[i];

		all_dep[total_dep]=new Depertment;
		all_dep[total_dep]=_d;//הוספת מחלקה חדשה לרשימת המחלקות
		total_dep++;

	}
	else 
		cout<<"Department already exists!\n";

}
int College::check_if_dep_exists(int code)//פונקציית עזר שבודקת אם המחלקה קיימת ברשימת המחלקות
{
	for(int i=0; i<total_dep;i++)
		if(code == all_dep[i]->getCode())//אם היא קיימת מוחזר המיקום שלה במערך
		{
			return i;
		}

		return NOT_EXISTS;//אחרת מוחזר משתנה גלובלי שמודיע שהמחלקה לא קיימת
}
int College::check_if_courses_exists(int code,int location)//פונקציית עזר שבודקת אם הקורס קיימת ברשימת הקורסים
{
	for(int i=0; i<all_dep[location]->getAmou_Crs(); i++)
		if(code == all_dep[location]->getCrs()[i]->getNumOfTheCours())//אם היא קיימת מוחזר המיקום שלה במערך
		{
			return i;
		}
		return NOT_EXISTS;//אחרת מוחזר משתנה גלובלי שמודיע שהקורס לא קיים
}
int College::check_if_students_exists(student *s ,int location)//פונקציית עזר שבודקת אם המחלקה קיימת ברשימת המחלקות
{
	for(int i=0; i<all_dep[location]->getAmou_Std(); i++)
		if( *(all_dep[location]->getStd()[i]) == *s)//אם הוא קיים מוחזר המיקום שלו במערך
		{
			return i;
		}
		return NOT_EXISTS;//אחרת מוחזר משתנה גלובלי שמודיע שהסטודנט לא קיימת
}
void College::Add_course_to_department()//פונקציה שמוסיפה קורס למחלקה
{
	Course *_c=new Course;//יצירת מצביע חדש מסוג קורס
	int dep_location,dep_code;
	cout<<"Enter department code: ";
	cin>>dep_code;
	dep_location=check_if_dep_exists(dep_code);

	if(dep_location!=NOT_EXISTS )//בדיקה אם המחלקה קיימת
	{
		cin>>*_c;//קליטת פרטי הקורס
		for(int i=0; i<all_dep[dep_location]->getAmou_Crs(); i++)//בדיקה אם הקורס קיים כבר במחלקה
			if( *(all_dep[dep_location]->getCrs()[i] )== *_c)
			{
				cout<<"Course already exists in some department!\n";
				return;
			}
			*(all_dep[dep_location])+= _c;//אם לא קיים הוא מתווסף לרשימת הקורסים
			_c->set_course_dep(all_dep[dep_location]);
	}
	else 
		cout<<"Department does not exists!\n";
}
void College::Add_student_to_department()
{
	student *_s=new student; //יצירת מצביע מסוג סטונדט
	int dep_location,dep_code;
	cout<<"Enter department code: ";
	cin>>dep_code;
	dep_location=check_if_dep_exists(dep_code);

	if(dep_location!=NOT_EXISTS )//בדיקה אם המחלקה קיימת
	{
		cin>>*_s;//קליטת פרטי הסטודנט
		for(int i=0;i<all_dep[dep_location]->getAmou_Std();i++)
			if( *_s == *(all_dep[dep_location]->getStd()[i]) )
			{
				cout<<"Student already exists in some department!\n";
				return;
			}
			//total_student++;//הגדלת כמות הסטונדטים במכללה
			*(all_dep[dep_location])+= _s;//הוספרת הסטונדט למחלקה

			student **new_std=std_total;//הוספת סטודנט למכללה
			std_total=new student*[total_student+1];
			for (int i = 0; i < total_student; i++)
				std_total[i]=new_std[i];

			std_total[total_student]=_s;
			std_total[total_student]->set_dep( all_dep[dep_location] );// עדכון המחלקה לסטודנט

			total_student++;//הגדלת כמות הסטונדטים במכללה

	}
	else 	cout<<"Department already exists!\n";

}
void College::Register_student_to_course()//פונקצייה לרישום סטונדט מהמחלקה לקורס
{
	student *selected_stu=NULL,s;
	Course *selected_crs=NULL;
	int dep_code;
	int num_of_course;
	int id;
	cout<<"Enter department code, course number and id of student:\n";
	cin>>dep_code>>num_of_course>>id;
	s.setID(id);
	int dep_location=check_if_dep_exists(dep_code);
	int course_location=check_if_courses_exists(num_of_course,dep_location);
	int student_location=check_if_students_exists(&s,dep_location);
	if(dep_location==NOT_EXISTS)//בדיקה אם המחלקה קיימת
		cout<<"Depertment does not exist!\n";
	else if(course_location==NOT_EXISTS)//בדיקה אם הקורס קיים
		cout<<"Course does not exist!\n";
	else if(student_location==NOT_EXISTS)//בדיקה אם הסטודנט קיים
		cout<<"Student does not exist!\n";
	else {
		selected_stu=all_dep[dep_location]->getStd()[student_location];
		selected_crs=all_dep[dep_location]->getCrs()[course_location];

		*selected_crs+=selected_stu;//הוספת הסטודנט לקורס
		*selected_stu+=selected_crs;//הוספת הקורס לרשימת הקורסים של הסטודנט
	}


}
void College::Print_course_information()//הדפסת פרטים של קורס
{
	int course_number,course_location;
	Course *c=NULL,_c;
	cout<<"Enter course number: ";
	cin>>course_number;
	cout<<endl;
	for (int i = 0; i < total_dep; i++)
	{
		course_location=check_if_courses_exists(course_number,i);//מציאת מיקום הקורס במחלקה
		if(course_location!=NOT_EXISTS)
		{
			c=all_dep[i]->getCrs()[course_location];
			break;
		}
		else if(i==total_dep)
		{
			cout<<"Course does not exist!\n";
			return;
		}
	}
	cout<<"The course was found in the following department:\n";
	cout<<"Name: "<<c->get_depCourse()->getDep_N()<<"\ncode: "<<c->get_depCourse()->getCode()<<endl;
	cout<<"Course information:\n"<<*c;

	if(c->calculation_average()!=-1)//הפעלת הפונקציה שמחשבת ממוצע קורס
		cout<<"The course average  is: "<<c->calculation_average()<<endl;//הדפסת ממוצע הקורס אם לכל הסטודנטים בקורס יש ציון
}
void College::Grading_students_in_course()//פונקציה שנותנת ציון לסטודנטים בקורס
{
	int course_number,course_location,dep_location,grade;
	cout<<"Enter course number: ";
	cin>>course_number;
	for (int i = 0; i < total_dep; i++)//מציאת מיקום הקורס במחלקה
	{
		course_location=check_if_courses_exists(course_number,i);
		if(course_location!=NOT_EXISTS)
		{
			dep_location=i;
			break;
		}
		else if(i==total_dep)
		{
			cout<<"Course does not exist!\n";
			return;
		}
	}
	int num_std=all_dep[dep_location]->getCrs()[course_location]->getAmount();//הכנסת כמות הסטודנטים בקורס למשתנה חדש
	cout<<"Please enter grades for the following students (ids).\n";
	for (int i = 0; i < num_std; i++)//לולאה שמציגה ת.ז של סטודטים וקולטת להם את ציוניהם
	{
		cout<<all_dep[dep_location]->getCrs()[course_location]->getRegister()[i]->getID()<<": ";
		cin>>grade;
		all_dep[dep_location]->getCrs()[course_location]->setGrade(i,grade);
		cout<<endl;
	}
	cout<<"Finished grading students.\n";
}
void College::Print_student_information()//הדפסת פרטים של סטודנט
{
	student *s=NULL,_s;
	int id;
	cout<<"Enter student id: ";
	cin>>id;
	cout<<endl;
	_s.setID(id);//הכנסת הת.ז של הסטודנט לאובייקט כדיי להשתמש באופרטור השוואה בין מחלקות
	for (int i = 0; i < total_student; i++)//מציאת הסטודנט הרצוי מבין כל הסטודנטים 
	{
		if(*std_total[i]==_s)//בדיקה אם מצאנו את הסטודנט הרצוי
		{
			s=std_total[i];
			cout<<"The course was found in the following department:\n";
			cout<<"Name: "<<s->get_dep()->getDep_N()<<"\ncode: "<<s->get_dep()->getCode()<<endl;//הדפסת פרטי הסטודנט
			cout<<"Student information:\n"<<*s;
			return;
		}
	}
	cout<<"Student does not exist!\n";
}
void College::Print_department_information()//הדפסת פרטים של מחלקה
{
	int dep_location,dep_code;
	cout<<"Enter department code: ";
	cin>>dep_code;
	cout<<endl;
	dep_location=check_if_dep_exists(dep_code);
	if (dep_location==NOT_EXISTS)//בדיקה אם המחלקה קיימת
	{
		cout<<"Department does not exists!\n";
		return;
	}
	cout<<*(all_dep[dep_location]);//הפעלת אופרטור ההדפסה של המחלקה על המחלקה המבוקשת
}
void College::Find_students_with_bad_academic_status()//פונקצייה למציאת סטודנטים עם ציונים קטנים מ65
{
	student *s=NULL;
	int dep_location,dep_code,j=0;
	cout<<"Enter department code: ";
	cin>>dep_code;
	cout<<endl;
	dep_location=check_if_dep_exists(dep_code);//בדיקה אם המחלקה קיימת
	if (dep_location==NOT_EXISTS)
	{
		cout<<"Department does not exists!\n";
		return;
	}

	all_dep[dep_location]->reset_fstd();//ניקוי המערך של התלמידים הנכשלים לאחר כל כניסה חדשה לפונקציה
	int amount_s=all_dep[dep_location]->getAmou_Std();//הכנסת גודל התלמידים למשתנה חדש
	for (int i = 0; i <amount_s ; i++)//לולאה שעוברת על כל התלמידים ובודקת באמצעות פונקציית עזר מי מהמתלמידים נכשל ומכניסה אותם למערך
	{
		if( (all_dep[dep_location]->getStd()[i]->alculation_average_all_courses()>=0 ) && ( all_dep[dep_location]->getStd()[i]->alculation_average_all_courses()<=65) )
		{
			s=all_dep[dep_location]->getStd()[i];
			all_dep[dep_location]->setAmou_Failed_Std(s,j);
		}
	}
}
void College::Remove_student_from_course()//פונקציה להסרת סטונדט מקורס 
{
	student *selected_stu=NULL,s;
	Course *selected_crs=NULL;
	int id, course_location, student_location,course_dep_location,student_dep_location,num_of_course;
	cout<<"Enter course number and id of student:\n";
	cin>>num_of_course>>id;
	s.setID(id);

	for(int i=0;i<total_dep;i++)//בדיקה אם הקורס קיים
	{
		for (int j = 0; j < all_dep[i]->getAmou_Crs(); j++)
		{
			course_location=check_if_courses_exists(num_of_course,i);
			if(course_location!=NOT_EXISTS)
			{
				course_dep_location=i;
				break;
			}
		}
	}

	for(int i=0;i<total_dep;i++)//בדיקה אם הסטודנט קיים בקורס
	{
		for (int j = 0; j < all_dep[i]->getAmou_Std(); j++)
		{
			student_location=check_if_students_exists(&s,i);
			if(student_location!=NOT_EXISTS)
			{
				student_dep_location=i;
				break;
			}
		}
	}

	if(course_location==NOT_EXISTS)
		cout<<"Course does not exist!\n";
	else if(student_location==NOT_EXISTS)
		cout<<"Student does not exist!\n";
	else
	{
		selected_stu=all_dep[student_dep_location]->getStd()[student_location];
		selected_crs=all_dep[course_dep_location]->getCrs()[course_location];

		*selected_crs-=selected_stu;//הסרת התלמיד מרשימת הקורסים
		*selected_stu-=selected_crs;//הסרת הקורס מרשימת הקורסים של הסטונדט
	}

}
int College::menu()//פונקציית התפריט 
{
	int choice;

	do{		system("cls");
	cout<<"1 - add department\n";
	cout<<"2 - Add course to department\n";
	cout<<"3 - Add student to department\n";
	cout<<"4 - Register student to course\n";
	cout<<"5 - Grading students in course\n";
	cout<<"6 - Print course information\n";
	cout<<"7 - Print student information\n";
	cout<<"8 - Print department information\n";
	cout<<"9 - Find students with bad academic status\n";
	cout<<"10 - Remove student from course\n";
	cout<<"11 - Exit\n";
	cout<<"please enter your choice: ";
	cin>>choice;
	cout<<endl;
	switch (choice)//לולאה שמנווטת את בחירת המשתמש ומפעילה את הפונקציה המתבקשת
	{
	case 1:
		Add_department();
		break;

	case 2:
		Add_course_to_department();
		break;

	case 3:
		Add_student_to_department();
		break;

	case 4:
		Register_student_to_course();
		break;

	case 5:
		Grading_students_in_course();
		break;

	case 6:
		Print_course_information();
		break;

	case 7:
		Print_student_information();
		break;

	case 8:
		Print_department_information();
		break;

	case 9:
		Find_students_with_bad_academic_status();
		break;

	case 10:
		Remove_student_from_course();
		break;

	}


	system("pause");//הקפאת המסך לפני ניקוי
	}while(choice!=EXIT);

	return 0;
}

