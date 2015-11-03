#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define LOCAL

using namespace std;

struct interval
{
    int first;
    int last;
};
bool cmp(interval x, interval y)
{
    if(x.first == y.first) return x.last < y.last;
    return x.first < y.first;
}

void mergeInterval(interval arr[], int n)
{
    sort(arr, arr + n, cmp);
    interval tmp = arr[0];
    for(int j = 1; j < n; j++)
    {
        if(arr[j].first > tmp.last)
        {
            printf("no");
            return;
        }
        else if(arr[j].last > tmp.last) tmp.last = arr[j].last;
    }
    printf("%d %d", tmp.first, tmp.last);
    return;
}
int main()
{
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    #endif // LOCAL

    int n;
    scanf("%d\n", &n);
    interval *arr;
    arr = (interval *)malloc(n * sizeof(interval));
    for(int j = 0; j < n; j++)
    {
        scanf("%d %d", &arr[j].first, &arr[j].last);
    }

    mergeInterval(arr, n);
    return 0;
}
