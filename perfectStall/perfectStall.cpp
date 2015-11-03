#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <limits.h>
#define INF INT_MAX
#define LOCAL

using namespace std;

int N, M;

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


int main()
{
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    #endif // LOCAL

    while(cin>> N>> M)
    {
        //相当于有N+M+2个顶点
        vector<vector<int> > c(N + M + 2, vector<int>(N + M + 2));

        for(int i = 1; i <= N; i++)
        {
            int num, right;
            cin>> num;
            c[0][i] = 1;
            for(int j = 0; j < num; j++)
            {
                cin>> right;
                c[i][right + N] = INF;
                c[right + N][N + M + 1] = 1;
            }
        }

        int flow, max_flow = 0;
        while((flow = bfs(c, 0, N + M + 1)) > 0)
        {
            max_flow += flow;
        }
        cout << max_flow << endl;

    }



    return 0;
}
