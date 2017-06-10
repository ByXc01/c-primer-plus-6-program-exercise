/* File: cmd_pow.c
 * Author: ByXc
 * About: command-line argument power
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys
 * Date: 20170609
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <stdlib.h>             // 提供 strtod() 和 strtol()  的函數原型 

double power(double, int);      // 支持指數為正、負整數。標準答案直接用 math.h 中 pow() 函數
int main(int argc, char * argv[])
{
   char * chp_end1, * chp_end2; 
   int i_exp;
   double db_base, db_result;

   if (argc > 2)                // 要有兩個參數
   {
      db_base = strtod(*(argv + 1), &chp_end1);
      i_exp   = strtol(*(argv + 2), &chp_end2, 0);              // 用 0 或 10 為十進制

      if (*(argv + 1) != chp_end1 && *(argv + 2) != chp_end2)   // 檢測轉換是否成功
      {
          db_result = power(db_base, i_exp);                    // 調用計算冪函數
          printf("%.3g to the power %d is %.5g \n", db_base, i_exp, db_result);
          puts("Hope you enjoyed this power trip -- Bye!");
      }
      else                                                      // 轉換失敗
          printf("%s and %s is a strings! \n", chp_end1, chp_end2);
   }
   else
       printf("Usage: %s Enter base and exp!", *argv);

   return 0;
}

double power(double db_base, int i_exp)
{
    double db_pow = 1.0;
    int i_count;

    if (i_exp == 0)                                             // 任何非零次冪都得1
    {
        if (db_base == 0)                                       // 零的零次冪未定義
        {
            puts("0 to the 0 underfined; using 0 as the value!");
            db_pow = 0;
        }
    }
    else if (db_base == 0)                                      // 零的任何次冪都得零
        db_pow = 0;
    else if (i_exp > 0)
        for (i_count = 0; i_count < i_exp; i_count++)           // 計算冪
            db_pow *= db_base;
    else                                                        // i_exp < 0
        db_pow = 1 / power(db_base, -i_exp);                    // 負負得正
    
    return db_pow;
}
