#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <limits.h>
#include <string.h>
#include <algorithm>
#define LOCAL

using namespace std;

//f[i][j]表示前i个设备，最小带宽为j时的最小价格
int f[103][2000];
int mi[103];
struct node
{
    int b;
    int p;
};

int main()
{
    #ifdef LOCAL
    freopen("data.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    #endif // LOCAL
    int t, n, maxB = 0;
    node devices[103][103];

    cin >> t;
    while(t--)
    {
        memset(f, 0x7f, sizeof(f));
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> mi[i];
            for(int j = 1; j <= mi[i]; j++)
            {
                cin >> devices[i][j].b >> devices[i][j].p;
                if(devices[i][j].b > maxB)
                {
                    maxB = devices[i][j].b;
                }
            }
        }

        //初始化
        for(int i = 0; i <= maxB; i++)
        {
            f[0][i] = 0;
        }

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= mi[i]; j++)
            {
                for(int k = 1; k <= devices[i][j].b; k++)
                {
                    f[i][k] = min(f[i][k], f[i - 1][k] + devices[i][j].p);
                }
            }
        }

        double ans = 0.0;
        for(int i = 1; i <= maxB; i++ )
        {
            ans = max(ans, i*1.0 / f[n][i]);

        }
        printf("%.3f\n", ans);
    }
    return 0;
}
