#include "Pupil.h"

Pupil* Pupil::Add_person(Person** p,char _layer,int class_num,int amount_presons)//פונצקיה שמייצרת אובייקט מצביע מסוג תלמיד
{
	Person::set_person();//קליטת פרטי התלמיד
	set_layer(_layer);
	set_num_of_class(class_num);
	for (int i = 0; i < amount_presons; i++)//לולאה שבודקת אם התלמיד רשום לבית הספר
		if(p[i]->get_id()==get_id())
			return this;

	amount_grades=((layer-97)+5);//עדכון כמות הציונים שיש לתלמיד לפי נוסחה :(שם השיכבה - 97 ==>אות קטנה מינוס 97 לפי טבלת האסקי ממירה למספר) + 5 מקצועות

	grade=new int[amount_grades];//הקצאת זיכרון למערך הציונים של התלמיד
	cout<<"Enter "<<amount_grades<<" grades for this pupil\n";
	for (int i = 0; i < amount_grades; i++)//לולאה שקולטת את הציונים של התלמיד
	{
		cout<<"grade number "<<i+1<<": ";
		cin>>grade[i];
	}

	return this;
}

Pupil::~Pupil()//בנאי הורס למחיקת מערך הציונים
{
	if(grade!=NULL)
		delete[] grade;
}

Pupil::Pupil( const Pupil&obj):Person(obj),amount_grades(obj.amount_grades),layer(obj.layer),num_of_class(obj.num_of_class)//בנאי העתקה
{
	grade=new int[obj.amount_grades];//הקצאת זיכרון חדש למערך הציונים
	for (int i = 0; i < obj.amount_grades; i++)//העתקת הציונים מהאובייקט
		grade[i]=obj.grade[i];
}

bool Pupil::check_if_outstanding()// מתודה שבודקת אם התלמיד מצטיין
{
	float avg=0;
	for (int i = 0; i < amount_grades; i++)//לולאה שמחשבת את ציוניו של התלמיד כל עוד הם לפחות 65
		if(grade[i]<=65)//במידה ויש לתמיד ציון שהוא מתחת ל65 התלמיד אינו מצטיין
			return false;
		else avg+=grade[i];

		return ((avg/amount_grades)>85);//אם ממוצע הציונים של התלמיד גדולים מ85 התלמיד מצטיין
}

void Pupil::print_person()//מתודה להדפסת פרטי התלמיד
{
	float avg=0;
	cout<<"~ Pupil datails:\n\n";
	Person::print_person();
	cout << "Layer: '" << layer << "' "<<endl;
	cout << "Class number: " << num_of_class << endl;
	cout<<"His grades: ";
	for (int i = 0; i < amount_grades; i++)//לולאה שמדפיסה את ציוניו של התלמיד
	{
		cout<<grade[i]<<", ";
		avg+=grade[i];
	}
	avg/=amount_grades;//חישוב ממוצע ציוניו של התלמיד
	cout<<"\nThe average of his grades: "<<avg<<endl;//הדפסת ממוצע הציונים של התלמיד
}

