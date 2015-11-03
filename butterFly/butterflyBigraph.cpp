/*
 * Author: Zhen Xiao
 * This code has several bugs which you need to fix to pass Homework 1.
 */

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#define LOCAL

using namespace std;

struct edge {
    int v;
    bool type;
};

//bfs
bool test_bipartite(const vector<vector<edge> > &lnklst)
{
    int n = lnklst.size();
    vector<bool> visited(n, false);
    vector<bool> color(n);
    queue<int> q;
    q.push(0);
    color[0] = 0;
    visited[0] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int j=0; j<lnklst[u].size(); j++)
        {
            edge e = lnklst[u][j];
            int v = e.v;
            if (!visited[v])
            {
                color[v] = color[u] ^ e.type;
                visited[v] = true;
                q.push(v);
            }
            else if (color[v] != color[u] ^ e.type)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif // LOCAL
    int n, m;
    while (cin >> n >> m)
    {
        vector<vector<edge> > lnklst(n);
        for (int i=0; i<m; i++)
        {
            int u, v, type;
            scanf("%d %d %d", &u, &v, &type);
            //cin >> u >> v >> type;
            edge e;
            e.v = v; e.type = type;
            lnklst[u].push_back(e);
            e.v = u;
            lnklst[v].push_back(e);
        }
        if (test_bipartite(lnklst)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
