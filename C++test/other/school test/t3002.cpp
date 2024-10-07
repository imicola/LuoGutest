#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> arr(0);
    arr.push_back(1);
    arr.push_back(1);
    for (size_t i = 1; i <= 35; i++)
    {
        int temp = arr[i] + arr[i-1];
        arr.push_back(temp); 
    }
    for (size_t i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        cout << arr[p - 1] <<endl;
    }
    
    
    return 0;
}