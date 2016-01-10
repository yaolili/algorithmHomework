#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#define LOCAL
using namespace std;

//big�����, smallС����
priority_queue<int, vector<int>, less<int> > big;
priority_queue<int, vector<int>, greater<int> > small;

void add(int value)
{
    if(small.empty())
    {
        small.push(value);
        return;
    }
    if(value > small.top())
    {
        //����С����
        if(small.size() > big.size())
        {
            big.push(small.top());
            small.pop();
        }
        small.push(value);

    }
    else
    {
        //��������
        if(big.size() > small.size())
        {
            //�������������С���ѣ����ҵ�ǰvalue���ڴ���ѵ�top������Ҫֱ�ӽ�value����С������
            //����������Ƿ�������
            if(value > big.top())
            {
                small.push(value);
                return;
            }
            small.push(big.top());
            big.pop();
        }
        big.push(value);
    }
    return ;
}

int main()
{
    #ifdef LOCAL
    freopen("data.txt", "r", stdin);
    #endif // LOCAL

    int P, caseID, M, line, tmp;
    scanf("%d", &P);
    while(P--)
    {
        while(!big.empty()) big.pop();
        while(!small.empty()) small.pop();
        vector<int> result;
        scanf("%d %d", &caseID, &M);

        for(int i = 1; i <= M; i++)
        {
            scanf("%d", &tmp);
            add(tmp);
            if(i % 2)
            {
                if(small.size() >= big.size()) result.push_back(small.top());
                else result.push_back(big.top());
            }
        }
        printf("%d %d\n", caseID, (M + 1) / 2);
        for(int i = 0; i < result.size(); i++)
        {

            if(i != 0 && (i % 10 == 0))
                printf("\n");
            printf("%d ", result[i]);
        }
        printf("\n");
    }
}
