//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;

int main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    vstr vs(n);
    for (auto &&i : vs) {
        cin >> i;
    }
    string k;
    // vstr result;
    priority_queue<string,vector<string>,greater<string>> result;
    cin >> k;
    for (size_t i = 0; i < vs.size(); i++) {
        int flag = 0;
        for (size_t j = 0; j < k.size(); j++) {
            if (vs[i][j] != k[j]){
                break;
            }
            flag++;
            if (flag == k.size()) result.push(vs[i]);
        }
    }
    // sort(all(result), [](string a, string b) { return a <= b; });
    // sort(all(result));
    while (!result.empty())
    {
        string s = result.top();
        cout << s << endl;
        result.pop();
    }
    return 0;
}