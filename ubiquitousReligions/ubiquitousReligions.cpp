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

int p[N], s;

void makeSet(int n)
{
    for(int i = 0; i < n; i++)
    {
        p[i] = i;
    }
    s = n;
    return;
}

int findParent(int i )
{
    if(p[i] != i)
    {
        p[i] = findParent(p[i]);
    }
    return p[i];
}

void unionSet(int i, int j)
{
    int pi = findParent(i);
    int pj = findParent(j);
    if(pi != pj)
    {
        p[pj] = p[i];
        s--;
    }
    return;
}

int main()
{
    #ifdef LOCAL
    freopen("data.txt", "r", stdin);
    #endif // LOCAL
    int n, m, tmp1, tmp2;
    int num = 0;
    while(scanf("%d %d",&n, &m),n, m)
    {
        makeSet(n);
        num++;
        for(int i = 0; i < m; i++)
        {
            cin >> tmp1 >> tmp2;
            unionSet(tmp1, tmp2);

        }
        printf("Case %d: %d\n", num, s);
    }
    return 0;
}
