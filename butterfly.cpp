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
        //ע��Ҫ��p[i]�ı�֮ǰ�ͼ���ȥ����������ʵ���ۼ�
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
    //��cin cout�ᳬʱ
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
//        //ÿһ���ж�֮��Ҫ�ǵð�flag��Ϊ��ʼ��true
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
