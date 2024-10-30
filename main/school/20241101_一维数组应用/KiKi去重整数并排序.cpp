#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> st;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        st.insert(temp);
    }
    for (auto&& i : st) {
        cout << i << " ";
    }
    return 0;
}