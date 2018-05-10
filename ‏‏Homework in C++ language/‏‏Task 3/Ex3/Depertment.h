#include "Course.h"
#ifndef DEPERTMAENT_H
#define DEPERTMAENT_H

class Depertment
{
public:
	string getDep_N(){ return dep_N;}//פונקציית גט כדיי לגשת למשתנה הפרייבט
	void setDep_N(string new_name){dep_N=new_name;}//פונקציית סט לעדכון השם של המחלקה
	int getCode(){ return code;}//פונקציית גט כדיי לגשת למשתנה הפרייבט
	void setCode(int new_code) {code=new_code;}//פונקציית סט לעדכון הקוד של המחלקה
	Course** getCrs(){ return crs; }//פונקציית גט כדיי לגשת למשתנה הפרייבט
	int getAmou_Crs(){ return amount_crs;}//פונקציית גט כדיי לגשת למשתנה הפרייבט
	student** getStd(){return std; }//פונקציית גט כדיי לגשת למשתנה הפרייבט
	int getAmou_Std(){ return amount_std;}//פונקציית גט כדיי לגשת למשתנה הפרייבט
	void setAmou_Std(){ amount_fstd++;}//פונקציית סט לעדכון כמות הסטודנטים הנכשלים של המחלקה
	student** getFstd(){return failed_std;}//פונקציית גט כדיי לגשת למשתנה הפרייבט
	void setAmou_Failed_Std(student *s,int location);
	int getAmou_Fstd(){ return amount_fstd;}//פונקציית גט כדיי לגשת למשתנה הפרייבט
	void setfstd(int size){amount_fstd=size;}
	Depertment operator = (const Depertment&d);
	bool operator > (const Depertment&d);
	friend ostream& operator << ( ostream&out , Depertment&d);
	friend istream& operator >> ( istream&in , Depertment&d);
	Depertment& Depertment::operator+=( Course *c);
	Depertment& Depertment::operator+=( student *s);
	void reset_fstd();
	Depertment(const Depertment&d);

	Depertment():dep_N(""),code(0),crs(NULL),amount_crs(0),std(NULL),amount_std(0),failed_std(NULL),amount_fstd(0){};//בנאי דיפולטיבי אינליין

	~Depertment();


private:
	string dep_N;
	int code;
	Course **crs;
	int amount_crs;
	student **std;
	int amount_std;
	student **failed_std;
	int amount_fstd;


};
#endif