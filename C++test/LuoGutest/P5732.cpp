#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,p = 1;
    cin >> n;
    int arr[25][25] = {0};
    arr[1][1] = 1;
    for (size_t i = 2; i <= n; i++)
    {
        for (size_t k = 1; k <= i; k++)
        {
            arr[i][k] = arr[i-1][k] + arr[i-1][k-1];
        }
        
    }
    for (size_t i = 1; i <= n; i++)
    {
        for (size_t k = 1; k <= i; k++)
        {
            cout << arr[i][k] << " ";
        }
        cout <<endl;
    }
    //水题

    return 0;
}