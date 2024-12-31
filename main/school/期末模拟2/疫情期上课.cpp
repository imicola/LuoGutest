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
    int _class = 0;
    int cnt = 0;
    int ch = 0;
    int ma = 0;
    int en = 0;
    while (cin >> _class) {
        if (_class == 1) {
            ch++;
            cnt++;
        }
        else if (_class == 2) {
            ma++;
            cnt++;
        }
        else if (_class == 3) {
            en++;
            cnt++;
        }
    }
    cout << cnt << endl;
    cout << "Chinese:" << ch << endl;
    cout << "Math:" << ma << endl;
    cout << "English:" << en << endl;
    return 0;
}