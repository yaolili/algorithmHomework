#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define LOCAL

using namespace std;


int main()
{

    #ifdef LOCAL
    freopen("data.txt", "r", stdin);
    #endif // LOCAL
    string s1, s2;
    int n, m, e, f[2][1000];
    while(cin >> s1 >> s2)
    {
        n = s1.size();
        m = s2.size();
        e = 0;
        memset(f, 0, sizeof(f));
        for(int i = 0; i < n; i++)
        {
            e = 1 - e;
            for(int j = 0; j < m; j++)
            {
                if(s1[i] == s2[j])
                {
                    f[e][j] = f[1 - e][j - 1] + 1;
                }
                else
                {
                    f[e][j] = max(f[1 - e][j], f[e][j - 1]);
                }
            }
        }
        cout << f[e][m - 1] << endl;

    }
    return 0;
}
