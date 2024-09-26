#include <bits/stdc++.h>
using namespace std;

// #define endl "\n"
// #define int long long
// #define doubel long double

int main()
{
    // //创立一个数组
    // int arr[] = {1,1,4,5,1,4};
    // list<int> lt(arr,arr+sizeof(arr)/sizeof(arr[0]));
    // cout << "befor" << endl;
    // for (auto &i : lt)
    // {
    //     cout << i <<endl;
    // }
    // //创立一个迭代器指向lt的头元素
    // list<int>::iterator it = lt.begin() ++;
    // //迭代器向后移动2位,指向4
    
    // //建立新的list或(vector);
    // vector<int> lt2 = {1,9,1,9,8,1,0};
    // //确定迭代器位置
    // auto it1 = lt2.begin();
    // auto it2 = lt2.end();
    // //在4的迭代器前,插入迭代器it1 - it2 这之间的数
    // //会返回插入的数的第一个元素的迭代器
    // auto itnew  = lt.insert(it,it1,it2);
    // cout << "after" << endl;
    // for (auto &i : lt)
    // {
    //     cout << i <<endl;
    // }
    // cout << "new iterator = " << *itnew <<endl;
    
    list<int> ls1 ={1,2,3,4,5};
    list<int> ls2 ={10,20,30,40,50};
    list<int> ls3 ={10,20,30};
    list<int> ls4 ={3,5,7,8};
    list<int> ls5 ={1,2,3,4,5};
    list<int> ls6 ={10,20,30,40,50};
    ls1.splice(ls1.begin(),ls2);
    for(auto &p : ls2)
    {
        cout << p << " ";
    }
    cout <<endl;
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
    cout << endl;
    ////////////////////////////////////////////////
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
    
    return 0;
}