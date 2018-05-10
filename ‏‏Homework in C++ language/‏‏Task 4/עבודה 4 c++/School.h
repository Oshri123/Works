#include "Person.h"
#include "Layer.h"
#include "Manager.h"
#include "Secretary.h"
#include <typeinfo>
#ifndef SCHOOL_H
#define SCHOOL_H

class School
{
public:
	School();
	~School();
	School(const School&obj);
	void manu();
	void Add_pupil();
	void Add_tutor();
	void Add_teacher();
	void Add_manager();
	void Add_secretary();
	void Print_workers_and_pupil_details();
	void Print_outstanding_people();
	void Print_tutor_class();
	void Print_worker_details_with_biggest_salary();
private:

	bool check_if_person_exist(int _id);//פונקציית עזר לבדיקה אם האדם קיים בבית הספר
	void help_copy(Person *p,int location);//פונקציית עזר לבנאי העתקה
	void add_person( Person *p);//מתודה פרטית להוספת פרסון למערך הפרסונים
	Layer** layers;
	int amount_layers;
	Person** persons;
	int amount_presons;
	bool exist_manager;
};

#endif