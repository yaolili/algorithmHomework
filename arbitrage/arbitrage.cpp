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
        //a[N][N]Ϊ�洢���ʵ����飬ÿ�ζ����г�ʼ��
        double a[N][N];
        memset(a, 0.0, sizeof(a));
        for(int i = 0; i < n; i++)
        {
            cin >> p[i];
            a[i][i] = 1.0;
        }

        //��ȡ������Ϣ
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
            //ע�����1�һ�����2�����2�һ�����1���ǻ�Ϊ������
            //a[index2][index1] = 1.0/tmp;
        }

        dp(n, a);

        //��a[N][N]���б���
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
