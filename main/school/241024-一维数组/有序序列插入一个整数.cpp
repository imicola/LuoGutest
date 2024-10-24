#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    priority_queue<int,vector<int>,greater<int>> arr;
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push(temp);
    }
    int k;
    cin >> k;
    arr.push(k);
    while (!empty(arr))
    {
        int temp = arr.top();
        cout << temp<<" ";
        arr.pop();
    }
    
    
    return 0;
}