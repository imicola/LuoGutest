#容器 #STL #队列
# 1.3 队列 [queue](https://zh.cppreference.com/w/cpp/container/queue)

- `incloud <queue>`

通过二次封装双端队列，实现==先进先出==(双端获取)的数据结构
## 1.3.1常用方法

| 作用   | 用法              | 示例                    |
| ---- | --------------- | --------------------- |
| 构造   | `queue<类型> que` | `queue<int> que`      |
| 进队   | `que.push(元素)`  | `que.push(1)`         |
| 出队   | `.pop()`        | `que.pop()`           |
| 取队首  | `.front()`      | `int a = que.front()` |
| 取队尾  | `.banc()`       | `int a = que.back()`  |
| 查看大小 | `.size()`       | `int a = que.size()`  |
| 清空   | `.clear()`      | `que.clear()`         |
| 判空   | `.empty()`      | `que.empty()`         |

## 1.3.2 注意事项

**不能访问内部元素!** 示例同[[Stark 栈#2.4 写栈的注意事项]]

> 有一类特殊的队列容器[[Priority_queue 优先队列]]可以做到将队列内的元素以$O(\log n)$的速度读入并排序
