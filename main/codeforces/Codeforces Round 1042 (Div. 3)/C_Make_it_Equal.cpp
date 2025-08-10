//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
#define endl '\n'
// #define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

void solve()
{
    int n, k;
    cin >> n >> k;
    map<int, int> mps, mpt;
    for (size_t i = 0; i < n; i++) {
        int t;
        cin >> t;
        mps[t % k]++;
    }
    for (size_t i = 0; i < n; i++) {
        int t;
        cin >> t;
        mpt[t % k]++;
    }
    set<int> modk;
    for (auto &&i : mps) {
        modk.insert(i.first);
    }
    for (auto &&i : mpt) {
        modk.insert(i.first);
    }
    for (auto &&i : modk) {
        if(i == 0){
            if(mps[i] != mpt[i]){
                cout << "NO" << endl;
                return;
            }
        }
        if (k % 2 == 0 && i == k / 2) {
            if (mps[i] != mpt[i]) {
                cout << "NO" << endl;
                return;
            }
        }
        if (mps[i] + mps[(k - i) % k] != mpt[i] + mpt[(k - i) % k]){
            cout << "NO" << endl;
            return;
        } }
    cout << "YES" << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}