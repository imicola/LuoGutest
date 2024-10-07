#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[9] = {1,2,3,4,5,6,7,8,9};
    int p = 0;
    do
    {
        for (size_t i = 0; i < n; i++)
        {
            p++;
            if (p%n == 0)
            {
                cout << arr[i];
            }
            else
            {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    } while (next_permutation(arr,arr+n));
    
    return 0;
}