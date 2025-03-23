//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
#define endl '\n'
#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> pushNeedles(N);
    for (int i = 0; i < N; i++) {
        cin >> pushNeedles[i];
    }
    int pos = 0;
    stack<int> smallBox;
    vvint branches;
    while (pos < N || !smallBox.empty()) {
        vint branch;
        int firstNeedle;
        if (!smallBox.empty()) {
            firstNeedle = smallBox.top();
            smallBox.pop();
        }
        else if (pos < N) {
            firstNeedle = pushNeedles[pos];
            pos++;
        }
        else {
            break;
        }
        branch.push_back(firstNeedle);
        while (branch.size() < (size_t)K) {
            int currentTop = branch.back();
            bool inserted = false;
            if (!smallBox.empty()) {
                int candidate = smallBox.top();
                if (candidate <= currentTop) {
                    branch.push_back(candidate);
                    smallBox.pop();
                    inserted = true;
                    continue;
                }
            }
            if (pos < N) {
                int candidate = pushNeedles[pos];
                if (candidate <= currentTop) {
                    branch.push_back(candidate);
                    pos++;
                    inserted = true;
                    continue;
                }
                else {
                    if ((int)smallBox.size() < M) {
                        smallBox.push(candidate);
                        pos++;
                        continue;
                    }
                    else {
                        break;
                    }
                }
            }
            else {
                break;
            }
        }
        branches.push_back(branch);
    }
    for (auto &branch : branches) {
        for (size_t i = 0; i < branch.size(); i++) {
            cout << branch[i] << (i + 1 == branch.size() ? "" : " ");
        }
        cout << endl;
    }
    return 0;
}
