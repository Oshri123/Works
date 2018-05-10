#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
//אושרי נחמני ת.ז 204566194
//עבודה 2 סעיף א. 
//הפונקציה מקבלת מספר והופכת אותו למספר הכי קטן שאפשרי בגודל של המספר שנכנס
long min_num(int length)
{
	long copy_length;
	copy_length = 1 * (pow(10.0, length - 1));
	return copy_length;
}

//
//עבודה 2 סעיף ב. 
// הפונקציה מקבלת 3 משתנים ומחזירה 1 אם המשתנה דיגיט נמצא במספר נאם והמשתנה שולד קונטיין שווה ל1 או אם המשתנה דיגיט אינו נמצא במספר נאם והמשתנה שולד קונטיין שווה ל0 .
//בשאר המקרים הפונקציה תחזיר 0
int contain(long num, int digit, int should_contain)
{
	long copy_num = num;
	int count = 0;
	int sheerit;
	sheerit = copy_num % 10;
	while (copy_num != 0)
	{
		copy_num = copy_num / 10;
		if (sheerit == digit)
			count++;
		sheerit = copy_num % 10;
	}
	if ((count != 0) && (should_contain == 1))
		return 1;
	if ((count == 0) && (should_contain == 0))
		return 1;
	else return 0;
}
//עבודה 2 סעיף ג
//הפונקציה מקבלת 4 משתנים.
// הפונקציה מחלקת את המספר השלם נאם במספר השלם דינאם ובודקת אם השארית שלו שווה למשתנה ריסולט.
//במקרה שהשארית שווה למשתנה ריסולט והמשתנה שולד בי שווה ל1 או במקרה שהשארית שונה מהמשתנה ריסולט והמשתנה שולד בי שווה ל0 הפונקציה תחזיר 1
//בשאר המקרים הפונקציה תחזיר 0.
int mod_a(long num, int dnum, int result, int should_be)
{
	long sherit_num_dnum = num%dnum;
	if ((sherit_num_dnum == result) && (should_be == 1))
		return 1;
	else if ((sherit_num_dnum != result) && (should_be == 0))
		return 1;
	else return 0;

}
/*
עבודה 2 סעיף ד.
הפונקציה הראשית.
קולטת מהמסך שישה משתנים : אורך ספרות. סיפרה. מספר לחלוקה. שארית. משתנה שולד בי ומשתנה שולד קונטיין.
הפונקציה משתמתשת בפונקציות שנבנו בסעיפים א-ג כדיי לבנות מספר מהספרות שנקלנטו ובודקת את כל המספרים האפשריים בעלות אותו מספר ספרות כמו המספר שנבנה.
עבור כל מספר שעבורו שתי הפונקציות של סעיף ב וג החזירו 1 הפונקציה מדפיסה אותו וסופרת כמה מספרים כאלו קיימים בתחום שחיפשנו. */
int main()
{
	int i, x, z, count = 0, digit, result, should_contain, should_be, length, dnum, k, z1, copy_count,
		number_of_kavim, copy_number_of_kavim, sfarot_of_count = 1;
	long num;
	char should_contain_yes_or_no, should_be_yes_or_no;
	do
	{

		printf("enter a int number from 1 to 9\n");
		scanf("%d", &length);

	} while (((length < 1) || (length>9)) && (printf("this number is not posible , Try again! \n")));

	do
	{

		printf("enter a int digit from 0 to 9\n");
		scanf("%d", &digit);

	} while (((digit < 0) || (digit>9)) && (printf("this number is not posible , Try again! \n")));
	do
	{

		printf("Do you want numbers which contain %d ?(y,n)\n", digit);
		flushall();
		scanf("%c", &should_contain_yes_or_no);

	} while (((should_contain_yes_or_no != 'y') && (should_contain_yes_or_no != 'n')) && (printf("this number is not posible , Try again! \n")));
	printf("enter a int dnum:\n");
	scanf("%li", &dnum);
	printf("enter result:\n");
	scanf("%d", &result);
	do
	{

		printf("Do you want: ( num % 9 == 0)? (y,n)\n");
		flushall();
		scanf("%c", &should_be_yes_or_no);

	} while (((should_be_yes_or_no != 'y') && (should_be_yes_or_no != 'n')) && (printf("this number is not posible , Try again! \n")));
	do
	{
		printf("enter a number from 11 to 19\n");
		scanf("%d", &number_of_kavim);
		if (number_of_kavim < 11)
		{
			printf("your number is  too small try again  ");
		}
		else if (number_of_kavim> 19)
			printf("your number is  too big try again  ");

	} while ((number_of_kavim < 11) || (number_of_kavim>19));

	if (should_contain_yes_or_no == 'y')
		should_contain = 1;
	else should_contain = 0;

	if (should_be_yes_or_no == 'y')
		should_be = 1;
	else should_be = 0;
	
	for (i = min_num(length); i < (min_num(length)*(10)); i++)
	{
		
		x = contain(i, digit, should_contain);
		
		z = mod_a(i, dnum, result, should_be);
		
		if ((x + z) == 2)
		{
			printf("%d\t", i);
			count++;
		}
	}
	printf("\nthe number of the numbers that mekaimim all the tnaim is : %d\n", count);
	printf("************************************************************************************************************************\n");
	printf("this program printed The number of numbers with %d digits, which contain the digit %d, and modulo %d are equal to %d is : %d\n", length, digit, dnum, result, count);
	printf("************************************************************************************************************************\n");

	
	copy_number_of_kavim = number_of_kavim;
	copy_count = count;
	while (copy_count / 10 != 0)
	{
		sfarot_of_count++;
		copy_count /= 10;
	}
	if ((number_of_kavim % 2 == 0) && (sfarot_of_count % 2 == 0) || (number_of_kavim % 2 != 0) && (sfarot_of_count % 2 != 0))
		z1 = (number_of_kavim - sfarot_of_count) / 2;
	else z1 = (number_of_kavim - sfarot_of_count) / 2 + 1;
	for (k = 0; k < 5; k++)
	{
		for (i = 0; i < number_of_kavim; i++)
		{

			if ((k == 2) && (i == z1))
			{

				printf("%d", count);
				number_of_kavim = number_of_kavim - sfarot_of_count;
			}
			printf("_");
		}
		printf("\n");
		number_of_kavim = copy_number_of_kavim;

	}
}
