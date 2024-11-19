//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    char mapp[35][35];
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= m; j++) {
            cin >> mapp[i][j];
        }
    }
    int ax1 = 0, ay1 = 0, ax2 = 0, ay2 = 0, maxx = 0, maxy = 0;
    // int L1 = 0, L2 = 0; // L1 长 L2 ;
    for (size_t y1 = 1; y1 <= n; y1++) {
        for (size_t x1 = 1; x1 <= m; x1++) {
            for (size_t y2 = y1; y2 <= n; y2++) {
                for (size_t x2 = x1; x2 <= m; x2++) {
                    bool ishave = true;
                    for (size_t i = y1; i <= y2; i++) {
                        for (size_t j = x1; j <= x2; j++) {
                            if (mapp[i][j] == '*') ishave = false;
                        }
                    }
                    if (ishave && (((x2 - x1 + 1) * (y2 - y1 + 1)) > (maxx * maxy))) {
                        ay1 = y1;
                        ax1 = x1;
                        ay2 = y2;
                        ax2 = x2;
                        maxx = x2 - x1 + 1;
                        maxy = y2 - y1 + 1;
                    }
                }
            }
        }
    }

    cout << ay1 << " " << ax1 << " " << ay2 << " " << ax2;
    return 0;
}