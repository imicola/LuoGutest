#pragma GCC optimize(3)
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
    string s = "123456789";
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    for (size_t i = 100; i < 1000; i++) {
        for (size_t j = 100; j < 1000; j++) {
            for (size_t k = 100; k < 1000; k++) {
                string p = to_string(i) + to_string(j) + to_string(k);
                sort(all(p));
                if (p == s && i * 2 == j && i * 3 == k) {
                    cout << i << " " << j << " " << k << endl;
                }
            }
        }
    }

    return 0;
}