#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<string> jiechengans(1010, "0");

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

string jiecheng(int a)
{
    jiechengans[0] = "1";
    jiechengans[1] = "1";
    jiechengans[2] = "2";
    for (int i = 1; i <= a; i++) {
        if (jiechengans[i] != "0")
            continue;
        else {
            jiechengans[i] = largemuiti(to_string(i), jiechengans[i - 1]);
        }
    }
    return jiechengans[a];
}

int strcount(string a, int num)
{
    int result = 0;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] == num + '0') result++;
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    clock_t be = clock();
    // int n;
    // cin >> n;
    // for (size_t i = 0; i < n; i++) {
    //     int k, p;
    //     cin >> k >> p;
    //     cout << strcount(jiecheng(k), p) << endl;
    // }
    cout << jiecheng(10000) <<endl;
    clock_t ed = clock();
    cout << ed - be << "ms";
    return 0;
}