//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<string> s(n);
    for (size_t i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s.begin(), s.end(), [](string a, string b) { return a <= b; });
    for (auto &&i : s) {
        cout << i << endl;
    }

    return 0;
}