#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <limits.h>
#define LOCAL
#define N 50001

using namespace std;

//s为假话数目
int p[N], s, w[N];

void makeSet(int n)
{
    for(int i = 0; i < n; i++)
    {
        p[i] = i;
        w[i] = 0;
    }
    s = 0;
    return;
}

int findParent(int i)
{
    if(p[i] != i)
    {
        int tmp = p[i];
        p[i] = findParent(p[i]);
        w[i] = (w[i] + w[tmp]) % 3;
    }
    return p[i];
}

void unionSet(int i, int j, int type)
{
    int pi = findParent(i);
    int pj = findParent(j);

    //i, j在一个连通分量里
    if(pi == pj)
    {
        if(type == 1 && w[i] != w[j])
        {
            s++;
        }

        if(type == 2 && w[i] != (w[j] + 1) %3)
        {
            s++;
        }

    }
    else
    {
        p[pj] = pi;
        w[pj] = (w[i] - (type - 1) + (3 - w[j])) %3;
    }
    return;
}


int main()
{
    #ifdef LOCAL
    freopen("data.txt", "r", stdin);
    #endif // LOCAL
    int n, k, type, tmp1, tmp2;
    //cin会超时
    //cin >> n >> k;
    scanf("%d %d", &n, &k);
    makeSet(n);
    for(int i = 0; i < k; i++)
    {
        //cin >> type >> tmp1 >> tmp2;
        scanf("%d %d %d", &type, &tmp1, &tmp2);
        if(tmp1 > n || tmp2 > n)
        {
            s++;
            continue;
        }
        if(type == 2 && tmp1 == tmp2)
        {
            s++;
            continue;
        }
        unionSet(tmp1, tmp2, type);
    }
    //cout << s << endl;
    printf("%d\n", s);
    return 0;
}
