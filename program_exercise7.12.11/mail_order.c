/* File: mail_order.c
 * Author: ByXc
 * About: 做的好亂啊， 怪自己以前沒加注釋
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define PRINT "Please enter the number of pound to buy:"
#define ARTICHOKE		2.05
#define BEET			1.15
#define CARROT			1.09

#define FREIGHT_PACKING_CHARGES1 6.5
#define FREIGHT_PACKING_CHARGES2 14.00
#define DISCOUNT_NUMBER          100
#define DISCOUNT		0.05

#define BASE1			5
#define BASE2			20
#define BEYOND			0.5

float fl_freight_packing_charges = 0;						//定义了全局变量
double db_cargo_price = 0, db_total_cost = 0;
float fl_pound = 0;

void choice(char ch_letter);
void print(void);
void compute(void);
float scan(void);
int main(void)
{
	char ch_enter;
	
	print();
	
	while (scanf(" %c", &ch_enter))
	{
		if (isalpha(ch_enter))
		{
			ch_enter = toupper(ch_enter);
			if ('Q' == ch_enter)
				break;
			else
				choice(ch_enter);
		}
		else
			printf("Error, Please a number. \n");
		
		print();
	}
	compute();
	
	printf("Bye");
	
	return 0;
}

void print(void)
{
	int i_temp;
	
	for (i_temp = 0; i_temp < strlen(PRINT) - 2; i_temp++)
		printf("- ");
	
	printf("\n%s \n", PRINT);
	printf("A)artichoke $%.2f/pound        B)beet $%.2f/pound \n", ARTICHOKE, BEET);
	printf("C)carrot $%.2f/pound           Q)exit oftion \n", CARROT);
	
	for (i_temp = 0; i_temp < strlen(PRINT) - 2; i_temp++)
		printf("- ");
	putchar('\n');
}

void choice(char ch_letter)
{
	float fl_cpound = 0;
	switch (ch_letter)
	{
		case 'A':
			printf("You picked a artichoke. \n");
			fl_cpound = scan();
			
			db_cargo_price += fl_cpound * ARTICHOKE;
			fl_pound += fl_cpound;
			
			printf("Do you want to continue to choose other vegetables, enter Q to settlement. \n");
			break;
			
		case 'B':
			printf("You picked a beet. \n");
			fl_cpound = scan();
			
			db_cargo_price += fl_cpound * BEET;
			fl_pound += fl_cpound;
			
			printf("Do you want to continue to choose other vegetables, enter Q to settlement. \n");
			break;
			
		case 'C':
			printf("You picked a carrot. \n");
			
			fl_cpound = scan();
			
			db_cargo_price += fl_cpound * CARROT;
			fl_pound += fl_cpound;
			
			printf("Do you want to continue to choose other vegetables, enter Q to settlement. \n");
			break;
			
		default:
			printf("Enter error. \n");
	}
}

float scan(void)
{
	float fl_temp;
	
	scanf("%f", &fl_temp);
	
	return fl_temp;
}

void compute(void)
{
	float fl_discount = 0;
	if (fl_pound <= BASE1)
		fl_freight_packing_charges = FREIGHT_PACKING_CHARGES1;
	else if (fl_pound <= BASE2)
		fl_freight_packing_charges = FREIGHT_PACKING_CHARGES2;
	else
		fl_freight_packing_charges = FREIGHT_PACKING_CHARGES2 + ((fl_pound - FREIGHT_PACKING_CHARGES2) * BEYOND);

	if (db_cargo_price >= DISCOUNT_NUMBER)
		fl_discount = db_cargo_price * DISCOUNT;
	
	db_total_cost = (db_cargo_price * (1.0 - DISCOUNT)) + fl_freight_packing_charges;
	
	printf("cargo price: %g, freight and packing charges: %g, pound: %g, discount: %g,"
			"total cost: %g \n", db_cargo_price, fl_freight_packing_charges, fl_pound,
			fl_discount, db_total_cost);
}