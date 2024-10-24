#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    for (size_t i = 0; i < n; i++)
    {
        int temp; cin >> temp;
        a.push_back(temp);
    }
    int k;
    cin >> k;
    auto newend = remove(a.begin(),a.end(),k);
    a.erase(newend,a.end());
    for(auto &&i : a) cout << i <<" ";
}