#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    int x1 = a/b;
    int x2 = a%b;
    int x3 = (a = b);
    int c = (a >= b);
    int d = (a != b);
    int x5 = (a&&b);
    cout << x1 <<" "<< x2 <<" "<< x3 <<" "<< c <<" "<< d <<" "<< x5;
    return 0;
}