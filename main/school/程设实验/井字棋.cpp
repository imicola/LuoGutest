//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<vector<char>> map0(3, vector<char>(3));
    for (auto &&i : map0) {
        for (auto &&j : i) {
            cin >> j;
        }
    }
    for (size_t i = 0; i < 3; i++) {
        if (map0[i][1] == map0[i][0] && map0[i][1] == map0[i][2] && map0[i][0] != 'O') {
            if (map0[i][1] == 'K')
                cout << "KiKi wins!";
            else
                cout << "BoBo wins!";
            return 0;
        }
        if (map0[1][i] == map0[0][i] && map0[1][i] == map0[2][i] && map0[0][i] != 'O') {
            if (map0[1][i] == 'K')
                cout << "KiKi wins!";
            else
                cout << "BoBo wins!";
            return 0;
        }
        if (map0[0][0] == map0[1][1] && map0[1][1] == map0[2][2] && map0[0][0] != 'O') {
            if (map0[0][0] == 'K')
                cout << "KiKi wins!";
            else
                cout << "BoBo wins!";
            return 0;
        }
        if (map0[0][2] == map0[1][1] && map0[1][1] == map0[2][0] && map0[1][1] != 'O') {
            if (map0[1][1] == 'K')
                cout << "KiKi wins!";
            else
                cout << "BoBo wins!";
            return 0;
        }
    }
    cout << "No winner!";
    return 0;
}