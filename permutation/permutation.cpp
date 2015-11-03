#include <iostream>
#include <string>

using namespace std;

void swap(string &s, int a, int b)
{
    int tmp = s[a];
    //换前，从后往前挪
    if(a - b > 1)
    {
        for(int i = a; i > b; i--)
        {
            s[i] = s[i-1];
        }
    }
    //换后，从前往后挪
    else if(b - a > 1)
    {
        for(int i = a; i < b; i++)
        {
            s[i] = s[i+1];
        }
    }
    else
    {
        s[a] = s[b];
    }
    s[b] = tmp;
    return;
}

void permulation(string &s, int i, int NUM)
{
    if(i >= NUM)
    {
        cout<< s <<endl;
        return;
    }
    else
    {
        for(int j = i; j < NUM; j++)
        {
            swap(s, j, i);
            permulation(s, i+1, NUM);
            swap(s, i, j);
        }

    }
    return;
}

int main()
{
    string s;
    cin>> s;
    permulation(s, 0,s.size());
    return 0;
}
