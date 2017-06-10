/* File: rate2.c
 * Author: ByXc
 * About: 此版本是別人寫的，是最簡單也是最麻煩的。
 * Version: 1.0
 * Compiler: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BASE_A 17850
#define BASE_B 23900
#define BASE_C 29750
#define BASE_D 14875

#define STR "請選擇你的稅金種類"

void star(char ch, int num);
float fnutax(float f_sum);
void temp(float num);

int main(void)
{
	char ch;
	float sum, tax;
	float tax_a, tax_b;
	
	sum = tax = 0;
	tax_a = 0.15;
	tax_b = 0.28;			//switch中case中好像不能用常量進行，這裡只好用變量 （byxc表示可以，在本人的版用define親測可以）
	
	begin:
	star('-', strlen(STR) * 3);
	printf("%s", STR);
	printf("A)單身     : 前17,850美元按15%, 超出部分按28% \n");//byxc提示这幾行printf()的%要用%%表示
	printf("B)戶主     : 前23,900美元按15%, 超出部分按28% \n");
	printf("C)已婚,共有: 前29,750美元按15%, 超出部分按28% \n");
	printf("D)已婚,離異: 前14,875美元按15%, 超出部分按28% \n");
	printf("E)退出程序 \n");
	star('-', strlen(STR) * 3);
	
	while ((ch = getchar()) != 'E')
	{
		if (isalnum(ch))
			switch(ch)
			{
				case 'A':
					printf("請輸入你的收入:");
					scanf("%f", &sum);
					if (sum <= BASE_A)
					{
						tax = sum * tax_a;
						printf("\n你的收入是%.2f，應付稅金為%.2f \n", sum, tax);
					}
					else
					{
						tax = (sum - BASE_A) * tax_b + BASE_A * tax_a;
						printf("\n你的收入是%.2f，應付稅金為%.2f \n", sum, tax);
					}
					goto begin;
					break;
					
					case 'B':
						printf("請輸入你的收入:");
						scanf("%f", &sum);
						if (sum <= BASE_B)
						{
							tax = sum * tax_a;
							printf("\n你的收入是%.2f，應付稅金為%.2f \n", sum, tax);
						}
						else
						{
							tax = (sum - BASE_B) * tax_b + BASE_B * tax_a;
							printf("\n你的收入是%.2f，應付稅金為%.2f \n", sum, tax);
						}
						goto begin;
						break;
						
						case 'C':
							printf("請輸入你的收入:");
							scanf("%f", &sum);
							if (sum <= BASE_C)
							{
								tax = BASE_C * tax_a;
								printf("\n你的收入是%.2f， 應付稅金%.2f \n", sum, tax);
							}
							else
							{
								tax = (sum - BASE_C) * tax_b + BASE_C * tax_a;
								printf("\n你的收入是%.2f，應付稅金%.2f\n", sum, tax);
							}
							goto begin;
							break;
							
							case 'D':
								printf("請輸入你的收入:");
								scanf("%f", &sum);
								if (sum <= BASE_D)
								{
									tax = BASE_D * tax_a;
									printf("\n你的輸入是%.2f，應付稅金%.2f", sum, tax);
								}
								else
								{
									tax = (sum - BASE_D) * 	tax_b + BASE_D * tax_a;
									printf("\n你的收入是%.2f，應付稅金為%.2f \n", sum, tax);
								}
								goto begin;
								break;
								
								default:
									printf("你的輸入有錯誤，請重新輸入 \n");
									goto begin;
									break;
			}
	}
	system("PAUSE");
	
	return 0;
}

void star(char ch, int num)
{
	int temp;
	for (temp = 0; temp < num; temp++)
		putchar(ch);
	putchar('\n');
}