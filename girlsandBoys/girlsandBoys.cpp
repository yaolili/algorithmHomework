#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <queue>
#include <climits>
#include <algorithm>
#include <vector>

#define LOCAL

#define N (1002 + 2)
#define M (N*N + 4*N)

typedef long long LL;

//���ƥ��
using namespace std;

struct edge
{
    int v, cap, next;
};
edge e[M];

int head[N], level[N], cur[N];
int num_of_edges;

/*
 * When there are multiple test sets, you need to re-initialize before each
 */
void dinic_init(void)
{
    num_of_edges = 0;
    memset(head, -1, sizeof(head));
    return;
}

int add_edge(int u, int v, int c1, int c2)
{
    int& i=num_of_edges;

    assert(c1>=0 && c2>=0 && c1+c2>=0); // check for possibility of overflow
    e[i].v = v;
    e[i].cap = c1;
    e[i].next = head[u];
    head[u] = i++;

    e[i].v = u;
    e[i].cap = c2;
    e[i].next = head[v];
    head[v] = i++;
    return i;
}

void print_graph(int n)
{
    for (int u=0; u<n; u++)
    {
        printf("%d: ", u);
        for (int i=head[u]; i>=0; i=e[i].next)
        {
            printf("%d(%d)", e[i].v, e[i].cap);
        }
        printf("\n");
    }
    return;
}

/*
 * Find all augmentation paths in the current level graph
 * This is the recursive version
 */
int dfs(int u, int t, int bn)
{
    if (u == t) return bn;
    int left = bn;
    for (int i=head[u]; i>=0; i=e[i].next)
    {
        int v = e[i].v;
        int c = e[i].cap;
        if (c > 0 && level[u]+1 == level[v])
        {
            int flow = dfs(v, t, min(left, c));
            if (flow > 0)
            {
                e[i].cap -= flow;
                e[i^1].cap += flow;
                cur[u] = v;
                left -= flow;
                if (!left) break;
            }
        }
    }
    if (left > 0) level[u] = 0;
    return bn - left;
}

bool bfs(int s, int t)
{
    memset(level, 0, sizeof(level));
    level[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (u == t) return true;
        for (int i=head[u]; i>=0; i=e[i].next)
        {
            int v = e[i].v;
            if (!level[v] && e[i].cap > 0)
            {
                level[v] = level[u]+1;
                q.push(v);
            }
        }
    }
    return false;
}

LL dinic(int s, int t)
{
    LL max_flow = 0;

    while (bfs(s, t))
    {
        memcpy(cur, head, sizeof(head));
        max_flow += dfs(s, t, INT_MAX);
    }
    return max_flow;
}

int upstream(int s, int n)
{
    int cnt = 0;
    vector<bool> visited(n);
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i=head[u]; i>=0; i=e[i].next)
        {
            int v = e[i].v;
            if (e[i].cap > 0 && !visited[v])
            {
                visited[v] = true;
                q.push(v);
                cnt++;
            }
        }
    }
    return cnt; // excluding s
}


int main()
{
    #ifdef LOCAL
    freopen("data.txt", "r", stdin);
    #endif // LOCAL
    int n, s, t, id, k, tmp;
    while(scanf("%d", &n) != EOF)
    {
        dinic_init();
        s = 0;
        t = 2 * n + 1;
        for(int m = 1; m <= n; m++)
        {
            scanf("%d: (%d)", &id, &k);
            add_edge(s, id + 1, 1, 0);
            for(int i = 1; i <= k; i++)
            {
                scanf("%d", &tmp);
                add_edge(id + 1, tmp + n + 1, 1, 0);
            }


        }
        //add node to t
        for(int i = n + 1; i <= 2 * n; i++)
        {
            add_edge(i, t, 1, 0);
        }

        int maxFlow = dinic(s, t);
        printf("%d\n", n - maxFlow / 2);
    }
    return 0;
}
