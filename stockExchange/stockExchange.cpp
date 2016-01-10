#include <iostream>
#include <cstdlib>
#include <cstdio>
#define MAX 100003
#define LOCAL

using namespace std;
int L, a[MAX], f[MAX], g[MAX];

int main()
{

    #ifdef LOCAL
    freopen("data.txt", "r", stdin);
    #endif // LOCAL

    while(scanf("%d", &L) != EOF)
    {
        for(int i = 1; i <= L; i++)
        {
            scanf("%d", &a[i]);
        }
        f[0] = 0;
        int maxValue = 0, index = -1;
        for(int j = 1; j <= L; j++)
        {
            f[j] = 1;
            for(int i = 1; i < j; i++)
            {
                if(a[i] < a[j] && f[i] + 1 > f[j])
                {
                    f[j] = f[i] + 1;
                    g[j] = i;

                }

            }
            if(f[j] > maxValue)
            {
                maxValue = f[j];
                index = j;
            }

        }
        printf("%d %d\n", maxValue, f[index]);
        for(int i = 1; i <= maxValue; i++)
        {

            cout << a[index] << " ";
            index = g[index];

        }
        cout << "\n-----\n";
    }

    return 0;
}
