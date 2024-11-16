#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string largemin(string a, string b)
{
    int flag = 0;
    if (b.size() >= a.size() && b >= a) {
        swap(a, b);
        flag = 1;
    }
    int p = 0;
    for (size_t i = 0; i < b.size(); i++) {
        int ai = a[a.size() - 1 - i] - '0';
        int bi = b[b.size() - 1 - i] - '0';
        int diff = ai - bi - p;
        if (diff < 0) {
            p = 1;
            diff += 10;
        }
        else
            p = 0;
        a[a.size() - i - 1] = diff + '0';
    }
    for (size_t i = b.size(); i < a.size(); i++) {
        int ai = a[a.size() - i - 1] - '0';
        if (ai == 0 && p == 1) {
            a[a.size() - i - 1] = '9';
        }
        else {
            a[a.size() - i - 1] = ai - p + '0';
            p = 0;
        }
    }
    while (*a.begin() == '0' && a.size() > 1) a.erase(a.begin());
    if (flag) a.insert(a.begin(), '-');
    return a;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string a, b;
    cin >> a >> b;
    cout << largemin(a, b);
    return 0;
}