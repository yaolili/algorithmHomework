#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#define LOCAL

using namespace std;

void genealogicalTree(vector<vector<int> > lnklst, vector<int> outDegree, int length)
{
    stack<int> result;
    queue<int> q;
    int ans[length], cur = 0;

//    //This method will time limited exceeded
//    for(int i = 1; i <= length; i++)
//        if(outDegree[i] == 0) result.push(i);
//
//    while(result.size() < length)
//    {
//        int tmp = result.top();
//        for(int j = 1; j <= length; j++)
//        {
//            if(!outDegree[j]) continue;
//            for(int m = 0; m < lnklst[j].size(); m++)
//            {
//                if(lnklst[j][m] == tmp)
//                {
//                    outDegree[j]--;
//                    if(!outDegree[j]) result.push(j);
//                }
//            }
//        }
//
//    }
//    for(int m = 0; m < length; m++)
//    {
//        printf("%d ", result.top());
//        result.pop();
//    }

    //找出出度为0的点
    for(int i = 1; i <= length; i++)
        if(outDegree[i] == 0) q.push(i);

    while(!q.empty())
    {
        int tmp = q.front();
        ans[cur] = tmp;
        cur++;
        q.pop();
        for(int j = 1; j <= length; j++)
        {
            if(!outDegree[j]) continue;
            for(int m = 0; m < lnklst[j].size(); m++)
            {
                if(lnklst[j][m] == tmp)
                {
                    outDegree[j]--;
                    if(!outDegree[j]) q.push(j);
                }
            }
        }
    }

    print result;
    for(int m = length - 1; m >= 0; m--) printf("%d ", ans[m]);

    return;
}

int main()
{
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    #endif // LOCAL

    int n, tmp;
    scanf("%d\n", &n);

    vector< vector<int> > lnklst(n + 1);
    vector<int> outDegree(n + 1);

    for(int i = 1; i <= n; i++)
    {
        while(1)
        {
            scanf("%d", &tmp);
            if(tmp != 0) lnklst[i].push_back(tmp);
            else
            {
                 outDegree[i] = lnklst[i].size();
                 break;
            }
        }
    }
    genealogicalTree(lnklst, outDegree, n);
    return 0;
}
