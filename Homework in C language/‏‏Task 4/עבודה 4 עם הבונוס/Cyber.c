#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
enum colors { blue = 0, green, yellow, orange, red, purple, white, black, brown, grey, pink, MAX };
int is_empty(int *top);
int find_code(char *color);
void print_color(int num_of_color);
int is_full(int *top, int size);
void print(int *top, int *cards);
int insert(int num_of_color, int *top, int *cards, int size);
int remove(int *top, int *cards, int *ptr_card);
int main()
{
	char saction, color[7];
	int x, size, top = -1, *cards, ptr_card = 0;
	printf("enter max of cards that you want\n");
	scanf("%d", &size);//����� ����� �� ����� ������
	cards = (int*)malloc(size*sizeof(int));//����� ������ ������ ������
	do
	{
		_flushall();
		system("cls");//����� ���� ������ ����
		printf("if you want to insert a card press: i\n");
		printf("if you want to remove a card press: d\n");
		printf("if you want to print the cards press: p\n");
		printf("if you want to check if the packet are full press: f\n");
		printf("if you want to check if the packet are empty press: e\n");
		printf("if you want to exit from the program press: q\n");
		printf("\nthis is the colors you can use in that program:\n");
		printf("**************************************************************************\n");
		printf("blue, green, yellow, orange, red, purple, white, black, brown, grey, pink\n");
		printf("**************************************************************************\n");
		scanf("%c", &saction);//����� ������

		switch (saction)
		{
		case 'i'://������� ����� ��� ������
			printf("enter the color\n");
			_flushall();
			gets(color);
			x = find_code(color);//����� ���� ������� �� ���� ������
			if (x == -2)// �� ������ ��������� -2 �� �� ���� ����� ������� ����� �� ����
			{
				printf("this color is is not posible\n");
				_getch();//����� ����
				break;
			}
			x = insert(x, &top, cards, size);// �� ���� ���� ��� ������ ������ ������
			if (x == 0)//�� �������� ������ 0 �� �� ���� ��� ���� ������ ��� �� ������ ����
				printf("The packet is full\n");
			else
				printf("The card inserded succesfully\n");
			_getch();//����� ����
			break;
		case 'd'://������� ���� ��� �������
			x = remove(&top, cards, &ptr_card);//����� �������� remove
			if (x == 1)//�� �������� ������ 1 �� ���� ���� ������� ����� ������
			{
				printf("the color that removed is: ");
				print_color(ptr_card);
			}
			_getch();//����� ����
			break;
		case 'p'://������� ����� ����� ������
			print(&top, cards);//����� �������� ������� �� ����� ������
			_getch();//����� ����
			break;
		case 'e'://������� ������ �� ����� ������ ����
			x = is_empty(&top);
			if (x == 0)//�� ����� 0 ��������� �� ������� �� ���� ������� ����� �����
			{
				printf("The packet is not empty!\n");
				_getch();//����� ����

			}
			break;
		case 'f'://������� ������ �� ����� ������ ����
			x = is_full(&top, size);
			if (x == 0)//�� ����� 0 ��������� �� ������� �� ���� ������� ����� �����
			{
				printf("The packet is not full!\n");
				_getch();//����� ����
			}
			break;
		case 'q'://������� ����� �������
			printf("Goodbye...\n");
			_getch();//����� ����
			break;
		default://����� ������ �� ���� ���� ����� �� ����
			printf("Wrong input, please try again!\n");
			_getch();//����� ����
			break;
		}
	} while (saction != 'q');

	free(cards);//����� �������
}
int find_code(char *color)//������� ������ ��� �� ��� 
{//�������� ������ ������� �� ������ ������� ������� �� ���� �� �� ���
	if (strcmp(color, "blue") == 0)
		return blue;
	if (strcmp(color, "green") == 0)
		return green;
	if (strcmp(color, "yellow") == 0)
		return yellow;
	if (strcmp(color, "orange") == 0)
		return orange;
	if (strcmp(color, "red") == 0)
		return red;
	if (strcmp(color, "purple") == 0)
		return purple;
	if (strcmp(color, "white") == 0)
		return white;
	if (strcmp(color, "black") == 0)
		return black;
	if (strcmp(color, "brown") == 0)
		return brown;
	if (strcmp(color, "grey") == 0)
		return grey;
	if (strcmp(color, "pink") == 0)
		return pink;
	return -2;//�� ���� �� ���� ���� ����� -2
}
void print_color(int num_of_color)//�������� ����� ��� �� ������� ������ ���� ��� �� ��� ������� ����
{
	switch (num_of_color)
	{
	case blue:
		printf("blue\n");
		break;
	case green:
		printf("green\n");
		break;
	case yellow:
		printf("yellow\n");
		break;
	case orange:
		printf("orange\n");
		break;
	case red:
		printf("red\n");
		break;
	case purple:
		printf("purple\n");
		break;
	case white:
		printf("white\n");
		break;
	case black:
		printf("black\n");
		break;
	case brown:
		printf("brown\n");
		break;
	case grey:
		printf("grey\n");
		break;
	case pink:
		printf("pink\n");
		break;
	}
}
int insert(int num_of_color, int *top, int *cards, int size)//�������� ������ ��� ������ ������
{

	if (*top >= (size - 1))//����� �� ������ ����
	{
		*top = (size - 1);//�� ������ ���� �� ���� ����� ����� �� ������ "���" ������� ���� ������ �� ���� ������ �����
		return 0;//�� ������ ���� ����� 0 ������
	}
	else
	{
		*top = *top + 1;//�� ������ �� ���� ������� �� ������ ������ �� ���� ��� ������ ���� ���� ������ �����
		cards[*top] = num_of_color;// ����� ���� ������ ������
		return 1;//�������� ������ 1
	}

}
int remove(int *top, int *cards, int *ptr_card)//������� ������ ��� �������
{
	if (is_empty(top) != 1)
	{
		*ptr_card = cards[*top];//�� ������ �� ���� �� ������ ������� ������� ������ ���� �� ���� �� ���� ������ ������ ������
		*top = *top - 1;//����� ������ "���" ���� ���
		return 1;//�������� ������ 1
	}

	else return 0;//�� ������ ���� ����� 0
}
int is_full(int *top, int size)//������� ������ �� ������ ����
{
	if (*top >= (size - 1))//����� �� ������ "���" ����� �� ����� ������ ������
	{
		*top = (size - 1);
		printf("Is FULL!!\n");//�� �� ������ �����
		_getch();//����� ���� ���� ������� ���� �� ������ ���� ������ ���� �����
		return 1;//�������� ������ 1
	}
	return 0;//�� ������ �� ���� ����� 0
}
int is_empty(int *top)//������� ������ �� ������ ����
{
	if (*top == -1)//�� ������ "���" ����� �� -1 �� �� ���� �������� ����
	{
		printf("Is Empty!!\n");//�� �� ������ �����
		_getch();//����� ���� ���� ������� ���� �� ������ ���� ������ ���� �����
		return 1;//�������� ������ 1
	}
	else return 0;//�� ������ �� ���� ����� 0
}
void print(int *top, int *cards)//������� ������� �� �� ������ ������� ������
{
	int i, x;
	if (*top == -1)//����� �� ������ ���� , �� �� ������ ����� �����
		printf("is empty ,insert cards!\n");
	else
	{
		printf("The color\\s in the packet are:\n");
		printf("------\n");
		for (i = *top; i >= blue; i--)//�� ������ �� ���� ������� ������ �� �� ������
		{
			x = cards[i];
			print_color(x);
		}
		printf("------\n");
	}
}