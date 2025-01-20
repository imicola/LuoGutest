//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        int k;
        cin >> k;
        vector<int> arr(k, 0);
        for (size_t i = 0; i < k; i++) {
            string s;
            cin >> s;
            arr[i] = s.find('#');
        }
        for (int j = k - 1; j >= 0; j--) {
            cout << arr[j]+1 << " ";
        }
        cout << endl;
    }

    return 0;
}