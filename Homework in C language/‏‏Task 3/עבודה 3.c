#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<conio.h>
#define SIZE 81//קבוע שמשמש גודל מחרוזות
#define LENGTH_ARR 10//קבוע שמשמש גודל המערך של סעיף א
#define GODEL 5// קבוע שמשמש גודל המערך הדו מימדי של סעיף ה
#define M 3// קבוע שמשמש גודל המערך התלת מימדי של סעיף ו
#define GODEL2 10 //קבוע שמשמש למספר הקלט ללולאות בתכנית הראשית
void change_arr(int arr[]);//הכרזת פונקציה סעיף א
int machpela_arr(int arr[10]);//הכרזת פונקציה סעיף ב
void change_string(char shorttext[], char longtext[]);//הכרזת פונקציה סעיף ג
int password(char password_srt[]);//הכרזת פונקציה סעיף ד
int reshonee(int length);//פונקציה שבודקת אם מספר הוא ראשוני
int maarah_reshonee(int[GODEL][GODEL]);//הכרזת פונקציה סעיף ה
int maarah_pina(int[M][M][M]);//הכרזת פונקציה סעיף ו


int main()
{

	char saction, longtext[SIZE], shorttext[SIZE], password_srt[SIZE];
	int length, k, i, j, x, arr[LENGTH_ARR], arr1[GODEL][GODEL], arr_pina[M][M][M];
	do
	{
		_flushall();
		system("cls");//ניקוי המסך בהפעלה חדשה
		printf("which saction do you want? (a,b,c,d,e,f) \nif you want to exit from the program press y\n");
		scanf("%c", &saction);//בחירת המשתמש

		switch (saction)
		{
		case 'a'://אם המשתמש בחר להפעיל את האפשרות הראשונה
			printf("enter 10 integer numbers please\n");
			for (i = 0; i < GODEL2; i++)//לולאת קלט לתוך המערך 
				scanf("%d", &arr[i]);
			change_arr(arr);//הפעלת הפונקציה על המערך
			for (i = 0; i < GODEL2; i++)//ללולאה שמדפיסה את המערך החדש לאחר הפעלת הפונקציה עליו
				printf("the new arr[%d] is : %d \n", i, arr[i]);
			printf("press any key to return to the menu\n");
			_getch();//המתנה על מנת שהמשתמש יוכל לראות את הקלט
			break;
		case 'b'://אם המשתמש בחר להפעיל את האפשרות השניה
			printf("enter 10 negative or positive intager numbers with 2 digits please\n");
			for (i = 0; i < GODEL2; i++)//לולאת קלט לתוך המערך
				scanf("%d", &arr[i]);
			printf("The num in arr that the difference from him to his previous is the biggest is: %d \n", machpela_arr(arr));
			printf("press any key to return to the menu\n");
			_getch();//המתנה על מנת שהמשתמש יוכל לראות את הקלט
			break;
		case 'c'://אם המשתמש בחר להפעיל את האפשרות השלישית
			printf("enter a string please\n");
			scanf("%s", longtext);//קלט לתוך המחרוזת
			change_string(shorttext, longtext);//הפעלת הפונקציה על המחרוזות
			printf("the new string is : %s \n", shorttext);//הדפסת המחרוזת לאחר ביצוע הפונקציה
			printf("press any key to return to the menu\n");
			_getch();//המתנה על מנת שהמשתמש יוכל לראות את הקלט
			break;
		case 'd'://אם המשתמש בחר להפעיל את האפשרות הרביעית
			printf("enter a password which contain big latter , small latter , number and the length is 6 up to 11 please\n");
			_flushall();
			gets(password_srt);//קלט הסיסמא של המשתמש
			x = password(password_srt);//הפעלת הפונקציה על הסיסמא
			if (x == 1)//בדיקה אם הסיסמא נכונה או לא
				printf("Your password is Ok\n");
			else
				printf("Your password is not good\n");
			printf("press any key to return to the menu\n");
			_getch();//המתנה על מנת שהמשתמש יוכל לראות את הקלט
			break;
		case 'e'://אם המשתמש בחר להפעיל את האפשרות החמישית
			for (i = 0; i < GODEL; i++)// לולאת קלט למערך הדו מימדי
			{
				for (j = 0; j < GODEL; j++)
				{
					printf("enter a number\n");
					scanf("%d", &arr1[i][j]);
				}
			}
			x = maarah_reshonee(arr1);// קריאה לפונקציה ה שבודקת אם בתוך המערך הדו ממדי השורות והעמודות החיצוניות מכילות אך ורק מספרים ראשוניים
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
			_getch();//המתנה על מנת שהמשתמש יוכל לראות את הקלט
			break;

		case 'f'://אם המשתמש בחר להפעיל את האפשרות השישית
			for (i = 0; i < M; i++)// לולאת קלט למערך התלת מימדי
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
			x = maarah_pina(arr_pina);//קריאה לפונקציה ו
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
			_getch();//המתנה על מנת שהמשתמש יוכל לראות את הקלט
			break;

		}
	} while (saction != 'y');

}
void change_arr(int arr[])//הפונקציה מקבלת מערך
{
	int i, limb1, limb2;
	for (i = 0; i < 10; i = i + 2)//לולאת מעבר בין ערכי המערך
	{
		if (arr[i] % arr[i + 1] == 0)//בדיקה אם האיברים הזוגיים במערך מתחלקים בתאים האי זוגיים העוקבים להם ללא שארית
		{
			limb1 = arr[i];//הפיכת התאים אם התנאי מתקיים
			limb2 = arr[i + 1];
			arr[i] = limb2;
			arr[i + 1] = limb1;
		}
	}
}
int machpela_arr(int arr[])	//הפונקציה מקבלת מערך בעל 10 תאים שבתוכו 10 מספרים בעלי שתי ספרות.
{
	int i, max_efresh, z = 0, new_arr[5];
	for (i = 0; i < 10; i = i + 2)
	{
		new_arr[z] = (arr[i + 1] * 100) + arr[i];//הפונקציה לוקחת כל שתי זוגות מספרים במערך והופכת אותם למספר אחד בעל 4 ספרות ואותם מכניסה למערך חדש בעל 5 תאים
		z++;//משמש בתור המקום של המערך החדש שאליו יכנס המספר בעל 4 הספרות.
	}
	max_efresh = abs(new_arr[1] - new_arr[0]);//הכנסת ההפרש הראשון למשתנה max_efresh
	z = 1;
	for (i = 1; i < 4; i++)//לולאת בדיקה איזה הפרש בין שני איברים במערך גדול יותר (בערך מוחלט) ומכניסה אותו למשתנה max_efresh.
	{
		if (max_efresh < abs(new_arr[i + 1] - new_arr[i]))
		{
			z = i + 1;//משמש בתור האיבר במערך שבו יש את המספר שבינו לבין קודמו יש את ההפרש הגדול ביותר z.
			max_efresh = abs(new_arr[i + 1] - new_arr[i]);
		}
	}
	for (i = 0; i < 5; i++)
		printf("The new arr [%d] is : %d \n", i, new_arr[i]);
	return new_arr[z];// z הפונקציה מחזירה את . 
}
void change_string(char shorttext[], char longtext[])//הפונקציה מקבלת שתי מחרוזות 
{
	char sign = longtext[0];//לתוך המשתנה נכנס איבר מהמחרוזת longtext. 
	int j = 0, i, s = 0, n = 0;
	for (i = 0; i < 80; i++)
	{
		if (sign == '\0')//בדיקה מתי נגמרת המחרוזת
			break;
		shorttext[n] = sign;//לתוך המחרוזת נכנס איבר מהחרוזת השניה
		while (sign == longtext[j])//בדיקה כמה פעמים האיבר נמצא במחרוזת ברצף
		{
			s++;//צבירה של מספר הפעמים שבהם המספר מופיעה ברצף
			j++;//בדיקת האיבר הבא במחרוזת long text.

		}
		sign = longtext[j];//המשתנה מקבל את האיבר השונה הבא
		i = j;
		shorttext[n + 1] = (s + '0');//הכנסת מספר הפעמים שהאיבר נמצא ברצף לתוך המחרוזת shorttext.
		n = n + 2;
		s = 0;
	}

	shorttext[n] = '\0';//סגירת המחרוזת לאחר ביצוע הפעולה
}
int password(char password_srt[])//הפונקציה מקבלת מחרוזת שמכילה סיסמא של משתמש ובודקת אם היא תקינה או לא ומחזירה 1 אם היא תקינה ואם לא 0
{
	int s = 0, z = 0, n = 0, i, length;
	length = strlen(password_srt);//פונקציה שבודקת את האורך של הסיסמא 
	if ((length > 5) && (length < 12))//בדיקה אם הסיסמא קטנה מ6 וארוכה יותר מ11
	{
		for (i = 0; i < length; i++)
		{
			if (password_srt[i] == password_srt[i + 1])//בדיקה אם הסיסמא מכילה את אותו התו פעמיים ברצף
				return 0;
			if ((password_srt[i] >= 48) && (password_srt[i] <= 57))//בדיקה אם הסיסמא מכילה אותיות מספרים
				s = 1;
			if ((password_srt[i] >= 65) && (password_srt[i] <= 90))//בדיקה אם הסיסמא מכילה אותיות גדולות
				z = 1;
			if ((password_srt[i] >= 97) && (password_srt[i] <= 122))//בדיקה אם הסיסמא מכילה אותיות קטנות
				n = 1;
		}
	}
	else return 0;
	if ((s + z + n) == 3)//בדיקה אם הסיסמא מכילה גם אות גדולה ,גם אות קטנה, וגם מספר
		return 1;//אם כן מחזירה 1
	else
		return 0;//אם לא מחזירה 0
}
int reshonee(int number)//הפונקציה מקבלת מספר ובודקת אם הוא ראשוני או לא
{
	int i, k = 1;
	for (i = 2; i <= number; i++)//לולאת בדיקה אם למספר יש מחלקים חוץ מחילוק בעצמו וב1
	{
		if ((number%i) == 0)//אם נמצא שיש למספר מחלק נוסף מגדילים את k 
			k++;
	}
	if (k > 2)//אם נמצאו מחלקים חוץ מב1 וחילוק בעצמו (המספר לא ראשוני) הפונקציה מחזירה 1 אם אין עוד מחלקים (המספר ראשוני) הפונקציה מחזירה 0 
		return 1;
	else return 0;
}
int maarah_reshonee(int arr1[GODEL][GODEL])//הפונקציה מקבלת מערך דו מימדי 
{
	int i, j, counter = 0;
	for (j = 0; j < GODEL; j++)//בדיקה אם השורה הראשונה במערך הדו מימדי בנויה ממספרים ראשוניים
	{
		if (reshonee(arr1[0][j]) != 0)//  אם המספר ראשוני הוא נצבר לתוך הצובר
			return 0;
	}
	for (j = 0; j < GODEL; j++)//בדיקה אם השורה האחרונה במערך הדו מימדי בנויה ממספרים ראשוניים
	{
		if (reshonee(arr1[GODEL - 1][j]) != 0)
			return 0;
	}
	for (i = 1; i < (GODEL - 1); i++)//בדיקה אם המספר הראשון ואחרון בכל שורה במערך מהמקום הראשון עד המקום הלפני אחרון בנויה ממספרים ראשוניים
	{
		if ((reshonee(arr1[i][0]) != 0) && (reshonee(arr1[i][GODEL - 1]) != 0))
			return 0;
	}
	return 1;//אם כל הבדיקות נכונות יוחזר 1
}
int maarah_pina(int arr_pina[][M][M]) //הפונקציה מקבלת מערך תלת מימדי ובודקת אם הוא מערך פינה
{
	int i, j, k, s = 0, z = 0;
	for (i = 0; i < M; i++)// לולאת קלט למערך התלת מימדי
	{
		for (j = i; j < M; j++)
		{
			for (k = i; k < M; k++)
			{
				if ((arr_pina[i][i][i] != arr_pina[i][k][j]) && (arr_pina[i][i][i] != arr_pina[k][j][i])) //בדיקה אם המערך הוא מערך פינה
					if (arr_pina[i][i][i] != arr_pina[k][i][j])
						return 0;	
			}
		}
	}
	return 1;
	
}
