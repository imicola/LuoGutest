#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
// 创建数据类型
struct QAQ {
    string s1;
    int n1;
    int n2;
} s[10];

int main()
{
    s[1] = { "QAQ", 1, 2 };
    cout << s[1].s1;
    // 或者
    QAQ kk[5]; //第二种方法构建
    cin >> kk[3].s1;
    cout << kk[3].s1;
    return 0;
}