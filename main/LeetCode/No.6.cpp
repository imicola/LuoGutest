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
    string convert(string s, int numRows)
    {
        vector<vector<char>> arr(numRows, vector<char>(s.size(), '#'));
        int p = 0;
        int i = 0, j = 0;
        while (p < s.size()) {
            if (i % (numRows - 1) == 0) {
                for (j = 0; j < numRows; j++) {
                    arr[j][i] = s[p];
                    p++;
                    if (p >= s.size()) {
                        break;
                    }
                }
                i++;
                j--;
                continue;
            }
            j--;
            arr[j][i] = s[p];
            i++;
            p++;
        }
        string s2;
        for (auto &&i : arr) {
            for (auto &&j : i) {
                if (j != '#') s2 += j;
                // cout << j;
            }
            // cout << endl;
        }
        return s2;
    }
};

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    Solution So;
    string s1;
    int k;
    cin >> s1 >> k;
    cout << So.convert(s1, k);

    return 0;
}