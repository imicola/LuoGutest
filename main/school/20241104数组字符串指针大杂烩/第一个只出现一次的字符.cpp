//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    unordered_map<char, int> mp;
    for (auto &&i : s) mp[i]++;
    for (auto &&i : s) {
        if (mp[i] == 1) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}