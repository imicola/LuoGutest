//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;

bool isprime(LL n)
{
    if (n < 2) return 0;
    for (size_t i = 2; i <= n / i; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    LL t;
    cin >> t;
    string s = to_string(t);
    string result;
    result = s;
    for (int i = s.size() - 2; i >= 0; i--) {
        result += s[i];
    }
    // cout << result;
    LL resultn = stoll(result);
    if (isprime(resultn) == 0) cout << "noprime";
    else
        cout << "prime";
    return 0;
}