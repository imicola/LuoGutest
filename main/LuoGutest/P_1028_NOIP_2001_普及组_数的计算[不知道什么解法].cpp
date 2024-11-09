//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int ans;

void dfs(int n,int p)
{
    ans++;
    if (p < 1) return;
    dfs(p, p / 2);
    dfs(p, p - 1);
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    dfs(n, n / 2);
    cout << (ans + 1) / 2;
    return 0;
}