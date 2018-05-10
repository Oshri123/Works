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
	scanf("%d", &size);//קליטת הגודל של חבילת הקלפים
	cards = (int*)malloc(size*sizeof(int));//הקצאת זיכרון לחבילת הקלפים
	do
	{
		_flushall();
		system("cls");//ניקוי המסך בהפעלה חדשה
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
		scanf("%c", &saction);//בחירת המשתמש

		switch (saction)
		{
		case 'i'://אופציית הוספת קלף לחבילת
			printf("enter the color\n");
			_flushall();
			gets(color);
			x = find_code(color);//בדיקת הקוד המיספרי של הצבע שהוכנס
			if (x == -2)// אם קיבלנו מהפונקציה -2 אז זה אומר שהצבע שהמשתמש הכניס לא תקין
			{
				printf("this color is is not posible\n");
				_getch();//הקפאת המסך
				break;
			}
			x = insert(x, &top, cards, size);// אם הצבע תקין הוא מתווסף לחבילת הקלפים
			if (x == 0)//אם הפונקציה החזירה 0 אז זה אומר שאי אפשר להכניס עוד כי החבילה מלאה
				printf("The packet is full\n");
			else
				printf("The card inserded succesfully\n");
			_getch();//הקפאת המסך
			break;
		case 'd'://אופציית הסרת קלף מהחבילה
			x = remove(&top, cards, &ptr_card);//הפעלת הפונקציה remove
			if (x == 1)//אם הפונקציה מחזירה 1 אז הקלף הוסר ומודפסת הודעה מתאימה
			{
				printf("the color that removed is: ");
				print_color(ptr_card);
			}
			_getch();//הקפאת המסך
			break;
		case 'p'://אופציית הדפסת חבילת הקלפים
			print(&top, cards);//קריאה לפונקציה שמדפיסה את חבילת הקלפים
			_getch();//הקפאת המסך
			break;
		case 'e'://פונקציה שבודקת אם חבילת הקלפים ריקה
			x = is_empty(&top);
			if (x == 0)//אם מוחזר 0 מהפונקציה אז המחסנית לא ריקה ומודפסת הודעה בהתאם
			{
				printf("The packet is not empty!\n");
				_getch();//הקפאת המסך

			}
			break;
		case 'f'://פונקציה שבודקת אם חבילת הקלפים מלאה
			x = is_full(&top, size);
			if (x == 0)//אם מוחזר 0 מהפונקציה אז המחסנית לא מלאה ומודפסת הודעה בהתאם
			{
				printf("The packet is not full!\n");
				_getch();//הקפאת המסך
			}
			break;
		case 'q'://אופציית יציאה מהתכנית
			printf("Goodbye...\n");
			_getch();//הקפאת המסך
			break;
		default://הודעה למשתמש אם הקלט שהוא מכניס לא תקין
			printf("Wrong input, please try again!\n");
			_getch();//הקפאת המסך
			break;
		}
	} while (saction != 'q');

	free(cards);//שחרור הזיכרון
}
int find_code(char *color)//פונקציה למציאת קוד של צבע 
{//הפונקציה משתמשת בפונציה של השוואת מחרוזות ומחזירה את הקוד של כל צבע
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
	return -2;//אם הצבע לא נמצא בקוד מוחזר -2
}
void print_color(int num_of_color)//הפונקציה מקבלת קוד של פונקציה מתרגמת אותו לשם של צבע ומדפיסה אותו
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
int insert(int num_of_color, int *top, int *cards, int size)//הפונקציה מוסיפה קלף לחבילת הקלפים
{

	if (*top >= (size - 1))//בדיקה אם החבילה מלאה
	{
		*top = (size - 1);//אם החבילה מלאה אז כדיי למנוע חריגה של המצביע "טופ" מעדכנים אותו שיצביע על הקלף העליון ביותר
		return 0;//אם החבילה מלאה מוחזר 0 לתכנית
	}
	else
	{
		*top = *top + 1;//אם החבילה לא מלאה מעדכנים את המצביע שיצביע על הקלף הבא שנכניס שהוא יהיה העליון ביותר
		cards[*top] = num_of_color;// הכנסת הקלף לחבילת הקלפים
		return 1;//הפונקציה מחזירה 1
	}

}
int remove(int *top, int *cards, int *ptr_card)//פונקציה שמסירה קלף מהחבילה
{
	if (is_empty(top) != 1)
	{
		*ptr_card = cards[*top];//אם החבילה לא ריקה אז המצביע שקיבלנו מהתכנית הראשית מקבל את הערך של הקלף העליון שאנחנו מסירים
		*top = *top - 1;//עדכון המצביע "טופ" לרדת אחד
		return 1;//הפונקציה מחזירה 1
	}

	else return 0;//אם החבילה ריקה מוחזר 0
}
int is_full(int *top, int size)//פונקציה שבודקת אם החבילה מלאה
{
	if (*top >= (size - 1))//בדיקה אם המצביע "טופ" מצביע על האיבר האחרון בחבילה
	{
		*top = (size - 1);
		printf("Is FULL!!\n");//אם כן מודפסת הודעה
		_getch();//הקפאת המסך כדיי שהמשתמש יראה את ההודעה לפני שעושים למסך ניקוי
		return 1;//הפונקציה מחזירה 1
	}
	return 0;//אם החבילה לא מלאה מוחזר 0
}
int is_empty(int *top)//פונקציה שבודקת אם החבילה ריקה
{
	if (*top == -1)//אם המצביע "טופ" מצביע על -1 אז זה אומר שהמכסנית ריקה
	{
		printf("Is Empty!!\n");//אם כן מודפסת הודעה
		_getch();//הקפאת המסך כדיי שהמשתמש יראה את ההודעה לפני שעושים למסך ניקוי
		return 1;//הפונקציה מחזירה 1
	}
	else return 0;//אם החבילה לא ריקה מוחזר 0
}
void print(int *top, int *cards)//פונקציה שמדפיסה את כל הקלפים שהוכנסו לחבילה
{
	int i, x;
	if (*top == -1)//בדיקה אם החבילה ריקה , אם כן מודפסת הודעה בהתאם
		printf("is empty ,insert cards!\n");
	else
	{
		printf("The color\\s in the packet are:\n");
		printf("------\n");
		for (i = *top; i >= blue; i--)//אם החבילה לא ריקה מדפיסים בלולאה את כל הצבעים
		{
			x = cards[i];
			print_color(x);
		}
		printf("------\n");
	}
}