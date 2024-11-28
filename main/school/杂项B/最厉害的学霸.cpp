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

struct xueba
{
    string name;
    int a, b, c;
};

bool cmp(const xueba &a, const xueba &b)
{
    if (a.a + a.b + a.c == b.a + b.b + b.c) {
        if (a.a == b.a) return 0;
        return a.a > b.a;
    }
    return (a.a + a.b + a.c > b.a + b.b + b.c);
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    cin >> t;
    xueba st[t];
    for (size_t i = 0; i < t; i++) {
        cin >> st[i].name >> st[i].a >> st[i].b >> st[i].c;
    }
    sort(st, st + t, cmp);
    cout << st[0].name << " " << st[0].a << " " << st[0].b << " " << st[0].c;
    return 0;
}