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

struct S_t
{
    string name;
    int num, score_a, score_b, score_c;
};

void input(S_t *&st)
{
    cin >> st->num >> st->name >> st->score_a >> st->score_b >> st->score_c;
}

void printc(S_t *&st)
{
    cout << st->num << " " << st->name << " " << st->score_a << " " << st->score_b << " " << st->score_c << endl;
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    cin >> t;
    vector<S_t> studen(t);
    for (auto &&i : studen) {
        auto ptr = &i;
        input(ptr);
    }
    for (auto &&i : studen) {
        auto ptr = &i;
        printc(ptr);
    }
    return 0;
}