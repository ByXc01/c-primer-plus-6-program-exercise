/* File: strncpy.c
 * Author: ByXc
 * About: copy string
 * Version: 1.0
 * Compiler: arm-linux-androideabi-gcc 6.1.0
 * Date: 20170604
 * Github: ByXc01
 * Bolg: http://ByXc01.github.io
 */
 
#include <stdio.h>
#include <string.h>

#define POSTSCRIPT "Enter a source string, please(empty line to quit):"
#define SIZE 12

char * mystrncpy(char *, const char *, int);
char * s_gets(char *, int);

int main()
{
	char cha_target[SIZE], cha_source[SIZE];
    int i_number, i_count;

    puts(POSTSCRIPT);
    while (s_gets(cha_source, SIZE * 2) && *cha_source != '\0')         // 返回值不能為空指針且第一個字符不能是換行符
    {
        printf("Please enter a copy integer(<= %d):", SIZE); 
        while (!scanf("%d", &i_number) || i_number > SIZE)
        {
            while (getchar() != '\n')                                   // 處理錯誤輸入
                continue;

            puts("Enter error, try again!");
        }
        while (getchar() != '\n')                                       // 即使輸入成功， 但回車還留在緩衝區
            continue;

        if (mystrncpy(cha_target, cha_source, i_number))
        {
            printf("source: %s \n", cha_source);
            printf("target: ");
            for (i_count = 0; i_count < i_number; i_count++)            // 因目標字符數組可能不是一個字符串(沒用空子符)
                printf("%c", *(cha_target + i_count));
            putchar('\n');
        }

        puts(POSTSCRIPT);
    }
    puts("Bye!");

	return 0;
}

char * mystrncpy(char * chp_string, const char * cchp_source, int i_number)
{
	int i_index;

	for (i_index = 0; i_index < i_number; i_index++)
		*(chp_string + i_index) = *(cchp_source + i_index);		// 拷貝字符

	i_index = 0;
	while (*(cchp_source + i_index++))		// 統計字符
		continue;

	if (i_index < i_number)
		*(chp_string + i_index) = '\0';		// 添加空字符

	return chp_string;
}

char * s_gets(char * chp_string, int i_number)
{
    char * chp_return_value;
    char * chp_value;
    
    chp_return_value = fgets(chp_string, i_number, stdin);
    if (chp_return_value)                   // 等價于 chp_return_value != NULL
    {
        chp_value = strchr(chp_string, '\n');
        
        if (chp_value)
            *(chp_value) = '\0';            // 找到換行符替換為空字符
        else
            while (getchar() != '\n')       // 跳過剩餘的輸入
                continue;
    }

    return chp_return_value;
}
