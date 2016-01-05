#include <iostream>
#include <cstdlib>
#include <cstdio>
#define MAX  100002
#define LOCAL

using namespace std;

int p[MAX], b[MAX];

void makeSet(int n)
{
    for(int i = 1; i <= n; i++)
    {
        p[i] = i;
        b[i] = 0;
    }
}

int findParent(int i)
{
    if(p[i] != i)
    {
        int tmp = p[i];
        p[i] = findParent(p[i]);
        b[i] = (b[i] + b[tmp]) %2;
    }
    return p[i];
}

void unionSet(int i, int j)
{
    int pi = findParent(i);
    int pj = findParent(j);
    if(pi != pj)
    {
        p[pj] = pi;
        b[pj] = (b[i] + b[j] + 1) %2;
    }

}

int main()
{
    #ifdef LOCAL
    freopen("data.txt", "r", stdin);
    #endif // LOCAL

    int T, N, M, u, v;
    char c;
    scanf("%d\n", &T);
    while(T--)
    {
        scanf("%d%d\n", &N, &M);
        makeSet(N);
        for(int i = 0; i < M; i++)
        {
            scanf("%c%d%d\n", &c, &u, &v);
            if(c == 'A')
            {
                int pu = findParent(u);
                int pv = findParent(v);

                if(pu != pv) cout << "Not sure yet." << endl;
                else
                {
                   int type = (b[u] + b[v]) % 2;
                   if(type) cout << "In different gangs." << endl;
                   else cout << "In the same gang." << endl;
                }


            }
            else
            {
                unionSet(u, v);
            }

        }
    }

    return 0;
}
