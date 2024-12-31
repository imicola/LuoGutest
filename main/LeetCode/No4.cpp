//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
#define endl '\n'
#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

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

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int m, n;
    cin >> m >> n;
    vector<int> nums1(m);
    vector<int> nums2(n);
    cin >> nums1;
    cin >> nums2;
    vector<int> p;
    int i = 0, j = 0;
    while (i < m || j < n) {
        if (i >= m) {
            p.emplace_back(nums2[j]);
            j++;
            continue;
        }
        if (j >= n) {
            p.emplace_back(nums1[i]);
            i++;
            continue;
        }
        if (nums1[i] < nums2[j]) {
            p.emplace_back(nums1[i]);
            i++;
        }
        else if (nums1[i] > nums2[j]) {
            p.emplace_back(nums2[j]);
            j++;
        }
        else {
            p.emplace_back(nums1[i]);
            p.emplace_back(nums2[j]);
            i++;
            j++;
        }
    }
    if ((m + n) % 2 == 1) {
        cout << p[(m + n) / 2];
    }
    else {
        double x = (p[(m + n) / 2] + p[(m + n) / 2 - 1]) / (2.0);
        printf("%.5f", x);
    }
    return 0;
}