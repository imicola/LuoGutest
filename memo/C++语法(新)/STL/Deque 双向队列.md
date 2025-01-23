#STL #容器 #队列 
# deque [双向队列](https://blog.csdn.net/H1727548/article/details/130959610)

- **作用：** deque可以作为一个双向队列，在队首队尾以及任意位置实现元素的插入和删除
- **定义：** 和*[[Vector]]*一致
- 有和[[Queue 队列]]几乎一样的功能，但双端可操作，是经常

**成员函数：**

```cpp
    push_back()     //在队列的尾部插入元素。
    emplace_front() //与push_front()的作用一样
    push_front()    //在队列的头部插入元素。
    emplace_back()  //与push_back()的作用一样
    pop_back()      //删除队列尾部的元素。
    pop_front()     //删除队列头部的元素。
    back()          //返回队列尾部元素的引用。
    front()         //返回队列头部元素的引用。
    clear()         //清空队列中的所有元素。
    empty()         //判断队列是否为空。
    size()          //返回队列中元素的个数。
    begin()         //返回头位置的迭代器
    end()           //返回尾+1位置的迭代器
    rbegin()        //返回逆头位置的迭代器
    rend()          //返回逆尾-1位置的迭代器
    insert()        //在指定位置插入元素
    erase()         //在指定位置删除元素
```
