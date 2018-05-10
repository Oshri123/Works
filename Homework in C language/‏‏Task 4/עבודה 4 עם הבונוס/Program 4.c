#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<conio.h>
int *symmetricDiff(int *A, int sizeA, int *B, int sizeB, int *pNewSize)
{
	int length_Of_arr1 = 0, i, j, if_A_equal_B = 0, *arr1;
	arr1 = (int *)malloc((*pNewSize) * sizeof(int));//הקצאת גודל ראשוני למערך החדש
	if (arr1 == NULL)
	{
		printf("NO MEMORY!!\n"); exit(1);
	}
	for (i = 0; i < sizeA; i++)//הלולאה הראשונה רצה על כל האיברים של המערך A.
	{
		for (j = 0; j < sizeB; j++)//הלולאה השניה משווה בין איבר במערך הראשון לכל האיברים במערך השני
		{
			if ((*(A + i)) == (*(B + j)))//תנאי בדיקה אם האיברים שווים
			{
				if_A_equal_B = 1;
				continue;
			}

		}
		if (if_A_equal_B != 1)//בדיקה אם האיבר במערך הראשון שונה מכל האיברים במערך השני אם כן אז האיבר של המערך הראשון נכנס למערך החדש
		{
			*(arr1 + length_Of_arr1) = *(A + i);
			length_Of_arr1++;//ספירת גודלו של המערך החדש
		}
		if_A_equal_B = 0;//איפוס למשתנה הבדיקה
	}
	/*if_A_equal_B = 0;*/
	for (i = 0; i < sizeB; i++)//הלולאה הראשונה רצה על כל האיברים של המערך B
	{
		for (j = 0; j < sizeA; j++)//הלולאה השניה משווה בין איבר במערך השני לכל האיברים במערך הראשון
		{

			if ((*(B + i)) == (*(A + j)))//תנאי בדיקה אם האיברים שווים
			{
				if_A_equal_B = 1;
				continue;
			}

		}
		if (if_A_equal_B != 1)//בדיקה אם האיבר במערך השני שונה מכל האיברים במערך הראשון אם כן אז האיבר של המערך השני נכנס למערך החדש
		{
			*(arr1 + length_Of_arr1) = *(B + i);
			length_Of_arr1++;
		}
		if_A_equal_B = 0;//איפוס למשתנה הבדיקה
	}
	if (length_Of_arr1 == 0)
		printf("the two arrays are same!\n");
	arr1 = (int *)realloc(arr1, length_Of_arr1 * sizeof(int));//הקצאת הגודל המדויק של המערך החדש 
	if (arr1 == NULL)
	{
		printf("NO MEMORY!!\n"); exit(1);
	}
	*pNewSize = length_Of_arr1;//עדכון גודל המערך החדש
	return arr1;//החזרת המצביע של המערך החדש
	free(arr1);

}
void split(int n, int *pSmallDigits, int *pBigDigits)
{
	int z = 0, i, copy_n, moduloo, s = 1, k = 1;
	copy_n = n;

	while (copy_n / 10 != 0) //לולאת בדיקת אורך המספר n.
	{
		z++;
		copy_n = copy_n / 10;
	}
	copy_n = n;
	for (i = 0; i <= z; i++) //לולאה שעוברת על המספר שקיבלנו ובודקת את כל הספרות שלו
	{
		moduloo = copy_n % 10;
		copy_n = copy_n / 10;
		if ((moduloo > 0) && (moduloo < 5))// הרכבה של מספר חדש שמורכב מהספרות של המספר  שהן בין 0 ל 5 לפי סדר הופעתן במספר
		{
			*pSmallDigits = *pSmallDigits + (s*moduloo);
			s = s * 10;
		}
		else if (moduloo == 0)
		{
			s = s * 10;
		}
		else if ((moduloo >= 5) && (moduloo < 10))//  הרכבה של מספר חדש שמורכב מהספרות של המספר שהן בין 5 ל 9  לפי סדר הופעתן במספר
		{
			*pBigDigits = *pBigDigits + (k*moduloo);
			k = k * 10;
		}

	}
}
int isEquivalent(char*lines[], int length, char* text)
{
	int size_of_text, i, j, y, z = 0, size_of_all_lines = 0;
	size_of_text = strlen(text);//בדיקת הגודל של המחרוזת "טקסט
	for (i = 0; i < length; i++)
	{
		y = strlen(*(lines + i));//בדיקת הגודל של כל שורה במערך "ליינס
		size_of_all_lines = size_of_all_lines + y;//צבירה של כל סכום של שורה
	}
	if (size_of_all_lines != size_of_text)// בדיקה אם הגודל של המחרוזת "טקסט" והגודל של השרשור של כל המילים ב"ליינס" שווה 
		return 0;// אם הוא שונה אז השרשור לא שווה למחרוזת טקסט
	for (i = 0; i < length; i++)
	{
		y = strlen(*(lines + i));
		for (j = 0; j < y; j++)// לולאת בדיקה שעוברת על כל המילים בליינס ובודקת אם הם שוות באותו סדר למחרוזת "טקסט"
		{
			if (*(*(lines + i) + j) != *(text + z++))
				return 0;
		}
	}
	return 1;//אם הלולאה לא הפסיקה והגיעה לכאן זה אומר שהשרשור שווה למחרוזת טקסט ולכן מוחזר 1
}
int main()
{
	int *A, sizeA, *B, sizeB, pNewSize, *arr2, i, n, pSmallDigits, pBigDigits, length, current, size, j, y;
	char saction, **lines = NULL, ch, *text;
	do
	{
		_flushall();
		system("cls");//ניקוי המסך בהפעלה חדשה
		printf("which saction do you want? \n");
		printf("\t*********************************\n");
		printf("\t  press a for --SymmetricDiff--\n");
		printf("\t  press b for --IsEquivalen--\n");
		printf("\t  press c for --Split--\n");
		printf("\t*********************************\n");
		printf("if you want to exit from the program press y\n");
		scanf("%c", &saction);//בחירת המשתמש

		switch (saction)
		{
		case 'a'://אם המשתמש בחר להפעיל את האפשרות הראשונה
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
			_getch();//המתנה על מנת שהמשתמש יוכל לראות את הקלט
			break;
		case 'b':

			text = (char*)malloc(1);// הקצאה התחלתית של תו אחד למחרוזת "טקסט 
			if (text == NULL)
			{
				printf("NO MEMORY!!\n"); exit(1);
			}
			current = 0;//משמש כמספר האיבר במחרוזות
			size = 1;//משמש כגודל הדינמי של המחרוזות ובכל אות שנכנסת הוא גודל
			printf("enter your text\n");
			_flushall();
			scanf("%c", &ch);

			while (ch != '\n')//קלט המילים בתור טקסט כל עוד המשתמש לא לחץ אנטר
			{
				*(text + current) = ch;//הכנסת התווים למחרוזת
				text = (char*)realloc(text, ++size);
				if (text == NULL)
				{
					printf("NO MEMORY!!\n"); exit(1);
				}
				current++;
				scanf("%c", &ch);
			}
			*(text + current) = '\0';//סגירת המחרוזת "טקסט"

			printf("How much words you want to write?\n");
			scanf("%d", &length);
			lines = (char **)malloc(length * sizeof(char*));//הקצאת המערך למספר המילים שיוכנסו
			if (lines == NULL)
			{
				printf("NO MEMORY!!\n");
				exit(1);
			}
			for (i = 0; i < length; i++)// קלט של כל מילה בנפרד
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
					*(*(lines + i) + current) = '\0';//  אם זו המילה האחרונה במערך , היא נסגרת עם ,\0
				else
				{
					*(*(lines + i) + current) = ' ';//כל עוד זו לא המילה האחרונה , לפני סגירת המילה מתווסף רווח
					*(lines + i) = (char*)realloc(*(lines + i), ++size);
					if (lines == NULL)
					{
						printf("NO MEMORY!!\n");
						exit(1);
					}
					current++;
					*(*(lines + i) + current) = '\0';// סגירת כל מילה 
				}
			}
			y = isEquivalent(lines, length, text);// הפונקציה בודקת אם שרשור המחרוזת "ליינס" שווה למחרוזת "טקסט"
			if (y == 1)
				printf("The strings are same\n");
			else
				printf("The strings are not same\n");
			free(text);//שחרור המצביע טקסט
			for (i = 0; i < length; i++)
				free(*(lines + i));//שחרור כל המצבעים של ליינס
			free(lines);
			printf("press any key to return to the menu\n");
			_getch();//המתנה על מנת שהמשתמש יוכל לראות את הקלט
			break;

		case 'c':

			pSmallDigits = 0; pBigDigits = 0;
			printf("enter a int number please\n");
			scanf("%d", &n);
			split(n, &pSmallDigits, &pBigDigits);//הפעלת הפונקציה ספליט
			printf("Small Digits=%d\nBig Digits=%d\n", pSmallDigits, pBigDigits);
			printf("press any key to return to the menu\n");
			_getch();//המתנה על מנת שהמשתמש יוכל לראות את הקלט
			break;
		}
		puts("\nGoodBye...");
	} while (saction != 'y');
}



