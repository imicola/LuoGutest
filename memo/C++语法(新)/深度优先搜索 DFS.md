#递归与递推 #搜索 #模板
# DFS 深度优先搜索

- **题目来源：[P1036 [NOIP2002 普及组] 选数](https://www.luogu.com.cn/problem/P1036)**
- 题目核心:
> **[NOIP2002 普及组] 选数**
> **题目描述**
> 已知 $n$ 个整数 $x_1,x_2,\cdots,x_n$，以及 $1$ 个整数 $k$（$k<n$）。从 $n$ 个整数中任选 $k$ 个整数相加，可分别得到一系列的和。例如当 $n=4$，$k=3$，$4$个整数分别为 $3,7,12,19$ 时，可得全部的组合与它们的和为：
> $3+7+12=22$
> $3+7+19=29$
> $7+12+19=38$
> $3+12+19=34$

> [!tip]
>
> - 有别于传统模拟，这种在$N$个数里找$k$个数的操作，正常人应该都不会想到使用 *循环* 或 *枚举* 但受限于知识则停滞不前
> - 其实思路很简单，选多少个数就建立多少个标记，然后从某一标记开始移动，将所有标记过的数加和即可
> - 问题是，怎么使用代码实现？

> **DFS**:深度优先搜索
> 这时候就需要用到[[递归]]搜索了。
> 该类搜索算法的特点在于，将要搜索的目标分成若干「层」，每层基于前几层的状态进行决策，直到达到目标状态。

先看核心代码

```cpp
void dfs(int m, int sum, int startx){
    if(m == k){
        if(isprime(sum))
            ans++;
        return ;
    }
    for(int i = startx; i < n; i++)
        dfs(m + 1, sum + a[i], i + 1);
    return ;
}
```

> **前置知识**：每次递归调用`dfs`时，都会创建一个新的栈帧，并将`m + 1`、`sum + a[i]`和`i + 1`作为参数传递给`dfs`函数。当`dfs`函数执行到`return`语句时，它会返回到上一个栈帧，也就是上一次调用`dfs`的地方

- 例子

> - 让我们用一个简化的例子来说明DFS算法的运行原理。假设我们有一个数组 `a = [1, 3, 5, 7]` 和 `k = 2`，我们要找出所有长度为2的子数组，其和为素数
```text
 开始
  |
  v
 dfs(0, 0, 0)  <- 初始化，m=0（子数组长度），sum=0（子数组和），startx=0（起始索引）
  |
  |
  |--> dfs(1, 1, 1)  <- 选择a\[0]，m=1，sum=1，startx=1
  |   |
  |   |--> dfs(2, 4, 2)  <- 选择a\[1]，m=2，sum=4，startx=2
  |   |   |
  |   |   |--> 检查sum=4（不是素数），结束这个分支
  |   |
  |   |<-- 返回到 dfs(1, 1, 1) \[返回到这个栈帧的时候for循环内的参数不会变化] //保留了这个栈帧的数据
  |
  |   |--> dfs(2, 8, 2)  <- 选择a\[2]，m=2，sum=8，startx=2
  |   |   |
  |   |   |--> 检查sum=8（不是素数），结束这个分支
  |   |
  |   |<-- 返回到 dfs(1, 1, 1)
  |   |
  |<----- 返回到 dfs(0, 0, 0)
  |
  |--> dfs(1, 3, 1)  <- 选择a\[1]，m=1，sum=3，startx=1
  |   |
  |   |--> dfs(2, 6, 2)  <- 选择a\[2]，m=2，sum=6，startx=2
  |   |   |
  |   |   |--> 检查sum=6（不是素数），结束这个分支
  |   |
  |   |<-- 返回到 dfs(1, 3, 1)
  |
  |   |<-- 返回到 dfs(0, 0, 0)
  |
  |--> dfs(1, 5, 1)  <- 选择a\[2]，m=1，sum=5，startx=1
  |   |
  |   |--> dfs(2, 10, 2)  <- 选择a\[3]，m=2，sum=10，startx=2
  |   |   |
  |   |   |--> 检查sum=10（不是素数），结束这个分支
  |   |
  |   |<-- 返回到 dfs(1, 5, 1)
  |
  |   |<-- 返回到 dfs(0, 0, 0)
  |
  |<-- 返回到开始
 结束
 ```
## 使用DFS实现全排列

- DFS的核心思路是一路往下寻找，不撞南墙不回头==说明当DFS到达边界情况时，就完成了一次搜索==
- 使用DFS时就要考虑完成一次**“搜索”**所需要的条件和边界情况

> **使用DFS实现全排列**
>
> - 思考第一步：全排列的一次情况的边界条件
>   - 我们不妨对DFS传入一个参数 `step` 表示完成一次全排列的步骤
>   - 当`step` 到 n 的时候，一次全排列的一种情况便结束了：
>   - 在当前情况下，我们需要做的事情是：
>     -  输出全排列的一次情况
> - Q1：如何输出一次全排列情况？
>   - A:用result数组存
> - 思考第二步：全排列的实现
>   - 我们可以使用一 个 path 来保留加入到result数组
>   - path 数组在一次查找过程中先将其标记，再进入下一个DFS函数查找，再取消标记，即一次回溯操作

```cpp
vector<bool> path;
vint result;
int t = 1;

void quan(int step)
{
    if (step == t + 1) {
        for (size_t i = 1; i <= t; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    for (size_t i = 1; i <= t; i++) {
        if (path[i] == 0) {
            path[i] = 1;
            result[step] = i;
            quan(step + 1);
            path[i] = 0;
        }
    }
    return;
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> t;
    path = vector<bool>(t + 10);
    result = vint(t + 10);
    quan(1);
    return 0;
}
```

# \[板子] 一组数据取任意个数据进行操作

**例1：在数组\[1,2,3,4,5] 中取任意个数，求这些取出来的数相加的结果**

#### 方法一：DFS爆搜
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

vint res;
void dfs(int n, int sum, int T, vint k)
{
    if (n >= T) return;
    sum += k[n];
    res.emplace_back(sum);
    for (size_t i = n + 1; i < T; i++) {
        dfs(i, sum, T, k);
    }
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    vint k(T);
    for (auto &&i : k) {
        cin >> i;
    }
    for (size_t i = 0; i < T; i++) {
        dfs(i, 0, T, k);
    }
    cout << 0 << " ";
    for (auto &&i : res) {
        cout << i << " ";
    }
    return 0;
}
```

> 其结果表现为：
> - 0 1 3 6 10 15 11 7 12 8 4 8 13 9 5 10 6 2 5 9 14 10 6 11 7 3 7 12 8 4 9 5 
> - 充分体现了人类看不懂栈帧的特点
#### 法二：DP

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

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    vint food(T);
    for(auto && i : food){
        cin >> i;
    }
    vint dp;
    dp.emplace_back(0); // 初始状态
    for (auto &&i : food) {
        vint temp = dp;
        for (auto &&j : dp) {
            temp.emplace_back(i + j);
        }
        dp = move(temp);
    }
    for (auto &&i : dp)
    {
        cout << i << " ";
    }
    return 0;
}
```

> 输出如下：
>
> 0 1 2 3 3 4 5 6 4 5 6 7 7 8 9 10 5 6 7 8 8 9 10 11 9 10 11 12 12 13 14 15
> - 已验证，两个程序的结果除了顺序完全一致
**例2: [P2036](https://www.luogu.com.cn/problem/P2036) \[COCI2008-2009 #2] PERKET**
#### 例二 法一：DFS
```cpp
//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
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

int T;
vpii food;
// vint result;
int ans = 1e6;

void dfs(int n, int sum_s, int sum_k)
{
    if (n == T) {
        sum_s *= food[n - 1].first;
        sum_k += food[n - 1].second;
        ans = min(ans, abs(sum_s - sum_k));
        return;
    }
    sum_s *= food[n].first;
    sum_k += food[n].second;
    ans = min(ans, abs(sum_s - sum_k));
    for (size_t k = 0; k < T; k++) {
        for (size_t i = n; i < T; i++) {
            dfs(i + 1, sum_s, sum_k);
        }
        sum_s = 1;
        sum_k = 0;
    }
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> T;
    food = vpii(T);
    // result = vint(T, 0);
    for (auto &&[s, k] : food) {
        cin >> s >> k;
    }
    dfs(0, 1, 0);
    cout << ans;
    return 0;
}
// 比我命还暴力这个算法
// 这题绝对能用DP写，待我研究一下
```

#### 例二 法二 ： DP

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

signed main()
{
    int T = 1;
    cin >> T;
    vector<pii> food(T);
    for (auto &&[s, k] : food) {
        cin >> s >> k;
    }
    // 使用集合记录所有可能的 (酸度, 苦度) 组合
    set<pii> dp;
    dp.emplace(1, 0); // 初始状态
    for(auto &[s, b] : food){
        set<pii> temp = dp;
        for(auto &[acid, bitter] : dp){
            temp.emplace(acid * s, bitter + b);
        }
        dp = move(temp);
    }
    // gtp写的，确实很精巧，用set记录了每个可能的情况
    // 因为初始状况是(1,0),就相当于每一次内层循环的第一次都是只选当前组的食物
    // 每一次都会把dp数组过完一遍，相当于在之前的所有情况下加一个 选择当前食物的情况
    ll result = LLONG_MAX;
    for(auto &[acid, bitter] : dp){
        if(acid != 1 || bitter != 0){
            result = min(result, abs(acid - bitter));
        }
    }
    cout << result;
    return 0;
}
```