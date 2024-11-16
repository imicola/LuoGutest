//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string be;
    LL n;
    cin >> be >> n;
    LL mun = be.size();
    while (mun < n) {
        LL k = mun;
        while (k < n) {
            k *= 2;
        }
        k /= 2;
        n -= k + 1;
        if (n == 0) n = k;  //---> (1*)
    }
    cout << be[n - 1];
    return 0;
}
/*
这题就是很抽象，想明白就想明白了，想不明白就死活想不出来
大致思路是：
对于字符串 COW 而言
第k_0次 --->  COW
第K_1次 --->  COWWCO --->        [COW] *W* [CO]
第K_2次 --->  COWWCOOCOWWC --->  [COWWCO] *O* [COWWC]
我们发现第K_i个的字符串的第一个[XXX]内的内容与K_(i-1)个的内容完全一致
同时第K_i个的字符串的第二个[XXX]内的内容和第一个[XXX]只差了*X*的内容
所以对于第N个字符在第K_i个字符串的位置我们可以将其推到第K_(i-1)的位置上
具体如下:
    N_(k-1) = N_(k) - L/2 - 1   --> (1)
    N_(k)一定会落在K_i的第二个[XXX]或*X*串里,因为倘若在第一个[XXX]串里N_(k)就会落在K_(i-1)里而非K里
    如果是COWCOW COWCOW 这样的串那就是 N_(K-1) = N_(K) - L/2
    但由于这个特殊的构建方式，我们需要多减去*X*来正确的移动位置,即得到(1)式
    但如果我们正好选到*X*的话，我们需要特殊处理：
    不难发现*X*的位置是在 L/2 + 1 的位置上 --> 我们带入(1)式会发现结果为0
    即---> 当我们算出 0 的时候说明这是 *X*,而第K_(i)串的*X* 与其 L/2 相等,于是我们直接移位至 L/2 处参与下一次的(1)式子递推
    所以代码会有像 (1*) 一样的操作，因为此处的 k = L/2
*/
/*
感悟：光滑的大脑皮层不支持我写这种题QAQ
*/