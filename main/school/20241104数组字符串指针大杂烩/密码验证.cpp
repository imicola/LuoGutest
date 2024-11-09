//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    cout << (s1 == s2 ? "same" : "different");
    return 0;
}