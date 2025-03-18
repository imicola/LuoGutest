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
    int n, m;
    cin >> n >> m;
    vector<unordered_map<int, int>> p(n + 1);
    for (size_t i = 1; i <= n; i++) {
        int px;
        cin >> px;
        for (size_t j = 0; j < px; j++) {
            int pl;
            cin >> pl;
            p[i][pl]++;
        }
    }
    int q;
    cin >> q;
    for (size_t i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        int cnt = 0;
        for (auto &&i : p) {
            if (i.find(a) != i.end() && i.find(b) != i.end()) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}