#STL #容器 #哈希
# 1.6 映射 [map](https://zh.cppreference.com/w/cpp/container/map)

**`include <map>`**

- 提供==对数==时间的有序键值对结构\[任意类型的映射];

```cpp
map<string,int> a;
a["qaq"] = 1;
a["abc"] = 2;
a["mmp"] = 3;
```

- *key*\[键]:的概念

```cpp
a[key] = value;
```

*key* 在映射中处于中括号内,表示提示*map*的元素

- **性质**

| 性质  | 解释             | map     | multimap | unordered_map |
| --- | -------------- | ------- | -------- | ------------- |
| 互异性 | 一个键仅可以在映射中出现一次 | ✔       | ❌（任意次）   | ✔             |
| 无序性 | 键是没有顺序的        | ❌（从小到大） | ❌（从小到大）  | ✔             |

## 1.6.1 构造及常用操作

`map<key,value> mp;`

- 增/改:`map[0] = 1`

- > 倘若没有定义就直接访问map,就会返回一个初值(默认为0)

- 查找元素\[找的是 *key*]:`mp.find()`$\to$返回这个元素的迭代器,若找不到,返回mp.end(尾迭代器)
- 删除: `mp.erase(元素)`
- 查找\[找的是 *key*]:`mp.count()`$\to$ 返回的是元素数量

- 清空判空同上

## 1.6.2 遍历

1. 萌新式遍历\[适合\<int int>型]

```cpp
map<int , int> mp;
mp[6] = 3;
mp[5] = 1;
mp[7] = 3;
mp[9] = 666;
for (size_t i = 0; i < mp.size(); i++)
{
    cout << mp[i] <<endl;
}
```

> 缺点很明显,给个图就明白了

![[Pasted image 20250123203818.png]]

2. 迭代器式遍历

```cpp
string a;
map<string , int> mp;
mp["aaa"] = 1;
mp["bbb"] = 5;
mp["tsts"] = 3;
for (map<string , int>::iterator it = mp.begin() ;it != mp.end() ; it++)
{
    cout << it->second <<endl;
}
```

> 这个遍历器指向一个键对,所以得用 `it->first`或 `it->second`来判断指向的哪一个

3. auto范围遍历

```cpp
string a;
map<string , int> mp;
mp["aaa"] = 1;
mp["bbb"] = 5;
mp["tsts"] = 3;
for(auto &el:mp)
{
    cout << el.first << " " <<el.second<<endl;
}
```

## 1.6.3 适用范围

- **维护特殊的映射**\[string $\to$ int]

> 统计输入的字符串组中每个字符串出现的次数

```cpp
map<string ,int> mp;
vector<string> vec;
vec.push_back("aqa");
vec.push_back("aqa");
vec.push_back("qaq");
vec.push_back("qaq");
vec.push_back("wqw");
vec.push_back("aqa");
vec.push_back("qaq");

for (size_t i = 0; i < vec.size(); i++)
{
    mp[vec[i]]++;
}
for (auto &el : mp)
{
    cout << el.first << " " <<el.second<<endl;
}
```

![[Pasted image 20250123203907.png]]

> 效果如此

## 1.6.4 注意事项

- 空map会返回一个默认值
- 不能使用遍历器找下标

> unordered_map无序map 也称哈希表，我们可以随意的建立映射关系，时间复杂度是O(1)
