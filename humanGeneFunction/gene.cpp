#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <limits.h>
#define LOCAL
#define N 102

using namespace std;

int charMapInt(char c)
{
    if(c == 'A') return 0;
    if(c == 'C') return 1;
    if(c == 'G') return 2;
    if(c == 'T') return 3;
    return -1;
}


int dp(int m, int n, string s1, string s2, int a[5][5])
{
    int f[N][N];
    int bigger = m > n? m : n;
    //令f[0][0] = 0可以让下一步好操作
    f[0][0] = 0;
    for(int i = 1; i <= n ; i++)
    {
        f[0][i] = a[charMapInt(s2[i - 1])][4] + f[0][i - 1];
    }

    for(int i = 1; i <= m ; i++)
    {
        f[i][0] = a[charMapInt(s1[i - 1])][4] + f[i - 1][0];
    }

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <=n ; j++)
        {
            f[i][j] = INT_MIN;
            int val1 = a[charMapInt(s1[i-1])][charMapInt(s2[j-1])] + f[i-1][j-1];
            int val2 = a[charMapInt(s1[i-1])][4] + f[i-1][j];
            int val3 = a[charMapInt(s2[j-1])][4] + f[i][j-1];
            if(f[i][j] < val1) f[i][j] = val1;
            if(f[i][j] < val2) f[i][j] = val2;
            if(f[i][j] < val3) f[i][j] = val3;

        }
    }

//    for(int i = 0; i <= bigger; i++)
//    {
//        for(int j = 0; j <= bigger; j++)
//            cout << f[i][j] << " ";
//        cout << "\n";
//    }
    return f[m][n];
}


int main()
{
    #ifdef LOCAL
    freopen("data.txt", "r", stdin);
    #endif // LOCAL
    int t, m, n;
    string s1, s2;

    //记录匹配的得分数组
    int a[5][5];
    for(int i = 0; i < 5; i++)
    {
        a[i][i] = 5;
    }
    a[0][1] = a[1][0] = a[0][3] = a[3][0] = a[3][4] = a[4][3] = -1;
    a[0][2] = a[2][0] = a[1][3] = a[3][1] = a[2][3] = a[3][2] = a[2][4] = a[4][2] = -2;
    a[0][4] = a[4][0] = a[1][2] = a[2][1] =-3;
    a[1][4] = a[4][1] = -4;

    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> m >> s1 >> n >> s2;
        //cout << s1[0] << ", " << s2[0] << endl;
        cout << dp(m, n, s1, s2, a) << endl;
    }
    return 0;
}
