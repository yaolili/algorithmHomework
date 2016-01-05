#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#define LOCAL

using namespace std;

//全局变量都会初始化为0
int R, C;
int f[102][102], p[102][102];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<bool> > visited(102, vector<bool>(102));

int dfs(int i, int j)
{
    if(visited[i][j]) return f[i][j];
    visited[i][j] = true;
    for(int t = 0; t < 4; t++)
    {
        int x = i + dir[t][0];
        int y = j + dir[t][1];
        if(x >= 1 && x <= R && y >= 1 && y <= C && p[x][y] < p[i][j])
        {
            f[x][y] = dfs(x, y);
            f[i][j] = f[x][y] + 1 > f[i][j] ? f[x][y] + 1: f[i][j];
        }
    }

    /*
    //up
    if(i > 1 && p[i][j] > p[i-1][j])
    {

        f[i-1][j] = dfs(i-1, j);
        f[i][j] = (f[i-1][j] + 1) > f[i][j] ? (f[i-1][j] + 1) : f[i][j];

    }
    //down
    if(i < R && p[i][j] > p[i+1][j])
    {

        f[i+1][j] = dfs(i+1, j);
        f[i][j] = (f[i+1][j] + 1) > f[i][j] ? (f[i+1][j] + 1) : f[i][j];

    }
    //left
    if(j > 1 && p[i][j] > p[i][j-1])
    {
        f[i][j-1] = dfs(i, j-1);
        f[i][j] = (f[i][j-1] + 1) > f[i][j] ? (f[i][j-1] + 1) : f[i][j];
    }
    //right
    if(j < C && p[i][j] > p[i][j+1])
    {

        f[i][j+1] = dfs(i, j+1);
        f[i][j] = (f[i][j+1] + 1) > f[i][j] ? (f[i][j+1] + 1) : f[i][j];
    }
    */
    return f[i][j];

}

int main()
{
    #ifdef LOCAL
    freopen("data.txt", "r", stdin);
    #endif // LOCAL

    cin >> R >> C;
    int maxHeight = 0;

    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= C; j++)
        {
            cin >> p[i][j];
        }
    }


    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= C; j++)
        {
            f[i][j] = dfs(i, j);
            maxHeight = f[i][j] > maxHeight ? f[i][j] : maxHeight;
        }
    }
    cout << maxHeight + 1<< endl;


    return 0;
}
