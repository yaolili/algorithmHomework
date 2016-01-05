#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <math.h>
#define LOCAL

using  namespace std;

int corridorPosition(int roomIndex)
{
    return ceil(roomIndex / 2.0);

}

int main()
{
    #ifdef LOCAL
    freopen("data.txt", "r", stdin);
    #endif // LOCAL
    int T, N, s, t;
    int p[201];
    cin >> T;
    while(T--)
    {
        memset(p, 0, sizeof(p));
        cin >> N;
        for(int i = 0; i < N; i++)
        {
            cin >> s >> t;

            int index1 = corridorPosition(s);
            int index2 = corridorPosition(t);
            int first = index1 < index2? index1 : index2;
            int last = index1 < index2? index2 : index1;
            for(int j = first; j <= last; j++)
            {
                p[j] += 10;
            }
        }
        int maxTime = 0;
        for(int i = 1; i <= 200; i++)
        {
            maxTime = p[i] > maxTime? p[i] : maxTime;
        }
        cout << maxTime << endl;
    }
    return 0;
}
