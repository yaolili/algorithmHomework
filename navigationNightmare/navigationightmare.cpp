#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
#define MAX 40003
#define LOCAL

using namespace std;

int direction[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
struct node
{
    int p, x, y;
}UF[MAX];


void makeSet(int N)
{
    for(int i = 1; i <= N; i++)
    {
        UF[i].p = i;
        UF[i].x = 0;
        UF[i].y = 0;
    }
}

int findParent(int i)
{
    if(UF[i].p != i)
    {
        int tmp = UF[i].p;
        UF[i].p = findParent(UF[i].p);
        UF[i].x += UF[tmp].x;
        UF[i].y += UF[tmp].y;
    }
    return UF[i].p;
}

void unionSet(int i, int j, int l, char d)
{
    int t;
    if(d == 'N') t = 0;
    else if(d == 'S') t = 1;
    else if(d == 'W') t = 2;
    else if(d == 'E') t = 3;

    int pi = findParent(i);
    int pj = findParent(j);

    UF[pj].p = pi;
    UF[pj].x = UF[i].x + direction[t][0] * l - UF[j].x;
    UF[pj].y = UF[i].y + direction[t][1] * l - UF[j].y;

}


int main()
{
    #ifdef LOCAL
    freopen("data.txt", "r", stdin);
    #endif // LOCAL
    int N, M, u, v, l, K, qu, qv, I;
    char d;

    scanf("%d %d", &N, &M);
    vector<vector<int> > info(M + 1, vector<int>(4));
    vector<char> dir(M + 1);
    for(int i = 1; i <= M; i++)
    {
        scanf("%d %d %d %c", &info[i][1], &info[i][2], &info[i][3], &dir[i]);
    }

    makeSet(N);

    scanf("%d", &K);
    int flag = 1;
    for(int i = 1; i <= K; i++)
    {
        scanf("%d %d %d", &qu, &qv, &I);

        for(int j = flag; j <= I; j++)
        {

            u = info[j][1];
            v = info[j][2];
            l = info[j][3];
            d = dir[j];
            unionSet(u, v, l, d);
        }

        if(findParent(qu) == findParent(qv))
        {
            printf("%d\n", abs(UF[qu].x - UF[qv].x) + abs(UF[qu].y - UF[qv].y));

        }
        else
        {
            printf("-1\n");
        }

        flag = I;

    }

    return 0;
}
