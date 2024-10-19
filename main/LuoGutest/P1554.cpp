#include <bits/stdc++.h>
using namespace std;

int arr[11];

int main()
{
    int m,n = 0;
    cin >> m >> n;
    for (size_t i = m; i <= n; i++)
    {
        string temp = to_string(i);
        for (size_t k = 0; k < temp.size(); k++)
        {
            arr[temp[k] - '0']++;
        }
        temp = {0};
    }
    
    for (size_t i = 0; i < 10; i++)
    {
        cout << arr[i] <<" ";
    }
    


    return 0;
}