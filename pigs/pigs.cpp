#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <vector>
#include <queue>
#include <map>
#define INF INT_MAX
#define LOCAL

using namespace std;

int N, M;


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


int main()
{
    cin>> M>> N;
    vector<vector<int> > c(N + 2, vector<int>(N + 2));
    vector<int> cap(M + 1);
    vector<vector<int> > visited(M + 1, vector<int>(2));
    //记录每个猪圈里猪的个数
    for(int i = 1; i <= M; i ++)
    {
        int capacity;
        cin >> capacity;
        cap[i] = capacity;
    }

    for(int i = 1; i <= N; i++)
    {
        int keyNum, house, need;
        cin >> keyNum;
        for(int j = 0; j < keyNum; j++)
        {
            cin >> house;
            //这里需要更新visited
            //该客户是这个猪圈的第一个客户
            if(!visited[house][0])
            {
                visited[house][0] = 1;
                visited[house][1] = i;
                c[0][i] += cap[house];
            }
            //不是第一个客户，讲上一个客户与当前客户连接一条INF边，更新上一个用户为当前用户
            else
            {
                int lastCustomer = visited[house][1];
                c[lastCustomer][i] = INF;
                visited[house][1] = i;
            }
        }
        cin >> need;
        c[i][N + 1] = need;

    }
    /*
    //test usage!
    for(int i = 0; i < N + 2; i++)
    {
        for(int j = 0; j < N + 2; j++)
            cout<< c[i][j]<< " ";
        cout<< "\n";
    }
    cout<< "\n";
    */

    int flow, max_flow = 0;
    while(flow = bfs(c, 0, N + 1))
    {
        max_flow += flow;
    }
    cout << max_flow << endl;

    return 0;
}
