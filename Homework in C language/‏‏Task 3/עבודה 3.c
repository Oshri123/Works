#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<conio.h>
#define SIZE 81//���� ����� ���� �������
#define LENGTH_ARR 10//���� ����� ���� ����� �� ���� �
#define GODEL 5// ���� ����� ���� ����� ��� ����� �� ���� �
#define M 3// ���� ����� ���� ����� ���� ����� �� ���� �
#define GODEL2 10 //���� ����� ����� ���� ������� ������ ������
void change_arr(int arr[]);//����� ������� ���� �
int machpela_arr(int arr[10]);//����� ������� ���� �
void change_string(char shorttext[], char longtext[]);//����� ������� ���� �
int password(char password_srt[]);//����� ������� ���� �
int reshonee(int length);//������� ������ �� ���� ��� ������
int maarah_reshonee(int[GODEL][GODEL]);//����� ������� ���� �
int maarah_pina(int[M][M][M]);//����� ������� ���� �


int main()
{

	char saction, longtext[SIZE], shorttext[SIZE], password_srt[SIZE];
	int length, k, i, j, x, arr[LENGTH_ARR], arr1[GODEL][GODEL], arr_pina[M][M][M];
	do
	{
		_flushall();
		system("cls");//����� ���� ������ ����
		printf("which saction do you want? (a,b,c,d,e,f) \nif you want to exit from the program press y\n");
		scanf("%c", &saction);//����� ������

		switch (saction)
		{
		case 'a'://�� ������ ��� ������ �� ������� �������
			printf("enter 10 integer numbers please\n");
			for (i = 0; i < GODEL2; i++)//����� ��� ���� ����� 
				scanf("%d", &arr[i]);
			change_arr(arr);//����� �������� �� �����
			for (i = 0; i < GODEL2; i++)//������ ������� �� ����� ���� ���� ����� �������� ����
				printf("the new arr[%d] is : %d \n", i, arr[i]);
			printf("press any key to return to the menu\n");
			_getch();//����� �� ��� ������� ���� ����� �� ����
			break;
		case 'b'://�� ������ ��� ������ �� ������� �����
			printf("enter 10 negative or positive intager numbers with 2 digits please\n");
			for (i = 0; i < GODEL2; i++)//����� ��� ���� �����
				scanf("%d", &arr[i]);
			printf("The num in arr that the difference from him to his previous is the biggest is: %d \n", machpela_arr(arr));
			printf("press any key to return to the menu\n");
			_getch();//����� �� ��� ������� ���� ����� �� ����
			break;
		case 'c'://�� ������ ��� ������ �� ������� �������
			printf("enter a string please\n");
			scanf("%s", longtext);//��� ���� �������
			change_string(shorttext, longtext);//����� �������� �� ��������
			printf("the new string is : %s \n", shorttext);//����� ������� ���� ����� ��������
			printf("press any key to return to the menu\n");
			_getch();//����� �� ��� ������� ���� ����� �� ����
			break;
		case 'd'://�� ������ ��� ������ �� ������� �������
			printf("enter a password which contain big latter , small latter , number and the length is 6 up to 11 please\n");
			_flushall();
			gets(password_srt);//��� ������ �� ������
			x = password(password_srt);//����� �������� �� ������
			if (x == 1)//����� �� ������ ����� �� ��
				printf("Your password is Ok\n");
			else
				printf("Your password is not good\n");
			printf("press any key to return to the menu\n");
			_getch();//����� �� ��� ������� ���� ����� �� ����
			break;
		case 'e'://�� ������ ��� ������ �� ������� �������
			for (i = 0; i < GODEL; i++)// ����� ��� ����� ��� �����
			{
				for (j = 0; j < GODEL; j++)
				{
					printf("enter a number\n");
					scanf("%d", &arr1[i][j]);
				}
			}
			x = maarah_reshonee(arr1);// ����� �������� � ������ �� ���� ����� ��� ���� ������ �������� ��������� ������ �� ��� ������ ��������
			if (x == 1)
			{
				printf("----------------------------------\n");
				printf("All the frame contain prime numbers\n");
				printf("----------------------------------\n");
			}
			else
			{
				printf("----------------------------------\n");
				printf("Not all the frame contain prime numbers\n");
				printf("----------------------------------\n");
			}
			printf("press any key to return to the menu\n");
			_getch();//����� �� ��� ������� ���� ����� �� ����
			break;

		case 'f'://�� ������ ��� ������ �� ������� ������
			for (i = 0; i < M; i++)// ����� ��� ����� ���� �����
			{
				for (j = 0; j < M; j++)
				{
					for (k = 0; k < M; k++)
					{
						printf("enter a number\n");
						scanf("%d", &arr_pina[i][j][k]);
					}
				}
			}
			x = maarah_pina(arr_pina);//����� �������� �
			if (x == 1)
			{
				printf("----------------------------------\n");
				printf("the arry is pina\n");
				printf("----------------------------------\n");
			}
			else
			{
				printf("----------------------------------\n");
				printf("the arry is not pina\n");
				printf("----------------------------------\n");
			}
			
			printf("press any key to return to the menu\n");
			_getch();//����� �� ��� ������� ���� ����� �� ����
			break;

		}
	} while (saction != 'y');

}
void change_arr(int arr[])//�������� ����� ����
{
	int i, limb1, limb2;
	for (i = 0; i < 10; i = i + 2)//����� ���� ��� ���� �����
	{
		if (arr[i] % arr[i + 1] == 0)//����� �� ������� ������� ����� ������� ����� ��� ������ ������� ��� ��� �����
		{
			limb1 = arr[i];//����� ����� �� ����� ������
			limb2 = arr[i + 1];
			arr[i] = limb2;
			arr[i + 1] = limb1;
		}
	}
}
int machpela_arr(int arr[])	//�������� ����� ���� ��� 10 ���� ������ 10 ������ ���� ��� �����.
{
	int i, max_efresh, z = 0, new_arr[5];
	for (i = 0; i < 10; i = i + 2)
	{
		new_arr[z] = (arr[i + 1] * 100) + arr[i];//�������� ����� �� ��� ����� ������ ����� ������ ���� ����� ��� ��� 4 ����� ����� ������ ����� ��� ��� 5 ����
		z++;//���� ���� ����� �� ����� ���� ����� ���� ����� ��� 4 ������.
	}
	max_efresh = abs(new_arr[1] - new_arr[0]);//����� ����� ������ ������ max_efresh
	z = 1;
	for (i = 1; i < 4; i++)//����� ����� ���� ���� ��� ��� ������ ����� ���� ���� (���� �����) ������� ���� ������ max_efresh.
	{
		if (max_efresh < abs(new_arr[i + 1] - new_arr[i]))
		{
			z = i + 1;//���� ���� ����� ����� ��� �� �� ����� ����� ���� ����� �� �� ����� ����� ����� z.
			max_efresh = abs(new_arr[i + 1] - new_arr[i]);
		}
	}
	for (i = 0; i < 5; i++)
		printf("The new arr [%d] is : %d \n", i, new_arr[i]);
	return new_arr[z];// z �������� ������ �� . 
}
void change_string(char shorttext[], char longtext[])//�������� ����� ��� ������� 
{
	char sign = longtext[0];//���� ������ ���� ���� �������� longtext. 
	int j = 0, i, s = 0, n = 0;
	for (i = 0; i < 80; i++)
	{
		if (sign == '\0')//����� ��� ����� �������
			break;
		shorttext[n] = sign;//���� ������� ���� ���� ������� �����
		while (sign == longtext[j])//����� ��� ����� ����� ���� ������� ����
		{
			s++;//����� �� ���� ������ ���� ����� ������ ����
			j++;//����� ����� ��� ������� long text.

		}
		sign = longtext[j];//������ ���� �� ����� ����� ���
		i = j;
		shorttext[n + 1] = (s + '0');//����� ���� ������ ������ ���� ���� ���� ������� shorttext.
		n = n + 2;
		s = 0;
	}

	shorttext[n] = '\0';//����� ������� ���� ����� ������
}
int password(char password_srt[])//�������� ����� ������ ������ ����� �� ����� ������ �� ��� ����� �� �� ������� 1 �� ��� ����� ��� �� 0
{
	int s = 0, z = 0, n = 0, i, length;
	length = strlen(password_srt);//������� ������ �� ����� �� ������ 
	if ((length > 5) && (length < 12))//����� �� ������ ���� �6 ������ ���� �11
	{
		for (i = 0; i < length; i++)
		{
			if (password_srt[i] == password_srt[i + 1])//����� �� ������ ����� �� ���� ��� ������ ����
				return 0;
			if ((password_srt[i] >= 48) && (password_srt[i] <= 57))//����� �� ������ ����� ������ ������
				s = 1;
			if ((password_srt[i] >= 65) && (password_srt[i] <= 90))//����� �� ������ ����� ������ ������
				z = 1;
			if ((password_srt[i] >= 97) && (password_srt[i] <= 122))//����� �� ������ ����� ������ �����
				n = 1;
		}
	}
	else return 0;
	if ((s + z + n) == 3)//����� �� ������ ����� �� ��� ����� ,�� ��� ����, ��� ����
		return 1;//�� �� ������ 1
	else
		return 0;//�� �� ������ 0
}
int reshonee(int number)//�������� ����� ���� ������ �� ��� ������ �� ��
{
	int i, k = 1;
	for (i = 2; i <= number; i++)//����� ����� �� ����� �� ������ ��� ������ ����� ��1
	{
		if ((number%i) == 0)//�� ���� ��� ����� ���� ���� ������� �� k 
			k++;
	}
	if (k > 2)//�� ����� ������ ��� ��1 ������ ����� (����� �� ������) �������� ������ 1 �� ��� ��� ������ (����� ������) �������� ������ 0 
		return 1;
	else return 0;
}
int maarah_reshonee(int arr1[GODEL][GODEL])//�������� ����� ���� �� ����� 
{
	int i, j, counter = 0;
	for (j = 0; j < GODEL; j++)//����� �� ����� ������� ����� ��� ����� ����� ������� ��������
	{
		if (reshonee(arr1[0][j]) != 0)//  �� ����� ������ ��� ���� ���� �����
			return 0;
	}
	for (j = 0; j < GODEL; j++)//����� �� ����� ������� ����� ��� ����� ����� ������� ��������
	{
		if (reshonee(arr1[GODEL - 1][j]) != 0)
			return 0;
	}
	for (i = 1; i < (GODEL - 1); i++)//����� �� ����� ������ ������ ��� ���� ����� ������ ������ �� ����� ����� ����� ����� ������� ��������
	{
		if ((reshonee(arr1[i][0]) != 0) && (reshonee(arr1[i][GODEL - 1]) != 0))
			return 0;
	}
	return 1;//�� �� ������� ������ ����� 1
}
int maarah_pina(int arr_pina[][M][M]) //�������� ����� ���� ��� ����� ������ �� ��� ���� ����
{
	int i, j, k, s = 0, z = 0;
	for (i = 0; i < M; i++)// ����� ��� ����� ���� �����
	{
		for (j = i; j < M; j++)
		{
			for (k = i; k < M; k++)
			{
				if ((arr_pina[i][i][i] != arr_pina[i][k][j]) && (arr_pina[i][i][i] != arr_pina[k][j][i])) //����� �� ����� ��� ���� ����
					if (arr_pina[i][i][i] != arr_pina[k][i][j])
						return 0;	
			}
		}
	}
	return 1;
	
}
