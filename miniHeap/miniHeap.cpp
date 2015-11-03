#include <stdio.h>
#include <math.h>
#define N 100002
#define LOCAL

int p[N];
int heapSize;


void shiftUp(int i)
{
    if(i == 1) return;
    int parent = floor(i / 2);
    //这里就直接和父节点比较
    if(p[i] < p[parent])
    {
        int tmp = p[i];
        p[i] = p[parent];
        p[parent] = tmp;
        shiftUp(parent);
    }
    return;
}

void shiftDown(int i)
{
    //此时已经到叶子节点了
    if(2 * i > heapSize) return;
    int children = 2 * i;
    //找出左右孩子节点中较小的那个
    if(children + 1 <= heapSize && p[children] > p[children + 1]) children += 1;
    if(p[i] > p[children])
    {
        int tmp = p[i];
        p[i] = p[children];
        p[children] = tmp;
        shiftDown(children);
    }
    return;
}

void del(int i)
{
    printf("%d\n", p[i]);
    //删除最后一个节点
    if(i == heapSize)
    {
        heapSize -= 1;
        return;
    }

    int x = p[i];
    p[i] = p[heapSize];
    heapSize -= 1;
    if(p[i] < x) shiftUp(i);
    else shiftDown(i);
    return;
}

void add(int i)
{
    heapSize += 1;
    p[heapSize] = i;
    shiftUp(heapSize);
    return;
}

int main()
{
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif // LOCAL

    int caseNum;
    scanf("%d\n", &caseNum);
    for(int i = 0; i < caseNum; i++)
    {
        int operationNum;
        scanf("%d\n", &operationNum);
        for(int j = 0; j < operationNum; j++)
        {
            int type;
            scanf("%d ", &type);
            if(type == 1)
            {
                int element;
                scanf("%d", &element);
                add(element);
            }
            //type == 2
            else del(1);
        }
        //记得每组测试数据完了之后要把heapSize清空
        heapSize = 0;
    }
    return 0;
}
