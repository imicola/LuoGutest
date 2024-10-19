#include <bits/stdc++.h>
using namespace std;

//大数比大小
bool largepanduan(string &a ,string &b)
{
    if (a.size() > b.size()) return 1;
    else if (a.size() < b.size()) return 0;
    //在C++中，对于两个字符串的比较，>=运算符会按照字典顺序（即按字符从左到右的顺序）进行比较
    //这意味着如果字符串a在字典顺序上大于或等于字符串b，a >= b将返回1 ；否则返回 0
    return a >= b;
}

//假设string a > string b ,做高精度减法
string largemin(string a ,string b)
{
    int p = 0;
    for (size_t i = 0; i < b.size(); i++)
    {
        //寻找两字符串的第i位数字
        int ai = a[a.size() - 1 - i] - '0';
        int bi = b[b.size() - 1 - i] - '0';
        //计算差值
        int diff = ai - bi - p;
        //如果差值小于0，就向前一位"借一位"，类比竖式减法;
        if (diff < 0)
        {
            diff += 10;
            p = 1;
        }
        else p = 0;
        //将这一位减后的数存入string a 的第i位 
        a[a.size() - 1 - i] = diff + '0';
    }
    //处理string a 中大于 string b位的部分
    for (size_t i = b.size(); i < a.size(); i++)
    {
        int ai = a[a.size() - 1 - i] - '0';
        //如果该位为 0 且被上一位请求进位了，将该位变为9，并且再次借1
        if (ai == 0 && p == 1)
        {
            a[a.size() - 1 - i] = '9';
        }
        //未借位的情况，清除借位buff
        else 
        {
            a[a.size() - 1 - i] = (ai - p) + '0';
            p = 0;
        }
    }
    //简明的去除前导零
    while (a.size() > 1 && a[0] == '0')
    {
        a.erase(a.begin());
    }
    return a;
}

//高精度取模
string modlarge(string a , string &b)
{
    //简单说一下逻辑
    //只要 a 比 b 大，则把 a -= b
    //再一次判断新的 a 有没有 b 大，重复
    //直到 a < b ，此时的a 一定是 b 的模数
    while (largepanduan(a,b))
    {
        a = largemin(a,b);
    }
    return a;
}
//高精度gcd函数
//和欧几里得算法一样的思想，只是数据类型不同
string gcdlarge(string a , string b)
{
    while ( b != "0")
    {
        string temp = modlarge(a,b);
        a = b;
        b = temp;
    }
    return a;
}


int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    cout << gcdlarge(s1,s2);
    return 0;
}