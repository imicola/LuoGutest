//#pragma GCC optimize(3)
#include <bits/stdc++.h>
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

// 比较函数，用于排序
bool cmp(pii a, pii b)
{
    // 如果两个pii的第二个元素相等，则比较第一个元素
    if (a.second == b.second) return a.first < b.first;
    // 否则比较第二个元素
    return a.second > b.second;
}

int main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int m, n, k, l, d;
    // 输入m, n, k, l, d
    cin >> m >> n >> k >> l >> d;
    unordered_map<int, int> ry;
    unordered_map<int, int> rx;
    // 遍历d次，输入temp1y, temp1x, temp2y, temp2x
    for (size_t i = 0; i < d; i++) {
        int temp1y, temp1x, temp2y, temp2x;
        cin >> temp1y >> temp1x >> temp2y >> temp2x;
        // 如果temp1x == temp2x，则将temp1y和temp2y的最小值作为key，value加1
        if (temp1x == temp2x) {
            ry[min(temp1y, temp2y)]++;
        }
        // 如果temp1y == temp2y，则将temp1x和temp2x的最小值作为key，value加1
        if (temp1y == temp2y) {
            rx[min(temp1x, temp2x)]++;
        }
    }
    set<int> resulty;
    set<int> resultx;
    // 将ry和rx中的元素存入vector中
    vector<pii> ryy(ry.begin(), ry.end());
    vector<pii> rxx(rx.begin(), rx.end());
    // 对rxx和ryy进行排序
    sort(all(rxx), cmp);
    sort(all(ryy), cmp);
    // 将ryy的前k个元素存入resulty中
    for (size_t i = 0; i < k; i++) {
        resulty.insert(ryy[i].first);
    }
    // 将rxx的前l个元素存入resultx中
    for (size_t i = 0; i < l; i++) {
        resultx.insert(rxx[i].first);
    }
    // 输出resulty中的元素
    for (auto &&i : resulty) {
        cout << i << " ";
    }
    cout << endl;
    // 输出resultx中的元素
    for (auto &&i : resultx) {
        cout << i << " ";
    }
    return 0;
}