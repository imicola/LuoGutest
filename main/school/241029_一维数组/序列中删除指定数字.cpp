#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    for (size_t i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    int k;
    cin >> k;
    auto newend = remove(a.begin(), a.end(), k);
    a.erase(newend, a.end());
    for (auto&& i : a)
        cout << i << " ";
    return 0;
}
//简单版

// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     int k;
//     cin >> k;
//     for (int i = 0; i < n; i++) {
//         if (arr[i] == k) continue;
//         cout << arr[i] << " ";
//     }
//     return 0;
// }
