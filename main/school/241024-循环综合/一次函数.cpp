#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n,k,b;
    int flag = 0;
    cin >> n >> k >> b;
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin >> x >> y;
        if (k*x + b == y)
        {
            flag++;
        }
    }
    cout << flag;
    return 0;
}