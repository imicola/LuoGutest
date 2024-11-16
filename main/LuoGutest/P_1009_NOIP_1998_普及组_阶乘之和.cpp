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
        int a1 = a[a.size() - i - 1] ^ 48;
        int b1 = b[b.size() - i - 1] ^ 48;
        int adde = a1 + b1 + p;
        if (adde >= 10) {
            adde -= 10;
            p = 1;
        }
        else
            p = 0;
        a[a.size() - i - 1] = adde ^ 48;
    }
    for (size_t i = b.size(); i < a.size(); i++) {
        int a1 = a[a.size() - i - 1] ^ 48;
        int adde = a1 + p;
        if (adde >= 10) {
            adde -= 10;
            p = 1;
        }
        else
            p = 0;
        a[a.size() - i - 1] = adde ^ 48;
    }
    if (p == 1) a.insert(a.begin(), '1');
    return a;
}

string largemit(string a, string b)
{
    if (a == "0" || b == "0") return "0";
    vector<int> result(a.size() + b.size(), 0);
    for (int i = a.size() - 1; i >= 0; i--) {
        for (int j = b.size() - 1; j >= 0; j--) {
            int mit = (a[i] ^ 48) * (b[j] ^ 48);
            int sum = result[i + j + 1] + mit;
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }
    string res = {};
    for (size_t i = 0; i < result.size(); i++) {
        if (!(result[i] == 0 && res.empty())) {
            res += to_string(result[i]);
        }
    }
    return res;
}

string jiechen(int n)
{
    if (n == 1 || n == 0) return "1";
    return largemit(to_string(n), jiechen(n - 1));
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    string s;
    for (size_t i = 1; i <= n; i++) {
        s = largeadd(s, jiechen(i));
    }
    cout << s;
    return 0;
}