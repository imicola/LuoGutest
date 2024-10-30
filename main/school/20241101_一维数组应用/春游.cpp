#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    set<int> p;
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        p.insert(temp);
    }
    if (p.size() == n) {
        cout << n;
    } else {
        for (size_t i = 0; i < n; i++) {
            if (!p.count(i)) cout << i <<" ";
        }
    }

    return 0;
}