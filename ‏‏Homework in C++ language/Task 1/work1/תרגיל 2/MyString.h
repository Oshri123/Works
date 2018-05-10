#ifndef TicTacToe_H
#define TicTacToe_H
#include <iostream>
using namespace std;
#define MAX 81
class CMyString{

private:
	char *str;
	int length;

public:
	CMyString();
	~CMyString();
	CMyString(char *str2);
	CMyString(const CMyString&other);
	void PrintString();
	void ChangeString(char *str3);
	int LengthString();
	int SumOfBigAndLowLatter(char latter);
	int Words();
	char* TheNword(int n);
	void ByReference(int *digit,int *biglatter,int *lowlatter);
	void Concatenation(CMyString ms3);
	void ChangeBigLatter();
	void ChangeSmallLatter();
	char clean_screen();
};
#endif