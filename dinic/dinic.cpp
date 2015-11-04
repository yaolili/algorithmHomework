#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#define INF INT_MAX
#define LOCAL

using namespace std;

int n, m;
vector<int> level;
vector<vector<int> > c(n + 1, vector<int>(n + 1));

//在一次bfs中，构建一次level，当前层次图都不能走通了之后再调用bfs重新构建层次图
bool bfs(int s, int t)
{
    queue<int> q;
    level.clear();
    level.resize(n + 1, -1);
    q.push(s);
    level[s] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if(u == t) return true;
        for(int i = 0; i <= n; i++)
        {
            if(c[u][i] > 0 && level[i] < 0)
            {
                q.push(i);
                level[i] = level[u] + 1;
            }
        }
    }
    return false;
}

int augment(int s, int t, int bottleNeck)
{
    if(s == t) return bottleNeck;
    for(int i = 0; i <= n; i++)
    {
        if(c[s][i] > 0 && (level[i] == level[s] + 1))
        {
            int bt = (bottleNeck < c[s][i]) ? bottleNeck: c[s][i];
            int flow = augment(i, t, bt);
            if(flow > 0)
            {
                c[s][i] -= flow;
                c[i][s] += flow;
                return flow;
            }
        }
    }
    //这句话应该不用加的
    level[s] = 0;
    return 0;
}

int dinic(int s, int t)
{
    int flow, maxFlow = 0;
    while(bfs(s, t))
    {

        while(flow = augment(s, t, INF))
        {
            maxFlow += flow;
        }
    }
    return maxFlow;
}

int main()
{
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif // LOCAL
    while(cin>> m>> n)
    {
        c.clear();
        c.resize(n + 1, vector<int>(n + 1, 0));
        int u, v, cap;
        for(int i = 0; i < m; i++)
        {
            cin>> u>> v>> cap;
            c[u][v] += cap;
        }
        cout<< dinic(1, n)<< endl;
    }

    return 0;
}
