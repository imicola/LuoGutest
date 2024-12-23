#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

signed main()
{
    int T = 1;
    cin >> T;
    vector<pii> food(T);
    for (auto &&[s, k] : food) {
        cin >> s >> k;
    }
    // 使用集合记录所有可能的 (酸度, 苦度) 组合
    set<pii> dp;
    dp.emplace(1, 0); // 初始状态
    for(auto &[s, b] : food){
        set<pii> temp = dp;
        for(auto &[acid, bitter] : dp){
            temp.emplace(acid * s, bitter + b);
        }
        dp = move(temp);
    }
    // gpt写的，确实很精巧，用set记录了每个可能的情况
    // 因为初始状况是(1,0),就相当于每一次内层循环的第一次都是只选当前组的食物
    // 每一次都会把dp数组过完一遍，相当于在之前的所有情况下加一个 选择当前食物的情况
    ll result = LLONG_MAX;
    for(auto &[acid, bitter] : dp){
        if(acid != 1 || bitter != 0){
            result = min(result, abs(acid - bitter));
        }
    }
    cout << result;
    return 0;
}