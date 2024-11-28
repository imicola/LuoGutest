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

struct st
{
    string stnum, name;
    vint a = vint(6, 0);
};

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    cin >> t;
    vector<st> ap(t);
    for (size_t i = 0; i < t; i++) {
        cin >> ap[i].stnum >> ap[i].name;
        for (size_t j = 0; j < 6; j++) {
            cin >> ap[i].a[j];
        }
    }
    string s;
    cin >> s;
    for (size_t i = 0; i < t; i++) {
        if (ap[i].stnum == s) {
            cout << ap[i].name << " ";
            int sum = 0;
            for (size_t j = 0; j < 6; j++) {
                sum += ap[i].a[j];
            }
            cout << sum << " ";
            printf("%.2f", (sum / 6.0));
        }
    }

    return 0;
}