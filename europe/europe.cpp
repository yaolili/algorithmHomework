#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <limits.h>
#include <float.h>
#define LOCAL

using namespace std;

double dp(int bridgeLoad, int bridgeLength, int n, vector<vector<int> > &cars)
{
    vector<double> f(n + 1, DBL_MAX);
    f[0] = 0.0;
    for(int j = 1; j <= n; j++)
    {
        int weight = 0;
        int speed = INT_MAX;
        for(int i = j; i > 0; i--)
        {
            weight += cars[i][0];
            if(weight > bridgeLoad) break;
            if(speed > cars[i][1])
            {
                speed = cars[i][1];
            }

            double time = (bridgeLength * 1.0 / speed) * 60 + f[i - 1];
            if(f[j] > time)
            {
                f[j] = time;
            }

        }
    }
    return f[n];
}

int main()
{
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    #endif // LOCAL

    int bridgeLoad, bridgeLength, n;
    int weight, speed;
    while(1)
    {
        cin>> bridgeLoad >> bridgeLength >> n;
        if(!bridgeLoad && !bridgeLength && !n) break;

        vector<vector<int> > cars(n + 1, vector<int>(2));


        for(int i = 1; i <= n; i++)
        {
            cin>> weight>> speed;
            cars[i][0] = weight;
            cars[i][1] = speed;
        }

        /*
        for (int i = 1; i <= n; i++)
        {
            cout << cars[i][0]<< " , "<< cars[i][1]<< endl;
        }
        */
        printf("%.1f\n", dp(bridgeLoad, bridgeLength, n, cars));
    }
    return 0;
}
