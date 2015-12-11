#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <limits.h>
#define LOCAL
#define N 31

using namespace std;

string p[N];

void dp(int n, double a[N][N])
{

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                if(a[i][j] < a[i][k]*a[k][j])
                    a[i][j] = a[i][k]*a[k][j];
            }
        }
    }

    return;
}

int main()
{
    #ifdef LOCAL
    freopen("data.txt", "r", stdin);
    #endif // LOCAL

    int n, m, caseNum = 0;
    double tmp;
    string s1, s2;

    while(cin >> n)
    {
        if(!n) break;
        caseNum++;
        //a[N][N]为存储汇率的数组，每次都进行初始化
        double a[N][N];
        memset(a, 0.0, sizeof(a));
        for(int i = 0; i < n; i++)
        {
            cin >> p[i];
            a[i][i] = 1.0;
        }

        //读取汇率信息
        cin >> m;
        for(int i = 0; i < m; i++)
        {
            cin >> s1 >> tmp >> s2;
            int index1 = -1;
            int index2 = -1;
            for(int i = 0; i < n; i++)
            {
                if(p[i] == s1) index1 = i;
                if(p[i] == s2) index2 = i;
                if(index1 != -1 && index2 != -1) break;
            }
            a[index1][index2] = tmp;
            //注意货币1兑换货币2与货币2兑换货币1不是互为倒数的
            //a[index2][index1] = 1.0/tmp;
        }

        dp(n, a);

        //对a[N][N]进行遍历
        bool flag = false;
        for(int i = 0; i < n; i++)
        {
            if(a[i][i] > 1)
            {
                flag = true;
                break;
            }
        }
        if(flag) cout << "Case " << caseNum << ": Yes" << endl;
        else cout << "Case " << caseNum << ": No" << endl;
    }
    return 0;
}
