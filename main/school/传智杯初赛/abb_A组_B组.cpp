#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

/*
三个数据结构分别存放
fir_ch -> 字符串
mp1    -> 读取字符时存入哈希表的 key(即字符) val(即字符出现的数量)
mp2    -> 实际解决时会使用的哈希表和mp1存储类型一致
*/

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    long long ans = 0;
    cin >> n;
    vector<char> fir_ch(n);
    unordered_map<char, int> mp1;
    unordered_map<char, int> mp2;
    // 简单读取数据
    for (size_t i = 0; i < n; i++) {
        char temp = '0';
        cin >> temp;
        fir_ch[i] = temp;
        mp1[temp]++;
    }
    // 这串循环十分诡异但巧妙
    // 我们先需要了解对这个长度为 n 的字符串的第 i 个字符，它能组成的abb型字符的算式
    // 即 ---> ai = C(2,b1) + C(2,b2) + C(2,b3)....+C(2,bk);
    // 其中 ai 表示第 i 个字符，它能组成的abb型字符的数量
    // bk表示除去 i 字符的其他每一个字符在序列i后出现的数量
    // bk 可以表示为 bn - bm --> 其中bn表示这个字符在字符串出现的数量，bm表示在序列 i 之前的数量
    // 我们要求的就是所有ai的和，用ans表示即可
    // 表示完所有东西我们就用哈希表(mp2)来愉快存放数据进行计算啦
    for (size_t i = 0; i < n; i++) {
        for (auto it = mp1.begin(); it != mp1.end(); it++) {
            if (fir_ch[i] == it->first) continue;
            int temp = (it->second - mp2[it->first]);
            ans += (temp * (temp - 1)) / 2;
        }
        mp2[fir_ch[i]]++;
    }
    cout << ans;
    return 0;
}