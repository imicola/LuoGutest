#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

//假设 a > b
string largeadd(string a, string b)
{
    int p = 0;
    int len = max(a.size(), b.size()) + 1;
    string s;
    for (size_t i = 0; i < b.size(); i++) {
        int ai = a[a.size() - i - 1] - '0';
        int bi = b[b.size() - i - 1] - '0';
        int sum = ai + bi;
        if (sum >= 10) {
            p = 1;
            sum -= 10;
        }
        s[a.size() - 1 - i] = sum + '0';
    }
    
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    return 0;
}