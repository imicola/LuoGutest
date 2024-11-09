//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a[10], b[10], c[10];
    int ak_a, ak_b, ak_c;
    int p_a, p_b, p_c, result_a = 0, result_b = 0, result_c = 0;
    cin >> ak_a;
    for (size_t i = 0; i < 10; i++) {
        cin >> a[i];
        result_a += a[i];
    }
    cin >> p_a;
    result_a += p_a * 20;
    cin >> ak_b;
    for (size_t i = 0; i < 10; i++) {
        cin >> b[i];
        result_b += b[i];
    }
    cin >> p_b;3
    result_b += p_b * 20;
    cin >> ak_c;
    for (size_t i = 0; i < 10; i++) {
        cin >> c[i];
        result_c += c[i];
    }
    cin >> p_c;
    result_b += p_c * 20;
    //我们使用特殊的技巧来提高AK的权重，只要AK权重提高点足够高，便可忽略罚时对ak数的影响
    //便可以把三人的ak数和罚时数整合起来
    int out_a, out_b, out_c;
    out_a = (result_a)- ak_a * 1000;
    out_b = (result_b)- ak_b * 1000;
    out_c = (result_c)- ak_c * 1000;
    //map 数据类型，可以存储两个类型的数据并按从小到大排序
    map<int, string> mp;
    mp[out_a] = "alisa";
    mp[out_b] = "折鸦";
    mp[out_c] = "imicola";
    for (auto &&i : mp) {
        cout << i.second << endl;
    }
    return 0;
}