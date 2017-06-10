/* File: power.c
 * Author: ByXc
 * About: power
 * Version: 1.0
 * Compiler: gcc 5.1.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

/* 感覺學編程吧， 是把編程、數學、英語一起數的
 * a^-n = 1 / (a^n) 上網找的公式, 負整數冪就可
 * 求了。 因正、負實數的小數部分，較復雜，程序
 * 清單6.20用的也是正整數， 此程序也只能用負整
 * 數。不會讓讓我這個新手去實現math.h中的pow()
 * 函數吧。
 */
 
#include <stdio.h>

double power(double, int);                  //正、負整數計算函數
double xpower(double, int);					// 這是標準答案的做法， 處理負次冪此函數使用了"取絕對值，然後再調用自身一次(遞歸)
int main(void)
{
    double db_input;
    int i_exp;

    printf("Enter a number and the positive integer power to which"
           "\nthe number will number will be raised. Enter q to quit. \n");
    while (scanf("%lf %d", &db_input, &i_exp) == 2)
    {
        if (0 == power(db_input, i_exp))
            printf("Zero zero power undefined");
        else
            printf("%.3g to the power %d is %.5g \n", db_input, i_exp, power(db_input, i_exp));
        
        printf("Enter enxt pair of numbers or q to quit. \n");
    }
    printf("Hope you enjoyed this power trip -- Bye! \n");

    return 0;
}

double power(double db_number, int i_exp)
{
    int i_count, i_absolute_value;
    double db_power;

    i_absolute_value = i_exp > 0 ? i_exp : -i_exp;       //求絕對值
    db_power = 1.0;

    if (0 == i_exp && 0 == db_number)
        return 0;                                       //因0的0次冪未定義， 直接返回0（個人作風爲了不跟下面的語句其衝突）
    else if (0 == db_number)
        return 1.0;

    for (i_count = 1; i_count <= i_absolute_value; i_count++)
            db_power *= db_number;

    if (i_exp < 0)
        return (1.0 / db_power);                          // 判定指數爲負整數， 根據公式計算
	
	return db_power;                                      // 默認指數爲正整數， 直接返回
}

double xpower(double a, int b)		/* function definition */
{
	double pow = 1;
	int i;
	
	if (b == 0)
	{
		if ( a == 0)
			printf("0 to the 0 undefined; using 1 as the value \n");
		pow = 1.0;
	}
	else if (a == 0)
		pow = 0.0;
	else if (b > 0)
		for (i = 1; i <= b; i++)
			pow *= a;
	else	/* b < 0 */
		pow = 1.0 / xpower(a, -b);							// 傳遞-b， 負負得正

	return pow;												/* return the value of pow */
}