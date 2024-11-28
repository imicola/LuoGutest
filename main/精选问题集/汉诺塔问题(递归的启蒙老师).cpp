#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef pair<int, int> pii;

void f(int n, char be, char temp, char end)
{
    if (n == 1)
        cout << n << ": " << be << " -> " << end << endl;
    else {
        f(n - 1, be, end, temp);
        cout << n << ": " << be << " -> " << end << endl;
        f(n - 1, temp, be, end);
    }
}

//思路：汉诺塔问题
//递归思想:
//   -> 1.确定函数是干什么的
//   -> 2.将大问题拆解为小问题
//   -> 3.相信递归一定可以解决你所提出的问题
//汉诺塔思路:
//确定递归函数传参含义与该函数的行为 -> 传参函数 f(int a,char be,char temp , char end)
// n   -> 目前的处理的圆盘序号
// be  -> 这次处理移动的起始位置
// end -> 这次处理移动的目标位置
// temp-> 这次处理圆盘未到达过的位置
// f()的作用 -> 将编号为n的圆盘从 be 移动到end [!!! 必须时刻牢记]
// -------------------------------------------------------------
//对汉诺塔问题的递归解：
// 边界情况 --> 当 n == 1 时，即圆盘编号为 1 时直接将这个圆盘从be 移动到 end
// 对多个圆盘而言,都可以将其看为是：一个编号为n的圆盘和其他圆盘[(n-1)到1]
// 我们先来考虑最简单的多盘问题，即只有编号1和2的情况
// --> 1号盘从 be --> temp
// --> 2号盘从 be --> end
// --> 1号盘从 temp --> end
// 好，现在我们已经完成了最简单的情况，这其实就是一个最小操作，我们将这个操作放大到 对n生效
// --> (n-1)盘从 be --> temp
// --> n    盘从 be --> end
// --> (n-1)盘从 temp --> end
// [!!!] 注意，在对n生效的时候，be，end，temp对汉诺塔 1 2 3 柱子的联系性已经消失
// 同理 (n-1) 在递归中将被拆解为 (n-2) 与 (n-1) 这样依次下去直到到达 n == 1 即边界情况
// 到达边界情况时候，将会发生一次最小操作

int main()
{
    clock_t be = clock();
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    char a, b, c;
    cin >> n >> a >> b >> c;
    f(n, a, b, c);
    clock_t ed = clock();
    cout << endl << (ed - be) << "ms" << endl;
    return 0;
}