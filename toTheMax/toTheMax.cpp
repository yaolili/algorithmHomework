#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <queue>
#define LOCAL

using namespace std;
int arr[102][102], sumArr[102];

int maxSubSum(int sumArr[102], int n)
{

    int f[n];
    int sum = 0;
    //因为有负值，所以初始化f类似负无穷大
    for(int i = 0; i < n; i++)
    {
        f[i] = -12800;
    }

    for(int i = 0; i < n; i++)
    {
        if(i == 0) f[i] = sumArr[i];
        else
        {
            f[i] = sumArr[i] + max(f[i - 1], 0);
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(f[i] > sum) sum = f[i];
    }
    return sum;
}

int main()
{
    #ifdef LOCAL
    freopen("data.txt", "r", stdin);
    #endif // LOCAL
    int n;
    while(scanf("%d", &n) != EOF)
    {
        int maxSum = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                scanf("%d", &arr[i][j]);
            }

        }

        int f[n];
        //注意先是从第一行往下压缩，再是第二行...
        for(int line = 0; line < n; line++)
        {
            memset(f, 0, sizeof(f));
            memset(sumArr, 0, sizeof(sumArr));
            for(int i = line; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    sumArr[j] += arr[i][j];
                }

                f[i] = maxSubSum(sumArr, n);
            }

            for(int i = 0; i < n; i++)
            {
                if(f[i] > maxSum) maxSum = f[i];
            }
        }

        printf("%d\n", maxSum);
    }
    return 0;
}
