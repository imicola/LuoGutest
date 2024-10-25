#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int a;
    cin >> a;
    if (a == 1 || a == 6)
    {
        cout << "汉堡";
    }
    else if (a == 2 || a == 5)
    {
        cout << "炸鸡";
    }
    else
    {
        cout << "披萨";
    }
    
    return 0;
}