#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<char>> mapp(r + 2, vector<char>(c + 2, '.'));
    for (int i = 1; i <= r; i++) {
        for (size_t k = 1; k <= c; k++) {
            cin >> mapp[i][k];
        }
    }
    int x_min = 1000, x_max = 0, y_max = 0, y_min = 1000;
    for (int i = 1; i <= r; i++) {
        for (int k = 1; k <= c; k++) {
            if (mapp[i][k] == '.') continue;
            if (mapp[i][k] == 'X') {
                int flag = 0;
                if (mapp[i][k - 1] == '.') flag++;
                if (mapp[i][k + 1] == '.') flag++;
                if (mapp[i - 1][k] == '.') flag++;
                if (mapp[i + 1][k] == '.') flag++;
                if (flag > 2) {
                    mapp[i][k] = '0';
                }
                if (flag <= 2) {
                    if (k < x_min) x_min = k;
                    if (k > x_max) x_max = k;
                    if (i > y_max) y_max = i;
                    if (i < y_min) y_min = i;
                }
            }
        }
    }
    for (int i = y_min; i <= y_max; i++) {
        for (int k = x_min; k <= x_max; k++) {
            if (mapp[i][k] == '0') {
                cout << '.';
                continue;
            }
            cout << mapp[i][k];
        }
        cout << endl;
    }
    return 0;
}
//模拟题之最会用if的一集