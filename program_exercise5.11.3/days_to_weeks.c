//天數轉周數和天數
#include <stdio.h>
const unsigned short UH_WEEKS = 7;
#include <stdio.h>
int main(void)
{
	int i_weeks, i_days;			//存儲轉換的周數和天數
	int i_days_input;				//用戶輸入的天數
	
	
	printf("please input the days:");
	scanf("%d", &i_days_input);
	while (i_days_input > 0)
	{	
		i_weeks = i_days_input / UH_WEEKS;
		i_days  = i_days_input % UH_WEEKS;
	
		printf("intput %4d days, %4d weeks, %4d days. \n", i_days_input, i_weeks, i_days);
		printf("Next enter the days(q to quit): ");
		scanf("%d", &i_days_input);
	}
	printf("Bey! \n");
	return 0;
}