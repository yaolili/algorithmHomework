#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
#define MAX 30003
#define LOCAL

using namespace std;

//p��¼���׽ڵ㣬b��¼�븸�ڵ�ľ���(ʵ�������ڸ�Ԫ�ص��µĽڵ��ж��ٸ�), s��¼������(ʵ�������ڸ�Ԫ�������Ԫ��)
int p[MAX], d[MAX], s[MAX];

/*
����һ��
//p��¼���׽ڵ㣬s��¼�������� b��¼��ײ��ڵ���
int p[MAX], s[MAX], b[MAX];
������·��ѹ����ÿ���ڵ㶼ȥ����s��b,���������ᳬʱ

��������
//p��¼���׽ڵ㣬����vector s��¼���ӱ�ţ� b��¼��ײ��ڵ���
int p[MAX], b[MAX];
vector<vector<int> > s(MAX, vector<int>(1));
����·��ѹ������Ҫ��¼���ڵ�����к��ӱ�ţ��ڴ泬��

������˼·���ǿ���ջ��Ԫ��Ϊ���ڵ�
��Ϊ��ǰ�濼�ǵ������û��·��ѹ�������Ա������е�·����ϵ�����ѹ��֮��Ҫ��֤�����ȷ
�Ҿ���Ҫ���溢�ӵĽڵ��ţ�ʵ���ϻ���˼·���Ͽ���Ҳ�ǿ��Եġ�

��ջ�׵�Ԫ�ص������ڵ�
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
