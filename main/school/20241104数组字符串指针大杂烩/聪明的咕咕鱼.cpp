//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<string> s = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    string a;
    cin >> a;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == a) {
            cout << 7 - i;
        }
    }

    return 0;
}