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
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    double cnts = 0;
    double l = -100;
    auto slo = [=](double x) -> double {
        double T_cnt = a * x * x * x + b * x * x + c * x + d;
        return T_cnt;
    };
    double res1 = 0, res2 = 0, res3 = 0, t = 3;
    while (t--) {
        while (slo(l) * slo(l + 1) > 0) {
            l++;
        }
        // cout << "x " << l << " slo(l) " << slo(l) << " slo(l+1) " <<slo(l + 1) << endl;
        if (abs(slo(l + 1)) < 0.0000001 && slo(l) != 0 && slo(l + 2) != 0) {
            printf("%.2f ", l + 1);
            // cout << l + 1 << endl;
            l += 2;
            continue;
        }
        double r = l + 1;
        double lt = l;
        while (lt < r) {
            double mid = (r + lt) / 2;
            // cout << slo(mid) << " " << slo(lt) << " " << lt << " " << r << mid << endl;
            if (abs(slo(lt) * slo(r)) < 0.0000001) {
                printf("%.2f ",
                       slo(r) == 0 ? (r < 0 ? ceil(r * 100) / 100.0 : floor(r * 100) / 100.0)
                                   : (lt < 0 ? ceil(lt * 100) / 100.0 : floor(lt * 100) / 100.0));
                l += 1;
                break;
            }
            if (slo(mid) * slo(lt) < 0) {
                r = mid;
                continue;
            }
            if (slo(mid) * slo(lt) > 0) {
                lt = mid;
                continue;
            }
        }
    }
    return 0;
}