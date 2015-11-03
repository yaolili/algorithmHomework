#include <iostream>
#define N 30001
using namespace std;

int p[N],s[N];

void makeSet(int m)
{
    for(int i = 0; i < m; i++)
    {
        p[i] = i;
        s[i] = 1;
    }
    return;
}

//path compression
int findParent(int i)
{
    if(p[i] != i)
    {
        p[i] = findParent(p[i]);
    }
    return p[i];
}

void united(int i, int j)
{
    int pi = findParent(i);
    int pj = findParent(j);
    if(pi != pj)
    {
        p[pj] = pi;
        s[pi] += s[pj];
    }

}

int main()
{
    int m,n;
    while(1)
    {
        cin>> m>> n;
        if(!m && !n) break;
        makeSet(m);
        for(int i = 0; i < n; i++)
        {
            int num,first,tmp;
            cin>> num>> first;
            for(int j = 1; j < num; j++)
            {
                cin>> tmp;
                //link by size
                if(s[findParent(first)] >= s[findParent(tmp)])
                    united(first, tmp);
                else united(tmp, first);
            }
        }
        cout << s[findParent(0)]<< endl;
    }
    return 0;
}
