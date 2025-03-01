//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
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

int get_2_low0(int n)
{
    int mask = (~n) & -(~n);
    int res = __builtin_ctz(mask);
    if (pow(2, res) > n) return -1;
    return res;
}

void solve()
{
    int n, x;
    cin >> n >> x;
    if (n == 1) {
        cout << x << endl;
        return;
    }
    int maxx = pow(2, get_2_low0(x)) - 1;
    if (get_2_low0(x) == -1) {
        int temp = 0 , temp2 = 0;
        for (size_t i = 0; i < n - 1  && i <= x; i++) {
            cout << i << " ";
            temp |= i;
            temp2 = i;
        }
        if(temp2 == n - 1){
            cout << endl;
            return;
        }
        else
        {
            if(temp2 == n - 2 && ((temp2 + 1)|temp) == x){
                cout << temp2 + 1;
                cout << endl;
                return;
            }
            for (size_t i = 0; i < n - temp2 - 2; i++)
            {
                cout << 0 << " ";
            }
            cout << x << endl;
        }
    }
    else {
        for (size_t i = 0; i <= maxx && i < n; i++) {
            cout << i << " ";
        }
        for (size_t i = 0; i < n - maxx - 2; i++) {
            cout << 0 << " ";
        }
        cout << x << endl;
    }
    return;
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}