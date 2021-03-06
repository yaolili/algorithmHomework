#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <cstring>
#include <assert.h>
#include <queue>
#include <vector>

#define LOCAL

using namespace std;

#define N (5002 + 2)
#define M (N*N + 4*N)

typedef long long LL;

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

    int n, m, s, t, cap, u, v;


    while(scanf("%d %d", &n, &m) != EOF)
    {
        s = 0;
        t = n + 1;
        LL profit = 0;
        dinic_init();
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &cap);
            if(cap > 0)
            {
                profit += cap;
                add_edge(s, i, cap, 0);
            }
            else add_edge(i, t, -cap, 0);
        }
        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d", &u, &v);
            add_edge(u, v, INT_MAX, 0);
        }
        LL flow = dinic(s, t);
        LL result = profit - flow;
        //cout << flow << endl;
        cout << upstream(s, n) << " " << result << endl;
    }

    return 0;
}
