#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#define LOCAL

using namespace std;

struct cow
{
    int spfmin, spfmax;
};

struct bottle
{
    int spf, num;
};

cow cows[2503];
bottle bot[2503];

bool cmpCow(cow a, cow b)
{
    return a.spfmin < b.spfmin;
}

bool cmpBot(bottle a, bottle b)
{
    return a.spf < b.spf;
}
priority_queue<int, vector<int>, greater<int> > q;
int main()
{
    #ifdef LOCAL
    freopen("data.txt", "r", stdin);
    #endif // LOCAL
    int C, L;
    scanf("%d %d", &C, &L);
    for(int i = 1; i <= C; i++)
    {
        scanf("%d %d", &cows[i].spfmin, &cows[i].spfmax);
    }
    for(int i = 1; i <= L; i++)
    {
        scanf("%d %d", &bot[i].spf, &bot[i].num);
    }
    sort(cows + 1, cows + C + 1, cmpCow);
    sort(bot + 1, bot + L + 1, cmpBot);

    int ans = 0;
    int j = 1;
    for(int i = 1; i <= L; i++)
    {
        /*
        //注意这里不能写成
        int j = 1;
        while(j <= C)
        {
            if(cows[j].spfmin <= bot[i].spf) q.push(cows[j].spfmax);
            j++;
        }
        //不是要一次都把所有的cows都遍历过去，而是每次只取到满足条件的，第二个瓶子是在第一个瓶子的基础上继续遍历
        //这样才可以保证所有的牛都只涂抹一次
        */
        while(j <= C && cows[j].spfmin <= bot[i].spf)
        {
            q.push(cows[j].spfmax);
            j++;
        }
        while(!q.empty() && bot[i].num)
        {
            int t = q.top();
            q.pop();
            if(bot[i].spf > t)continue;
            ans++;
            bot[i].num--;
        }
    }
    printf("%d\n", ans);

    return 0;
}

