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

// 通用版本的 >> 重载,用于任意类型的 std::vector<T>
template <typename T> istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v) {
        in >> x;
    }
    return in;
}
// 通用版本的 << 重载,用于任意类型的 std::vector<T>
template <typename T> ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const auto &x : v) {
        out << x << ' ';
    }
    return out;
}

int main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vint a(n);
        cin >> a;
        sort(all(a));
        cout << a;
    }
    return 0;
}