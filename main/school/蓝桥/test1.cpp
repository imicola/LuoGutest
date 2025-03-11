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

int cnt = 0;
bool check(vint mapp)
{
    vvint mapx(5, vint(5, -1));
    int k = 0;
    for (size_t i = 0; i < 5; i++) {
        for (size_t j = 0; j < 5; j++) {
            mapx[i][j] = mapp[k];
            k++;
        }
    }
    // for (auto &&i : mapx) {
    //     for (auto &&j : i) {
    //         cout << j;
    //     }
    //     cout << endl;
    // }
    // cout << "now_cnt = " << cnt;
    // cout << endl;
    for (size_t i = 0; i < 5; i++) {
        int k1 = 0;
        for (size_t j = 0; j < 5; j++) {
            if (mapx[i][j] == mapx[i][0]) {
                k1++;
            }
        }
        if (k1 == 5) {
            return 0;
        }
    }
    for (size_t i = 0; i < 5; i++) {
        int k1 = 0;
        for (size_t j = 0; j < 5; j++) {
            if (mapx[j][i] == mapx[0][i]) {
                k1++;
            }
        }
        if (k1 == 5) {
            return 0;
        }
    }
    int k3 = 0;
    for (size_t i = 0; i < 5; i++) {
        if (mapx[i][i] == mapx[0][0]) {
            k3++;
        }
    }
    if (k3 == 5) {
        return 0;
    }
    k3 = 0;
    for (size_t i = 0; i < 5; i++) {
        if (mapx[i][4 - i] == mapx[0][4]) {
            k3++;
        }
    }
    if (k3 == 5) {
        return 0;
    }
    return 1;
}

// 0 -> w
// 1 -> b
void dfs(vint mapp, int x, int type0, int type1)
{
    if (x == 25) {
        cnt += (check(mapp) ? 1 : 0);
        // for (auto &&i : mapp) {
        //     cout << i;
        // }
        cout << endl;
        return;
    }
    if (type0 > 0) {
        mapp[x] = 0;
        dfs(mapp, x + 1, type0 - 1, type1);
    }
    if (type1 > 0) {
        mapp[x] = 1;
        dfs(mapp, x + 1, type0, type1 - 1);
    }
}

signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    vint mapp(25, -1);
    dfs(mapp, 0, 13, 12);
    cout << cnt;
    return 0;
}
//