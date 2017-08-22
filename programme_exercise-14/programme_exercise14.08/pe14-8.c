/* pe14-8.c -- 以下是標準答案跟題目要求的有點區別 */
/* 1. 此程序會使用 air.dat 讀取數據， 如果沒有改文件則由用戶輸入。
 * 最後亦會寫入到 air.dat 文件。
 * 2. 選擇菜單輸入的是 o、e、l、a、d 和 q。
 * 3. 排序是按顧客的姓氏的首字母的。
 * 4. 此程序菜單的'a'和'd'說明跟 c primer plus 英中文五、六版不同。
 * 很多時候不是不會做， 而是題目講的不過清楚，或者是我理解能力太低
 * 了。不過我還是推薦此版本。多看別人寫的代碼還是很有好處的, 本人
 * 也修復了幾個bug。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEN      14
#define SEATS    12
#define EMPTY    0
#define TAKEN    1
#define CONTINUE 1
#define DONE     0

struct plane_stats
{
    int seat_id;
    int status;
    char last[LEN];
    char first[LEN];
};

/* 模塊化很好， 特別函數與函數間的調用 */
int get_menu(void);
int get_let(const char *);
int openings(const struct plane_stats[], int);
void show_empties(const struct plane_stats[], int);
void list_assign(struct plane_stats * [], int);
void assign_seat(struct plane_stats[], int);
void delete_seat(struct plane_stats[], int);
void show_seats(const struct plane_stats[], int);
void sort(struct plane_stats * [], int);
void make_list(const struct plane_stats[], char *, int);
char * s_gets(char *, int);

int main(void)
{
    struct plane_stats plane_1[SEATS], * ps[SEATS];
    int choice;
    int i;
    FILE * file_pointer;
    size_t size = sizeof(struct plane_stats);

    for (i = 0; i < SEATS; i++)
        ps[i] = &plane_1[i];

    if ((file_pointer = fopen("air.dat", "rb")) == NULL)
        for (i = 0; i < SEATS; i++)
        {
            plane_1[i].status = EMPTY;
            plane_1[i].seat_id = i + 1;
        }
    else
    {
        fread(plane_1, size, SEATS, file_pointer);
        fclose(file_pointer);
    }

    while ((choice = get_menu()) != 'q')
    {
        switch (choice)
        {
        case 'o':
            printf("There are %d empty seats.\n", openings(plane_1, SEATS));
            break;
        case 'e':
            show_empties(plane_1, SEATS);
            break;
        case 'l':
            list_assign(ps, SEATS);
            break;
        case 'a': 
            assign_seat(plane_1, SEATS);
            break;
        case 'd':
            delete_seat(plane_1, SEATS);
            break;
        default:
            puts("Switch trouble");
            break;
        }
    }
    if ((file_pointer = fopen("air.dat", "wb")) == NULL)
        puts("Can't save data to file.");
    else
    {
        fwrite(plane_1, size, SEATS, file_pointer);
        fclose(file_pointer);
    }
    puts("Bye from colossus Airlines!");

    return 0;
}

#define CHOICES 6
int get_menu(void)
{
    const char * descript[CHOICES] =
    {
        "Show number of empty seats",
        "Show list of empty seats",
        "Show alphabetical list of seat assignments",
        "Assign a customer to a seat",
        "Delete a seat assignment",
        "Quit"
    };
    const char labels[CHOICES + 1] = "oeladq";
    int i;

    puts("To choose a function, enter its letter label");
    for (i = 0; i < CHOICES; i++)
        printf("%c) %s\n", labels[i], descript[i]);

    return get_let(labels);
}

int get_let(const char * string)
{
    char character;

    character = tolower(getchar());
    while (strchr(string, character) == NULL)
    {
        printf("Enter a character in the list %s\n", string);
        while (getchar() != '\n')
            continue;
        character = tolower(getchar());
    }
    while (getchar() != '\n')
        continue;

    return character;
}

int openings(const struct plane_stats pl[], int n)
{
    int count = 0;
    int seat;

    for (seat = 0; seat < n; seat++)
        if (pl[seat].status == EMPTY)
            count++;

    return count;
}

void show_empties(const struct plane_stats pl[], int n)
{
    char seating[3 * SEATS];        // 其實 SEATS * 2 + 1 就夠了

    if (openings(pl, n) == 0)
        puts("All seats are assigned");
    else
    {
        puts("The following seats are available:");
        make_list(pl, seating, EMPTY);
        puts(seating);
    }
}

void make_list(const struct plane_stats pl[], char * string, int kind)
{
    int seat;
    char temp[LEN];     // 其實設置 4 就夠了

    string[0] = '\0';
    for (seat = 0; seat < SEATS; seat++)
        if (pl[seat].status == kind)
        {
            sprintf(temp, " %d", pl[seat].seat_id);
            strcat(string, temp);
        }
}

void list_assign(struct plane_stats * ps[], int n)
{
    int i;
    if (openings(*ps, n) == SEATS)
        puts("All seats are empty.");
    else
    {
        sort(ps, n);
        for (i = 0; i < n; i++)
            if (ps[i]->status == TAKEN)
                printf("Seat %d: %s, %s\n", ps[i]->seat_id, ps[i]->first, ps[i]->last);
    }
}

void assign_seat(struct plane_stats pl[], int n)
{
    char list[3 * SEATS];
    int seat, loop;

    if (openings(pl, n) == EMPTY)
        puts("All seat are assigned.");
    else
    {
        make_list(pl, list, EMPTY);
        puts("Which seat do you want? Choose from this list:");
        puts(list);

        do
        {
            while (scanf("%d", &seat) != 1)
            {
                scanf("%*s");
                puts("Enter a number from this list:");
                puts(list);
            }

            if (seat < 1 || seat > SEATS || pl[seat - 1].status == TAKEN)
            {
                puts("Enter a number from this list:");
                puts(list);
                loop = CONTINUE;
            }
            else
                loop = DONE;
        } while (loop == CONTINUE);
        while (getchar() != '\n')
            continue;

        puts("Enter first name:");
        s_gets(pl[seat - 1].first, LEN);
        puts("Enter lase name:");
        s_gets(pl[seat - 1].last, LEN);

        printf("%s %s assigned to seat %d.\n", pl[seat - 1].first, pl[seat - 1].last, pl[seat - 1].seat_id);
        puts("Enter a to accept asssignment, c to cancel it.");
        if (get_let("ac") == 'a')
        {
            pl[seat - 1].status = TAKEN;
            puts("Passenger assigned to seat.");
        }
        else
            puts("Passenget not assigned.");
    }
}

void delete_seat(struct plane_stats pl[], int n)
{
    int seat, loop;
    char list[3 * SEATS];

    if (openings(pl, n) == SEATS)
        puts("All seats alredy are empty.");
    else
    {
        show_seats(pl, n);
        make_list(pl, list, TAKEN);
        
        puts("Enter the number of the seat to be cancelled:");
        do
        {
            while (scanf("%d", &seat) != 1)
            {
                scanf("%*s");
                puts("Enter a number from this list:");
                puts(list);
            }
            if (1 > seat || 12 < seat || pl[seat - 1].status == EMPTY)
            {
                puts("Enter a number from this list:");
                puts(list);
                loop = CONTINUE;
            }
            else
                loop = DONE;
        } while (loop == CONTINUE);
        while (getchar() != '\n')
            continue;

        printf("%s %s to be cancelled for seat %d.\n", pl[seat - 1].first, pl[seat - 1].last, pl[seat - 1].seat_id);
        puts("Enter d to delete assignment, a to abort.");
        if (get_let("da") == 'd')
        {
            pl[seat - 1].status = EMPTY;
            puts("Passenger dropped.");
        }
        else
            puts("Passenger retained.");
    }
}

void show_seats(const struct plane_stats pl[], int n)
{
    int i;

    puts("Seats currently taken");
    for (i = 0; i < n; i++)
        if (pl[i].status == TAKEN)
            printf("Seat %d: %s, %s\n", pl[i].seat_id, pl[i].last, pl[i].first);
}

void sort(struct plane_stats * array[], int limit)
{
    int top, search;
    struct plane_stats * temp;

    for (top = 0; top < limit - 1; top++)
        for (search = top + 1; search < limit; search++)
            if (strcmp(array[search]->last, array[top]->last) < 0)
            {
                temp = array[search];
                array[search] = array[top];
                array[top] = temp;
            }
}

char * s_gets(char * string, int n)
{
    char * return_value;
    char * find;

    return_value = fgets(string, n, stdin);
    if (return_value)
    {
        find = strchr(string, '\n');        // look for newline
        if (find)                           // if the address is not NULL,
            *find = '\0';                   // place a null character there
        else
            while (getchar() != '\n')
                continue;                   // dispose of rest of line
    }

    return return_value;
}
