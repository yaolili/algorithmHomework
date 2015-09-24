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
    //�����ֱ�Ӻ͸��ڵ�Ƚ�
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
    //��ʱ�Ѿ���Ҷ�ӽڵ���
    if(2 * i > heapSize) return;
    int children = 2 * i;
    //�ҳ����Һ��ӽڵ��н�С���Ǹ�
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
    //ɾ�����һ���ڵ�
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
        //�ǵ�ÿ�������������֮��Ҫ��heapSize���
        heapSize = 0;
    }
    return 0;
}
