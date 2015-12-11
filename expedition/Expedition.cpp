#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <limits.h>
#define LOCAL
#define N 10010

using namespace std;

struct node
{
    int distance, fuel;
};

node station[N];

bool cmp(const node &n1, const node &n2)
{
    return n1.distance > n2.distance;
}

int main()
{
    #ifdef LOCAL
    freopen("data.txt", "r", stdin);
    #endif // LOCAL
    int n, l, p;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &station[i].distance, &station[i].fuel);
        }
        scanf("%d %d", &l, &p);
        sort(station, station + n, cmp);

        priority_queue<int> pq;
        int num = 0;
        int index = 0;
        pq.push(p);

        //贪心策略，每次都尽可能往前走，走到不能走的时候，中间加的油是当前经过的油站中油量最多的那个
        //注意不能缺l > 0，当中间加油站很多的情况下，pq还没有空而已经到村庄了
        while(!pq.empty() && l > 0)
        {
            int tmp = pq.top();
            pq.pop();
            l = l - tmp;
            //不能这么写！这样可能会把之前pop出去值再加入，只能不停往后走！
//            for(int i = 0; i < n; i++)
//            {
//                if(l <= station[i].distance)
//                {
//                    pq.push(station[i].fuel);
//                }
//            }

            while((index < n) && (station[index].distance >= l))
            {
                pq.push(station[index].fuel);
                index++;
            }
            num++;
        }
        printf("%d\n", l <= 0? num -1 : -1);
    }

    return 0;
}
