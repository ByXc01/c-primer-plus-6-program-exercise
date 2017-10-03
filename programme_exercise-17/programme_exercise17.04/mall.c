/* mall.c -- 使用 Queue 接口 */
/* 和 queue.c 一起編譯       */ 

#include <stdio.h>
#include <stdlib.h>                 // 提供 rand() 和 srand() 的原型，RAND_MAX 宏
#include <time.h>                   // 提供 time() 的原型
#include "queue.h"                  // 提供 Item、Queue 類型定義和一系列接口函數

#define MINUTE_PER_HOUR 60.0

bool new_customer(double x);        // 是否有新顧客要來？
Item customer_time(long when);      // 設置顧客參數

int main(void)
{
    Queue line1;                    // 攤位 1
    Queue line2;                    // 攤位 2

    Item temp;                      // 新的顧客數據
    int hours;                      // 模擬的小時數
    int per_hour;                   // 每小時平均多少位顧客
    long cycle, cycle_limit;        // 循環計數器、計數器的上限
    long turnaways = 0;             // 因隊列已滿被拒的顧客數量
    long customers = 0;             // 加入隊列的顧客數量
    long served = 0;                // 在模擬期間咨詢過的的顧客數量
    long sum_line = 0;              // 累計隊列的總長
    int wait_time1 = 0, wait_time2; // 每個攤位的每位顧客等待咨詢的時間
    double minute_per_customer;     // 顧客到來的平均時間
    long line_wait = 0;             // 隊列類型的等待時間
    
    InitializeQueue(&line1);
    InitializeQueue(&line2);
    srand((unsigned int) time(0));  // 初始化隨機種子

    puts("Case Study: Sigmund Lander's Advice Booth");
    puts("Enter the number of simulation hours:");
    scanf("%d", &hours);
    cycle_limit = MINUTE_PER_HOUR * hours;

    puts("Enter the average number of customer per hour:"); 
    scanf("%d", &per_hour);
    minute_per_customer = MINUTE_PER_HOUR / per_hour;

    for (cycle = 0; cycle < cycle_limit; cycle++)
    {
        if (new_customer(minute_per_customer))
        {
            if (QueueIsFull(&line1) && QueueIsFull(&line2))
                turnaways++;
            else
            {
                customers++;
                temp = customer_time(cycle);

                if (QueueIsFull(&line1))                // 如果攤位 1 排滿隊伍了
                    EnQueue(temp, &line2);              // 安排顧客去攤位 2
                else                                    // 攤位 1 未排滿
                    EnQueue(temp, &line1);              // 安排顧客去攤位 1
            }
        }

        /* 因為攤位 1 和攤位 2 的每一位顧客咨詢的咨詢時間都是隨機的，所以必須分開計算 */
        if (wait_time1 <= 0 && !QueueIsEmpty(&line1))
        {
            DeleteQueue(&temp, &line1);
            wait_time1 = temp.process_time;
            line_wait += cycle - temp.arrive;
            served++;
        }
        if (wait_time2 <= 0 && !QueueIsEmpty(&line2))
        {
            DeleteQueue(&temp, &line2);
            wait_time2 = temp.process_time;
            line_wait += cycle - temp.arrive;
            served++;
        }

        if (wait_time1 > 0)
            wait_time1--;
        if (wait_time2 > 0)
            wait_time2--;

        sum_line += QueueItemCount(&line1);
        sum_line += QueueItemCount(&line2);
    }

    if (customers > 0)
    {
        printf("customers accepted: %ld\n", customers);
        printf("  customers served: %ld\n", served);
        printf("          turnaway: %ld\n", turnaways);
        printf("average queue size: %.2f\n", (double) sum_line / cycle_limit);
        printf(" average wait time: %.2f minutes\n", (double) line_wait / served);
    }
    else
        puts("Node customers!");
    EmptyTheQueue(&line1);
    EmptyTheQueue(&line2);
    puts("Bye!");

    return 0;
}

// x 是顧客到來的平均時間（單位：分鐘）
// 如果 1 分鐘內有顧客到來，則返回 true
bool new_customer(double x)
{
    if(rand() * x / RAND_MAX < 1)
        return true;
    else
        return false;
}

// when 是顧客到來的時間
// 該函數返回一個 Item 結構，該函數到來的時間設置為 when，
// 咨詢的之間設置為 1 ~ 3 的隨機值
Item customer_time(long when)
{
    Item customer;

    customer.process_time = rand() % 3 + 1;
    customer.arrive = when;

    return customer;
}
