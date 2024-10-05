#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    cin >> n >>m;
    vector<int> arr;
    for (size_t i = 0; i < n; i++)
    {
        int temp = 0;
        cin >> temp;
        arr.push_back(temp);
    }
    int flag1 =0;
    int flag2 =0;
    for (size_t j = 0; j < n ; j++)
    {
        if (arr[j] == m)
        {
            flag1 = 1;
        }
    }

    for (size_t k = 0; k < n ; k++)
    {
        if (arr[k] == 1)
        {
            flag2 = 1;
        }
    }

    if (flag1 == 1 && flag2 == 1)
    {
        cout << "No";
    }
    else
    {
        cout << "Yes";
    }
    
    return 0;
}