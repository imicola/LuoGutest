#杂项练习 #codeforces

>[!tip]
>- 这是对codeforces里不会的题的详细题解,在自己平均水平之上，所以会比较详细
>- 对于较为简单的题，可以参阅[[杂项练习笔记4(codeforces)(简单ver)]]

### 同时取模两数相等的总个数
#数学
- 对两个数 $x_1,x_2$ ，从 0 到 $n$ 的所有数字中，存在 $p$ 使得 $p \mod x_1 = p \mod x_2$ 的所有 $p$ 的个数 $k$ 有  
$$
k = \left \lfloor \frac{\left( n+1 \right)}{\operatorname{lcm}{(x_1,x_2)}}\right \rfloor \cdot \min(x_1,x_2) + \begin{cases} 
(n + 1) \bmod \operatorname{lcm}(x_1, x_2) & \text{if } (n + 1) \bmod \operatorname{lcm}(x_1, x_2) < \min(x_1, x_2) \\
\min(x_1, x_2) & \text{otherwise}
\end{cases}
$$
- 可以精简为：
$$
k = \left\lfloor \frac{n+1}{\operatorname{lcm}(x_1, x_2)} \right\rfloor \cdot \min(x_1, x_2) + \min\left( (n+1) \bmod \operatorname{lcm}(x_1, x_2), \min(x_1, x_2) \right)
$$
用代码表示为：
```cpp
 k = ((n + 1) / lcm(x1,x2)) * min(x1,x2) + min((n+1)%lcm(x1,x2),min(x1,x2))
```
> [Educational Codeforces Round 175 (Rated for Div. 2)](https://codeforces.com/contest/2070/problem/A) A

### 对R1009.D3.C 异或解题思考
#数学 #二进制 
> [Codeforces Round 1009 (Div. 3) C. XOR and Triangle ](https://codeforces.com/contest/2074/problem/C)

原题目的要求是给定一个数 $x$ ，要求找到一个 $y$ 使得：
- $x + y > x \oplus y \qquad (1)$
- $y + x \oplus y > x \qquad (2)$
- $y < x \qquad \qquad \quad \ \ (3)$
有一个知识点：**加法可以用位运算表示**，即：
- $x + y = \left(x \oplus y\right) + 2 \left( x\,\&\, y \right)$
则题式就可以表示为：
$$
\begin{split}
x + y &> x \oplus y \\
 \,\ \left(x \oplus y\right) + 2 \left( x\,\&\, y \right) & > x \oplus y \\
即:\left( x\,\&\, y \right) &> 0
\end{split}
$$
同理，对(2)式有原式：$y + (x + y) - 2(x \& y) > x$ 即 $y > x\&y$

- 即我们得到条件 $\left( x\,\&\, y \right) > 0$ 和 $y > x\&y$ 
- 对二进制位分析则不难发现：
	- $y$ 的二进制位必须包含一个 $x$ 二进制位下的1 -> 对应条件 (1)
	- $y$ 的二进制位必须包含一个 $x$ 二进制位下的0 -> 对应条件 (2)
- 特殊情况分析：
	- 当 $x = 2^n$ 时不存在$y$
		- $x = 2^n$ 即$x$只有最高位为1，此时对任意 $y < x$ 有 $x \& y = 0$ , 不符合条件1
	- 当 $x$ 为全 1 数时不存在$y$ (根据条件(2)显然)
	**实现：**
- 对特殊情况，可以使用[[二进制#某些特殊二进制数判断|这个方法]]判断
- 对非特殊情况，可以使用构造，构造y为x的二进制最高有效位-1
	- `y = 1 << (31 - __bulitiz_clz(x)) - 1`

### 最大公约数(GCD)相关的优化问题
#数论

**问题**
- 考虑一个数组 $A$ 你可以时数组里的每个元素同时加任意数$d$ ,现在你需要找到数组中任意两个元素 $a_i,a_j$ 使得 $\gcd(a_i,a_j)$ 最大

正解是当我们选取$k$ 使
$$
k = \underset{A}{\max}\ a_i \,-\underset{A}{\min} a_j 
$$
- 知识点：对于任意整数 $x,y$ ,有 $\gcd(x,y)|(y-x)$ 
- 换句话说，$x$和$y$的最大公约数总是能整除他们的差
- 则对于任意一组数据$a_i,a_j$,其$\gcd(a_i + d,a_j + d)$不可能大于$\left \vert a_i - a_j \right \vert$
- 显然最大的$\left \vert a_i - a_j \right \vert$ 为 $\underset{A}{\max}\ a_i \,-\underset{A}{\min} a_j$ 
- 接下来，我们利用选取$d$的机会构造使得
$$
\gcd(\underset{A}{\max}\ a_i + d \, ,\, \underset{A}{\min} a_j + d) = \underset{A}{\max}\ a_i \,-\underset{A}{\min} a_j 
$$
我们记$\underset{A}{\max}\ a_i = M \,,\underset{A}{\min} a_j = m$ 

- 则我们构造一个$d$使得$m + d \equiv 0\, \left( \mathrm{mod}(M-m)\right)$ ,换句话说，我们得找到$d$使得$m + d$是$M-m$的倍数,则此时 $M + d$也为$M-m$的倍数
- **换句话说，$d$  一定是存在且非负的**
以上，证明完毕

> 来源：[Codeforces Round 1014 (Div. 2) A. Kamilka and the Sheep](https://codeforces.com/contest/2092/problem/A)

### 数论之质数和gcd与lcm
#数论 

**问题：**
给你一个整数 $n$ ，存在两个数$a,b$满足 $1 \leq a < b \leq n$ 现在，我们称:
$$
F\left(a,b\right) = \frac{\mathrm{lcm}(a,b)}{\gcd(a,b)}
$$
若 $F(a,b)$ 为质数，则我们称这个数对是"有趣的",现在我们想知道在满足$1 \leq a < b \leq n$的条件下有多少"有趣的"数对

思路：
- 数论基础知识：$a \cdot b = \gcd(a,b) \cdot \mathrm{lcm}(a,b)$
- 我们不妨将$F(a,b)$上下同乘$\gcd(a,b)$ 得到 $F(a,b) = \frac{a \cdot b}{\gcd^2{(a,b)}}$ 
- 设 $x = \gcd(a,b) \cdot a \ ,\ y = \gcd(a,b) \cdot b$ 
- 现在$F(a,b) = x \cdot y$ 
- 因为$F(a,b)$为质数，即$x \cdot y$为质数，根据质数性质，$x,y$必须是一个质数乘1
	- 因为 $a < b$ 且 $x = \gcd(a,b)\cdot a$ 则 $x = 1$
	- 那么 $y$ 为质数
- 那么接下来，问题变为:
	- 计算数对$(a,b)$ 中 $a \le \gcd(a,b) < \gcd(a,b) \cdot y \le n$ 的数对
- 我们将每个小于$n$质数$y$固定下来，$\gcd(a,b)$则可以取$1$到$\left \lfloor \frac{y}{n} \right \rfloor$的数
- 即对于每个$y$,有$\left \lfloor \frac{y}{n} \right \rfloor$个数对符合要求

在 $n \le 10^7$的数量下，必须先用埃式筛或欧拉筛提前准备质数数组，可以在最优$O(N + \pi(M))$ 下完成
- 其中$N$表示题目最大数据量，$M$表示测试数据最大数量
- 其中$\pi(M)$表示小于$M$的质数数量
来自：[CR1013 d3 E](https://codeforces.com/problemset/problem/2091/E)
### 二分搜索技巧
> 背景：
> 给定数组 A,B ，对A里的每个元素$a_i$我们可以做下面这个操作：
>  - 在B中选择一个元素$b_j$，使得 $a_i'= b_j - a_i$ 
>  - 问能不能实行若干次操作将数组A变为非递减序列

思路：
- 我们先对数组B进行排序，以便后续二分查找
- 对与每个$a_i$我们希望其在操作后尽可能的小，以便后续成立
- 对每一个$a_i$ 我们的任务是找到一个最小的$b_j$使得$b_j - a_i \ge a_{i-1}$ 
- 二分上，我们使用
```cpp
lower_bound(iterator_1,iterator_2,T,cmp)
```
>对于这个传函数式的传参，返回的是第一个为flase的值

则我们使用：
```cpp
lower_bound(all(b),-14,[](int k1,int k2){
	return k1 - a[i] < a[i-1];
})；
```
因为b数组已被排序，此时返回的就是b中不符合$b_j - a_i < a_{i-1}$的最小的$b_j$ 即满足$b_j - a_i \ge a_{i-1}$ 的最小的$b_j$ ,而这正是我们所需要的
- 对于每一个$a_i$ 如果找不到$b_j$ 则跳过
- 如果原本$a_i < a_{i-1}$ 且操作后仍 $b_j - a_i \ge a_{i-1}$ 则是无解的，跳过
- 其余则考虑在$b_j - a_i$ 与 $a_i$ 中找最小值
最后检查排序即可，这里可以使用`is_sorted`函数
来自：
[CR1003 d4 C_2](https://codeforces.com/problemset/problem/2065/C2)

### 贪心前缀和
> 你有一个长度为$n$的数组$A$ ,你现在可以执行下面操作直到数组为空
> - 选择一个数 $a$
> 	- 如果是 $a_i<0$ ，则用 $[a_1,a_2,\ldots,a_{i - 1}]$替换替换A(即删除以$a_i$开头的后缀)
> 	- 否则，将 $A$ 替换为 $[a_{i+1},a_{i+2},…,a_m]$ (即删除以 $a_i$ 结尾的前缀)
> - 每次选择数时将数$|a|$加入分数中
> - 我们需要最后分数最大

我们发现，每一次都是删除最左边的正数元素或删除最右边的负数元素从而获得最高的分数

则我们依据正数和负数构造两个数组表示前缀和后缀，而这些前后缀只对其对应符号的数生效

我们的答案就是找到么某个点使得其前缀加后缀最大

### 并查集策略
来自[ECR117 d2 C](https://codeforces.com/problemset/problem/2086/C)

> - 你有一个长度为 $n$ 的 **排列数组** $p$，也就是说它包含了从 $1$ 到 $n$ 的所有整数，且不重复。
> - 接下来你会收到 $n$ 个 **查询**，每个查询会把数组中某个位置的元素替换成 $0$(每个位置只会被替换一次)
> - 在每次查询之后，你要判断：**最少需要多少次操作，才能把当前这个数组恢复成一个合法的排列**（包含 $1$ 到 $n$，每个数恰好一次）。
> - 允许的操作是：对于 $1 \sim n$ 中的任意一个数 $i$，可以 **将数组的第 $i$ 个位置的值替换成 $i$**

- 思路：
	- 假设我们缺失的数字为$P_{d_i}$,我们知道最终的排列一定包含该数字，且该数字只能被放置在$P_{d_i}$,则$P_{P_{d_i}}$的数字可能被丢失，而该数字也必须被包含在排列中，以此类推。当一个数被放置在已经缺失数的位置上时候，该过程结束
- 我们只关心有哪些数会在一次修复中被涉及，我们考虑使用并查集或集合模拟
这里给出使用集合模拟的解决方法：
```cpp
void solve()
{
    int n;
    cin >> n;
    vint v(n);
    for (auto &&i : v) {
        cin >> i;
        i--;
    }
    set<int> x;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        d--;
        while (!x.contains(d)) {
            x.insert(d);
            d = v[d];
        }
        cout << x.size() << " ";
    }
    cout << endl;
}
```
- 其中核心操作为15-17行的操作
	- 维护一个集合X表示所有需要固定的位置
	- 输入其查询数字$P_{d_i}$,查询$P_{d_i}$是否在集合X中
	- 若存在，说明已经有该位置，可以则输出集合大小
	- 若不存在，则说明X中一定会增加$P_{d_i}$这个位置
		- 此时将 $P_{d_i}$ 赋值为 $d_i$ 表示查询$P_{d_i}$的位置，直到可以在集合X中找到为止
	- 因为每一次的丢失会继承到下一次查询中，所以不需要清空集合
	若使用思路也是一样的，将$P_{d_i}$ 与 $d_i$ 设置在一个集合中并且赋值，知道可以在集合中找到$P_{d_i}$ 

### 差分序列与反转下的最大值
来自：
[CR1001 d1+2 C](https://codeforces.com/problemset/problem/2062/C)
> 有一个数组 $A$  长度为 $n$ ,可以执行任意次下面的两个操作
> - 反转数组
> - 用差值序列替换序列。形式上，操作后\[a1,a2,…,an\] 变为\[a2−a1,a3−a2,…,an−an−1\] 
> 你需要求所有运算后a中元素的可能的和的最大值

思路：
- 对操作(1),反转后不会对数组和产生任何影响
- 对操作(2),构造一个差序对数组$\Delta A$ = \[$a_2​−a_1​,a_3​−a_2​,\cdots,a_m​−a_{m−1}$\]  
	- 显然对$\sum (\Delta A) = a_m - a_1$ 
	- 倘若我们先执行一遍操作(1) ,则$\sum (\Delta A') = a_1 - a_m = -\sum (\Delta A)$
- 若对 $A$ 执行 $k$ 次差分(其中可以自由执行操作(1)来构造最大值)，最终得到的序列长度为 $n - k$,其元素和正好为其元素和恰好是原序列经过 $k$ 次差分的**总和**,即$S^{(k)} = \underset{i = 1}{\overset{n-k}\sum}v_i$ 
	- 证明[^1]
- 则我们选择$k \in \{0 \sim n-1\}$的$\max(S^{(k)})$即可，特别的$S^{(0)} = \underset{i = 1}{\overset{n}\sum}a_i$ 
- 对于代码实现，直接模拟就可以
```cpp
void solve()
{
    int n;
    cin >> n;
    vint v(n);
    for (auto &&i : v) {
        cin >> i;
    }
    int ans = accumulate(all(v), 0);
    vint cur = v; //构造差序对数组
    for (size_t i = 1; i < n; i++) {
        int m = cur.size();
        int sum = 0;
        vector<int> nxt(m - 1); // 下一个差序对数组
        for (size_t k = 0; k + 1 < m; k++) {
            nxt[k] = cur[k + 1] - cur[k];
            sum += nxt[k];
        }
        ans = max(ans, abs(sum));
        cur.swap(nxt);
    }
    cout << ans << endl;
}
```

### 标答很简洁但是我写很多的难绷题目
> 来自[CR1022 d2 C](https://codeforces.com/problemset/problem/2108/C)

题目大意:
- 你有一个数组A，你可以选择一个数字放下标识
	- 这个标识可以左右移动
	- 当标识经过一个没有被标识经过的数时候就会将这个数加入到数组B中
- 我们需要数组B按单调递减排序且B含有A的所有元素
- 求最少需要放几个标识

我的思路：
- 先将数组A排序为数组B，再根据B的顺序去找A中的元素
- 其中找到第一个元素向左右扩散直到遇见上升数(即$a_i < a_{i+1}$)，将这些数加入mp和path中
	- 其中mp表示当我们在B遇到某个数时，该数有没有已经处于一个标识可以达到的集合之中，用`map<int,int>`记录
	- path表示该坐标有没有被走过
- 考虑到时间复杂度，必须使用很离谱的优化：即将数组A的数组与下标都保存在一个map中
```cpp
void solve()
{
    int n;
    cin >> n;
    vint a(n);
    for (auto &&i : a) {
        cin >> i;
    }
    vint vs = a;
    ranges::sort(vs, greater<int>{});
    //抽象优化技巧之把v[i]和其对应的下标存入map中
    map<int, vector<int>> v_index;
    for (int j = 0; j < n; ++j) {
        v_index[a[j]].push_back(j);
    }
    //为每个权重记录了下一次我们应该从 v_index[i] 向量的哪个位置开始查找
    map<int, size_t> next_idx_ptr;
    map<int, int> st;
    vint path(n, 0);
    int ans = 0;
    for (auto &&i : vs) {
        if (st[i] > 0) {
            st[i]--;
            continue;
        }
        //这个idx表示我们55行后面操作的下标
        int idx = -1;
        if (v_index.count(i)) {
            // 取当前数的所有下标集合
            vint &vi_idx = v_index[i];
            // 取这个数下标集合中进行到多少个下标
            size_t &now_idx = next_idx_ptr[i];
            while (now_idx < vi_idx.size()) {
                // f_inx 代表我们要找的第下标的实际值
                // 该下标应该满足path[idx] != 0
                int f_idx = vi_idx[now_idx];
                // 当我们找到符合的下标的时候退出
                if (path[f_idx] == 0) {
                    idx = f_idx;
                    now_idx++;
                    break;
                }
                now_idx++;
            }
        }
        // 为什么要做上面这一步？
        // 我们需要排除出现找10时候出现[... 10 10 ...] 这样的情况
        if (idx != -1) {
            ans++;
            path[idx] = 1;
            for (int k = idx; k + 1 < n; ++k) {
                if (a[k] >= a[k + 1] && path[k + 1] == 0) {
                    path[k + 1] = 1;
                    st[a[k + 1]]++;
                    continue;
                }
                break;
            }
            for (int k = idx; k - 1 >= 0; --k) {
                if (a[k] >= a[k - 1] && path[k - 1] == 0) {
                    path[k - 1] = 1;
                    st[a[k - 1]]++;
                    continue;
                }
                break;
            }
        }
    }
    cout << ans << endl; 
}
```

答案思路：
 - 其实从上面我的思路中就可以优化两点
	 1. 连续的相同数字不影响结果
	 2. 我们实际上找的是极大值点的数目
	 则非常简单的就可以出来
```cpp
void solve()
{
	int n;
	cin >> n;
	vint v;
	v.emplace_back(-1e9);
	for(int i = 0; i < n ; i++){
		int t = 0;
		cin >> t;
		if(t != v.back())v.emplace_back(t);
	}
	v.emplace_back(-1e9);
	int ans = 0;
	for(int i = 1; i + 1 < v.size() ; i++){
		if(v[i] < v[i + 1] && v[i] > v[i - 1]) ans++;
	}
	cout << ans << endl;
}
```

### 一种很新的贪心 -- 延迟决策与追溯修改
来自[CR 1026 d2 C](https://codeforces.com/contest/2110/problem/C)
> 大意:
> 你有一个飞行器，其起始高度$h_0 = 0$，同时给你一个操作数组 $d$ , $d$ 中存在两种操作可能，分别是：
> - 保持不动(0) -> $h_{i+1} = h_i$ 
> - 向上移动一位(1) -> $h_{i+1} = h_i + 1$
> - 其中还存在特殊操作 -1,代表你可以自己决定其保持不动还是上升
>
> 现在给你一些障碍，障碍的表现形式使用 $l_i,r_i$ 给出，当飞行器高度$l_i \leq h_i \leq r_i$ 时候，飞行器可以穿过障碍
> 操作从0起始，现在我们想知道能不能穿越所有障碍，如果不行输出-1,如果可以，输出整个操作数组$d$

核心思路：**延迟决策与追溯修改**
- 我们维护两个数组L，R表示$h_i$目前可以到达的可能的高度
- 维护一个栈*sk*保存出现-1的情况\[主要保存的是*idx*\]
- 对每一个障碍我们做如下判断
- 当$d_i \neq -1$时，直接根据$d_i$改变$h_i$
- 否则，将$i$，即*idx*存入栈中
- 当$h_i \notin [L,R]$ 时候
	- 当$h_i < L_i$时候，表示当前飞行器在不"人为干预"的情况下会撞到下障碍
		- 我们关注栈的状态，如果栈处于空，则直接输出-1,表示我们在之前已经没有多余的操作数去影响现在的$h_i$
		- 否则我们将栈中元素对应的*idx*的-1修改为1,并弹出栈顶表示飞行器向上移动一位
	- 当$h_i + sk.\text{size}() > R_i$时候，表示如果我们之前-1全设定为1时候会大于上障碍
		- 我们同样关注栈状态，如果栈空,直接输出-1，这表示我们没有办法通过前面的-1去降低$h_i$
		- 否则我们将栈中元素对应的*idx*的-1修改为0,并弹出栈顶,表示飞行器在之前假设最大高度下降一格

- 最后我们输出数组$d$,注意要输出`max(0,i) ` 因为到最后栈内元素不保证为空，则是我们不去控制即可，全部以0输出
>[!Tips] **延迟决策与追溯修改**
>- 对于这样的贪心思路，我们先储存操作可能，在需要操作的时候返回去修改操作的可能，我们称之为延迟操作与追溯修改
>- 这是一个非常不错的贪心思路，在这类需要全局操作和后面情况会对前项造成影响的时候可以尝试


















[^1]: 如果你连续做 $k$ 次差分，那么等价于先做一次差分得序列 $\Delta v$，再对它做一次差分 $\Delta^2 v$，……，直到 $\Delta^k v$。而每一步差分的“和”都只剩下“前者首尾之差”这种形式，所以对第 $k$ 次差分：
	$$
	 \sum (\Delta^k v) = (\Delta^{k-1} v)_{\text{末}} - (\Delta^{k-1} v)_{\text{首}}
	$$
	在最后一步我们依旧可以翻转来取正负号，于是对第 $k$ 次差分所能得到的和，就是
	$$
	\sum (\Delta^k v) =\pm \left[ (\Delta^{k-1} v)_{\text{末}} - (\Delta^{k-1} v)_{\text{首}} \right]
	$$
	而对于$(\Delta^{k-1} v)_{\text{末}}$ 与 $(\Delta^{k-1} v)_{\text{首}}$ 我们也可以用递归的方式展开，最终即可证明
