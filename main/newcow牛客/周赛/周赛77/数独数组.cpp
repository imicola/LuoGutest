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
    int T = 1;
    cin >> T;
    map<int, int> mp;
    for (size_t i = 0; i < T; i++) {
        int temp;
        cin >> temp;
        mp[temp]++;
    }
    for (size_t i = 1; i <= 9; i++) {
        if (T % 9 == 0 && mp[i] != T / 9) {
            cout << "NO";
            return 0;
        }
        if (T % 9 != 0) {
            if (mp[i] < T / 9 || mp[i] > T / 9 + 1) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";

    return 0;
}