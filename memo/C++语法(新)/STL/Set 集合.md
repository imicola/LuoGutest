#STL #容器
# 1.5 集合[set](https://zh.cppreference.com/w/cpp/container/set)

提供对数时间的插入、删除、查找的集合数据结构。底层原理是红黑树。

| 集合三要素 | 解释              | set     | multiset | unordered_set |
| ----- | --------------- | ------- | -------- | ------------- |
| 确定性   | 一个元素要么在集合中，要么不在 | ✔       | ✔        | ✔             |
| 互异性   | 一个元素仅可以在集合中出现一次 | ✔       | ❌（任意次）   | ✔             |
| 无序性   | 集合中的元素是没有顺序的    | ❌（从小到大） | ❌（从小到大）  | ✔             |

## 1.5.1 常用操作

- 函数构造 `set<类型,比较器>`
- 插入元素 `st.insert(元素)`
- 删除元素 `st.erase(元素)`

- 查找元素 `st.find(元素)`
- 查找元素个数 `st.count`

## 1.5.2 遍历

可以使用遍历器来遍历set数据:

```cpp
set<int> st;
for (set<int>::iterator it = st.begin() ; it != st.end();++it )
{
    cout << *it <<endl;
}
```

基于范围的循环:

```cpp
for(auto &ele : st)
{
    cout << ele << endl;
}
```

## 1.5.3适用范围

- 元素的去重 [1,1,2,3,3,5,7] $\to$ [1,2,3,5,7]
- 元素顺序的维护 [1,6,8,4,1] $\to$ [1,4,6,8]
- 元素大小很大但数量很少的情况(大小:[$-$10^18^,10^18^],数量10^6^)

## 1.5.4 注意事项

- set数据不存在下标的说法,但可以用遍历器找数据: 

```cpp
set<int>::iterator it = st.begin();
advance(it,2); //迭代器后面会讲
cout << *it <<endl;
```

- 元素都是只读的,set迭代器提取的元素都是只读的(因为是const迭代器),不能够修改它的值,需要先erase再inset

```cpp
cout << *st.begin() <<endl; //正确
*st.begin() = 1; //错误,不可写
```

- 不可用迭代器计算下标

set 的迭代器不能像 vector 一样相减得到下标。**下面是错误用法：**

```cpp
auto it = st.find(2);      // 正确，返回2所在位置的迭代器。
int idx = it - st.begin(); // 错误！不可相减得到下标。
```
