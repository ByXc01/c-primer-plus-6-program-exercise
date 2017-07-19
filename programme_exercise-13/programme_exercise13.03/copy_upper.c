/* File: copy_upper.c
 * Author: ByXc
 * About: 中文第六版的這一題好像翻譯錯誤或其它原因，已按照中文第五的的要求來做
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170716
 * Github: ByXc01
 * Blog: http://Github.github.io
 */

#include <stdio.h>
#include <stdlib.h>     // 為 exit() 提供原型, 為 EXIT_FAILURE 提供宏
#include <ctype.h>      // 為 toupper() 提供原型

#define LENGTH 40

int main(void)
{
   FILE * fp_input, * fp_output;
   int i_character;
   char cha_sourcefile[LENGTH], cha_targetfile[LENGTH];

   puts("Please enter source filename.");
   scanf("%40s", cha_sourcefile);
   puts("Please enter target filename.");
   scanf("%40s", cha_targetfile);

   if ((fp_input = fopen(cha_sourcefile, "r")) == NULL)
   {
       fprintf(stderr, "Can't open %s.\n", cha_sourcefile);
       exit(EXIT_FAILURE);
   }

   if ((fp_output = fopen(cha_targetfile, "w")) == NULL)
   {
       fprintf(stderr, "Can't create output file %s.\n", cha_targetfile);
       exit(2);
   }

   while ((i_character = getc(fp_input)) != EOF)
       putc(toupper(i_character), fp_output);

   if (fclose(fp_input) != 0)
       fprintf(stderr, "Could not close file %s", cha_sourcefile);
   if (fclose(fp_output) != 0)
       fprintf(stderr, "Could not close file %s.", cha_targetfile);

   return 0;
}
