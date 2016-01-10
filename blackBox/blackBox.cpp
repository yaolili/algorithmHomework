#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
#define LOCAL
using namespace std;

priority_queue<int> big;
priority_queue<int, vector<int>, greater<int> > small;

void add(int index, int value)
{
    if(big.size() < index)
    {
        //要从value以及small.top()中找到更小的数插入到big中
        small.push(value);
        big.push(small.top());
        small.pop();
    }
    else
    {
        if(value >= big.top())
            small.push(value);
        else
        {
            small.push(big.top());
            big.pop();
            big.push(value);
        }
    }
    return;
}

int main()
{
    #ifdef LOCAL
    freopen("data.txt", "r", stdin);
    #endif // LOCAL
    int m, n, a[30003], u[30003];

    scanf("%d%d", &m, &n);
    for(int i = 1; i <= m; i++)
    {
        scanf("%d", &a[i]);
    }

    int flag = 1;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &u[i]);
        int j;
        for(j = flag; j <= u[i]; j++)
        {
            add(i, a[j]);
        }
        flag = j;
        if(big.size() == i)
        {
            printf("%d\n", big.top());
        }
        else
        {
            big.push(small.top());
            small.pop();
            printf("%d\n", big.top());
        }

    }

    return 0;
}
