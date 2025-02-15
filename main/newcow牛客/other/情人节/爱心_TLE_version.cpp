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

vint TLE = {2,  3,  5,  6,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
            21, 22, 23, 24, 25, 26, 27, 28, 30, 31, 32, 33, 34, 38, 39, 40, 46};

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cout << 49 << endl;
    for (size_t i = 1; i <= 49; i++) {
        if (find(all(TLE), i) != TLE.end()) {
            cout << 1000 << " " << 10000 << endl;
            for (size_t i = 0; i < 1000; i++) {
                cout << 1 << " ";
            }
            cout << endl;
            for (size_t i = 1; i < 1000; i++) {
                cout << 1 << " " << 1000 << endl;
            }
        }
        else {
            cout << "1 1" << endl;
            cout << 1 << endl;
            cout << "1 1" << endl;
        }
    }

    return 0;
}