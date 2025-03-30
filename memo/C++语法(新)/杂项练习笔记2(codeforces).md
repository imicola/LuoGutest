#杂项练习 #codeforces

### 同时取模两数相等的总个数
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
