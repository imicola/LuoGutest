/*
给定一个字符串s,请你找出其中不含有重复字符的最长子串的长度
*/

//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
#define endl '\n'
#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;
    cin >> s;
    unordered_map<char, int> path;
    int ans = 0;
    int l = 0;
    for (int i = 1; i <= s.size(); i++) {
        if (path[s[i - 1]] > l && path[s[i - 1]] != 0) {
            ans = max(ans, i - l - 1);
            l = max(l, path[s[i - 1]]);
        }
        path[s[i - 1]] = i;
    }
    ans = max(ans, (int)s.size() - l);
    cout << ans;
    return 0;
}