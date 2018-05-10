#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<conio.h>
int *symmetricDiff(int *A, int sizeA, int *B, int sizeB, int *pNewSize)
{
	int length_Of_arr1 = 0, i, j, if_A_equal_B = 0, *arr1;
	arr1 = (int *)malloc((*pNewSize) * sizeof(int));//����� ���� ������ ����� ����
	if (arr1 == NULL)
	{
		printf("NO MEMORY!!\n"); exit(1);
	}
	for (i = 0; i < sizeA; i++)//������ ������� ��� �� �� ������� �� ����� A.
	{
		for (j = 0; j < sizeB; j++)//������ ����� ����� ��� ���� ����� ������ ��� ������� ����� ����
		{
			if ((*(A + i)) == (*(B + j)))//���� ����� �� ������� �����
			{
				if_A_equal_B = 1;
				continue;
			}

		}
		if (if_A_equal_B != 1)//����� �� ����� ����� ������ ���� ��� ������� ����� ���� �� �� �� ����� �� ����� ������ ���� ����� ����
		{
			*(arr1 + length_Of_arr1) = *(A + i);
			length_Of_arr1++;//����� ����� �� ����� ����
		}
		if_A_equal_B = 0;//����� ������ ������
	}
	/*if_A_equal_B = 0;*/
	for (i = 0; i < sizeB; i++)//������ ������� ��� �� �� ������� �� ����� B
	{
		for (j = 0; j < sizeA; j++)//������ ����� ����� ��� ���� ����� ���� ��� ������� ����� ������
		{

			if ((*(B + i)) == (*(A + j)))//���� ����� �� ������� �����
			{
				if_A_equal_B = 1;
				continue;
			}

		}
		if (if_A_equal_B != 1)//����� �� ����� ����� ���� ���� ��� ������� ����� ������ �� �� �� ����� �� ����� ���� ���� ����� ����
		{
			*(arr1 + length_Of_arr1) = *(B + i);
			length_Of_arr1++;
		}
		if_A_equal_B = 0;//����� ������ ������
	}
	if (length_Of_arr1 == 0)
		printf("the two arrays are same!\n");
	arr1 = (int *)realloc(arr1, length_Of_arr1 * sizeof(int));//����� ����� ������ �� ����� ���� 
	if (arr1 == NULL)
	{
		printf("NO MEMORY!!\n"); exit(1);
	}
	*pNewSize = length_Of_arr1;//����� ���� ����� ����
	return arr1;//����� ������ �� ����� ����
	free(arr1);

}
void split(int n, int *pSmallDigits, int *pBigDigits)
{
	int z = 0, i, copy_n, moduloo, s = 1, k = 1;
	copy_n = n;

	while (copy_n / 10 != 0) //����� ����� ���� ����� n.
	{
		z++;
		copy_n = copy_n / 10;
	}
	copy_n = n;
	for (i = 0; i <= z; i++) //����� ������ �� ����� ������� ������ �� �� ������ ���
	{
		moduloo = copy_n % 10;
		copy_n = copy_n / 10;
		if ((moduloo > 0) && (moduloo < 5))// ����� �� ���� ��� ������ ������� �� �����  ��� ��� 0 � 5 ��� ��� ������ �����
		{
			*pSmallDigits = *pSmallDigits + (s*moduloo);
			s = s * 10;
		}
		else if (moduloo == 0)
		{
			s = s * 10;
		}
		else if ((moduloo >= 5) && (moduloo < 10))//  ����� �� ���� ��� ������ ������� �� ����� ��� ��� 5 � 9  ��� ��� ������ �����
		{
			*pBigDigits = *pBigDigits + (k*moduloo);
			k = k * 10;
		}

	}
}
int isEquivalent(char*lines[], int length, char* text)
{
	int size_of_text, i, j, y, z = 0, size_of_all_lines = 0;
	size_of_text = strlen(text);//����� ����� �� ������� "����
	for (i = 0; i < length; i++)
	{
		y = strlen(*(lines + i));//����� ����� �� �� ���� ����� "�����
		size_of_all_lines = size_of_all_lines + y;//����� �� �� ���� �� ����
	}
	if (size_of_all_lines != size_of_text)// ����� �� ����� �� ������� "����" ������ �� ������ �� �� ������ �"�����" ���� 
		return 0;// �� ��� ���� �� ������ �� ���� ������� ����
	for (i = 0; i < length; i++)
	{
		y = strlen(*(lines + i));
		for (j = 0; j < y; j++)// ����� ����� ������ �� �� ������ ������ ������ �� �� ���� ����� ��� ������� "����"
		{
			if (*(*(lines + i) + j) != *(text + z++))
				return 0;
		}
	}
	return 1;//�� ������ �� ������ ������ ���� �� ���� ������� ���� ������� ���� ���� ����� 1
}
int main()
{
	int *A, sizeA, *B, sizeB, pNewSize, *arr2, i, n, pSmallDigits, pBigDigits, length, current, size, j, y;
	char saction, **lines = NULL, ch, *text;
	do
	{
		_flushall();
		system("cls");//����� ���� ������ ����
		printf("which saction do you want? \n");
		printf("\t*********************************\n");
		printf("\t  press a for --SymmetricDiff--\n");
		printf("\t  press b for --IsEquivalen--\n");
		printf("\t  press c for --Split--\n");
		printf("\t*********************************\n");
		printf("if you want to exit from the program press y\n");
		scanf("%c", &saction);//����� ������

		switch (saction)
		{
		case 'a'://�� ������ ��� ������ �� ������� �������
			printf("enter the length of array A\n");
			scanf("%d", &sizeA);
			A = (int *)malloc(sizeA * sizeof(int));
			if (A == NULL)
			{
				printf("NO MEMORY!!\n"); exit(1);
			}
			printf("enter the length of array B\n");
			scanf("%d", &sizeB);
			B = (int *)malloc(sizeB * sizeof(int));
			if (B == NULL)
			{
				printf("NO MEMORY!!\n"); exit(1);
			}
			pNewSize = sizeA + sizeB;
			printf("enter %d numbers FOR A\n", sizeA);
			for (i = 0; i < sizeA; i++)
				scanf("%d", &(*(A + i)));
			printf("enter %d numbers FOR B\n", sizeB);
			for (i = 0; i < sizeB; i++)
				scanf("%d", &(*(B + i)));
			arr2 = symmetricDiff(A, sizeA, B, sizeB, &pNewSize);
			printf("{");
			for (i = 0; i < pNewSize; i++)
              printf("%d, ", *(arr2 + i));
			
			printf("}");
			printf("\n");
			free(A);
			free(B);
			free(arr2);
			printf("press any key to return to the menu\n");
			_getch();//����� �� ��� ������� ���� ����� �� ����
			break;
		case 'b':

			text = (char*)malloc(1);// ����� ������� �� �� ��� ������� "���� 
			if (text == NULL)
			{
				printf("NO MEMORY!!\n"); exit(1);
			}
			current = 0;//���� ����� ����� ��������
			size = 1;//���� ����� ������ �� �������� ���� ��� ������ ��� ����
			printf("enter your text\n");
			_flushall();
			scanf("%c", &ch);

			while (ch != '\n')//��� ������ ���� ���� �� ��� ������ �� ��� ����
			{
				*(text + current) = ch;//����� ������ �������
				text = (char*)realloc(text, ++size);
				if (text == NULL)
				{
					printf("NO MEMORY!!\n"); exit(1);
				}
				current++;
				scanf("%c", &ch);
			}
			*(text + current) = '\0';//����� ������� "����"

			printf("How much words you want to write?\n");
			scanf("%d", &length);
			lines = (char **)malloc(length * sizeof(char*));//����� ����� ����� ������ �������
			if (lines == NULL)
			{
				printf("NO MEMORY!!\n");
				exit(1);
			}
			for (i = 0; i < length; i++)// ��� �� �� ���� �����
			{
				size = 1;
				current = 0;
				*(lines + i) = (char*)malloc(1);
				printf("enter word number: %d\n", i + 1);
				_flushall();
				scanf("%c", &ch);

				while (ch != '\n')
				{
					*(*(lines + i) + current) = ch;
					*(lines + i) = (char*)realloc(*(lines + i), ++size);
					if (lines == NULL)
					{
						printf("NO MEMORY!!\n");
						exit(1);
					}
					current++;
					scanf("%c", &ch);
				}
				if (i == (length - 1))
					*(*(lines + i) + current) = '\0';//  �� �� ����� ������� ����� , ��� ����� �� ,\0
				else
				{
					*(*(lines + i) + current) = ' ';//�� ��� �� �� ����� ������� , ���� ����� ����� ������ ����
					*(lines + i) = (char*)realloc(*(lines + i), ++size);
					if (lines == NULL)
					{
						printf("NO MEMORY!!\n");
						exit(1);
					}
					current++;
					*(*(lines + i) + current) = '\0';// ����� �� ���� 
				}
			}
			y = isEquivalent(lines, length, text);// �������� ����� �� ����� ������� "�����" ���� ������� "����"
			if (y == 1)
				printf("The strings are same\n");
			else
				printf("The strings are not same\n");
			free(text);//����� ������ ����
			for (i = 0; i < length; i++)
				free(*(lines + i));//����� �� ������� �� �����
			free(lines);
			printf("press any key to return to the menu\n");
			_getch();//����� �� ��� ������� ���� ����� �� ����
			break;

		case 'c':

			pSmallDigits = 0; pBigDigits = 0;
			printf("enter a int number please\n");
			scanf("%d", &n);
			split(n, &pSmallDigits, &pBigDigits);//����� �������� �����
			printf("Small Digits=%d\nBig Digits=%d\n", pSmallDigits, pBigDigits);
			printf("press any key to return to the menu\n");
			_getch();//����� �� ��� ������� ���� ����� �� ����
			break;
		}
		puts("\nGoodBye...");
	} while (saction != 'y');
}



