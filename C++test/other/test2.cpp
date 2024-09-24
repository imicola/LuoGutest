#include <bits/stdc++.h>
using namespace std;

// #define endl "\n"
// #define int long long
// #define doubel long double

int main()
{
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
    cout << "new iterator = " << *itnew <<endl;
    
    return 0;
}