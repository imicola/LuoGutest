#STl #容器
# 1.9 列表[list](https://blog.csdn.net/weixin_45031801/article/details/139361653)

**构造**
`list<类型> lt`
## 1.9.1 优势与适用范围

list容器插入和删除元素的效率较高，时间复杂度为==常数级别==,其底层为**带头双向循环链表**
## 1.9.2 常用方法

- 定义:
  - 构造空`list()` / 含有n个元素的类型容器`list` / 拷贝某个类型容器的复制品
  
  ```cpp
  list<int> lt1; //构造int类型的空容器
  list<int> lt2(10,2); //构造含有10个2的int类型容器
  list<int> lt3(lt2); //拷贝构造int类型的lt2容器的复制品
  list<int> lt4{ 1,2,3,4,5 };  // 直接使用花括号进行构造---C++11允许
  ```
  
  - 迭代器复制字符内容
  
  ```cpp
  string s("hello world");
  list<char> lt5(s.begin(),s.end()); //构造string对象某段迭代器区间的内容
  ```

## 1.9.3 list的遍历及迭代器的操作

- **迭代器**
- 正向迭代器

```cpp
int arr[] = {1,1,4,5,1,4}; //构造数组
list<int> lt(arr,arr+sizeof(arr)/sizeof(arr[0])); //copy数组到list
for(list<int>::iterator it = lt.begin();it != lt.end();++it)
{
    cout << *it <<endl;
}
```

- 反向遍历器(抽象)\[防止你不知道]

```cpp
int arr[] = {1,1,4,5,1,4};
list<int> lt(arr,arr+sizeof(arr)/sizeof(arr[0]));
for(list<int>::reverse_iterator it = lt.rbegin();it != lt.rend();++it)
{
    cout << *it <<endl;
}
```

- **范围for**(好用)

```cpp
int arr[] = {1,1,4,5,1,4};
list<int> lt(arr,arr+sizeof(arr)/sizeof(arr[0]));
for (auto &i : lt)
{
    cout << i <<endl;
}
```

---

- 常见容器操作

  - `.size()`:返回容器中有效元素的个数

  - `.resize()`:调整容器的有效元素大小(size)
  - `.empty()`:判断容器是否为空
  - `.clear()`:用于清空容器,清空后容器的size为0, 但是头结点(哨兵位)不会被清除

> - **`.resize(a,b)`**有两个参数:
>
>   - a:将list大小变为(a)
>   - b:若list新大小大于原大小,则新增的大小用b填充
## 1.9.4 list容器的常见访问操作

- `.front()`:访问list头元素\[返回list的第一个元素]
- `.back()`:访问list尾元素\[返回list的最后一个元素]
## 1.9.5 list 容器的常见修改操作

| 函数(接口)名称        | 函数(接口)说明                        |
| --------------- | ------------------------------- |
| `.push_front()` | 在list首元素前插入元素                   |
| `.pop_front()`  | 删除list首元素                       |
| `.push_back()`  | 在list尾部插入元素                     |
| `.pop_back()`   | 删除list最后一个元素                    |
| `.insert()`     | 在`list<int>::iterator it` 前插入元素 |
| `.erase()`      | 在`list<int>::iterator it` 前删除元素 |
| `.swap()`       | 交换两个元素                          |

> [!important]
>
> - 有关**insert()**的操作:[^7]
>
> - insert共有三种形式：
>
>   - insert(iterator, value);
>   - insert(iterator, num, value);
>   - insert(iterator, iterator1, iterator2); 
>
> - > instert的所有操作都由迭代器位置确定,不存在lt[2]这类的中括号表操作
>
> - 对`insert(iterator, value);`(会返回一个新迭代器指向插入的元素)
>
```cpp
//创立一个数组
int arr[] = {1,1,4,5,1,4};
list<int> lt(arr,arr+sizeof(arr)/sizeof(arr[0]));
cout << "befor" << endl;
for (auto &i : lt)
{
    cout << i <<endl;
}
//创立一个迭代器指向lt的头元素
list<int>::iterator it = lt.begin();
//迭代器向后移动2位,指向4
advance(it,2);
//在4的迭代器前,插入元素3
auto itnew = lt.insert(it,3);
cout << "after" << endl;
for (auto &i : lt)
{
    cout << i <<endl;
}
cout << "new iterator = " << *itnew <<endl;
return 0;```
> ![[Pasted image 20250123210215.png]]
>
> - 对 `insert(iterator, num, value);`(会返回一个新迭代器指向插入的第一个元素)
>
```cpp
//创立一个数组
int arr[] = {1,1,4,5,1,4};
list<int> lt(arr,arr+sizeof(arr)/sizeof(arr[0]));
cout << "befor" << endl;
for (auto &i : lt)
{
    cout << i <<endl;
}
//创立一个迭代器指向lt的头元素
list<int>::iterator it = lt.begin();
//迭代器向后移动2位,指向4
advance(it,2);
//在4的迭代器前,插入元素3个3
auto itnew = lt.insert(it,3,3);
cout << "after" << endl;
for (auto &i : lt)
{
    cout << i <<endl;
}
//新迭代器的位置在第一个3
cout << "new iterator = " << *itnew <<endl;
return 0;
```
> ![[Pasted image 20250123210256.png]]
- 对 `insert(iterator, iterator1, iterator2); `
```cpp
//创立一个数组
int arr[] = {1,1,4,5,1,4};
list<int> lt(arr,arr+sizeof(arr)/sizeof(arr[0]));
cout << "befor" << endl;
for (auto &i : lt)
{
    cout << i <<endl;
}
//创立一个迭代器指向lt的头元素
list<int>::iterator it = lt.begin();
//迭代器向后移动2位,指向4
advance(it,2);
//建立新的list或(vector);
vector<int> lt2 = {1,9,1,9,8,1,0};
//确定迭代器位置
auto it1 = lt2.begin();
auto it2 = lt2.end();
//在4的迭代器前,插入迭代器it1 - it2 这之间的数
//会返回插入的数的第一个元素的迭代器
auto itnew  = lt.insert(it,it1,it2);
cout << "after" << endl;
for (auto &i : lt)
{
    cout << i <<endl;
}
cout << "new iterator = " << *itnew;
return 0;
```
>![[Pasted image 20250123210417.png]]
>
> - **`.erase()`**用法和 **`.insert()`**差不多,只是从添加元素变为删除元素==删除的为迭代器==指向的元素或==两个迭代器之间(包括本身)==的元素

## 1.9.6 ==list容器常用的操作==

| **函数声明**        | **接口说明**          |
| --------------- | ----------------- |
| ***splice***    | **将元素从列表转移到其它列表** |
| ***remove***    | **删除具有特定值的元素**    |
| ***remove_if*** | **删除满足条件的元素**     |
| ***unique***    | **删除重复值**         |
| ***sort***(慢)   | **容器中的元素排序**      |
| ***merge***     | **合并排序列表**        |
| ***reverse***   | **反转元素的顺序**       |

- `.splice()`一共有四种形式
  - ***splice(iterator_pos, otherList) :*** 将otherList中的所有元素移动到iterator_pos指向元素之前

```cpp
list<int> ls1 ={1,2,3,4,5};
list<int> ls2 ={10,20,30,40,50};
ls2.splice(ls1.begin(),ls2); //和ls1.splice(ls1.begin(),ls2); 等价

for(auto &p : ls1)
{
    cout << p << " ";
}
//输出 10 20 30 40 50 1 2 3 4 5
//此时ls2的情况: 空
```

- ***splice(iterator_pos, otherList, iter1):*** 从 otherList转移 iter1 指向的元素到当前list。元素被插入到 iterator_pos指向的元素之前。

```cpp
list<int> ls3 ={10,20,30};
list<int> ls4 ={3,5,7,8};
auto it = ls3.begin();
advance(it,1);
ls3.splice(it,ls4,ls4.begin());
for(auto &p : ls3)
{
    cout << p << " ";
}    
cout <<endl;
//ls4
for(auto &p : ls4)
{
    cout << p << " ";
}
//输出:
//10 3 20 30
//5 7 8
```

- ***splice(iterator_pos, otherList, iter_start, iter_end) :*** 从 otherList转移范围 [iter_start, iter_end) 中的元素到 当前列表。元素被插入到 iterator_pos指向的元素之前。

```cpp
list<int> ls5 ={1,2,3,4,5};
list<int> ls6 ={10,20,30,40,50};
auto it2 = ls6.begin();
advance(it2,2); 
auto it3 = ls5.begin();
auto it4 = ls5.end();
advance(it3,1); 
advance(it4,-2); 
ls6.splice(it2,ls5,it3,it4);
for(auto &p : ls6)
{
    cout << p << " ";
}
cout << endl;
//ls5
for(auto &p : ls5)
{
    cout << p << " ";
}
cout << endl;
//输出: 
// 10 20 2 3 30 40 50 
// 1 4 5
```
