#STL #队列
## 1.4 优先队列(堆) [priority_queue](https://zh.cppreference.com/w/cpp/container/priority_queue)

`include <queue>`
## 1.4.1 构造

`priority_queue<类型,容器,比较器>`

- 类型:要储存的数据类型
- 容器:储存数据的底层容器,默认为 `vector<T>`,竞赛时保存默认即可
- 比较器: 比较大小使用的比较器,默认为 `less<T>`,可以自定义

```cpp
priority_queue<int> pque1;
priority_queue<int,vector<int>,greater<int>> pque2;//变小顶堆
```

> 自定义比较器尽量不用,容易犯迷糊

## 1.4.2 常用语法

| 作用           | 用法          | 示例                   |
| ------------ | ----------- | -------------------- |
| 进堆           | `.push(元素)` | `que.push(1);`       |
| 出堆           | `.pop()`    | `que.pop();`         |
| 取堆顶(最大值/最小值) | `.top()`    | `int a = que.top();` |
| 查看大小/判空      | 和vector一致   | 略                    |

> [!note]
>
> 进出堆复杂度$O(\log n)$,取堆顶$O(1)$

##### 适用场景

- 保持数据的有序性,每次向队列中插入大小不定的元素,或每次从队列取出最大/最小的元素,元素数量为$n$,插入操作数量为$k$
  - 使用快排:$k\cdot n \log n$
  - 使用优先队列:$k\cdot \log n$

### 1.4.3 注意事项

- **仅堆顶可读**

```cpp
cout << qpue[1] <<endl; //错误
```

- **所有元素不可写**

```cpp
qpue[1] = 2;
pque.top() = 1;
//均为错误
```

但如果要修改堆顶元素

```cpp
int tp = pque.top(); //保存堆顶
pque.pop(); //弹出堆顶
qpue.push(tp + 1); //通过保存的堆顶修改堆顶
```