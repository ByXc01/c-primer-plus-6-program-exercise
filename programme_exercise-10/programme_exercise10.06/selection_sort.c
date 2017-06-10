/* File: selection_sort.c
 * Author: ByXc
 * About: selection sort 
 * Version: 2.0
 * Compiler: arm-linux-androideabi-gcc 6.1.0
 * Date: 20170517
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */
 
#include<stdio.h>
#define SIZE 5

void sort (double *, int);                                          // 排序函數
void read_array (const double *, int);                              // 輸出函數

int main(void)
{
	double dbp_array[SIZE] = { 3.0, 2.0, 3.0, 5.0, 4.0 };

    printf("Not sorted: \n");
    read_array(dbp_array, SIZE);
    putchar('\n');

    printf("after sorting: \n");
	sort (dbp_array, SIZE);
	read_array (dbp_array, SIZE);

	return 0;
}

void sort(double * dbp_array, int i_line)
{
	int i_index, i_count, i_adp;                                    // 外層循環、內層循環和最大值出現的位置數
    double db_max;
	
	for (i_index = 0; i_index < i_line - 1; i_index++)              // 外層循環， 做多要要排序i_lin - 1, 因最後一個就是最小值了。
	{
        db_max = *(dbp_array + i_index);                            // 假設 *(dbp_array + index) 是最大值
        i_adp = i_index;                                            // 因 i_adp 保存最大值得下標， 所以默認為當前i_index的值 

		for (i_count = i_index + 1; i_count < i_line; i_count++)    // i_index + 1 是為了比較當前數組元素和當前元素的下一個元素
		{
		    if (db_max < *(dbp_array + i_count))                    // 若當前元素的下一個元素比當前元素的值大
            {

                db_max = *(dbp_array + i_count);                    // 更新最大值
                i_adp = i_count;                                    // 保存當前最大值得元素下標
            }
        }
        
        if (i_index == i_adp)                                       // 若當前數組元素為較大值時， 直接跳過本次循環。（避免沒必要的交換)
            continue;

        *(dbp_array + i_adp) = *(dbp_array + i_index);              // 將當前數組較小值賦值給當前數組元素的下一個元素
        *(dbp_array + i_index) = db_max;                            // 將較大值賦值給當前元素，保持當前元素是較大值。(及完成了交換)
    }
}

void read_array(const double * cdbp_array, int i_line)
{
	int i_index;

	for (i_index = 0; i_index < i_line; i_index++)
		printf ("%3g ", *(cdbp_array + i_index));
	putchar ('\n');
}
