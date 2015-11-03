#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string.h>
#define LOCAL

using namespace std;

void genealogicalTree(vector<vector<int> > &lnklst, vector<int> inDegree, int length)
{
    int ans[length], cur = 0;
    queue<int> q;

    //找出入度为0的点
    for(int i = 1; i < length; i++)
        if(inDegree[i] == 0)
        {
            q.push(i);
        }


    while(!q.empty())
    {
        int tmp = q.front();
        ans[cur] = tmp;
        cur++;
        q.pop();
        for(int j = 0; j < lnklst[tmp].size(); j++)
        {
            int children = lnklst[tmp][j];
            inDegree[children]--;
            if(!inDegree[children]) q.push(children);
        }
    }

    //print result;
    for(int m = 0; m < length - 1; m++) printf("%d ", ans[m]);
    return;
}

int main()
{
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    #endif // LOCAL

    int n, tmp;
    scanf("%d\n", &n);
    int length = n + 1;

    vector< vector<int> > lnklst(length);
    vector<int> inDegree(length);

    for(int i = 1; i <= n; i++)
    {
        while(1)
        {
            scanf("%d", &tmp);
            if(tmp != 0)
            {
                lnklst[i].push_back(tmp);
                inDegree[tmp]++;
            }
            else break;
        }
    }
    genealogicalTree(lnklst, inDegree, length);
    return 0;
}
