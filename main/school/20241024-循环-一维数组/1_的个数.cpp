#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n,flag = 0;
    cin >> n;
    for(int a = 32; a > 0 ; a--) if(1&(n >> a)) flag++;
    cout << flag;
    return 0;
}