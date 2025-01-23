#STL #函数类
# 6.3 STL函数
## 对容器操作类
- `sort(iterator_begin,iterator_end,cmp)` 快速排序
- `find`：顺序查找。`find(iterator_begin, iterator_end, value)`，其中 `value` 为需要查找的值。
- `reverse`：翻转数组、字符串。`reverse(iterator_begin, iterator_end())` 或 `reverse(a + begin, a + end)`。
- `unique`：去除容器中相邻的重复元素。`unique(ForwardIterator first, ForwardIterator last)`，返回值为指向 **去重后** 容器结尾的迭代器，原容器大小不变。与 `sort` 结合使用可以实现完整容器去重。
- `move`:  可以高效赋值容器，当你确定某一个容器在后面不需要被使用时可以使用 `move`来降低时间复杂度，尤其是对`vector<pair<int,int>>` 这类复杂容器而言
```cpp
    for(auto &&i : f){
        set<int> temp = dp;
        for(auto &&j : dp){
            temp.emplace(i+j);
        }
        dp = move(temp);
    }
```

  > **这是一个求一个数组取任意个数个数字相加的板子，其中使用到 move(temp) 就起到了降低时间复杂度的作用**

## 对容器改动类
- `().emplace() ` ` ().emplace_back()` 
  - `emplace` 是 C++11 引入的标准容器函数，用于直接在容器中**构造对象**，而不是先创建对象再插入。它适用于几乎所有 STL 容器（如 `vector`, `set`, `map`, `deque` 等），提供了比 `insert` 更高效的方式。
  - 例子：我们可以直接在 `set<pair<int,int>>` 后插入 (x,y)
```cpp
    set<pair<int,int>> st;
    //传统办法
    st.insert(make_pair(x,y));
    //emplace办法
    st.emplace(x,y);
```
- 对 `vector`而言，`emplace_back()` 几乎可以完全代替 `push_back()`  而`emplace` 则能代替 `insert`
```cpp
    vector<pair<int,int>> v
    v.push_back(make_pair(x,y)) == v.emplace_back(x,y);
    v.insert(v.begin(), make_paie(x,y)) == v.emplace(v.begin(),x,y)
```