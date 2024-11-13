//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

string largeadd(string a, string b)
{
    if (a.size() < b.size()) swap(a, b);
    int p = 0;
    for (size_t i = 0; i < b.size(); i++) {
        int ai = a[a.size() - i - 1] - '0';
        int bi = b[b.size() - i - 1] - '0';
        int sum = ai + bi + p;
        if (sum >= 10) {
            p = 1;
            sum -= 10;
        }
        else
            p = 0;
        a[a.size() - 1 - i] = sum + '0';
    }
    for (size_t i = b.size(); i < a.size(); i++) {
        int ai = a[a.size() - i - 1] - '0';
        if (ai == '9' && p == 1) {
            a[a.size() - i - 1] = '0';
        }
        else {
            a[a.size() - i - 1] = ai + p + '0';
            p = 0;
        }
    }
    if (p == 1) a.insert(a.begin(), '1');
    return a;
}
vector<string> dp(1010);

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, n;
    cin >> m >> n;
    dp[0] = "1";
    dp[1] = "1";
    for (int i = 2; i <= n; i++) {
        dp[i] = largeadd(dp[i - 1], dp[i - 2]);
    }
    cout << dp[n-m];
    return 0;
}
