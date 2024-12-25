#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct Date
{
    int y, m, d;
};

int main()
{
    Date k;
    auto [y, m, d] = k;
    cin >> y >> m >> d;
    int a = 0;
    int m0[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) m0[2]++;
    for (size_t i = 1; i < m; i++) {
        a += m0[i];
    }
    cout << a + d;
    return 0;
}