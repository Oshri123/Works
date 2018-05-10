עבודה במחשבים .
שם : אושרי נחמני . תז. : 204566194

//targil 1.

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void main()
{

	int merhak, meirut;
	float time_of_agaha, meirut_hiluk_merhak;
	printf("enter a integer number ot the meirut\n");
	scanf("%d", &meirut);
	printf("enter a integer number ot the nerhal\n");
	scanf("%d", &merhak);
	meirut_hiluk_merhak = float(meirut) / merhak;
	time_of_agaha = meirut_hiluk_merhak * 60.0;
	printf("the time of the agaha is: %f minutes\n", time_of_agaha);

}

//targil 2.

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{

	float tashlum, num_of_litrim;
	char delek;
	printf("for a delek of 98 press 'S'\nfor a delek of 95 press 'R'\nfor a delek of Soler press 'D'\n and if you dont want to fuek press 'X'\n");
	scanf("%c", &delek);
	if (delek == 'X')
	{
		printf("you didnt want to fuel\n");
		return 0;
	}
	printf("enter how much liters you want to fuel\n");
	scanf("%f", &num_of_litrim);


	if (delek == 'S')
		tashlum = 7.5* num_of_litrim;
	else if (delek == 'R')
		tashlum = 5.85* num_of_litrim;
	else if (delek == 'D')
		tashlum = 5.95* num_of_litrim;

	if (tashlum > 150)
		printf("you won at paper in free and your tashlum for the fuel is:%f\n", tashlum);
	else
		printf("your tashlum for the fuel is:%f\n", tashlum);
}

//targil 3.

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int num1, peula, copy_num1, num_of_the_digits = 1;
	printf("enter a integer number that not big from 4 digits please\n");
	scanf("%d", &num1);
	copy_num1 = num1;
	printf("if you want to calculate the numbers of the digits of your number press 1\n if you want to check if your number is zugi or ezugi press 2\n");
	scanf("%d", &peula);

	if (peula == 1)
	{
		while ((copy_num1 / 10) != 0)
		{
			num_of_the_digits++;
			copy_num1 = copy_num1 / 10;
		}
		if (num_of_the_digits < 5)
		{
			printf("the calculate of the numbers of the digits of your number is: %d\n", num_of_the_digits);

		}
		else
		{
			printf("your number is big  from 4 digits");
			return 0;
		}
	}
	if (peula == 2)
		if ((num1 % 2) == 0)
		{
			printf("your number %d is zugi\n", num1);

		}
		else{
			printf("your number %d is ezugi\n", num1);

		}

		if (num1 < 0)
			printf("your number is shlili so the number in hezka 2 is%d\n", num1*num1);
		return 0;

}

//targil 4.

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{

	int num1, copy_num1, hezka = 10000;
	int i, the_new_number = 0;
	printf("enter a number with 5 digits please\n");
	scanf("%d", &num1);   // imput number to x from the user
	copy_num1 = num1;

	for (i = 0; i < 5; i++)
	{
		if ((copy_num1 % 10) == 0)
		{
			printf("you have the number zero in the digits of the number \n");
			return 0;
		}
		the_new_number = the_new_number + ((copy_num1 % 10)*hezka);
		hezka = (hezka / 10);
		copy_num1 = copy_num1 / 10;
	}

	if (num1 == the_new_number)
		printf("the number: %d is palindrom\n", the_new_number);
	else
		printf("the number: %d is not palindrom\n", num1);

	return 0;
}

//targil 5.

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int num1, num2, copy_num1, copy_num2, sum_digit5_at_num2 = 0, sum_digit5_at_num1 = 0, s = 0, sheerit_num2, sheerit_num1;


	printf("enter a 2 number with 3 digits please\n");
	scanf("%d%d", &num1, &num2);

	sheerit_num1 = num1 % 10;

	copy_num1 = num1 / 10;
	sheerit_num2 = num2 % 10;
	copy_num2 = num2 / 10;

	while (s < 3)
	{
		s = s + 1;
		if (sheerit_num1 == 5)
		{
			sum_digit5_at_num1 = sum_digit5_at_num1 + 1;

		}
		if (sheerit_num2 == 5)
		{
			sum_digit5_at_num2 = sum_digit5_at_num2 + 1;

		}
		sheerit_num1 = copy_num1 % 10;
		copy_num1 = copy_num1 / 10;
		sheerit_num2 = copy_num2 % 10;
		copy_num2 = copy_num2 / 10;
	}

	if ((sum_digit5_at_num1 == sum_digit5_at_num2) && (sum_digit5_at_num1 >= 1))
		printf("the times that the digit '5' appears in the numbers is equal\n");
	else if ((sum_digit5_at_num1 == sum_digit5_at_num2) && (sum_digit5_at_num1 == 0))
		printf("the digit '5' is not apears in the numbers\n");
	else
		if (sum_digit5_at_num1 > sum_digit5_at_num2)
			printf("the number %d is the winner\n", num1);

		else
			printf("the number %d is the winner\n", num2);


}

//targil 6.

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void main()
{
	int i, j;

	for (i = 1; i < 11; i++)
	{

		for (j = 1; j < 11; j++)
		{
			printf("%d\t", (i*j));

		}
		printf("\n");
	}
}

//targil 7.

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void main()
{
	int i, num1, sum_ahadot = 0, sum_asarot = 0, sum_meot = 0, max = 0;

	for (i = 0; i < 30; i++)
	{
		printf("enter a number with 3 digits\n");
		scanf("%d", &num1);
		sum_ahadot = sum_ahadot + (num1 % 10);
		num1 = num1 / 10;
		sum_asarot = sum_asarot + (num1 % 10);
		num1 = num1 / 10;
		sum_meot = sum_meot + (num1 % 10);

	}

	if ((sum_ahadot <= sum_asarot) && (sum_ahadot <= sum_meot))
		if (sum_asarot <= sum_meot)
			printf("the sum pf the numbers from the smallest to the biggest is:\n ahadot:%d\n asarot:%d\n neot:%d\n ", sum_ahadot, sum_asarot, sum_meot);
		else
			printf("the sum pf the numbers from the smallest to the biggest is:\n ahadot:%d\n meot:%d\n asarot:%d\n ", sum_ahadot, sum_meot, sum_asarot);
	else
		if ((sum_asarot <= sum_ahadot) && (sum_asarot <= sum_meot))
			if (sum_ahadot <= sum_meot)
				printf("the sum pf the numbers from the smallest to the biggest is:\n asarot:%d\n ahadot:%d\n neot:%d\n ", sum_asarot, sum_ahadot, sum_meot);
			else
				printf("the sum pf the numbers from the smallest to the biggest is:\n asarot:%d\n meot:%d\n ahadot:%d\n ", sum_asarot, sum_meot, sum_ahadot);
		else
			if (sum_ahadot <= sum_asarot)
				printf("the sum pf the numbers from the smallest to the biggest is:\n meot:%d\n ahadot:%d\n asarot:%d\n ", sum_meot, sum_ahadot, sum_asarot);
			else
				printf("the sum pf the numbers from the smallest to the biggest is:\n meot:%d\n asarot:%d\n ahadot:%d\n ", sum_meot, sum_asarot, sum_ahadot);
}

//targil 8.

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void main()
{
	int num1, num2, the_new_number = 0, hezka = 1, i, copy_num1;

	do
	{
		printf("enter a number with 5 digits\n");
		scanf("%d", &num1);
		printf("enter a number with 1 digit\n");
		scanf("%d", &num2);
		copy_num1 = num1;

		for (i = 0; i < 5; i++)
		{
			if (copy_num1 % 10 != num2)
			{
				the_new_number = the_new_number + ((copy_num1 % 10)*hezka);
				hezka = (hezka * 10);
			}
			else the_new_number = the_new_number + 0;
			copy_num1 = copy_num1 / 10;
		}
		printf("the new number without the digit %d is:%d\n", num2, the_new_number);
		the_new_number = 0; hezka = 1;
	} while ((num1 != 0) && (num2 != 0));

}

//targil 9a.

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int sum_holocaust = 0, the_divider_num = 1, holocaust, num1, copy_num1 = 0;

	printf("enter a number\n");
	scanf("%d", &num1);
	copy_num1 = num1;

	while (copy_num1 - 1 != 0)
	{
		holocaust = num1 % the_divider_num;
		if (holocaust == 0)
		{
			sum_holocaust = sum_holocaust + the_divider_num;
		}
		copy_num1--;
		the_divider_num++;

	}

	if (num1 == sum_holocaust)
		printf("the number: %d is a good num\n", num1);

}

//targil 9b.

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int sum_holocaust = 0, the_divider_num = 1, holocaust, i, copy_i;

	printf("the number: 0 is a meshuchlal num\n");

	for (i = 1; i <= 10000; i++)
	{

		copy_i = i;

		while ((copy_i != 0) && (the_divider_num<i))
		{
			holocaust = i % the_divider_num;

			if (holocaust == 0)
			{
				sum_holocaust = sum_holocaust + the_divider_num;

			}
			copy_i--;

			the_divider_num++;

		}

		if (i == sum_holocaust)
			printf("the numbers: %d is a meshuchlal num\n", i);

		sum_holocaust = 0;
		the_divider_num = 1;

	}
}

//targil 10.

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int i, j, num1, copy_num1, min = 0, max = 0;
	float sum_num1 = 0;

	printf("enter a number\n");
	scanf("%d", &num1);
	max = num1;
	min = num1;
	for (i = 0; i < 2; i++)
	{
		sum_num1 = sum_num1 + num1;
		if (num1 >= max)
			max = num1;
		if (num1 <= min)
			min = num1;
		copy_num1 = num1;
		printf("all the numbers from 0 to %d that divid at 1,3,5 is:\n", num1);
		for (j = 0; j < num1; j++)
		{

			if (copy_num1 % 15 == 0)
				printf("%d\n", copy_num1);

			copy_num1--;
		}

		printf("enter a number\n");
		scanf("%d", &num1);

	}

	for (i = 0; i < 1; i++)
	{
		sum_num1 = sum_num1 + num1;
		if (num1 >= max)
			max = num1;
		if (num1 <= min)
			min = num1;
		copy_num1 = num1;
		printf("all the numbers from 0 to %d that divid at 1,3,5 is:\n", num1);
		for (j = 0; j < num1; j++)
		{

			if (copy_num1 % 15 == 0)
				printf("%d\n", copy_num1);

			copy_num1--;
		}


	}


	printf("the biggest num is%d\n", max);
	printf("the lowest num is%d\n", min);
	sum_num1 = (sum_num1 / 3);
	printf("the average of the numbers is %f\n", sum_num1);
}