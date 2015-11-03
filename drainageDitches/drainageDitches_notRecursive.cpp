#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <limits.h>
#define INF INT_MAX
#define LOCAL
using namespace std;

int augment(vector<vector<int> > &cap, int s, int t, const vector<int> &p)
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

//非递归形式不会超时
int bfs(vector<vector<int> > &cap, int s, int t)
{
    int n = cap.size();
	vector<bool> visited(n);
	vector<int> p(n);
	queue<int> q;
	visited[s] = true;
	q.push(s);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v=0; v<n; v++)
		{
			if (!visited[v] && cap[u][v] > 0)
			{
				visited[v] = true;
				p[v] = u;
				if (v == t) return augment(cap, s, t, p);
				q.push(v);
			}
		}
    }
    return 0;
}


int main() {
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    #endif // LOCAL
    int n, m;
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
		while((flow = bfs(cap, 1, n)) > 0)
		{
			max_flow += flow;
		}
		cout << max_flow << endl;
	}
	return 0;
}
