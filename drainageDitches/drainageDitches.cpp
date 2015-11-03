#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <limits.h>
#define INF INT_MAX
#define LOCAL

using namespace std;

int n, m;

int augment(vector<vector<int> > &cap, int s, int t, vector<int> &p)
{
    int bottleNeck = INF;
    for(int v = t; v != s; v = p[v])
    {
        int u = p[v];
        if(cap[u][v] < bottleNeck) bottleNeck = cap[u][v];
    }
    for(int v = t; v != s; v = p[v])
    {
        int u = p[v];
        cap[u][v] -= bottleNeck;
        cap[v][u] += bottleNeck;
    }
    return bottleNeck;
}

int bfs(vector<vector<int> > &cap, int s, int t, vector<int> &p, vector<bool> visited)
{
    if(s == t)
    {
        return augment(cap, 1, n, p);
    }

    vector<bool> curVisited = visited;
    curVisited[s] = true;
    int flow;

    for(int i = 0; i <= n; i++)
    {
        if(cap[s][i] > 0 && !curVisited[i])
        {
            p[i] = s;
            if((flow = bfs(cap, i, t, p, curVisited)) > 0)
                return flow;
            else continue;

        }
    }
    return 0;
}


int main()
{
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    #endif // LOCAL
    while (cin >> m >> n)
    {
		vector<vector<int> > cap(n+1, vector<int>(n+1));
		for (int i = 0; i < m; i++)
		{
		    int u, v, c;
		    cin >> u >> v >> c;
		    cap[u][v] += c;
		}
		int flow, max_flow = 0;
		vector<bool> visited(n + 1);
		vector<int> p(n + 1);
		while((flow = bfs(cap, 1, n, p, visited)) > 0)
		{
			max_flow += flow;
		}
		cout << max_flow << endl;
	}
	return 0;
}
