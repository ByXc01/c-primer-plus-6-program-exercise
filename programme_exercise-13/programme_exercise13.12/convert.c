/* File: convert.c
 * Author: ByXc
 * About: Digital convert picture.
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170718
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */
/*
#include <stdio.h>
#include <stdlib.h>     // 为了 exit(), malloc(), calloc() 提供原型, 为 EXIT_FAILURE 提供宏

#define ROWS 20
#define COLS 30

void convert(int (*)[COLS], char (*)[COLS + 1], int);
void initialization(FILE *, int (*)[COLS], int);

int main(void)
{
    FILE * fp_input, * fp_output;
    const char * cchp_input_name = "sample_input_text";
    const char * cchp_output_name = "picture";
    // 使用 malloc() 和 calloc() 纯粹为了熟悉一下用法
    int (* iap_number)[COLS] = (int (*)[COLS]) malloc(ROWS * COLS * sizeof(int));
    char (* chap_string)[COLS + 1] = (char (*)[COLS + 1]) calloc(ROWS * COLS + sizeof(char) * ROWS, sizeof(char));
    int i_row;

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

    initialization(fp_input, iap_number, ROWS);                                     // 給數組初始化文件的內容
    convert(iap_number, chap_string, ROWS);                                         // 將對應的數字轉換為字符串
    
    for (i_row = 0; i_row < ROWS; i_row++)
        fprintf(fp_output, "%s\n", *(chap_string + i_row));                         // 輸出至文件
    
    // 檢查關閉錯誤
    if (fclose(fp_input) != 0)
        fprintf(stderr, "Error in closing \"%s\"\n", cchp_input_name);
    if (fclose(fp_output) != 0)
        fprintf(stderr, "Error in closing \"%s\" file.\n", cchp_output_name);

    return 0;
}

void initialization(FILE * fp_file, int (* iap_pointer)[COLS], int i_line)
{
    int i_row, i_col;

    // 以下用指針表示法可能看起來比較複雜
    for (i_row = 0; i_row < i_line; i_row++)
        for (i_col = 0; i_col < COLS; i_col++)
            fscanf(fp_file, "%d", &*(*(iap_pointer + i_row) + i_col));              // 從文件讀取數據到數組
}

void convert(int (*iap_digital)[COLS], char (* chap_string)[COLS + 1], int i_line)
{
    int i_row, i_col;

    for (i_row = 0; i_row < i_line; i_row++)
    {
        for (i_col = 0; i_col < COLS; i_col++)
        {
            switch (*(*(iap_digital + i_row) + i_col))         // 用 switch() 篩選
            {
                case 0:
                    *(*(chap_string + i_row) + i_col) = ' ';   // 0 對應空格 
                    break;
                case 1:
                    *(*(chap_string + i_row) + i_col) = '.';   // 1 對應點
                    break;
                case 2:
                    *(*(chap_string + i_row) + i_col) = '\'';  // 2 對應 '
                    break;
                case 3:
                    *(*(chap_string + i_row) + i_col) = ':';   // 3 對應 :
                    break;
                case 4:
                    *(*(chap_string + i_row) + i_col) = '~';   // 4 對應 ~
                    break;
                case 5:
                    *(*(chap_string + i_row) + i_col) = '*';   // 5 對應 *
                    break;
                case 6:
                    *(*(chap_string + i_row) + i_col) = '=';   // 6 對應 =
                    break;;
                case 7:
                    *(*(chap_string + i_row) + i_col) = ' ';   // 7 沒有對應任何一個字符
                    break;
                case 8:
                    *(*(chap_string + i_row) + i_col) = '%';   // 8 對應 %
                    break;
                case 9:
                    *(*(chap_string + i_row) + i_col) = '#';   // 9 對應 #
                    break;
                default:
                    puts("There is no such character!");
                    break;
            }
        }
        *(*(chap_string + i_row) + i_col) = '\0';              // 第 COLS + 1 個放一個空字符， 使成為字符串
    }
}
*/

/* 因本人做的太複雜了， 推薦以下的標準答案 */
/* Programming Exercise 13-12 */

#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 30
#define LEVEL 10

const char trans[LEVEL + 1] = " .':~*=&%#";        // 答案錯了, 9 對應的應該是 #，已修正。& 應該是佔位符

void make_picture(int data[][COLS], char pic[][COLS], int row);
void initialization(char arr[][COLS], char ch);

int main(void)
{
    int row, col;
    int pictureInput[ROWS][COLS];
    char pictureOutput[ROWS][COLS];
    char fileName[81];
    FILE * inputFile;

    initialization(pictureOutput, 'S');

    printf("Enter name of file: ");
    scanf("%80s", fileName);
    if ((inputFile = fopen(fileName, "r")) == NULL)
    {
        fprintf(stderr, "Could not open data file.\n");
        exit(EXIT_FAILURE);
    }

    for (row = 0; row < ROWS; row++)
        for (col = 0; col < COLS; col++)
            fscanf(inputFile, "%d", &pictureInput[row][col]);

    if (ferror(inputFile))
    {
        fprintf(stderr, "Error getting data from file.\n");
        exit(EXIT_FAILURE);
    }
    make_picture(pictureInput, pictureOutput, ROWS);

    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
            putchar(pictureOutput[row][col]);     // 標準答案是輸出到屏幕而不是文件, 懶得更改了。請參照本人的程序
        putchar('\n');
    }

    return 0;
}

void initialization(char arr[][COLS], char ch)
{
    int r, c;
    
    for (r = 0; r < ROWS; r++)
        for (c = 0; c < COLS; c++)
            arr[r][c] = ch;
}

void make_picture(int data[][COLS], char picture[][COLS], int rows)
{
    int row, col;

    for (row = 0; row < rows; row++)
        for (col = 0; col < COLS; col++)
            picture[row][col] = trans[data[row][col]];      // 把整數數組元素當做字符數組的索引，這裡用的妙
}
