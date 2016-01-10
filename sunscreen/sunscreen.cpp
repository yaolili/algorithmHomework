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
        //ע�����ﲻ��д��
        int j = 1;
        while(j <= C)
        {
            if(cows[j].spfmin <= bot[i].spf) q.push(cows[j].spfmax);
            j++;
        }
        //����Ҫһ�ζ������е�cows��������ȥ������ÿ��ֻȡ�����������ģ��ڶ���ƿ�����ڵ�һ��ƿ�ӵĻ����ϼ�������
        //�����ſ��Ա�֤���е�ţ��ֻͿĨһ��
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

