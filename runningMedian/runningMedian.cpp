#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#define LOCAL
using namespace std;

//big大根堆, small小根堆
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
        //放入小根堆
        if(small.size() > big.size())
        {
            big.push(small.top());
            small.pop();
        }
        small.push(value);

    }
    else
    {
        //放入大根堆
        if(big.size() > small.size())
        {
            //当大根堆数大于小根堆，并且当前value大于大根堆的top，就需要直接将value放入小根堆中
            //其他情况都是放入大根堆
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
