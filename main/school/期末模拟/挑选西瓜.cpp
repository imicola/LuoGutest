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

struct Watermelon
{
    double size, color, sound, score;
};

double computeScore(Watermelon *w)
{
    return (w->color * w->size) / (w->sound);
}

double computeNormalizedScore(Watermelon *w, double maxV, double minV)
{
    return ((w->score - minV) / (maxV - minV)) * 100;
}
signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    cin >> t;
    vector<Watermelon> wa(t);
    for (size_t i = 0; i < t; i++) {
        double s, c, so;
        cin >> s >> c >> so;
        wa[i].size = s;
        wa[i].color = c;
        wa[i].sound = so;
    }
    double max_c = 0, min_c = 1e8;
    for (size_t i = 0; i < t; i++) {
        wa[i].score = computeScore(&wa[i]);
        max_c = max(max_c, wa[i].score);
        min_c = min(min_c, wa[i].score);
    }
    for (size_t i = 0; i < t; i++) {
        printf("%.2lf\n", computeNormalizedScore(&wa[i], max_c, min_c));
    }

    return 0;
}