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

vint s1,s2;
int cnt;
void merge(int L, int R, int Mid)
{
    int i = L;
    int j = Mid + 1;
    int k = L;
    while (i <= Mid && j <= R) {
        if (s1[i] <= s1[j])
            s2[k++] = s1[i++];
        else {
            cnt += Mid - i + 1;
            s2[k++] = s1[j++];
        }
    }
    while (i <= Mid) s2[k++] = s1[i++];
    while (j <= R) s2[k++] = s1[j++];
    for (i = L; i <= R; i++) s1[i] = s2[i];
}

void mergesort(int L, int R)
{
    if (L < R) {
        int Mid = (L + R) / 2;
        mergesort(L, Mid), mergesort(Mid + 1, R);
        merge(L, R, Mid);
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for (size_t i = 0; i < q; i++) {
        map<char, int> mp;
        for (size_t j = 1; j <= 26; j++) {
            char ch;
            cin >> ch;
            mp[ch] = j;
        }
        vint a(s.size() + 100, 0);
        vint r(s.size() + 100, 0);
        for (size_t p = 0; p < s.size(); p++) {
            a[p] = mp[s[p]];
        }
        s1 = a;
        s2 = vint(s.size() + 100,0);
        mergesort(0,s.size());
        cout << cnt - s.size() << endl;
        cnt = 0;
    }
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}