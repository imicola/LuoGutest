#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr1(m);
    vector<int> arr2;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr2.push_back(temp);
        arr1[temp]++;
    }
    for (size_t i = 0; i < n; i++) {
        if (arr1[arr2[i]] > 1) {
            cout << arr1[arr2[i]] - 1 << endl;
        } else {
            cout << "BeiJu" << endl;
        }
    }

    return 0;
}