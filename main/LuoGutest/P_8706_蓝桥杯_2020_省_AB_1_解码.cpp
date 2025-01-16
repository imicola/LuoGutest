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
    string s;
    cin >> s;
    string res;
    for (size_t i = 0; i < s.size(); i++) {
        if (i != s.size() - 1 && !isalpha(s[i + 1])) {
            string temp;
            int j = i + 1;
            while (!isalpha(s[j]) && j < s.size()) {
                // cout << s[j];
                temp += s[j];
                j++;
            }
            // cout << temp << endl;
            // cout << endl;
            for (size_t j = 0; j < stoi(temp); j++) {
                res += s[i];
            }
            i += temp.size();
        }
        else {
            res += s[i];
        }
    }
    cout << res;
    return 0;
}