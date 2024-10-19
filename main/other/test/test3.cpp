#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    if (a+b > 7)
    {
        cout << (a+b)%7;
    }
    else
    {
        cout << a+b;
    }
    return 0;
}