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

vector<char> yuan = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;
    cin >> s;
    string result;
    for (auto &&i : s) {
        if (find(all(yuan), i) != yuan.end()) {
            result += i;
        }
    }
    cout << result;
    return 0;
}