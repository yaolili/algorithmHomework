#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#define LOCAL

using namespace std;

int N;
vector<char> s1, s2;
short f[5002][5002];


int main()
{
    #ifdef LOCAL
    freopen("data.txt", "r", stdin);
    #endif // LOCAL

    char c;

    stack<char> st;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> c;
        s1.push_back(c);
        st.push(c);
    }
    while(!st.empty())
    {
        c = st.top();
        s2.push_back(c);
        st.pop();
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(s1[i-1] == s2[j-1]) f[i][j] = 1 + f[i-1][j-1];
            else f[i][j] = max(f[i-1][j], f[i][j-1]);
        }
    }
    cout << N - f[N][N] << endl;

    return 0;
}
