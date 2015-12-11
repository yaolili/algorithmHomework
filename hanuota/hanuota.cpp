#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#define LOCAL

using namespace std;

void print(int index, char from, char to)
{
    cout << index << ":" << from << "->" << to <<endl;
    return;
}

void hanuo(int n, char from, char dependent, char to)
{
    if(n == 1)
        print(n, from, to);
    else
    {
        hanuo(n - 1, from, to, dependent);
        print(n, from, to);
        hanuo(n - 1, dependent, from, to);
    }
    return;
}

int main()
{
    int n;
    char a, b, c;
    cin >> n >> a >> b >> c;
    hanuo(n, a, b, c);
    return 0;
}
