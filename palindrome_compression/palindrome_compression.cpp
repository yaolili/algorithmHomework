#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#define LOCAL
#define MAX 5005

using namespace std;

int N, f[2][MAX];
char s1[MAX], s2[MAX];

int main()
{
    #ifdef LOCAL
    freopen("data.txt", "r", stdin);
    #endif // LOCAL
    cin >> N;
    int i, j;
    for(i = 0, j = N-1; i < N; i++, j--)
    {
        cin >> s1[i];
        s2[j] = s1[i];
    }
    int e = 0;
    //It's not necessary to initialize f[][] yourself
    //memset(f, 0, sizeof(f));
    for(int i = 1; i <= N; i++)
    {
        e = 1 - e;
        for(int j = 1; j <= N; j++)
        {
            int tmp = 0;
            if(s1[i-1] == s2[j-1])
            {
                f[e][j] = f[1-e][j-1] + 1;
            }
            else f[e][j] = max(f[1-e][j], f[e][j-1]);

        }
    }
    cout << N - f[e][N] << endl;

    return 0;
}
