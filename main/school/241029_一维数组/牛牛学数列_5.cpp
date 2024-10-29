#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long arr[50];
    arr[1] = 1;
    arr[2] = 1;
    for (size_t i = 3; i <= 50; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    cout << arr[n];
}