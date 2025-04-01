#语法 #字符串 
C++针对字符串的读写有一套专门的方法，即stringstream
**语法规则：**
- `stringstream ss(str)`
- str是你想进行操作的字符串
场景：
- **读取字符串中的数据**：你可以通过 `stringstream` 从字符串中提取整数、浮动数、字符等。
- **将数据写入字符串**：可以将不同类型的数据输出到一个字符串中。
```cpp
main(){
	//读入
	std::stringstream ss(str);
    int num1, num2;
    ss >> num1 >> num2;  // 从stringstream读取数据
    std::cout << "num1: " << num1 << ", num2: " << num2 << std::endl;
    //写出
    int x = 10, y = 20;
    std::stringstream ss2;
    ss2 << x << " " << y;  // 将数字写入stringstream
    std::string result = ss2.str();  // 获取格式化后的字符串
    std::cout << "Formatted string: " << result << std::endl;
}
```

> 一般而言，我们习惯使用`getline`来将整个字符串读入，然后直接`stringstream ss(s)`

```cpp
main(){
	string s;
	getline(cin,s);
	std::stringstream ss(s);
	int p;
	//假设读入的都是数字
	while(ss >> p){
	/* code */
	}
}
```
