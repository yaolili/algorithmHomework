#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define LOCAL

using namespace std;

vector<bool> visited(101);
//注意如果一开始就定义好result大小，那么在pushback的时候是在后面加入
vector<int> result;

void dfs(int i, const vector<vector<int> > lnklst)
{
    if(visited[i]) return;
    visited[i] = true;
    for(int j = 0; j < int(lnklst[i].size()); j++)
    {
        int value = lnklst[i][j];
        //cout<<"i is:"<<i<<" , j is:"<< j<<" , value is:"<< value<<endl;
        dfs(value, lnklst);
    }

    result.push_back(i);
    //cout<<"push back size :"<< int(result.size())<<endl;
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

    for(int i = 1; i <= n; i++)
    {
        while(1)
        {
            scanf("%d", &tmp);
            if(tmp != 0)
            {
                lnklst[i].push_back(tmp);
            }
            else break;
        }
    }

    for(int j = 1; j < length; j++)
    {
        dfs(j, lnklst);
    }

    for(int m = n - 1; m >= 0; m--)
        printf("%d ", result[m]);

    return 0;
}
