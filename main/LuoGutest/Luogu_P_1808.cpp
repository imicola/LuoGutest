#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, int> t;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        t[s]++;
    }
    int ans = 0;
    for (auto&& i : t) {
        if (i.second != 0) ans++;
    }
    cout << ans << endl;
}