//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<vector<char>> farm(10, vector<char>(10, '.'));
    pair<int, int> index_B, index_R, index_L;
    for (size_t i = 0; i < 10; i++) {
        for (size_t j = 0; j < 10; j++) {
            cin >> farm[i][j];
            if (farm[i][j] == 'B') {
                index_B.first = i;
                index_B.second = j;
            }
            else if (farm[i][j] == 'R') {
                index_R.first = i;
                index_R.second = j;
            }
            else if (farm[i][j] == 'L') {
                index_L.first = i;
                index_L.second = j;
            }
        }
    }
    if(((index_B.first == index_L.first && index_R.first == index_B.first) && (index_R.second > min(index_B.second, index_L.second) &&
        index_R.second < max(index_B.second, index_L.second))) ||
        ((index_B.second == index_L.second && index_R.second == index_B.second ) && index_R.first > min(index_B.first, index_L.first) &&
            index_R.first < max(index_B.first, index_L.first)))
        cout << abs(index_B.first - index_L.first) + abs(index_B.second - index_L.second) + 1;
    else
        cout << abs(index_B.first - index_L.first) + abs(index_B.second - index_L.second) - 1;
    return 0;
}