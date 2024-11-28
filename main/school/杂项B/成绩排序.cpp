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

struct cj
{
    string name;
    vint c = vint(3, 0);
};

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    cin >> t;
    vector<cj> a(t);
    for (auto &&i : a) {
        cin >> i.name;
        for (size_t j = 0; j < 3; j++) {
            cin >> i.c[j];
        }
    }
    sort(all(a), [](cj a, cj b) {
        if (a.c[0] + a.c[1] + a.c[2] == b.c[0] + b.c[1] + b.c[2]) return a.name < b.name;
        return a.c[0] + a.c[1] + a.c[2] > b.c[0] + b.c[1] + b.c[2];
    });
    for (auto &&i : a) {
        cout << i.name << " ";
        int sum = 0;
        for (size_t j = 0; j < 3; j++) {
            sum += i.c[j];
        }
        cout << sum << endl;
    }
    return 0;
}
