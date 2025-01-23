#搜索 #递归与递推
# BFS 广度优先搜索

- 在前面我们介绍过[[深度优先搜索 DFS]]，深搜的核心思想是一条路走到底，直到得到符合的结果或者超出边界情况结束

- 而广度优先搜索则是从起始位置出发，每一次向外增加一圈，或执行完一大个操作之后再将计数变量增加

- 广搜一般适用于求最短路径，求最少操作次数的这些操作，因为广搜本身便是向外扩散式的一种搜索

广搜一般使用STL中的[[Queue 队列]]作为承接模板，通过其先进先出的特点实现广搜

例题：[洛谷P1135 奇怪的电梯](https://www.luogu.com.cn/problem/P1135)

```cpp
signed main()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> to,path;
    to = vector<int>(n + 1);
    path = vector<int>(n + 1, -1);
    for (size_t i = 1; i <= n; i++) {
        cin >> to[i];
    }
    // 输入数据
    queue<int> bfs; //建立一个bfs的queue队列
    int ans = 0;
    bfs.push(a); //将第一个元素存入队列中
    path[a] = 0; //第一个路径初始
    while (!bfs.empty()) { //如果队列非空，就说明仍然有可以进行下去的操作
        int up = bfs.front() + to[bfs.front()]; //第一种可能，往上坐电梯
        int down = bfs.front() - to[bfs.front()]; //第二种可能，往下坐电梯
        if (up > 0 && up <= n && path[up] == -1) { //如果往上做的电梯能到达(即存在这个楼层)，且这个楼层没有被达到过
            path[up] = path[bfs.front()] + 1; // 这个楼层的标识数 = 过来的楼层的标识数 + 1
            bfs.push(up); //把这个楼层加入到队列里，表示接下来会对这个楼层操作
        }
        if (down > 0 && down <= n && path[down] == -1) { //同上
            path[down] = path[bfs.front()] + 1;
            bfs.push(down);
        }
        bfs.pop(); //原始楼层操作完毕，弹出队列
    }
    cout << path[b]; //输出目标楼层的情况
    return 0;
}
```

> 显然，BFS对这种求最短是一个不错的解法，但有的时候还得考虑DP或其他时间复杂度更低的方法
