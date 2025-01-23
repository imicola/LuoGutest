#STL #容器
# 1 [vector](https://zh.cppreference.com/w/cpp/container/vector)

**构造**

**一维数组：** `vector<类别> dp(长度，初值)` [^5]

**二维数组：**`vector<vector<int>> dp(行数,vector<int> (列数,初值)); `

**三维数组：**

```cpp
 vector<vector<vector<int>>> dp3(3层,vector<vector<int>>(行数,vector<int> (列数,0)));
```

*等价于 `int mat[][][]`*

> [!note]
>
> 我们也可以使用 `vector<vector<int>> dp(100,vector<int>())`来构建不指定列数的二维数组

## 1.1 尾接与尾删

- 尾接： `dp.push_back(x)`[解释：在dp数组末尾添加数字x]
- 尾删：`dp.pop_back(x)`[解释：在dp数组末尾删除数字x]

## 1.2 size函数

- `dp.size()`[解释：获取dp数组的长度(数组内有多少个数)]

## 1.3清空数组

- `dp.clear()`[清空数组内数据]

## 1.4 empty函数

 使用`dp.empty()`判断数组是否为空，空返回true(1)，非空返回false(0)

 一般这个函数会放在if语句中

 ```cpp
 if(dp.empty()) //如果数组为空，则执行语句
 {
     //....
 }
 ```

## 1.5  resize函数

- `dp.resize(m,n)`[m表示新大小，n表示：如果增加长度，多出来的位置的默认数字]
- 注意resize函数改小的话，会将多出来的数据删除

## 1.6 访问vector的数据

- 使用dp[x],访问dp数组内x-1的数据

## 1.7 vector的赋值与读取

1. 一维数组的赋值

- 方法一(推荐)

```cpp
vector<int> dp(10,0);
for(int i = 0;i < k; i++)
{
    int temp;
    cin >> temp;
    dp.pish_back(temp);
}
```

- 方法二(不推荐)

```cpp
vector<int> dp(10,0);
for(int i = 0;i < k; i++)//k不能大于10(k > 10 也可以读入dp,但是会有诡异的bug)
{
    cin >> dp[i];
}
```

> [!note]
>
> **所以动态读写一套下来为：**
>
```cpp
> vector<int> dp(0,0);
> for (size_t i = 0; i < 15; i++)
> {
>     int temp;
>     cin >> temp;
>     dp.push_back(temp);
> }
> 
> for (size_t i = 0; i < dp.size(); i++)
> {
>     cout << dp[i] <<" ";
> }
```

2. 二维数组动态读写

> [!note]
```cpp
> vector <vector<int>> dp;
> vector<int> dp1;
> for (int i = 0; i <k; i++)    
> {
>     for (int j = 0; j <p; j++) //内部数组保存
>     {
>         int value;
>         cin >> value;
>         v.push_back(dp1); 
>     }
>     dp.push_back(dp1); //保存dp1的每个元素到dp[i]中
>     dp1.clear(); //清空dp1内元素
> }
> 
> for (int i = 0; i <array.size(); i++)
> {
>     for (int j = 0; j < p; j++)
>     {
>         cout <<array[i][j];
>     }
>     cout<<endl;
> }
> return 0;
```
>
> - 思路：先建立动态二维数组dp和动态临时一维数组dp1
> - dp1负责保存单行数据
> - dp负责保存dp1保存下来的行数据从而形成多数据
> - 记得clear dp1的元素

## 1.8 vector的使用情况

- 例：$n\times m$ 的矩阵，$1\leq n,m\leq 10^6$ 且 $n\times m \leq 10^6$

- 普通数组就是 `int arr[100010][100010]`，直接炸内存(MLE)
- 动态数组就可以 `vector<vector<int>> dp(n+10,vector<int> (m+10,0))`
- 在读取了m,n后再设立数组，解决了炸内存的尴尬

-  ~~虽然有时候我也会用 int arr\[m+10][n+10] 来写数组~~(好孩子不要学)
- vector储存在堆空间，不会炸栈

## 1.9 注意事项

- **提前规定长度**
- vector的push_back逻辑是，当超过长度时会消耗时间进行重分配

```cpp
// 优化前: 522ms
vector<int> a;
for (int i = 0; i < 1e8; i++)
{
    a.push_back(i);
}
// 优化后: 259ms
vector<int> a(1e8);
for (int i = 0; i < a.size(); i++)
{
	a[i] = i;
}
```

2. **小心size_t溢出**

vector 获取长度的方法 `.size()` 返回值类型为 `size_t`，通常 OJ 平台使用的是 32 位编译器（有些平台例如 cf 可选 64 位），那么该类型范围为 $[0,2^{32})$.

```cpp
vector<int> a(65536);
long long a = a.size() * a.size(); // 直接溢出变成0了
```

## 1.10 和其他容器的组合技

- 和[[Pair 二元组]]

```cpp
vector<pair<int,int>> dp1(10);
pair<int,int> p1;
for (size_t i = 0; i < 5; i++)
{
    cin >> p1.first >> p1.second;
    dp1[i] = p1;
}
int k;
cin >> k;
for (size_t i = 0; i < dp1.size(); i++)
{
    if (k == dp1[i].first)
    {
        cout << dp1[i].second;
    }
}
```

> [!tip]
>
> **dp[i]**可以作为一个二元组绑死.first和.second
>
> dp容器可以起到结构体的作用
