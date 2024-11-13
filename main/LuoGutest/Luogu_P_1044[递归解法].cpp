/*
P1044递归写法:
和dfs如出一辙 --> 确立一个栈帧状态 => 确定这个状态栈的空或者非空
如果栈空且入栈元素大于n，表示所有数字均已出栈,此时计数器+1表示一种情况
对每个栈帧,有两种操作:
    1. 入栈: 只要  < n,则可以入栈
    2. 出栈：只要 栈不为空，就可以让栈顶元素出栈
执行完操作之后要回溯:即返回未操作的状态以便下一个栈帧进行
*/

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int ans = 0, n;
stack<int> sta;
// vector<int> arr;
// a 用于记录输入状态  sta表示一个栈
void stasolve(int nextIn, stack<int> sta)
{
    if (sta.empty() && nextIn > n) {
        ans++;
        return;
    }
    if (nextIn <= n) {
        sta.push(nextIn);
        stasolve(nextIn + 1, sta);
        sta.pop(); // 回溯[就是没考虑到这个]
    }
    if (!sta.empty()) {
        int top = sta.top();
        sta.pop();
        stasolve(nextIn, sta);
        sta.push(top); // 回溯
    }
}

int main()
{
    cin >> n;
    stasolve(1, sta);
    cout << ans;
    return 0;
}