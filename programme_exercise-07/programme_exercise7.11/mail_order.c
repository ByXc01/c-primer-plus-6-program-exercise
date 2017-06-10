/* File: mail_order.c
 * Author: ByXc
 * About: 做的好亂啊， 怪自己以前沒加注釋
 * Version: 1.0
 * Compiler: gcc 5.1.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define PRINT1 "Please enter the number of pound to buy:"
#define PRINT2 "Please enter the vegetable alphabet you want to buy"

#define ARTICHOKE		2.05
#define BEET			1.15
#define CARROT			1.09

#define FREIGHT_PACKING_CHARGES1 6.5						// 包裝運費 <= 5 磅 
#define FREIGHT_PACKING_CHARGES2 14.00						// 包裝運費 6 ~ 20 磅
#define DISCOUNT_NUMBER          100						// 滿足條件才能享受折扣
#define DISCOUNT		0.05								// 折扣

#define BASE1			5									// 包裝磅數
#define BASE2			20
#define BEYOND			0.5									// 超出部分按每磅0.5美元收費

float fl_freight_packing_charges = 0;						// 包裝運費
double db_cargo_price = 0, db_total_cost = 0;				// 貨品價格和總成本
float fl_pound = 0;											// 購買的磅數
	
void choice(char ch_letter);
void print(void);
void compute(void);
float scan(void);

int main(void)
{
	char ch_enter;
	
	print();
	
	while ((ch_enter = getchar()) != 'q' || ch_enter != 'Q')			// q 退出
	{
		if (isalpha(ch_enter))
		{
			ch_enter = toupper(ch_enter);								// 將輸入轉換為大寫字母
			
			while (getchar() != '\n')									// 清除多餘的輸入
				continue;
			choice(ch_enter);
		}
		print();
	}
	compute();
	
	printf("Bye");
	
	return 0;
}

void print(void)
{
	int i_temp;
	
	for (i_temp = 0; i_temp < strlen(PRINT2) - 2; i_temp++)
		printf("-");
	
	printf("\n%s \n", PRINT2);
	printf("A)artichoke $%.2f/pound        B)beet $%.2f/pound \n", ARTICHOKE, BEET);
	printf("C)carrot $%.2f/pound           Q)exit option \n", CARROT);
	
	for (i_temp = 0; i_temp < strlen(PRINT2) - 2; i_temp++)
		printf("-");
	putchar('\n');
}

void choice(char ch_letter)
{
	float fl_cpound = 0;
	switch (ch_letter)
	{
		case 'A':
			printf("You picked a artichoke. \n");
			printf("%s \n", PRINT1);
			fl_cpound = scan();										// 輸入磅數
			
			db_cargo_price += fl_cpound * ARTICHOKE;				// 計算計算貨物的價格
			fl_pound += fl_cpound;									// 累加磅數
			
			printf("Do you want to continue to choose other vegetables, enter Q to settlement. \n");
			break;
			
		case 'B':
			printf("You picked a beet. \n");
			printf("%s \n", PRINT1);
			fl_cpound = scan();
			
			db_cargo_price += fl_cpound * BEET;
			fl_pound += fl_cpound;
			
			printf("Do you want to continue to choose other vegetables, enter Q to settlement. \n");
			break;
			
		case 'C':
			printf("You picked a carrot. \n");
			printf("%s \n", PRINT1);
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
		fl_freight_packing_charges = FREIGHT_PACKING_CHARGES2 + (fl_pound - FREIGHT_PACKING_CHARGES2) * BEYOND;			// 計算超出磅數金額

	if (db_cargo_price >= DISCOUNT_NUMBER)																				// 檢測是否符合折扣條件
	{
		fl_discount = db_cargo_price * DISCOUNT;																		// 計算打折金額
		db_cargo_price *= 1.0 - DISCOUNT;																				// 計算打折后的總額
	}
	db_total_cost = db_cargo_price + fl_freight_packing_charges;														// 成本總額
	
	printf("cargo price: %g, freight and packing charges: %g, pound: %g, discount: %g,"
			"total cost: %g \n", db_cargo_price, fl_freight_packing_charges, fl_pound,
			fl_discount, db_total_cost);
}

/* 推薦標準答案， 本人做的太爛了。但標準答案有一個地方做的， 已改正 */
/* pe7-11.c */
/* Programming Exercise 7-11 */
/*
#include <stdio.h>
#include <ctype.h>
int main(void)
{
	const double price_artichokes = 2.05;
	const double price_beets = 1.15;
	const double price_carrots = 1.09;
	
	const double DISCOUNT_RATE = 0.05;
	
	const double under5 = 6.50;
	const double under20 = 14.00;
	
	const double base20 = 14.00;
	const double extralb = 0.50;
	
	char ch;
	double lb_artichokes = 0;
	double lb_beets = 0;
	double lb_carrots = 0;
	double lb_temp;
	double lb_total;
	
	double cost_artichokes;
	double cost_beets;
	double cost_carrots;
	double cost_total;
	
	double final_total;
	double discount;
	double shipping;
	
	printf("Enter a to buy artichokes, b for beets, ");
	printf("c for carrots, q to quit: ");
	
	while ((ch = getchar()) != 'q' && ch != 'Q')
	{
		if (ch == '\n')
			continue;
		while (getchar() != '\n')
			continue;
		
		ch = tolower(ch);
		switch (ch)
		{
			case 'a' : 
				printf("Enter pounds of artichokes: ");
				scanf("%lf", &lb_temp);
				lb_artichokes += lb_temp;
				break;
			case 'b' : 
				printf("Enter pounds of beets: ");
				scanf("%lf", &lb_temp);
				lb_beets += lb_temp;
				break;
			case 'c' : 
				printf("Enter pounds of carrots: ");
				scanf("%lf", &lb_temp);
				lb_carrots += lb_temp;
				break;
			default : 
				printf("%c is not a valid choice.\n", ch);
		}
		printf("Enter a to buy artichokes, b for beets, ");
		printf("c for carrots, q to quit: ");
	}
	cost_artichokes = price_artichokes * lb_artichokes;
	cost_beets = price_beets * lb_beets;
	cost_carrots = price_carrots * lb_carrots;
	cost_total = cost_artichokes + cost_beets + cost_carrots;
	lb_total = lb_artichokes + lb_beets + lb_carrots;
	
	if (lb_total <= 0)
		shipping = 0.0;
	else if (lb_total < 5.0)
		shipping = under5;
	else if (lb_total < 20)
		shipping = under20;
	else
		//shipping = base20 + extralb * lb_total;				// 標準答案出錯了， 這裡 lb_total 還要減去 base20 的
		shipping = base20 + (lb_total - base20) * extrlb; 
	if (cost_total > 100.0)
		discount = DISCOUNT_RATE * cost_total;
	else
		discount = 0.0;
	
	final_total = cost_total + shipping - discount;
	printf("Your order:\n");
	printf("%.2f lbs of artichokes at $%.2f per pound:$ %.2f\n", lb_artichokes, price_artichokes, cost_artichokes);
	printf("%.2f lbs of beets at $%.2f per pound: $%.2f\n", lb_beets, price_beets, cost_beets);
	printf("%.2f lbs of carrots at $%.2f per pound: $%.2f\n", lb_carrots, price_carrots, cost_carrots);
	printf("Total cost of vegetables: $%.2f\n", cost_total);
	
	if (cost_total > 100)
		printf("Volume discount: $%.2f\n", discount);
	
	printf("Shipping: $%.2f\n", shipping);
	printf("Total charges: $%.2f\n", final_total);
	return 0;
}
*/