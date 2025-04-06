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

void solve()
{
    int n;
    cin >> n;
    stack<unsigned long long> a;
    while (n--) {
        string s;
        cin >> s;
        if (s == "push") {
            unsigned long long p;
            cin >> p;
            a.push(p);
            continue;
        }
        else if (s == "pop") {
            if (a.empty()) {
                cout << "Empty" << endl;
            }
            else {
                a.pop();
            }
            continue;
        }
        else if (s == "query") {
            if (a.empty()) {
                cout << "Anguei!" << endl;
            }
            else {
                cout << a.top() << endl;
            }
            continue;
        }
        else if (s == "size") {
            cout << a.size() << endl;
            continue;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int TT = 1;
    cin >> TT;
    while (TT--) {
        solve();
    }
    return 0;
}