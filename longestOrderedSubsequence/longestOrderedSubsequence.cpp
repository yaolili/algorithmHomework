#include <iostream>
#include <cstdlib>
#include <cstdio>
#define LOCAL

using namespace std;
int N, f[1003], a[1003];

int dp()
{
    int max_value = 0;
    for(int j = 1; j <= N; j++)
    {
        f[j] = 1;
        for(int i = 1; i < j; i++)
        {
            if(a[j] > a[i])
            {
                f[j] = f[j] > (f[i] + 1) ? f[j] : (f[i] + 1);
            }
        }
        if(f[j] > max_value) max_value = f[j];
    }
    return max_value;
}

int main()
{
    #ifdef LOCAL
    freopen("data.txt", "r", stdin);
    #endif // LOCAL
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }
    cout << dp() << endl;
    return 0;
}
