//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef pair<int, int> pii;

void transfromx(int n, int r)
{
    string s = "0123456789ABCDEF";
    string result;
    while (n > 0) {
        result += s[n % r];
        n /= r;
    }
    reverse(all(result));
    cout << result;
}

int main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n, r;
    cin >> n >> r;
    transfromx(n, r);
    return 0;
}