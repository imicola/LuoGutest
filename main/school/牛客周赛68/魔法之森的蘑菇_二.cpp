#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mapp(n + 1, vector<int>(m + 1, 0));
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= m; j++) {
            char temp;
            cin >> temp;
            if (temp == '.')
                mapp[i][j] = 0;
            else
                mapp[i][j] = 1;
        }
    }
    int L1 = 1, L2 = 1;
    vector<vector<int>> mapx(n + 1, vector<int>(m + 1, 0));
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= m; j++) {
            mapx[i][j] = mapp[i][j] + mapx[i - 1][j] + mapx[i][j - 1] - mapx[i - 1][j - 1];
        }
    }
    pair<int, int> ans1 = {0, 0};
    int ans = 0;
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    // L1 长
    // L2 宽
    while (L1 <= m) {
        while (L2 <= n) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (mapx[i][j] - mapx[i - L2][j] - mapx[i - L1][j] + mapx[i - L1][j - L2] == 0) {
                        ans1.first = L1;
                        ans1.second = L2;
                        x2 = j;
                        y2 = i;
                        x1 = j - L1 + 1;
                        y1 = i - L2 + 1;
                    }
                }
            }
            L2++;
        }
        L1++;
    }
    cout << y1 << " " << x1 << " " << y2 << " " << x2;
    return 0;
}

// 010
// 000
// 010