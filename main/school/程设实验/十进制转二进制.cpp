//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<char> ans;
    int n, flag = 0;
    cin >> n;
    if (n < 0) {
        n = abs(n);
        flag++;
    }
    for (int a = 31; a >= 0; a--) ans.push_back(((n >> a) & 1) ^ 48);
    while (*ans.begin() == '0' && ans.size() > 1) ans.erase(ans.begin());
    ans.push_back('B');
    if (flag) ans.insert(ans.begin(), '-');
    for (auto &&i : ans) cout << i;
    return 0;
}