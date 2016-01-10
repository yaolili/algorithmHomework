#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <vector>
#define LOCAL

using namespace std;

//Time Limit Exceeded
int a[10000003];
queue<int> mini, maxi;

struct cmpLess
{
    //从大到小排列
    bool operator()(const int i, const int j)
    {
        return a[i] < a[j];
    }
};

struct cmpGreater
{
    //从小到大排序
    bool operator()(const int i, const int j)
    {
        return a[i] > a[j];
    }
};


priority_queue<int, vector<int>, cmpLess> q1;
priority_queue<int, vector<int>, cmpGreater> q2;

int main()
{
    #ifdef LOCAL
    freopen("data.txt", "r", stdin);
    #endif // LOCAL
    int n, k;
    vector<bool> flag(10000003, true);
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if(i <= k)
        {
            q1.push(i);
            q2.push(i);
            if(i == k)
            {
                maxi.push(q1.top());
                mini.push(q2.top());
            }
        }
        else
        {
            flag[i-k] = false;
            q1.push(i);
            q2.push(i);
            while(!flag[q1.top()])
            {
                q1.pop();
            }
            maxi.push(q1.top());
            while(!flag[q2.top()])
            {
                q2.pop();
            }
            mini.push(q2.top());
        }
    }

    //输出mini, maxi
    while(!mini.empty())
    {
        printf("%d ", a[mini.front()]);
        mini.pop();
    }
    printf("\n");
    while(!maxi.empty())
    {
        printf("%d ", a[maxi.front()]);
        maxi.pop();
    }
    return 0;
}
