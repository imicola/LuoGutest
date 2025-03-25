#背包问题 #动态规划
# **背包DP**
- 两个特点：
1. 一个物体有 大小 + 价值
2. 有一个背包只能容纳某一个特定大小

- 要求：找最大价值

- **一般性转移方程——>** 设背包大小为 $N$,有 $Y$ 个物品 , 物品价值为 $val_i$ 物品大小为 $size_j$
- 设$dp[i][j]$ 表示任取 $0\to i$ 个物品在$j$时间下取得的$\sum a_k$的最大值
- **初始化见下**：

 ```cpp
 vector<vector<int>> dp(Y,vector<int>(N+1,0)); 
 //对[0]行的初始
 for (size_t i = size[0]; i <= N; i++) {
     dp[0][i] = val[0];
 }
 //对[0]列的初始
 //在背包初始大小为0的情况，只有 size = 0 的物品可以被装下
 for(size_t j = 0; j <= Y ; j++){
     dp[i][0] = 0;
 }
 ```

- **现在我们来推递推方程：**

- 对于一个 $dp[i][j]$ 而言表示的是在 $j$ 背包大小下取得 前$i$个$val$ 的最大值
- 从 $dp[i-1][j]$ 到 $dp[i][j]$ 有两种情况
  1. **$j < size_i$**  ===>   $dp[i][j] = dp[i-1][j]$ 即当前容量装不下 $size_i$这个物品，只能与前一个的价值相同 \= => 即增加的$val = 0$
  2.  $j > size_i$ ：
     1.  装 $size_i$ :  $dp[i][j] = dp[i][j - size[i]]+val[i]$   .*1*
     2. 不装$size_i$:   $dp[i][j] = dp[i-1][j]$

- **对 *.1* 的解释：** 选择装下大小为 $size_i$ 价值为 $val_i$ 的物品，那对$dp$从$[i-1][j]$ 到的 $[i][j]$ 而言:
  - $i$ 表示选取的范围 那显然 $i-1 \to i$ 
  - $j$ 表示背包容量大小 ： 既然我们选取了这个物品 $i$ , 那我们就看对于没有该物品时候的背包大小所表示的价值 + 这个物品 $i$ 的价值即：$j\to j-size_i$
  - $dp[i][j]$本质是最大价值，则我们需要加上所选物品的价值 即： $dp[i][j-size[i]] + val[i]$

- 在选择 $j > size_i$ 的两种情况下选择较大的一方表示最大价值
- 即完整递推表达式为：

$$
dp[i][j] =
\left\{
\begin{aligned}
&dp[i-1][j] & j < size[i] \\
&\max(dp[i-1][j],dp[i][j-size[i]]+val[i]) & j \geq size{[i]} \\
\end{aligned}
\right.
$$

**代码表示见下**

```cpp
for (size_t i = 1; i < m; i++) {
    for (size_t j = 1; j <= t; j++) {
        if (j < size[i])
            dp[i][j] = dp[i - 1][j];
        else
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - size[i]] + val[i]);
    }
}
```
