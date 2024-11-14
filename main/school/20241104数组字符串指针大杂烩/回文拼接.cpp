//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

bool stringh(string s, int a)
{
    auto it2 = s.begin() + a;
    auto it3 = s.begin() + a + 1;
    for (auto it = s.begin(); it < it2; it++, it2--) {
        if (*it != *it2) return 0;
    }
    for (auto it4 = s.end() - 1; it3 < it4; it3++, it4--) {
        if (*it3 != *it4) return 0;
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (s.size() < 4){
            cout << "No" << endl;
            continue;
        }
        bool ans = 0;
        for (size_t i = 1; i + 2 < s.size(); i++) {
            if (stringh(s, i) == 1) ans = 1;
        }
        cout << (ans ? "Yes" : "No") << endl;
    }

    return 0;
}