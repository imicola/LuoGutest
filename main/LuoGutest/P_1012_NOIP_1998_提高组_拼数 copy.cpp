// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool cmp(string s1, string s2)
{
    if(stoll(s1 + s2) > stoll(s2 + s1))
    {
        return 1;
    }
    return 0;
} 

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
        // cout << i << endl;
    }
    cout << out;
    return 0;
}