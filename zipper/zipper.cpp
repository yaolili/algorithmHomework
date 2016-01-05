#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define LOCAL

using namespace std;

bool f[202][202];

int main()
{

    #ifdef LOCAL
    freopen("data.txt", "r", stdin);
    #endif // LOCAL
    int N, n, m;
    string s1, s2, s3;
    cin >> N;
    for(int caseNum = 1; caseNum <= N; caseNum++)
    {
        cin >> s1 >> s2 >> s3;
        n = s1.size();
        m = s2.size();

        //��ʼ��
        memset(f, 0, sizeof(f));
        //f[i][j]=1��ʾs3��ǰi+j���ַ�������s1ǰi����s2ǰj���ַ����
        //s1-s3�±��0��ʼ��i��j��ʾǰ*���ַ�
        for(int i = 1; i <= n; i++)
        {
            if(s3[i-1] == s1[i-1]) f[i][0] = true;
        }
        for(int j = 1; j <= m; j++)
        {
            if(s3[j-1] == s2[j-1]) f[0][j] = true;
        }


        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(s3[i+j-1] == s1[i-1] && f[i-1][j] || s3[i+j-1] == s2[j-1] && f[i][j-1])
                {
                    f[i][j] = true;
                }
            }
        }

        if(f[n][m]) cout << "Data set " << caseNum << ": yes" << endl;
        else cout << "Data set " << caseNum << ": no" << endl;

    }
    return 0;
}
