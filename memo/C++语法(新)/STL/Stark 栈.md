#STL #栈 #容器 
# 栈 **[stack](https://zh.cppreference.com/w/cpp/container/stack)**

**头文件：**\<stark>
## 2.1 构造方式

`stack<double> stk`[stk是栈名]；

## 2.2 进栈与出栈及取栈顶部

- 进栈：`stk.push(x);`[将x放入栈中]
- 出栈：`stk.pop();`[栈顶出栈]
- 取栈顶：`stk.top()`[获取栈顶
## 2.3 用vector模拟stack

使用`dp.back()`取栈(容器)顶

## 2.4 写栈的注意事项

- 不能访问栈的内部元素 ^bede8c
- **下面都是错误用法**

```cpp
stack<int> stk;
for(int i = 1;i < stk.size();i++)
{
    cout << stk[i]<<endl;
}
for(auto ele : stk)
{
    cout << stk <<endl;
}
```

^6be613

## 2.5 与 *vector* 相比 *stack*的优势是什么？

- stack效率是高于vector的
- stack的内存占用更低
- 在某些算法实现下(如[[深度优先搜索 DFS]])，stack可能是更自然的选择