#include <iostream>
#include <cstdio>
#include <cstdlib>
#define LOCAL

using namespace std;
int N, M, a[3410][2], f[2][12882];

int dp()
{
    for(int i = 0; i <= 1; i++)
    {
        f[i][0] = 0;
    }
    for(int w = 0; w <= M; w++)
    {
        f[0][w] = 0;
    }

    int e = 0;
    for(int i = 1; i <= N; i++)
    {
        e = 1 - e;
        for(int w = 1; w <= M; w++)
        {
            if(a[i][0] <= w)
            {
                f[e][w] = max(f[1-e][w-a[i][0]] + a[i][1], f[1-e][w]);
            }
            else
            {
                f[e][w] = f[1-e][w];
            }

        }
    }
    return f[e][M];
}

int main()
{
    #ifdef LOCAL
    freopen("data.txt", "r", stdin);
    #endif // LOCAL
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
    {
        scanf("%d %d", &a[i][0], &a[i][1]);
    }
    printf("%d\n", dp());

}
