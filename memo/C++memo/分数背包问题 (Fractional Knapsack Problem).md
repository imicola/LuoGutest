#贪心 #背包问题
# 分数背包问题 (*Fractional Knapsack Problem*)
>代表题目：洛谷P2240[部分背包问题][https://www.luogu.com.cn/problem/P2240] 
  > 部分背包问题，本质甚至不是动态规划，而是贪心,这个题名出的非常具有迷惑性
  特点：
  >   1. 有一个容量为$T$ 的背包
  >   2. 有$N$组物品，每组物品分别有以下两个特性：
  >      1. 价值：这堆物品所代表的价值
  >      2. 重量：这堆物品的重量
  >   3. 与经典的0/1背包不同的是，分数背包允许将物品划分为重量为 1 的单位物品
  >   ==策略：先计算每一堆物品的单位价值，再根据单位价值装填背包。==
  > 对P2240代码如下：
```cpp
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
   
   bool cmp(pair<double, int> a, pair<double, int> b)
   {
       if (a.first == b.first) return a.second > b.second;
       return a.first > b.first;
   }
   signed main()
   {
       //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
       int n, t;
       cin >> n >> t;
       vector<pair<double, int>> coin(n);
       for (auto &&[val, wei] : coin) {
           double m, v;
           cin >> m >> v;
           val = (v / m);
           wei = m;
       }
       sort(all(coin), cmp);
       double ans = 0;
       for (size_t i = 0; i < n; i++) {
           if (t >= coin[i].second) {
               ans += coin[i].second * coin[i].first;
               t -= coin[i].second;
           }
           else {
               ans += coin[i].first * t;
               break;
           }
       }
       printf("%.2f", ans);
       return 0;
   }
   ```

> 不难发现这其实是一种贪心而非背包问题