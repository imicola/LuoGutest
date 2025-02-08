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

class Solution
{
public:
    int reverse(int x)
    {
        string s;
        if (x >= 0) {
            s = to_string(x);
            std::reverse(s.begin(), s.end());
            // while (*s.begin() == '0') s.erase(s.begin());
            long long p = stoll(s);
            if (p >= INT32_MIN && p <= INT32_MAX)
                return p;
            else
                return 0;
        }
        else {
            s = to_string(x);
            s.erase(s.begin());
            std::reverse(s.begin(), s.end());
            s = "-" + s;
            long long p = stoll(s);
            if (p >= INT32_MIN && p <= INT32_MAX)
                return p;
            else
                return 0;
        }
    }
};

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    Solution so;
    cout << so.reverse(T);
    return 0;
}