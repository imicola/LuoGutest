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

### 贪心前缀和
> 你有一个长度为$n$的数组$A$ ,你现在可以执行下面操作直到数组为空
> - 选择一个数 $a$
> 	- 如果是 $a_i<0$ ，则用 $[a_1,a_2,\ldots,a_{i - 1}]$替换替换A(即删除以$a_i$开头的后缀)
> 	- 否则，将 $A$ 替换为 $[a_{i+1},a_{i+2},…,a_m]$ (即删除以 aiai 结尾的前缀)
> - 每次选择数时将数$|a|$加入分数中
> - 我们需要最后分数最大

我们发现，每一次都是删除最左边的正数元素或删除最右边的负数元素从而获得最高的分数

则我们依据正数和负数构造两个数组表示前缀和后缀，而这些前后缀只对其对应符号的数生效

我们的答案就是找到么某个点使得其前缀加后缀最大

