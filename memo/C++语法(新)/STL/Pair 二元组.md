#STL #容器 
# 1.8 二元组 [pair](https://zh.cppreference.com/w/cpp/utility/pair)

**构造**
`pair<int, int> pr;`
## 1.8.1 常用方法

- 赋初值: `pair<int , int> pr = {1,2}`
- 老式: `pair<int , int> pr2 = make_pair(1,2)`
- 判同 : `pr == pr2`

- 三元组~~曲线救国~~法:`pair<pair<int,char>,char> p3;`
- 访问第一个值 `.first`
- 访问第二个值 `.second`

## 1.8.2 适用范围
**适用于所有需要二元组的场景,效率和自己定义结构体差不多**

## 1.8.3 临时拆分二元组
我们可以使用语法 `auto [f,s] = pr`来将pair的两个元素起到临时拆分的作用，**同时在范围for循环里也可以使用这个对由pair构成的容器进行拆分**
- 下面罗列一些我清楚的
- [[Map 映射]] [[Vector]]构成的pair数组
```cpp
for(auto &&[a,b] : mp){
	/*
	对 a 和 b 的操作
	*/
}
```
 >[!tip]
 >对 auto 拆分的pair而言，\[a,b]内 a代表 `.first` b代表 `.second` ,而对于 map而言，a代表 key ， b代表值
 
 