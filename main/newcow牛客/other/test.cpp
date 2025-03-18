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
    int n;
    cin >> n;
    map<string, int> p;
    vstr p1(n);
    for (size_t i = 0; i < n; i++) {
        string s1;
        cin >> s1;
        p[s1]++;
        p1[i] = s1;
    }
    int up, cnt = 0;
    cin >> up;
    vstr vs;
    string s2;
    while (cin >> s2) {
        if (p[s2] != 0) {
            vs.emplace_back("-");
            cnt++;
        }
        vs.emplace_back(s2);
    }
    if (cnt > up) {
        cout << cnt << endl;
        cout << "He Xie Ni Quan Jia!" << endl;
    }
    if (vs.size() != 1) {
        for (auto &&i : vs) {
            if (i == "-") {
                cout << "<censored> ";
            }
            else {
                cout << i << " ";
            }
        }
    }
    else {
        string s3 = vs[0];
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < s3.size(); j++) {
                int cnt2 = 0;
                for (size_t k = 1; k <= p1[i].size() && j + k < s3.size(); k++) {
                    if (s3[j + k] == p1[i][k - 1] && s3[j + k] != '|') {
                        cnt2++;
                    }
                    // cout << s3[j + k] << " " << p1[i][k - 1] << endl;
                }
                // cout << cnt2 << " " << p1[i].size() << endl;
                if (cnt2 == p1[i].size()) {
                    cnt++;
                    for (size_t k = j; k < j + p1[i].size(); k++) {
                        s3[k] = '|';
                    }
                }
            }
        }
        for (size_t i = 0; i < s3.size(); i++) {
            
        }
    }

    return 0;
}