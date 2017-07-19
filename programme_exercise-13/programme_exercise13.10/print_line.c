/* File: print_line.c
 * Author: ByXc
 * About: print line
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170717
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <stdlib.h>     // 提供 exit() 的原型

#define MAX 41

int main(void)
{
    FILE * fp_file;
    char cha_filename[MAX];
    char i_character;
    long int l_index;
    fpos_t ft_value, ft_pos;

    puts("Enter the name of the file to the processed:");
    scanf("%40s", cha_filename);

    if ((fp_file = fopen(cha_filename, "r")) == NULL)
    {
        fprintf(stderr, "Can't open \"%s\" file.\n", cha_filename);
        exit(EXIT_FAILURE);
    }

    fseek(fp_file, 0L, SEEK_END);
    if (fgetpos(fp_file, &ft_value) != 0)     // 使用 fgetpos() 和 fsetpos() 純粹為了熟悉一下用法
    {
        fprintf(stderr, "Gets the length of failure.\n");
        exit(2);
    }

    printf("Enter an index in the range 0 - %lld.\n", ft_value - 1);
    while (scanf("%ld", &l_index) == 1 && l_index >= 0 && l_index < ft_value)
    {
        ft_pos = (fpos_t) l_index;
        fsetpos(fp_file, &ft_pos);            // 定位到 ft_pos 處
         
        while ((i_character = getc(fp_file)) != EOF && i_character != '\n')
            putc(i_character, stdout);

        if (i_character != '\n')
            putchar('\n');
        else
            puts("This position is newline character.");

        puts("Next index (out of range to quit):");
    }

    if (fclose(fp_file) != 0)
        fprintf(stderr, "Error closing file \"%s\"\n", cha_filename);
    puts("Bye!");

    return 0;
}
