//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

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

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << largemuiti("123", "234");
    return 0;
}