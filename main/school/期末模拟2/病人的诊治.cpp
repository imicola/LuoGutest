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

struct person
{
    string s;
    int bz, age;
};

bool cmp(const person &a, const person &b)
{
    if (a.bz == b.bz) {
        if (a.age == b.age) return a.s < b.s;
        return a.age > b.age;
    }
    return a.bz > b.bz;
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    vector<person> p(n);
    for (auto &&[a, b, c] : p) {
        cin >> a >> b >> c;
    }
    sort(all(p), cmp);
    for (auto &&[a, b, c] : p) {
        cout << a << " " << b << " " << c << endl;
    }
    return 0;
}