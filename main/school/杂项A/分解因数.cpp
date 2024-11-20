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

int ant(int n, int befromnum)
{
    int ans = 0;
    if (n == 1) return 1;
    for (size_t i = befromnum; i <= n; i++) {
        if (n % i == 0) {
            ans += ant(n / i, i);
        }
    }
    return ans;
}

int main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << ant(n, 2) << endl;
    }
    return 0;
}