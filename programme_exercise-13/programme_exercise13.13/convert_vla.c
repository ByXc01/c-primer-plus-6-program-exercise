/* File: convert_vla.c
 * Author: ByXc
 * About: Digital convert picture, variable-length array
 * Version: 2.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170718
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <stdlib.h>     // 为了 exit() 原型, 为 EXIT_FAILURE 提供宏

void convert(int, int, int (*)[*], char (*)[*]);     // 變長數組
void initialization(int, int, FILE *, int (*)[*]);

const char * cchp_trans = " .':~*=&%#";              // 全局變量， 模仿標準答案。 7 对应 &, 其实只作用来占位符。因文本里没有数字7

int main(void)
{
    FILE * fp_input, * fp_output;
    const char * cchp_input_name = "sample_input_text";
    const char * cchp_output_name = "picture";
    int i_lines = 20, i_cols = 30;
    int i_row;
    int ia_number[i_lines][i_cols];
    char cha_string[i_lines][i_cols + 1];                                           // 最後一個存空字符

    if ((fp_input = fopen(cchp_input_name, "r")) == NULL)                           // 以讀文本模式打開文件
    {
        fprintf(stderr, "Could not open file \"%s\"\n", cchp_input_name);
        exit(EXIT_FAILURE);
    }

    if ((fp_output = fopen(cchp_output_name, "w")) == NULL)                         // 以寫文本模式打開文件
    {
        fprintf(stderr, "Could not open file \"%s\"\n", cchp_output_name);
        exit(EXIT_FAILURE);
    }

    // 檢查讀取錯誤
    if (ferror(fp_input) != 0)
    {
        fprintf(stderr, "Error in readingfile \"%s\"\n", cchp_input_name);
        exit(EXIT_FAILURE);
    }

    initialization(i_lines, i_cols, fp_input, ia_number);                          // 給數組初始化文件的內容
    convert(i_lines, i_cols, ia_number, cha_string);                               // 將對應的數字轉換為字符串
    
    for (i_row = 0; i_row < i_lines; i_row++)
        fprintf(fp_output, "%s\n", *(cha_string + i_row));                         // 輸出至文件
    
    // 檢查關閉錯誤
    if (fclose(fp_input) != 0)
        fprintf(stderr, "Error in closing \"%s\"\n", cchp_input_name);
    if (fclose(fp_output) != 0)
        fprintf(stderr, "Error in closing \"%s\" file.\n", cchp_output_name);

    return 0;
}

void initialization(int i_lines, int i_cols, FILE * fp_file, int (* iap_pointer)[i_cols])
{
    int i_r, i_c;

    // 以下用指針表示法可能看起來比較複雜
    for (i_r = 0; i_r < i_lines; i_r++)
        for (i_c = 0; i_c < i_cols; i_c++)
            fscanf(fp_file, "%d", &*(*(iap_pointer + i_r) + i_c));                  // 從文件讀取數據到數組
}

void convert(int i_lines, int i_cols, int (*iap_digital)[i_cols], char (* chap_string)[i_cols + 1])
{
    int i_r, i_c;

    for (i_r = 0; i_r < i_lines; i_r++)
    {
        for (i_c = 0; i_c < i_cols; i_c++)
           *(*(chap_string + i_r) + i_c) = *(cchp_trans + *(*(iap_digital + i_r) + i_c));       // 將整數數組元素當做字符數組(字符串)的索引

        *(*(chap_string + i_r) + i_c) = '\0';                                       // 第 COLS + 1 個放一個空字符， 使成為字符串
    }
}
