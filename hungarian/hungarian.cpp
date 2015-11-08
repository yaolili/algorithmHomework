#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#define LOCAL

using namespace std;

//remain to fix
//bool bfs(const vector<vector<int> > &lnklst, vector<int> &left, vector<int> &right, int u, int m)
//{
//    vector<bool> visited(m);
//    queue<int> q;
//
//    for(int i = 0; i < lnklst[u].size(); i++)
//    {
//        int v = lnklst[u][i];
//        q.push(v);
//    }
//
//    while(!q.empty())
//    {
//        int v = q.front();
//        q.pop();
//        if(visited[v]) continue;
//        visited[v] = true;
//        //v已经被匹配过了
//        if(right[v] >= 0)
//        {
//
//            int newU = right[v];
//            for(int i = 0; i < lnklst[newU].size(); i++)
//            {
//                int newV = lnklst[newU][i];
//                q.push(newV);
//            }
//
//        }
//        else
//        {
//            right[v] = u;
//            left[u] = v;
//            return true;
//        }
//
//    }
//
//    return false;
//}


bool dfs(const vector<vector<int> > &lnklst, vector<int> &left, vector<int> &right, vector<bool> &visited, int u)
{
    for(int i = 0; i < lnklst[u].size(); i++)
    {
        int v = lnklst[u][i];
        if(visited[v]) continue;
        visited[v] = true;
        if(right[v] < 0 || dfs(lnklst, left, right, visited, right[v]))
        {
            right[v] = u;
            left[u] = v;
            return true;
        }
    }
    return false;
}

int match(const vector<vector<int> > &lnklst, vector<int> &left, vector<int> &right)
{
    int matchNum = 0;
    for(int u = 0; u < lnklst.size(); u++)
    {
        //注意left、right初始化为-1
        //这里可以不用这个语句，但在已有的网络图中求增广路径时有意义
        if(left[u] >= 0) continue;
        for(int i = 0; i < lnklst[u].size(); i++)
        {
            int v = lnklst[u][i];
            if(right[v] < 0)
            {
                left[u] = v;
                right[v] = u;
                matchNum++;
                break;
            }
        }
    }
    return matchNum;

}

int hungarian(const vector<vector<int> > &lnklst, int m)
{
    int n = lnklst.size();
    vector<int> left(n, -1);
    vector<int> right(m, -1);
    int maxMatch = match(lnklst, left, right);
    for(int u = 0; u < lnklst.size(); u++)
    {
        if(left[u] < 0)
        {
            //visited数组只记录右边节点
            vector<bool> visited(m);
            if(dfs(lnklst, left, right, visited, u))
//            if(bfs(lnklst, left, right, u, m))
            {
                maxMatch++;
            }

        }
    }
    return maxMatch;
}

int main()
{
    int n,m;
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    #endif // LOCAL

    while(cin >> n>> m)
    {
        vector<vector<int> >lnklst(n);
        for(int u = 0; u < n; u++)
        {
            int num;
            cin >> num;
            while(num--)
            {
                int v;
                cin >> v;
                //注意这里下标从0开始
                lnklst[u].push_back(v - 1);
            }
        }

        cout<< hungarian(lnklst, m)<< endl;
    }
    return 0;
}
