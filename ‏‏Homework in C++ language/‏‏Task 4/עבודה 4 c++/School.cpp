#include "School.h"

School::School()
{
	int j=0;
	amount_layers=6;
	layers=new Layer*[amount_layers];

	for(char i='a';i != 'g';i++)
	{
		layers[j]=new Layer(i);
		j++;
	}
	amount_presons=0;
	persons=NULL;
	exist_manager=false;
}

School::~School()
{

	for (int i = 0; i < amount_layers; i++)
		delete layers[i];

	if(layers!=NULL)
		delete[] layers;

	for (int i = 0; i < amount_presons; i++)
	{
		if(persons[i]!=NULL)
			delete persons[i];
	}

	if(persons!=NULL)
		delete[] persons;

}

void School::help_copy(Person *p,int location)//מתודת עזר פרטית לבנאי ההעתקה כדיי להעתיק את כל המערך של הפרסונים מהאובייקט
{
	Pupil *help1=dynamic_cast<Pupil*>(p);//שימוש בדינאמיק-קאסט כדיי להעתיק אובייקט מסוג תלמיד
	Teacher *help2=dynamic_cast<Teacher*>(p);//שימוש בדינאמיק-קאסט כדיי להעתיק אובייקט מסוג מורה
	Tutor *help3=dynamic_cast<Tutor*>(p);//שימוש בדינאמיק-קאסט כדיי להעתיק אובייקט מסוג מחנך
	Manager *help4=dynamic_cast<Manager*>(p);//שימוש בדינאמיק-קאסט כדיי להעתיק אובייקט מסוג מנהל
	Secretary *help5=dynamic_cast<Secretary*>(p);//שימוש בדינאמיק-קאסט כדיי להעתיק אובייקט מסוג מזכירה

	if(help1!=NULL)//בדיקה אם האובייקט שהתקבל הוא של תלמיד
	{
		for (int i = 0; i < amount_layers; i++)//לולאה שעוברת על כל השכבות
		{
			for (int j = 0; j < 3; j++)// לולאה אמצעית שעוברת על  3 הכיתות שבכל שיכבה
				for(int k=0;k<layers[i]->get_classes()[j]->get_amount_pupils();k++)//לולאה פנימית שעוברת על כל התלמידים שבכל כיתה
				{
					if(layers[i]->get_classes()[j]->get_pupils()[k]->get_id()==help1->get_id())//השוואת התלמיד אובייקט עם התלמידים מהכיתה ע"י ת.ז
						persons[location]=layers[i]->get_classes()[j]->get_pupils()[k];//אם זוהה התלמיד אזיי מעתיקים את הכתובת שלו למערך הפרסונים כדיי להימנע מדליפת זיכרון
				}
		}
	}
	else if((help2!=NULL)&&(help3==NULL))//בדיקה אם האובייקט שהתקבל הוא של מורה
		persons[location]=new Teacher(*help2);//יצירת אובייקט חדש להעתקת המורה מהאובייקט למערך ה-פרסונים
	else if(help3!=NULL)//בדיקה אם האובייקט שהתקבל הוא של מחנך
		persons[location]=new Tutor(*help3);//יצירת אובייקט חדש להעתקת המחנך מהאובייקט למערך ה-פרסונים
	else if(help4!=NULL)//בדיקה אם האובייקט שהתקבל הוא של מנהל
		persons[location]=new Manager(*help4);//יצירת אובייקט חדש להעתקת המנהל מהאובייקט למערך ה-פרסונים
	else if(help5!=NULL)//בדיקה אם האובייקט שהתקבל הוא של מזכירה
		persons[location]=new Secretary(*help5);//יצירת אובייקט חדש להעתקת המזכירה מהאובייקט למערך ה-פרסונים
}

School::School(const School&obj):amount_layers(obj.amount_layers),amount_presons(obj.amount_presons),exist_manager(obj.exist_manager)
{
	layers=new Layer*[obj.amount_layers];//הקצאת זיכרון חדש למערך השכבות
	for (int i = 0; i < obj.amount_layers; i++)//העתקת השכבות מהאובייקט באמצעות בנאי העתקה של שיכבה
		layers[i]=new Layer(*obj.layers[i]);

	persons=new Person*[obj.amount_presons];//הקצאת זיכרון חדש למערך האנשים
	for (int i = 0; i < obj.amount_presons; i++)//העתקת התלמידים מהאובייקט באמצעות בנאי העתקה הוירטואלי של פרסון שיתאים לכל פרסון את בנאי העתקה שלו
		help_copy(obj.persons[i],i);
}

void School::add_person( Person *p)
{
	Person **temp=persons;//יצירת מצביע עזר למערך ה-פרסונים

	persons=new Person*[amount_presons+1];//הגדלת מערך ה-פרסונים כדיי שיעדכן בו את הפרסון החדש
	for (int i = 0; i < amount_presons; i++)//לולאה שמעתיקה את כל האנשים שהיו במערך לפני ההקצאה החדשה
		persons[i]=temp[i];

	persons[amount_presons]=p;//הכנסת הפרסון למערך ה-פרסונים
	amount_presons++;//הגדלת כמות האנשים בבית הספר

	if(temp!=NULL)//מחיקת מצביע העזר
		delete[] temp;
}

bool School::check_if_person_exist(int _id)
{
	for (int i = 0; i < amount_presons; i++)
		if(persons[i]->get_id()==_id)
			return true;
	return false;
}

void School::Add_pupil()//פונקציה להוספת תלמיד לבית הספר
{
	Pupil *pupil=new Pupil;//יצירת אובייקט מצביע מסוג תלמיד

	char layer_n;
	int class_n;

	do{cout<<"Enter layer: ";
	cin>>layer_n;
	}while((layer_n <'a'||layer_n > 'f') && (cout<<"\nWrong input , try again!\n\n"));//check layer input is from a-f

	do{cout<<"\nEnter class: ";
	cin>>class_n;
	}while(( class_n<1 || class_n>3) && (cout<<"\nWrong input , try again!\n\n"));//check class number input is from 1-3

	pupil=pupil->Add_person(persons,layer_n,class_n,amount_presons);// הפעלת הפונקציה שיוצרת אובייקט תלמיד חדש

	if (check_if_person_exist(pupil->get_id()))//בדיקה אם התלמיד כבר רשום בבית הספר
	{
		cout<<"The pupil already exist in the school!\n";
		delete pupil;
		return;
	}
	add_person(pupil);//הפעלת הפונקציה שמכניסה את התלמיד למערך הפרסונים בבית הספר
	layers[layer_n-97]->get_classes()[class_n-1]->add_pupil(pupil);//עדכון התלמיד בשכבה המתאימה
}

void School::Add_teacher()
{
	Teacher *teacher=new Teacher;//יצירת אובייקט מצביע מסוג מורה
	int amount_courses;

	teacher->set_person();//הפעלת הפונקציה לקליטת פרטי המורה

	if(check_if_person_exist(teacher->get_id()))//לולאה שבודקת אם המורה כבר קיימת בבית הספר
	{
		delete teacher;
		cout<<"The teacher already exist in the school!\n";
	}
	teacher->set_professions();//הפעלת המתודה לקליטת המקצועת שהמורה מלמד/ת
	add_person(teacher);//הפעלת הפונקציה שמכניסה את המורה למערך הפרסונים בבית הספר
}

void School::Add_tutor()
{	
	Tutor *tutor=new Tutor;//יצירת אובייקט מצביע מסוג מחנך

	char layer_n;
	int amount_courses,class_n;

	do{cout<<"Enter layer: ";
	cin>>layer_n;
	}while((layer_n <'a'||layer_n > 'f') && (cout<<"\nWrong input , try again!\n\n"));//check layer input is from a-f

	do{cout<<"\nEnter class: ";
	cin>>class_n;
	}while(( class_n<1 || class_n>3) && (cout<<"\nWrong input , try again!\n\n"));//check class number input is from 1-3

	if(layers[layer_n-97]->get_classes()[class_n-1]->get_tutor()!=NULL)//בדיקה אם לכיתה יש כבר מחנך
	{
		cout<<"The class already have tutor!\n";
		delete tutor;//שחרור הזיכרון של המחנך שלא מומש
		return;
	}

	tutor->set_person();//הפעלת הפונקציה לקליטת ועדכון פרטי המחנך

	if(check_if_person_exist(tutor->get_id()))//הפעלת הפונקציה שבודקת אם המחנך כבר שייך לבית הספר
	{
		delete tutor;//שחרור הזיכרון של המחנך שלא מומש
		cout<<"The tutor already exist in the school!\n";
		return;
	}

	tutor->set_professions();//קליטת ועדכון מקצועות המחנך
	layers[layer_n-97]->get_classes()[class_n-1]->set_tutor(tutor);//עדכון המחנך בכיתה המתאימה
	tutor->set_cls(layers[layer_n-97]->get_classes()[class_n-1]);//עדכון הכיתה המתאימה במחנך 
	add_person(tutor);//הפעלת הפונקציה שמכניסה את המחנך למערך הפרסונים בבית הספר
}

void School::Add_manager()
{
	if(exist_manager)//בדיקה אם קיים מחנך בבית הספר
	{
		cout<<"The school already have manager!\n";
		return;
	}
	exist_manager=true;//עדכון המשתנה הבלויאני לאמת

	Manager *manager=new Manager;//יצירת אובייקט מצביע מסוג מנהל

	manager->set_person();//קליטת פרטי המנהל ועדכונם
	if(check_if_person_exist(manager->get_id()))//בדיקה אם האדם כבר קיים בבית הספר
	{
		delete manager;
		cout<<"The person already exist in the school!\n";
		return;
	}
	add_person(manager);//הפעלת הפונקציה שמכניסה את המנהל למערך הפרסונים בבית הספר
}

void School::Add_secretary()
{

	Secretary *secretary=new Secretary;//יצירת אובייקט מצביע מסוג מזכירה
	secretary->set_person();//קליטת ועידכון פרטי המזכירה

	if(check_if_person_exist(secretary->get_id()))//בדיקה אם האדם כבר קיים בבית הספר
	{
		delete secretary;
		cout<<"\nThe secretary already exist in the school!\n";
		return;
	}
	add_person(secretary);//הפעלת הפונקציה שמכניסה את המזכירה למערך הפרסונים בבית הספר
}

void School::Print_workers_and_pupil_details()//מתודה שמדפיסה את פרטי כל האנשים ששיכים לבית הספר
{
	for (int i = 0; i < amount_presons; i++) ///הדפסה לפי מערך האנשים
	{
		cout<<"******* Person number "<<i+1<<": *******\n";
		persons[i]->print_person();//שימוש בפולימורפיזם להדפסת פרטי כל פרטי האנשים
		cout<<endl;
	}
}

void School::Print_outstanding_people()//מתודה שמדפיסה את כל האנשים בבית הספר שמצטיינים
{
	int flag=0;
	for (int i = 0; i < amount_presons; i++) ///הדפסה לפי מערך האנשים
	{
		if(persons[i]->check_if_outstanding())//שימוש בפולימורפיזם לבדיקת הצטיינות האנשים
		{
			flag=1;
			cout<<"*******\n";
			persons[i]->print_person();//שימוש בפולימורפיזם להדפסת פרטי כל האנשים המצטיינים
			cout<<"*******\n";
		}
	}
	if(!flag)
		cout<<"There is no outstanding persons in the school!\n";
}

void School::Print_tutor_class()//מתודה שקולטת מהמשתמש תעודת זהות ואם היא ת.ז של מחנך היא מדפיסה את פרטי הכיתה שלו כולל שם השיכבה ומספר הכיתה
{
	int id;
	Tutor *help;//יצירת מצביע עזר לשימוש בדינאמיק-קאסט
	cout<<"Enter tutor id: ";
	cin>>id;//קליטת ת.ז מהמשתמש
	cout<<endl;
	for (int i = 0; i < amount_presons; i++)//לולאה שעוברת על כל האנשים ומשווה את תעודת הזהות שלהם
	{
		if(persons[i]->get_id()==id)//אם יש התאמה בתעודת הזהות בודקים באמצעות דינאמיק-קאסט שזה מחנך
		{
			help=dynamic_cast<Tutor*>(persons[i]);//ביצוע דינאמיק-קאסט למצביע במערך הפרוסנים
			if(help!=NULL)//בדיקה אם זהו מחנך
			{
				cout<<"The layer of the tutor is: "<<help->get_cls()->get_layer_name()<<endl;//הדפסת שם השכבה שבה הוא מחנך
				cout<<"The number of his class: "<<help->get_cls()->get_num_class()<<endl;//הדפסת מספר הכיתה 
				help->print_pupils();//הפעלת המתודה של המחנך שמדפיסה את תלמידיו
				return;
			}
		}
	}
	cout<<"This id is not a tutor id!\n";
}

void School::Print_worker_details_with_biggest_salary()//מתודה שמוצאת את העובד עם השכר הכי גבוהה ומדפיסה את פרטיו
{
	Worker *help;//יצירת מצביע עזר לשימוש בדינאמיק-קאסט
	int max_salary=0,location;//יצירת משתנים לשימור המשכורת הכי גבוהה ולשימור מיקומו של האדם במערך ה-פרסונים

	for (int i = 0; i < amount_presons; i++)//לולאה שעוברת על כל האנשים במערך ה-פרסונים
	{
		help=dynamic_cast<Worker*>(persons[i]);//ביצוע דינאמיק-קאסט למצביע במערך הפרוסנים
		if(help!=NULL)//בדיקה אם זהו אדם ששיך למחלקת העובדים
			if(help->return_salary()>max_salary)//בדיקת המשכורת הכי גבוהה
			{
				max_salary=help->return_salary();//שמירת המשכורת הגבוהה
				location=i;//שמירת המיקום של האדם במערך עם המשכורת הגבוהה
			}
	}
	if(max_salary)
	{
		cout<<"The details of the person with the max salary is:\n\n";
		persons[location]->print_person();//הדפסת פרטי העובד בעל המשכורת הכי גבוהה
	}
	else
		cout<<"There are no persons with salary at this school!\n";

}

void School::manu()
{

	int choice;
	bool exit=true;
	do{		system("cls");
	cout<<"1 - Add pupil\n";
	cout<<"2 - Add teacher\n";
	cout<<"3 - Add tutor\n";
	cout<<"4 - Add manager\n";
	cout<<"5 - Add secretary\n";
	cout<<"6 - Print workers and pupil details\n";
	cout<<"7 - Print outstanding people\n";
	cout<<"8 - Print tutor's class\n";
	cout<<"9 - Print worker details with biggest salary\n";
	cout<<"10 - Exit\n";
	cout<<"please enter your choice: ";
	cin>>choice;
	cout<<endl;
	switch (choice)//לולאה שמנווטת את בחירת המשתמש ומפעילה את הפונקציה המתבקשת
	{
	case 1:
		Add_pupil();//מתודה שמוסיפה תלמיד 
		break;

	case 2:
		Add_teacher();//מתודה שמוסיפה מורה 
		break;

	case 3:
		Add_tutor();//מתודה שמוסיפה מחנך 
		break;

	case 4:
		Add_manager();//מתודה שמוסיפה מנהל 
		break;

	case 5:
		Add_secretary();//מתודה שמוסיפה מזכירה 
		break;

	case 6:
		Print_workers_and_pupil_details();//מתודה שמדפיסה את פרטי האנשים השייכים לבית הספר 
		break;

	case 7:
		Print_outstanding_people();//מתודה שמדפיסה את פרטי האנשים המצטיינים שבבית הספר
		break;

	case 8:
		Print_tutor_class();//מתודה שמקבלת ת.ז ואם היא שייכת למחנך מדפיסה את פרטי כיתתו
		break;

	case 9:
		Print_worker_details_with_biggest_salary();//מתודה שמדפיסה את פרטיו של העובד עם המשכורת הכי גבוהה
		break;

	case 10:
		exit=false;//יציאה מהמערכת
		break;

	}

	system("pause");//הקפאת המסך לפני ניקוי
	}while(exit);
	cout<<"\nGood-Bye..\n\n";
}