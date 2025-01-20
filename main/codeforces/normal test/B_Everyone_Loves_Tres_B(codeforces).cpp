#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 1 || a == 3) {
            cout << -1 << endl;
            continue;
        }
        string s;
        s += "66";
        int len = 2,flag = 0;
        while (a - len > 0) {
            if ((a - len)%2 == 1 && flag == 0) {
                s += "363";
                len += 3;
                flag++;
                continue;
            }
            s += "33";
            len += 2;
            //cout << a - len << endl;
        }
        reverse(s.begin(), s.end());
        cout << s << endl;
    }

    return 0;
}