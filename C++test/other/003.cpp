#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr;
    for (size_t i = 0; i < 10; i++)
    {
        arr.push_back(i);
    }
    for(vector<int>::iterator it = arr.begin(); it != arr.end();it++)
    {
        cout << *it <<endl;
    }
    auto it = arr.begin();
    return 0;
}