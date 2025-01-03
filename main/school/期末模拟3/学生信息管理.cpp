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

struct St
{
    int n;
    string name;
    int cj1, cj2, cj3;
};

void input(St &a)
{
    cin >> a.n >> a.name >> a.cj1 >> a.cj2 >> a.cj3;
}

void output(St &a)
{
    cout << a.n << " " << a.name << " " << a.cj1 << " " << a.cj2 << " " << a.cj3 << endl;
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    vector<St> s(t);
    for (auto &&i : s) {
        input(i);
        output(i);
    }

    return 0;
}