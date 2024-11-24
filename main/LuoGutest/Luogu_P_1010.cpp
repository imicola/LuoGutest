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

string erf(int t)
{
    string ans;
    if (t <= 7) {
        vint re(3);
        int k = 0;
        while (t > 0) {
            int temp = (t & 1);
            re[k++] = temp;
            t >>= 1;
        }
        string s;
        for (int i = 2; i >= 0; i--) {
            if (re[i] == 1 && i != 1)
                s += ("2(" + to_string(i) + ")+");
            else if (re[i] == 1 && i == 1)
                s += "2+";
        }
        s.pop_back();
        return s;
    }
    else {
        while (t > 7) {
            string sp;
            int high2 = -1;
            int copyt = t;
            while (copyt > 0) {
                high2++;
                copyt >>= 1;
            }
            // cout << "tt" << high2 << endl;
            string temp;
            // temp.pop_back();
            t -= pow(2, high2);
            temp += ("2(" + erf(high2) + ")");
            if (t > 0) temp += "+";
            ans += temp;
        }
        if (t > 0) ans += erf(t);
    }
    return ans;
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    cin >> t;
    cout << erf(t);
    return 0;
}