//#pragma GCC optimize(3)
#include <bits/stdc++.h>
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

int main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    vvint mp(2, vint(n));
    for (size_t i = 0; i < 2; i++) {
        for (size_t j = 0; j < n; j++) {
            char a;
            cin >> a;
            if (a == '.')
                mp[i][j] = 0;
            else
                mp[i][j] = 1;
        }
    }
    int ans = 0;
    

    return 0;
}