#include "Class.h"

#ifndef LAYER_H
#define LAYER_H

class Layer
{
public:
	Layer(char layer_n);
	~Layer();
	Layer(const Layer&obj);
	Class* return_class(int location);
	Class** get_classes(){return classes;}
	char get_layer_name(){return layer_name;}
	void set_layer_name(char name){layer_name=name;}
	int get_amount_classes(){return amount_classes;}
private:
	char layer_name;
	Class** classes;
	int amount_classes;
};

#endif