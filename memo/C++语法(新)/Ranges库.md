#语法

1. range::find(v,'1');
	- 在容器 v 内查找传入的第二个参数，返回值是第一个找到的参数的迭代器，如果没找到，则返回`v.end()`
2. range::minmax(v)
	- 以一个pair形式返回容器中的最大值和最小值
```cpp
	//常用接收形式
	auto [s1,s2] = ranges::minmax(v)
```
3. ranges::max_element(v)
	- 如果不进行二次传参，则返回范围内最大的一个元素的迭代器
	- 如果进行二次传参，则可以创建一个映射关系，返回映射关系下最大的那个元素的迭代器，例如：
```cpp
	vector<string> v = {"12","12345","1234"};
    auto s1 = ranges::max_element(v,
	{},     //comp比较函数，一般默认即可 
    [](const string &s) { return s.size(); }); //自定义映射函数，一般使用lambda进行编写
    cout << *s1;
```
4. ranges::sort(v)
	- 与std::sort()用法几乎一致，但是ranges::sort()仅仅需要传入数组名即可排序
	- ranges::sort(v,comp,porj)
		- porj：
			- porj投影函数，旨在简化传入参数的复杂情况，它可以将元素映射为其他属性或值。
			- 若不传入proj，则会对元素本身进行排列
			- 例：`ranges::sort(v, {}, string::size);`
			- 在上面的例子中，v容器内的字符串被转换成为了string::size,sort对size进行排列
			- 传入的函数也可以是一个lambda形式的函数
				`ranges::sort(v, {}, [](const string &s) { return s.size() % 3; });`
			- 例2:
```cpp
	struct Person {
	std::string name;
	int age;
	};
	
int main() {
	std::vector<Person> people = {{"Alice", 30}, {"Bob", 25}, {"Charlie", 35}};	
	std::ranges::sort(people, {}, &Person::age);  // 按 age 属性排序
	for (const auto& person : people) {
	std::cout << person.name << " ";  // 输出: Bob Alice Charlie
    }
}
```
- 在这个例子中调用了Person::age将容器内的元素转化为age进行比较

5. views::take / views::drop
	- 这是view命名空间下的函数，作用是取前n个(take) 去前n个(drop)
	- 语法规则：`auto vi_1 = v | view::take(n)`
		- 其中：v 是容器 ， n 是取的值， vi_1是一个视图
		- 视图可以采用范围for的迭代方式，如果要对视图进行操作，可以使用两种解决方案：
			1. 使用.begin() + index操作视图
			2. 使用 to\<vector\>操作 
				- `vector<int> v = vw | ranges::to<vector>();`

```cpp
int main()
{
	vector<int> a = {1,2,3,4,5};
	auto a1 = a | views::take(2);
	for(auto && i : a1)
	{
		cout << i << " ";
	}
	// 输出 1 2
	cout << endl;
	auto a2 = a | views::drop(2);
	for(auto && i : a2)
	{
		cout < i << " ";
	}
	// 输出 3 4 5 6
	cout << endl;
	auto vi = a2 | ranges::to<vector>();
	for(auto && i : a2)
	{
		cout << i << " ";
	}
	//输出同 a2
}
```

