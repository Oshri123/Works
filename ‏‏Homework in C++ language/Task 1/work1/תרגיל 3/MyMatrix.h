#include <iostream>
using namespace std;
#define GODEL 2
#define LAB1 0
#define LAB2 1


class MyMatrix 
{
private:

	float a11,a12,a21,a22;
	float matrix[2][2];

public:
	MyMatrix(float a11,float a12,float a21,float a22);
	MyMatrix();
	~MyMatrix();
	MyMatrix(const MyMatrix&other);
	void set(const MyMatrix &m);
	bool set(int i, int j, float num);
	bool get(int i, int j, float &num) const ;
	bool is_equal(const MyMatrix &m) const;
	void print() const;
	float det() const;
	bool invertible() const;
	bool is_inverse(const MyMatrix &m);
};

