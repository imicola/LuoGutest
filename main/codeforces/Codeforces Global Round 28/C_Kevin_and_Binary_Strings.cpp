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
    int t = 1;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int l1, r1, l2, r2;
        l1 = 1;
        r1 = s.size();
        int first_0 = s.find_first_of('0'); //return index + 1 // -1 notfind
        if (first_0 == -1) {
            r2 = l2 = s.size();
            cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
            continue;
        }
        else {
            string s1 = s.substr(first_0);
            int maxx = -1;
            for (size_t i = 0; i < s.size() - s1.size() + 1; i++) {
                int diffsum = 0;
                for (size_t j = i; j < i + s1.size(); j++) {
                    if (s[j] != s1[j - i]) {
                        diffsum++;
                    }
                }
                if (diffsum > maxx) {
                    l2 = i + 1;
                    r2 = l2 + s1.size() - 1;
                    maxx = diffsum;
                }
            }
            cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
        }
    }

    return 0;
}