#include <iostream>
#include <stdio.h>
#define N 1001
#define LOCAL
using namespace std;

int p[N];
bool b[N];

void makeSet(int n)
{
    for(int i = 0; i < n; i++)
    {
        p[i] = i;
        b[i] = 0;
    }
}

int findParent(int i)
{
    if(p[i] != i)
    {
        int tmp = p[i];
        p[i] = findParent(p[i]);
        //注意要在p[i]改变之前就加上去，这样才能实现累加
        b[i] = (b[i] + b[tmp]) % 2;
    }
    return p[i];
}

bool united(int i, int j, bool type)
{
    int pi = findParent(i);
    int pj = findParent(j);
    if(pi == pj)
    {
        if((b[i] + b[j] + type) % 2) return false;
    }
    else
    {
        p[pj] = pi;
        b[pj] = (b[i] + b[j] + type) % 2;
    }
    return true;
}

int main()
{
    int n, m, pairOne, pairTwo;
    bool type;
    bool flag = true;
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    #endif // LOCAL
    //用cin cout会超时
//    while(cin >> n>> m)
//    {
//        makeSet(n);
//        for(int i = 0; i < m; i++)
//        {
//            cin >> pairOne >> pairTwo>> type;
//            if(!united(pairOne, pairTwo, type))
//            {
//                flag = false;
//            }
//
//        }
//        if(flag) cout<< "YES"<< endl;
//        else cout<< "NO"<< endl;
//        //每一组判断之后要记得把flag变为初始的true
//        flag = true;
//    }
    while(scanf("%d %d\n", &n, &m) != EOF)
    {
        makeSet(n);
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d %d\n", &pairOne, &pairTwo, &type);
            if(!united(pairOne, pairTwo, type))
            {
                flag = false;
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
        flag = true;
    }
    #ifdef LOCAL
    fclose(stdin);
    #endif // LOCAL
    return 0;
}
