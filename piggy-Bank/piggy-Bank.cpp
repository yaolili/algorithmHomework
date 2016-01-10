#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#define LOCAL

using namespace std;
int W, N, a[503][2], f[10003];
bool full[10003];

int dp()
{
    memset(full, 0, sizeof(full));
    full[0] = true;
    f[0] = 0;
    for(int w = 1; w <= W; w++)
        f[w] = INT_MAX;
    for(int i = 1; i <= N; i++)
    {
        for(int w = 1; w <= W; w++)
        {
            if(a[i][1] <= w && full[w-a[i][1]])
            {
                int tmp = f[w-a[i][1]] + a[i][0];
                f[w] = min(f[w], tmp);
                full[w] = true;
            }
        }
    }
    return f[W];
}

int main()
{
    #ifdef LOCAL
    freopen("data.txt", "r", stdin);
    #endif // LOCAL
    int T, E, F;
    cin >> T;
    while(T--)
    {
        cin >> E >> F;
        W = F - E;
        cin >> N;
        for(int i = 1; i <= N; i++)
        {
            cin >> a[i][0] >> a[i][1];
        }
        int tmp = dp();
        if(full[W])
        {
            cout << "The minimum amount of money in the piggy-bank is " << tmp << "." << endl;
        }
        else cout << "This is impossible." << endl;
    }


}
