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

string preprocess(const string &s)
{
    string t = "^";
    for (char c : s) {
        t += "#" + string(1, c);
    }
    t += "#$";
    return t;
}

string longestPalindrome(const string &s)
{
    string T = preprocess(s);
    int n = T.size();
    vector<int> P(n, 0); //P[i] 记录以 t[i] 为中心的回文半径
    int C = 0, R = 0;    //C 是回文中心，R 是回文串的最右边界
    for (size_t i = 1; i < n - 1; i++) {
        // 确定对称位置
        int Mirror = 2 * C - i;
        if (i < R) {
            P[i] = min(P[Mirror], R - i);
        }
        // 尝试扩展边界
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
            P[i]++;
        }
        // 如果当前回文串扩展超过了 R，更新中心和右边界
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }
    // 找到最长的回文子串
    int maxLen = 0;
    int Centerindex = 0;
    for (size_t i = 0; i < n - 1; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            Centerindex = i;
        }
    }
    // 构造回文串
    int start = (Centerindex - maxLen) / 2;
    return s.substr(start, maxLen);
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;
    cin >> s;
    cout << longestPalindrome(s) << endl;
    return 0;
}