#include "Layer.h"

Layer::Layer(char layer_n)//���� ����� �� �� ����� ����� ������ 3 �����
{
	layer_name=layer_n;
	amount_classes=3;
	classes=new Class*[amount_classes];//����� ������ ����� ������ ����� �� ���� ������

	for (int i = 0; i < amount_classes; i++)//����� ������ ����� ��� ����� �����
		classes[i]=new Class(layer_name,i);
}

Layer::~Layer()//���� ���� ������ �������
{
	for (int i = 0; i < amount_classes; i++)//����� ������� �� �� ������ �� ������
		delete classes[i];

	if(classes!=NULL)//����� ������ �� ��������
		delete[] classes;
}

Layer::Layer(const Layer&obj):layer_name(obj.layer_name),amount_classes(obj.amount_classes)//���� �����
{
	classes=new Class*[obj.amount_classes];//����� ������ ��� �����
	for (int i = 0; i < obj.amount_classes; i++)//����� ������ + ����� ����� ���������
		classes[i]=new Class(*obj.classes[i]);
}

Class* Layer::return_class(int location)//����� ������ ����� �� ���� ����� ������� �� ������ ����
{
	if( location < 0 || location >= 3 )//����� ������� ������ ����
		return classes[0];
	else return classes[location];
}
