#include "Course.h"
#ifndef DEPERTMAENT_H
#define DEPERTMAENT_H

class Depertment
{
public:
	string getDep_N(){ return dep_N;}//�������� �� ���� ���� ������ �������
	void setDep_N(string new_name){dep_N=new_name;}//�������� �� ������ ��� �� ������
	int getCode(){ return code;}//�������� �� ���� ���� ������ �������
	void setCode(int new_code) {code=new_code;}//�������� �� ������ ���� �� ������
	Course** getCrs(){ return crs; }//�������� �� ���� ���� ������ �������
	int getAmou_Crs(){ return amount_crs;}//�������� �� ���� ���� ������ �������
	student** getStd(){return std; }//�������� �� ���� ���� ������ �������
	int getAmou_Std(){ return amount_std;}//�������� �� ���� ���� ������ �������
	void setAmou_Std(){ amount_fstd++;}//�������� �� ������ ���� ��������� ������� �� ������
	student** getFstd(){return failed_std;}//�������� �� ���� ���� ������ �������
	void setAmou_Failed_Std(student *s,int location);
	int getAmou_Fstd(){ return amount_fstd;}//�������� �� ���� ���� ������ �������
	void setfstd(int size){amount_fstd=size;}
	Depertment operator = (const Depertment&d);
	bool operator > (const Depertment&d);
	friend ostream& operator << ( ostream&out , Depertment&d);
	friend istream& operator >> ( istream&in , Depertment&d);
	Depertment& Depertment::operator+=( Course *c);
	Depertment& Depertment::operator+=( student *s);
	void reset_fstd();
	Depertment(const Depertment&d);

	Depertment():dep_N(""),code(0),crs(NULL),amount_crs(0),std(NULL),amount_std(0),failed_std(NULL),amount_fstd(0){};//���� ��������� �������

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