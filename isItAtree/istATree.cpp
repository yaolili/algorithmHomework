#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string.h>
#define LOCAL
#define N 105

using namespace std;

int p[N];
bool visited[N];

void makeSet()
{
    for(int i = 0; i < N; i++)
    {
        p[i] = i;
        visited[i] = false;
    }
    return ;
}

int findParent(int i)
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
        p[pj] = pi;
    }
    return;
}

int main()
{
    #ifdef LOCAL
    freopen("data.txt", "r", stdin);
    #endif // LOCAL

    int caseNum = 1;
    int tmp1, tmp2, root;
    while(scanf("%d %d", &tmp1, &tmp2))
    {
        if(tmp1 == -1 && tmp2 == -1) break;
        if(tmp1 == 0 && tmp2 ==0)
        {
            printf("Case %d is a tree.\n", caseNum);
            caseNum++;
            continue;
        }

        makeSet();
        visited[tmp1] = visited[tmp2] = true;
        root = tmp1;
        bool isTree = true;
        if(tmp1 == tmp2) isTree = false;
        else unionSet(tmp1, tmp2);

        while(scanf("%d %d", &tmp1, &tmp2), tmp1, tmp2)
        {
            visited[tmp1] = visited[tmp2] = true;
            if(findParent(tmp1) == findParent(tmp2))
            {
                isTree = false;
            }
            else unionSet(tmp1, tmp2);

        }
        //这里是为0 0，开始输出
        //连通分量不为1则不是树
        for(int i = 0; i < N; i++)
        {
            if(visited[i] && findParent(i) != findParent(root))
            {
                isTree = false;
                break;
            }
        }
        if(isTree) printf("Case %d is a tree.\n", caseNum);
        else printf("Case %d is not a tree.\n", caseNum);
        caseNum++;
    }
    return 0;
}
