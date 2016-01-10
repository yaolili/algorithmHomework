#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <limits.h>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <assert.h>
#define LOCAL

using namespace std;

int int_max(int a, int b)
{
   return a > b? a : b;
}

int int_min(int a, int b)
{
   return a < b? a : b;
}

int f[51][50*450];

int main()
{
    #ifdef LOCAL
    freopen("data.txt", "r", stdin);
    #endif
    int n, numTop, weightTop, weightTot = 0;
    scanf("%d", &n);

    vector<int> weight(n + 1);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &weight[i]);
        weightTot += weight[i];
    }
    numTop = (n + 1)/ 2;
    weightTop = (weightTot + 1) / 2;

    f[0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = numTop; j > 0; j--)
        {
            for(int k = weightTop; k >= weight[i]; k--)
            {
                if(!f[j][k] && f[j-1][k-weight[i]])
                {
                    f[j][k] = 1;
                }
            }

        }
    }

    for(int k = weightTop; k >= 0; k--)
    {
        if(f[n/2][k] || f[(n+1)/2][k])
        {
            int another = weightTot - k;
            k = int_max(k, another);
            another = weightTot - k;
            printf("%d %d\n", another, k);
            return 0;
        }
    }
    return 0;
}
