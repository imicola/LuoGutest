//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    auto itb = s.begin();
    auto ite = s.end() - 1;
    while (ite > itb) {
        if (*itb != *ite) {
            cout << "No!";
            return 0;
        }
        else {
            itb++;
            ite--;
        }
    }
    cout << "Yes!";
    return 0;
}