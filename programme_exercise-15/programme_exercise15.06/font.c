/* File: font.c
 * Author: ByXc
 * About: setting font
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170903
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

/* “該程序要使用按位與運算符(&)和合適的掩碼來把字體ID和字體大小
 * 信息轉換到指定的範圍。” 因這句話沒看懂什麼意思，有沒有標準答
 * 案，所以我是瞎寫的。只要不作死，不按要求輸入，程序是沒問題的，
 * 否則後果自負。但我能保證的是字體ID和字體大小值不會超出範圍。
 */

#include <stdio.h>
#include <stdbool.h>        // for bool、true、false
#include <ctype.h>          // for tolower()
#include <string.h>         // for strchr()

#define ID_MASK    0XFF
#define SIZE_MASK  0x7F

struct font
{
    unsigned int font_id    : 8;
    unsigned int font_size  : 7;
    unsigned int alignment  : 2;
    bool bold               : 1;
    bool italic             : 1;
    bool underline          : 1;
};

void info_menu(const struct font *);
void clean(void);
char get_let(const char *);

int main(void)
{
    struct font font_info = { 1, 12, 0, false, false, false };
    char ch_choice;
    unsigned ui_id, ui_size;

    info_menu(&font_info);
    while ((ch_choice = get_let("fsabiuq")) != 'q')
    {
        switch (ch_choice)
        {
            case 'f': 
                printf("Enter font id(0-255): ");
                scanf("%u", &ui_id);
                clean();                                    // 把 scanf() 留在緩衝區的換行符清除
                font_info.font_id = ID_MASK & ui_id;        // 轉換到指定的範圍（其實我不太清楚這話的意思）
                break;
            case 's': 
                printf("Enter font size(0-127): ");
                scanf("%u", &ui_size);
                clean();                                    // 把 scanf() 留在緩衝區的換行符清除
                font_info.font_size = SIZE_MASK & ui_size;
                break;
            case 'a': 
                puts("Select alignment:");
                puts("l)left    c)center    r)right");
                switch (get_let("lcr"))                     // 嵌套 switch，不推薦。我是懶得寫函數了。
                {
                    case 'l': font_info.alignment = 0; break;
                    case 'c': font_info.alignment = 1; break;
                    case 'r': font_info.alignment = 2; break;
                }
                break;
            case 'b': font_info.bold = !font_info.bold; break;
            case 'i': font_info.italic = !font_info.italic; break;
            case 'u': font_info.underline = !font_info.underline; break;
        }
        info_menu(&font_info);
    }
    puts("Bye!");

    return 0;
}

void info_menu(const struct font * st_pointer)
{
    puts("  ID SIZE ALIGNMENT  B   I   U");
    printf("%4u %4u ", st_pointer->font_id, st_pointer->font_size);
    switch (st_pointer->alignment)
    {
        case 0:  printf("%6s ", "letf"); break;
        case 1:  printf("%6s ", "center"); break;
        case 2:  printf("%6s ", "right"); break;
        default: printf("Unknow type!");
    }
    printf("%6s ", st_pointer->bold ? "on" : "off");
    printf("%3s ", st_pointer->italic ? "on" : "off");
    printf("%3s\n\n", st_pointer->underline ? "on" : "off");

    puts("f)change font    s)change size    a)change alignment");
    puts("b)toggle bold    i)toggle italic  u)toggle underline");
    puts("q)quit");
}

void clean(void)
{
    while (getchar() != '\n')
        continue;
}

char get_let(const char * chp_string)
{
    char ch_character;

    ch_character = tolower(getchar());      // 為了更好的比較，轉換為小寫
    while (strchr(chp_string, ch_character) == NULL)
    {
        printf("Enter a character in the list %s\n", chp_string);
        clean();
        ch_character = tolower(getchar());
    }
    clean();

    return ch_character;
}

