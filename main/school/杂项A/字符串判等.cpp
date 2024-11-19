//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    string s3, s4;
    for (auto &&i : s1) {
        if (isalpha(i)) {
            s3 += i;
        }
    }
    for (auto &&i : s2) {
        if (isalpha(i)) {
            s4 += i;
        }
    }
    auto it1 = s3.begin();
    for (auto it2 = s4.begin(); it1 != s1.end() && it2 != s4.end(); it1++, it2++) {
        if (*it1 - *it2 != 0 && abs(*it1 - *it2) != (int)('a' - 'A')) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}