#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <limits.h>
#define LOCAL

using namespace std;

int dp(int n, vector<int> lnk)
{
    int f[n+1][n+1];
    for(int i = 1; i < n; i++)
    {
        f[i][i+1] = 0;
    }

    //因为题目中有要求i,j的间隔要超过2才行，所以多了l进行区间长度的遍历
    for(int l = 3; l <= n; l++)
    {
        for(int i = 1; i <= n-l+1; i++)
        {
            int j = i+l-1;
            f[i][j] = INT_MAX;
            for(int k = i + 1; k < j; k++)
            {
                int val = f[i][k] + f[k][j] + lnk[i] * lnk[k] * lnk[j];
                if(val < f[i][j]) f[i][j] = val;
            }
        }
    }
    return f[1][n];

}

int main()
{
    int n, tmp;
    vector<int> lnk(1, -1);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        lnk.push_back(tmp);
    }
    cout << dp(n, lnk) << endl;
    return 0;
}
