// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool cmp(string s1, string s2)
{
    int k = 0;
    while (s1[k] != s2[k] && k < min(s1.size(), s2.size()) - 1) {
        k++;
    }
    if (k != min(s1.size(), s2.size()) - 1) {
        if (s1[k] > s2[k]) return s1 < s2;
        return s1 >= s2;
    }
    else {
        if (s1.size() > s2.size()) return s1 < s2;
        return s1 >= s2;
    }
}
// 987 98765 21
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<string> s(n);
    for (auto &&i : s) {
        cin >> i;
    }
    sort(s.begin(), s.end(), cmp);
    string out;
    for (auto &&i : s) {
        out += i;
        cout << i << endl;
    }
    cout << out;
    return 0;
}