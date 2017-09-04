/* File: font2.c
 * Author: ByXc
 * About: setting font
 * Version: 2.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170903
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

/* 終於做好了:)！！剛開始覺得不用字段做很麻煩。一度想放棄了。
 * 在寫宏的時候因不太熟悉二進制，折騰了好久。後來又因小問題
 * 調試了了好久。終於皇天不負有心人。附上標準答案，寫比我好
 * 多了（缺乏開發經驗），模塊化編程，不像我在main()寫這麼多。
 * 顯得臃腫。
 */

#include <stdio.h>
#include <ctype.h>      // for tolower()
#include <string.h>     // for strchr()

#define ID_MASK    0xFF
#define SIZE_MASK  0x7F00
#define ALIGN_MASK 0x18000

#define LEFT       0x0000
#define CENTER     0x8000
#define RIGHT      0X10000

#define BOLD       0x20000
#define ITALIC     0x40000
#define UNDERLINE  0X80000

void info_menu(unsigned long);
void clean(void);
char get_let(char *);

int main(void)
{
    unsigned long ul_font_info = 0xc01;
    char ch_choice;
    unsigned long ul_id, ul_size;

    info_menu(ul_font_info);
    while ((ch_choice = get_let("fsabiuq")) != 'q')
    {
        switch (ch_choice)
        {
            case 'f':
                printf("Enter font id(0-255): ");
                scanf("%lu", &ul_id);
                clean();                            // 把 scanf() 留在緩衝的換行符清除

                ul_font_info &= ~ID_MASK;           // 將 ID 部分清零
                ul_font_info |= (ID_MASK & ul_id);  // 控制 ID 範圍并賦值
                break;
            case 's':
                printf("Enter font size(0-127): ");
                scanf("%lu", &ul_size);
                clean();
                ul_font_info &= ~SIZE_MASK;         // 將 size 部分清零
                ul_font_info |= (ul_size << 8);     // 為 size 部分賦值
                break;
            case 'a':
                puts("Select alignment:");
                puts("l)left    c)center    r)right");
                ul_font_info &= ~ALIGN_MASK;        // 將 alignment 部分清零
                switch(get_let("lcr"))
                {
                    case 'l': ul_font_info |= LEFT; break;
                    case 'c': ul_font_info |= CENTER; break;
                    case 'r': ul_font_info |= RIGHT; break;
                }
                break;
            case 'b': ul_font_info ^= BOLD; break;  // 用按位異或控制開關
            case 'i': ul_font_info ^= ITALIC; break;
            case 'u': ul_font_info ^= UNDERLINE; break;
        }
        info_menu(ul_font_info);
    }
    puts("Bye!");

    return 0;
}

void info_menu(unsigned long ul_font)
{
    puts("  ID SIZE ALIGNMENT  B   I   U");
    printf("%4lu %4lu ", ul_font & ID_MASK, (ul_font >> 8) & ID_MASK);
    switch (ul_font & ALIGN_MASK)
    {
        case LEFT:   printf("%6s ", "left"); break;
        case CENTER: printf("%6s ", "center"); break;
        case RIGHT:  printf("%6s ", "right"); break;
        default:     printf("Unknown type!!");
    }
    printf("%6s ", (ul_font & BOLD) == BOLD ? "no" : "off");
    printf("%3s ", (ul_font & ITALIC) == ITALIC ? "no" : "off");
    printf("%3s\n\n", (ul_font & UNDERLINE) == UNDERLINE ? "no" : "off");

    puts("f)change font    s)change size    a)change alignment");
    puts("b)toggle bold    i)toggle italic  u)toggle underline");
    puts("q)quit");
}

void clean(void)
{
    while (getchar() != '\n')
        continue;
}

char get_let(char * chp_string)
{
    char ch_character;

    ch_character = tolower(getchar());       // 為了更好的比較，轉換為小寫
    while (strchr(chp_string, ch_character) == NULL)
    {
        printf("Enter a character in the list %s\n", chp_string);
        clean();
        ch_character = tolower(getchar());
    }
    clean();

    return ch_character;
}
