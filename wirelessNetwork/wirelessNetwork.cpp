#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
#define MAX 30003
#define LOCAL

using namespace std;
int p[1003], d;
bool visited[1003];

struct node
{
    int x, y;
}nodes[1003];

void makeSet(int n)
{
    for(int i = 1; i<=n; i++)
    {
        p[i] = i;
        visited[i] = false;
    }
}

int findParent(int i)
{
    if(p[i] != i) p[i] = findParent(p[i]);
    return p[i];
}

bool connected(node n1, node n2)
{
    int dist = (n1.x - n2.x)*(n1.x - n2.x) + (n1.y - n2.y) * (n1.y - n2.y);
    if(dist <= d * d) return true;
    else return false;
}

int main()
{
    #ifdef LOCAL
    freopen("data.txt", "r", stdin);
    #endif // LOCAL

    int n, x, y, u, v;
    char c;

    scanf("%d %d", &n, &d);
    makeSet(n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d %d", &nodes[i].x, &nodes[i].y);
    }
    while(cin >> c)
    {
        if(c == 'O')
        {
            scanf("%d", &u);
            visited[u] = true;
            for(int i = 1; i <= n; i++)
            {
                if(i != u && visited[i] && connected(nodes[i], nodes[u]))
                {
                    int pi = findParent(i);
                    int pu = findParent(u);
                    if(pi != pu)
                    {
                        p[pu] = pi;
                    }
                }
            }
        }
        else
        {
            scanf("%d %d", &u, &v);
            if(findParent(u) == findParent(v)) printf("SUCCESS\n");
            else printf("FAIL\n");
        }
    }
    return 0;
}
