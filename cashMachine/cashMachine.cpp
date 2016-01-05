#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define LOCAL

using namespace std;

int N, f[2][100002];

struct node
{
    int n, D;
} bills[10];

//remain to fix
int main()
{
    #ifdef LOCAL
    freopen("data.txt", "r", stdin);
    freopen("out.txt", "w+", stdout);
    #endif // LOCAL
    int cash;
    while(cin >> cash)
    {
        cin >> N;
        for(int i = 0; i < N; i++)
        {
            cin >> bills[i].n >> bills[i].D;
        }
        int e = 0;

        memset(f, 0, sizeof(f));
        for(int i = 1; i <= N; i++)
        {
            e = 1 - e;
            //f[i][0] = 0;
            for(int j = 1; j <= cash; j++)
            {
                int w = bills[i].D;
                f[e][j] = f[1-e][j];
                if(j >= w)
                {
                    if(bills[i].n)
                    {
                        bills[i].n -= 1;
                        f[e][j] = max(f[1-e][j], f[e][j-w] + w);
                    }
                    else
                    {
                        f[e][j] = max(f[1-e][j], f[1-e][j-w] + w);
                    }
                }
            }
        }

        cout << f[e][cash] << endl;

    }
    return 0;
}
