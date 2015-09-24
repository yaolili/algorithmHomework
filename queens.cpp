#include <iostream>
#include <stdio.h>
#include <cstring>
#define N 8
#define LOCAL
using namespace std;

int p[N],tot;

void print(int tot)
{
    int q[N];
    for(int i = 0; i < N; i++) q[p[i]] = i;
    cout<< "No. "<< tot<< endl;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(j != q[i]) cout<< "0 ";
            else cout<< "1 ";
        }
        cout<<"\n";
    }
    return;
}

void queen(int line)
{
    if(line == N)
    {
        tot++;
        //print the result;
        print(tot);
        return;
    }
    //遍历该行的每一列
    for(int i = 0; i < N; i++)
    {
        bool flag = true;
        p[line] = i;
        for(int j = 0; j < line; j++)
        {
            if((p[j] == p[line]) || (j + p[j] == line + p[line]) || (j - p[j] == line - p[line]))
            {
                flag = false;
                break;
            }
        }
        if(flag) queen(line+1);
    }
    return;
}

int main()
{
    #ifdef LOCAL
    freopen("data.out", "w", stdout);
    #endif // LOCAL
    memset(p, 0, sizeof(p));
    tot = 0;
    queen(0);
    return 0;
}
