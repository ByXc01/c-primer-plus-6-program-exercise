/* FIle: seat_reservation2.c
 * Author: ByXc
 * About: seat reservation procedure, add flight.
 * Version: 2.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170820
 * Github: ByXc
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <ctype.h>      // 為 tolower() 提供函數原型
#include <string.h>     // 為 strcmp() 和 strchr() 提供函數原型
#include <stdbool.h>    // 為了使用 bool， 為 true 和 false 提供宏

#define SEAT_MAX 12
#define NAME_MAX 15
#define FLIGHT 4

struct info
{
    int i_number;
    bool b_reserved;
    struct { char cha_first_name[NAME_MAX], cha_last_name[NAME_MAX]; };     // 匿名結構
};

struct flight                                                               // 航班
{
    struct info plane[SEAT_MAX];
    bool b_confirm;
};

void home_page(void);
void menu(void);
char get_let(const char *);
int choice(char);                                                           // 讀入字符，返回當前字符索引
void initialization(struct info *, struct info *[], int);                   // 初始化
void get_data(struct info *, struct flight *, int);                         // 將已經保存的航班信息賦值給目標數組。但有可能初始化兩次
char * s_gets(char *, int);

int empty_seat(const struct info *, int);                                   // 輸出空座位總數
void empty_seat_list(const struct info *, int);                             // 輸出空座位列表
void make_list(const struct info *, char *, bool);                          // 製作一個列表
void alphabetical(struct info *[], int);                                    // 按首名字排序
void add_customer(struct info *, int);                                      // 增加一個旅客
void delete_customer(struct info *,int);                                    // 刪除一個旅客
void confirm_assign(struct flight *, const struct info *, int);             // 確定座位分配，即確定某個航班的信息

int main(void)
{
    struct info seats[SEAT_MAX];                                    // 為了兼容性上一版， 不做太多改變
    struct info * sort[SEAT_MAX];                                   // 儲存排序后的結構指針
    static struct flight page[FLIGHT];                              // 靜態儲存期，無鏈接。我要利用的是特性是：沒有初始化，值會是是零
    char ch_letter, ch_alpha;
    int i_index;

    home_page();
    while ((ch_alpha = get_let("abcde")) != 'e')
    {
        initialization(seats, sort, SEAT_MAX);
        i_index = choice(ch_alpha);
        get_data(seats, &page[i_index], SEAT_MAX);
        menu();

        while ((ch_letter = get_let("abcdefg")) != 'g')
        {
            switch (ch_letter)
            {
                case 'a':
                    printf("There are %d empty seats.\n", empty_seat(seats, SEAT_MAX));
                    break;
                case 'b':
                    empty_seat_list(seats, SEAT_MAX);
                    break;
                case 'c':
                    alphabetical(sort, SEAT_MAX);
                    break;
                case 'd':
                    add_customer(seats, SEAT_MAX);
                    break;
                case 'e':
                    delete_customer(seats, SEAT_MAX);
                    break;
                case 'f':
                    confirm_assign(&page[i_index], seats, SEAT_MAX);
                    break;
            }
            choice(ch_alpha);
            menu();
        }
        home_page();
    }
    puts("Bye from Colossus Airlines!");

    return 0;
}

void home_page(void)
{
    puts("Please select a flight:");
    puts("a) 102 flight");
    puts("b) 311 flight");
    puts("c) 444 flight");
    puts("d) 519 flight");
    puts("e) Quit");
}

int choice(char ch_alpha)
{
    int i_count;

    switch (ch_alpha)
    {
        case 'a':
            puts("102 flight");
            break;
        case 'b':
            puts("311 flight");
            break;
        case 'c':
            puts("444 flight");
            break;
        case 'd':
            puts("519 flight");
            break;
    }

    for (i_count = 0; 'a' + i_count < ch_alpha; i_count++)      // 假設字母是連續的，如果不支持就再用一個 switch 語句
        continue;

    return i_count;
}

void menu(void)
{
    puts("To choose a function, enter its letter label:");
    puts("a) Show number of empty seats");
    puts("b) Show lisst of empty seats");
    puts("c) Show alphabetical list of seats");
    puts("d) Assign a customer to a seat assigment");
    puts("e) Delet a seat assignment");
    puts("f) Confirming a seat assigment");
    puts("g) Quit");
}

char get_let(const char * chp_string)
{
    char ch_character;

    ch_character = tolower(getchar());                  // 為了更好比較，轉換為了小寫儲存
    while (strchr(chp_string, ch_character) == NULL)
    {
        printf("Enter a character in the list %s\n", chp_string);
        
        while (getchar() != '\n')
            continue;
        ch_character = tolower(getchar());
    }
    while (getchar() != '\n')
        continue;

    return ch_character;
}

void initialization(struct info * stp_seats, struct info * sta_sort[], int i_max)
{
    int i_count;

    for (i_count = 0; i_count < i_max; i_count++)
    {
        stp_seats[i_count].i_number = i_count + 1;      // 給座位編號初始化化
        stp_seats[i_count].b_reserved = false;          // 初始化為 0，表示沒人預定
        stp_seats[i_count].cha_first_name[0] = '\0';
        stp_seats[i_count].cha_last_name[0]  = '\0';
        sta_sort[i_count] = &stp_seats[i_count];        // 初始化結構指針數組
    }
}

int empty_seat(const struct info * cstp_seat, int i_max)
{
    int i_count, i_index;

    for (i_index = i_count = 0; i_index < i_max; i_index++)
        if (!cstp_seat[i_index].b_reserved)             // 遍歷所有未預定的位置
            i_count++;

    if (i_count == 0)
        puts("Sorry, the seats are full!");
    
    return i_count;
}

void empty_seat_list(const struct info * cstp_seat, int i_max)
{
    char cha_seating[2 * SEAT_MAX + 1];

    if (empty_seat(cstp_seat, i_max) == 0)              // 如果一個空位都沒有
        puts("Sorry, the seats are full!");
    else
    {
        puts("The following seats are available:");
        make_list(cstp_seat, cha_seating, false);
        puts(cha_seating);
    }
}

void make_list(const struct info cstp_seat[], char * chp_string, bool b_flag)
{
    int i_count;
    char cha_temp[SEAT_MAX];

    chp_string[0] = '\0';
    for (i_count = 0; i_count < SEAT_MAX; i_count++)
        if (cstp_seat[i_count].b_reserved == b_flag)        // 按照 b_flag 狀態製作列表
        {
            sprintf(cha_temp, " %d", cstp_seat[i_count].i_number);
            strcat(chp_string, cha_temp);
        }
}

void alphabetical(struct info * sta_sort[], int i_max)
{
    int i_count , i_index;
    struct info * stp_temp;

    if (empty_seat(*sta_sort, i_max) == i_max)                  // 如果全都是空位
        puts("Sorry, all seats are not booked!");
    else
    {
        for (i_count = 0; i_count < i_max - 1; i_count++)       // 將顧客的名字的第一個字符按 ASCII 碼排序
            for (i_index = i_count + 1; i_index < i_max; i_index++)
                // 結構的標誌，狀態都必須要已預訂，且升序排序
                if ((sta_sort[i_count]->b_reserved && sta_sort[i_index]->b_reserved) && (strcmp(sta_sort[i_count]->cha_first_name, sta_sort[i_index]->cha_first_name) > 0))
                {
                    stp_temp = sta_sort[i_count];
                    sta_sort[i_count] = sta_sort[i_index];
                    sta_sort[i_index] = stp_temp;
                }
    }
    
    for (i_count = 0; i_count < i_max; i_count++)              // 將排序好的內容輸出
        if (sta_sort[i_count]->b_reserved)
            printf("customer: %s %s, seat mumber: %d.\n", sta_sort[i_count]->cha_first_name, sta_sort[i_count]->cha_last_name, sta_sort[i_count]->i_number);
}

void add_customer(struct info * stp_seat, int i_max)
{
    int i_number;
    bool b_flag;
    char cha_list[2 * SEAT_MAX + 1];

loop:
    if (empty_seat(stp_seat, i_max) == 0)                      // 如果一個空位都沒有， 說明已滿
        puts("All seats are assigned.");
    else
    {
        make_list(stp_seat, cha_list, false);
        puts("Which seat to you want? choose from shis list:");
        puts(cha_list);
        do 
        {
            while (scanf("%d", &i_number) != 1)                 // 捕捉非法輸入
            {
                scanf("%*s");
                puts("Enter a number from this list:");
                empty_seat_list(stp_seat, i_max);
            }
                                                                // 檢測範圍和是否有人預定
            if (i_number < 1 || i_number > 12 || stp_seat[i_number - 1].b_reserved) 
            {
                puts("Enter a number from this list:");
                puts(cha_list);
                b_flag = true;
            }
            else
                b_flag = false;
        } while (b_flag);
        
        while (getchar() != '\n')
            continue;

        // 輸入姓名
        puts("Please enter the first name of the reservation person:");
        s_gets(stp_seat[i_number - 1].cha_first_name, NAME_MAX);
        puts("Please enter the lase name of the resveration person:");
        s_gets(stp_seat[i_number - 1].cha_last_name, NAME_MAX);

        puts("Enter a to accept assignment, c to cancel it.");
        if (get_let("ac") == 'a')
        {
            stp_seat[i_number - 1].b_reserved = true;
            puts("Passenger assigned to seat.");
        }
        else
            puts("Passenger not assigned.");

        puts("Do you want to continue to add?<y/n>");
        if (get_let("yn") == 'y')
            goto loop;
    }
}

void delete_customer(struct info * stp_seat, int i_max)
{
    int i_input;
    bool b_flag;
    char cha_list[2 * SEAT_MAX + 1];
    
loop:
    if (empty_seat(stp_seat, i_max) == i_max)
        puts("Sorry, all seats are not booked!");
    else
    {
        make_list(stp_seat, cha_list, true);
        puts("Please enter the number of the seat you want to delete:");
        puts(cha_list);
        do
        {
            while (scanf("%d", &i_input) != 1)
            {
                scanf("%*s");
                puts("Please use numeric input:");
            }

            // 檢測是否超出範圍
            if (i_input < 1 || i_input > 12 || !stp_seat[i_input - 1].b_reserved)
            {
                puts("Enter a number from this list:");
                puts(cha_list);
                b_flag = true;
            }
            else
                b_flag = false;
        } while (b_flag);

        while (getchar() != '\n')
            continue;

        printf("%s %s to be canseled for seat %d.\n", stp_seat[i_input - 1].cha_first_name, stp_seat[i_input - 1].cha_last_name, stp_seat[i_input - 1].i_number);  
        puts("Enter d to delete assignment, a to abort.");
        if (get_let("da") == 'd')
        {
            stp_seat[i_input - 1].b_reserved = false;       // 其實并沒有刪除， 只是改變了預定狀態
            puts("Deleted Success!");

            puts("Do you want to continue to delete?<y/n>:");
            if (get_let("yn") == 'y')
                goto loop;
        }
        else
        {
            puts("Passenger assigned to seat.");
            puts("Do you want to continue to delete?<y/n>:");
            if (get_let("yn") == 'y')
            goto loop; 
        }
    }
}

char * s_gets(char * chp_string, int i_max)
{
    char * chp_return_value, * chp_find;

    chp_return_value = fgets(chp_string, i_max, stdin);
    if (chp_return_value)
    {
        chp_find = strchr(chp_string, '\n');    // look for newline
        if (chp_find)                           // if the address is not NULL
            *chp_find = '\0';                   // place a null character there
        else
            while (getchar() != '\n')
                continue;                       // dispose of rest of line
    }

    return chp_return_value;
}

void confirm_assign(struct flight * stp_targer, const struct info * cstp_source, int i_limit)
{
    int i_count;

    if (empty_seat(cstp_source, i_limit) == i_limit)                // 如果全都空的就不用儲存了
        puts("The save failed because the data is empty!");
    else
    {
        for (i_count = 0; i_count < i_limit; i_count++)             // 將數據賦值個給航班信息
            if (cstp_source[i_count].b_reserved)
            {
                stp_targer->b_confirm = true;
                stp_targer->plane[i_count] = cstp_source[i_count];  // 結構可以直接賦值
            }
        puts("Saved success!");
    }
}

void get_data(struct info * stp_target, struct flight * stp_source, int i_limit)
{
    int i_count;

    for (i_count = 0; i_count < i_limit; i_count++)
        if (stp_source->b_confirm == true)
            stp_target[i_count] = stp_source->plane[i_count];
}
