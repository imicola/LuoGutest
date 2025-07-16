#语法

C++11 提供 `std::function` 这样一个函数包装式来封装函数
- 基本语法：
	- `function<返回值(传参)>`
	- 示例： `function<int(int,int)> func`
- 利用`function`包装函数：
```cpp
void add(int a,int b){
	return a+b;
}

int main()
{
	std::function<int(int,int)> fun = add;
	int res = fun(3,4);
	// 此时res输出 7
}
```

你同样也可以使用 `function`包装一个lambda表达式 ~~为什么不直接使用lambda~~
```cpp
int main()
{
	auto lamb = [&](int a,int b){
	return a+b;
	}
	std::function<int(int,int)> fun1 = lamb;
	//上式等价于下式
	std::function<int(int,int)> fun2 = [&](int a,int b)-> int{
		return a+b;
	};
}
```
