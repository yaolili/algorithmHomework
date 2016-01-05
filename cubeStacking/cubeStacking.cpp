#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
#define MAX 30003
#define LOCAL

using namespace std;

//p记录父亲节点，b记录与父节点的距离(实际上是在该元素底下的节点有多少个), s记录孩子数(实际上是在该元素上面的元素)
int p[MAX], d[MAX], s[MAX];

/*
方法一：
//p记录父亲节点，s记录孩子数， b记录最底部节点编号
int p[MAX], s[MAX], b[MAX];
不进行路径压缩，每个节点都去更新s、b,这种做法会超时

方法二：
//p记录父亲节点，改用vector s记录孩子编号， b记录最底部节点编号
int p[MAX], b[MAX];
vector<vector<int> > s(MAX, vector<int>(1));
进行路径压缩，需要记录根节点的所有孩子编号，内存超了

这两种思路都是考虑栈顶元素为根节点
因为我前面考虑的是如果没有路径压缩，可以保存所有的路径关系；如果压缩之后还要保证结果正确
我就想要保存孩子的节点编号，实际上换种思路往上考虑也是可以的。

把栈底的元素当做根节点
*/

void makeSet()
{
    for(int i = 1; i < MAX; i++)
    {
        p[i] = i;
        s[i] = 1;
        d[i] = 0;
    }
}


int findParent(int i)
{
    if(p[i] != i)
    {
        int tmp = p[i];
        p[i] = findParent(p[i]);
        d[i] += d[tmp];
    }
    return p[i];
}


void unionSet(int i, int j)
{
    int pi = findParent(i);
    int pj = findParent(j);


//    cout << "i = " << i << " , j = " << j << endl;
//    cout << "pi = " << pi << " , pj = " << pj << endl;
//    cout << "si = " << s[i] << " , sj = " << s[j] << endl;
//    cout << "di = " << d[i] << " , dj = " << d[j] << endl;
//    cout << "p[" << pi << "] : " << p[pi] << " => " << pj << endl;
//    cout << "d[" << pi << "] : " << d[pi] << " => " << d[pi] + s[pj] << endl;
//    cout << "s[" << pj << "] : " << s[pj] << " => " << s[pj] + s[pi] << endl;
//    cout << "-------------" << endl;


    p[pi] = pj;
    d[pi] += s[pj];
    s[pj] += s[pi];
}

int main()
{
    #ifdef LOCAL
    freopen("data.txt", "r", stdin);
    //freopen("out.txt", "w+", stdout);
    #endif // LOCAL

    int P, u, v;
    char ch;
    scanf("%d\n", &P);
    makeSet();
    while(P--)
    {
        scanf("%c", &ch);
        if(ch == 'M')
        {
            scanf("%d %d\n", &u, &v);
            unionSet(u, v);
        }
        else
        {
            scanf("%d\n", &u);
            int pu = findParent(u);
            printf("%d\n",  d[u]);
        }
    }
    return 0;
}
