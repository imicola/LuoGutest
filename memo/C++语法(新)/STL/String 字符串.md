#STL #容器 #字符串
# 1.7 字符串[string](https://zh.cppreference.com/w/cpp/string)

## 1.7.1 常用方法

- 构造: `string str;`
- 输入: `cin >> str;`
- 输出:`cout << str;`

- string 的初值构造 `string str(100,'0')`

- 赋值 `str = "awa";`

- 判断相等 `str1 == str2`
- 修改字符 `str[0] = "a"`
- 连接字符串 `str1 + str2;`
- 字符串尾接 `str1 += "awa";`

- 取子串:

```cpp
string s1 = "123123123";
cout << s1.substr(3) <<endl; //从第三位开始输出到末尾
cout << s1.substr(3,4) <<endl; //从第三位输出,输出4位 
```

- 查找函数 : `find(字串)`  $\to$ 返回字串起始点的下标[若找不到,则会返回一个 `string::npos`]
- 对上面一条：==返回的是下标，是size_t类型的数字!==

##### 6.1.7.2 string 转化

- str $\to$ int : `int x = stoi(str)`
- str $\to$ long long : `long long x =stoll(str)`
- str $\to$ float : `stof()`
- str $\to$ double : `stod()`
- str $\to$ long double : `stold()`

- int $\to$ str : `string str = to_string(x)`

##### 6.1.7.3 注意事项

- 尾接要用 += [使用 `str = str + "awa"`很慢]
- `.substr()`方法下,第一个参数传的是字串起点下标,第二个是字串长度
- `.find()`的实现是暴力枚举,复杂度是$O(n^2)$
