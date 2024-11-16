//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

string largeadd(string &a, string b)
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
        if (ai == 9 && p == 1) {
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

string largemuiti(string a, string b)
{
    if (a == "0" || b == "0") return "0";
    int len1 = a.size();
    int len2 = b.size();
    vector<int> result(len1 + len2, 0);
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mult = (a[i] - '0') * (b[j] - '0');
            int sum = result[i + j + 1] + mult;
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }
    string res = "";
    for (size_t i = 0; i < result.size(); i++) {
        if (!(result[i] == 0 && res.empty())) {
            res += to_string(result[i]);
        }
    }
    return res;
}

string jiecheng(int n)
{
    if (n == 1 || n == 0) return "1";
    return largemuiti(to_string(n), jiecheng(n - 1));
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    string s;
    for (int i = 1; i <= n; i++) {
        s = largeadd(s, jiecheng(i));
    }
    cout << s;
    return 0;
}