//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int y1, m1, d1, y2, m2, d2;
    cin >> y1 >> m1 >> d1;
    cin >> y2 >> m2 >> d2;
    if (m2 - m1 == 0) {
        cout << y2 - y1 << "岁" << endl;
    }
    else if (m2 - m1 < 0) {
        cout << y2 - y1 - 1 << "岁零" << m2 + 12 - m1 << "个月" << endl;
    }
    else {
        cout << y2 - y1 << "岁零" << m2 - m1 << "个月" << endl;
    }
    return 0;
}