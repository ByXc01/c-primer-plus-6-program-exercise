/*
 * Author: ByXc
 * About: command line argument version
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170716
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096
#define STRING_LENGTH 81

void append(FILE * fp_source, FILE * fp_destination);

int main(int argc, char * argv[])
{
    FILE * fp_target, * fp_source;      // 分別指向目標文件和源文件
    int i_files = 0;                    // 附加的文件數量
    int i_character;
    int i_count;

    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s [targetfile] [sourcefile]...\n", *argv);
        exit(EXIT_FAILURE);
    }

    if ((fp_target = fopen(*(argv + 1), "a+")) == NULL)
    {
        fprintf(stderr, "Can't open %s.\n", *(argv + 1));
        exit(EXIT_FAILURE);
    }

    if (setvbuf(fp_target, NULL, _IOFBF, BUFFER_SIZE) != 0)
    {
        fputs("Can't create output buffer.\n", stderr);
        exit(EXIT_FAILURE);
    }

    for (i_count = 2; i_count < argc; i_count++)
    {
        if (strcmp(*(argv + 1), *(argv + i_count)) == 0)
            fputs("Can't append file to itself\n", stderr);
        else if ((fp_source = fopen(*(argv + i_count), "r")) == NULL)
            fprintf(stderr, "Can't open %s\n.", *(argv + i_count));
        else
        {
            if (setvbuf(fp_source, NULL, _IOFBF, BUFFER_SIZE) != 0)
            {
                fputs("Can't create input buffer.\n", stderr);
                continue;
            }

            append(fp_source, fp_target);

            if (ferror(fp_source) != 0)
                fprintf(stderr, "Error in reading file %s.\n", *(argv + i_count));
            if (ferror(fp_target) != 0)
                fprintf(stderr, "Error in writing file %s.\n", *(argv + 1));

            if (fclose(fp_source) != 0)
                fprintf(stderr, "Could not close file %s.\n", *(argv + i_count));

            i_files++;
        }
    }

    printf("Done appending. %d files appended.\n", i_files);
    rewind(fp_target);

    printf("%s contents:\n", *(argv + 1));

    while ((i_character = getc(fp_target)) != EOF)
        putc(i_character, stdout);
    puts("Done displaying.");
    fclose(fp_target);

    return 0;
}

void append(FILE * fp_source, FILE * fp_destination)
{
    size_t st_bytes;
    static char cha_temp[BUFFER_SIZE];      // 只分配一次(本人覺得 static 可有可無)

    if ((st_bytes = fread(cha_temp, sizeof(char), BUFFER_SIZE, fp_source)) > 0)
        fwrite(cha_temp, sizeof(char), st_bytes, fp_destination);
}
