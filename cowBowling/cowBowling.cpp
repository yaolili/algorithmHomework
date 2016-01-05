#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#define LOCAL

using namespace std;

int f[352][352], p[352][352], N;
bool visited[352][352];

int dp(int i, int j)
{
    if(visited[i][j]) return f[i][j];
    if(i == N) return p[i][j];

    visited[i][j] = true;
    f[i+1][j] = dp(i+1, j);
    f[i+1][j+1] = dp(i+1, j+1);
    f[i][j] = max((p[i][j] + f[i+1][j]), (p[i][j] + f[i+1][j+1]));
    return f[i][j];
}

int main()
{
    #ifdef LOCAL
    freopen("data.txt", "r", stdin);
    #endif // LOCAL

    int tmp;
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            cin >> p[i][j];
        }
    }

    cout << dp(1, 1) << endl;
    return 0;
}
