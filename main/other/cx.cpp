#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(4);
    auto it = arr.begin() + 1;
    //arr.erase(it);
    // it++;
    // arr.erase(it);
    auto newend = remove(arr.begin(),arr.end(),1);
    arr.erase(newend,arr.end());
    for(auto &&i : arr) cout << i << " ";
    return 0;
}