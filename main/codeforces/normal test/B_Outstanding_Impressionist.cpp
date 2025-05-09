#include <iostream>
#include <vector>
#include <string>
#include <numeric>   // Might not be strictly needed for this version
#include <algorithm> // For std::max
#include <tuple>     // For std::tuple and std::make_tuple

// User's defines (or similar competitive programming setup)
// #pragma GCC optimize(3) // Compiler specific, cannot include in standard C++
// #define int LL // If long long is desired, but int seems sufficient here
#define endl '\n'
// #define size_t int // User had this, but std::size_t is standard
// #define all(v) v.begin(), v.end() // Not used in this specific solution structure
// using namespace std; // Generally avoided in headers or shared code, but fine in .cpp

// typedef long long LL; // If #define int LL is used
// typedef vector<int> vint;
// typedef vector<vint> vvint;
// typedef vector<string> vstr;
// typedef pair<int, int> pii;
// typedef vector<pii> vpii;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::tuple<int, int, int>> all_intervals(n);

    // According to the problem: 1 <= l_i <= r_i <= 2*n.
    // So, the maximum coordinate value we need to handle is 2*n.
    // We'll use 1-based indexing for coordinates.
    int max_coord_val = 2 * n;

    // fixed_counts[k] stores how many intervals are fixed at value k (i.e., l_i == r_i == k)
    std::vector<int> fixed_counts(max_coord_val + 2,
                                  0); // +2 for safety for 1-based index up to max_coord_val and potential x+1 access

    std::vector<std::tuple<int, int, int>> flexible_intervals_data;
    flexible_intervals_data.reserve(n); // Pre-allocate memory if n is large

    for (int i = 0; i < n; ++i) {
        int l, r;
        std::cin >> l >> r;
        all_intervals[i] = std::make_tuple(l, r, i); // Store l, r, and original index

        if (l == r) {
            // It's a fixed-point interval
            if (l >= 1 && l <= max_coord_val) { // Ensure l is within expected bounds
                fixed_counts[l]++;
            }
        }
        else {
            // It's a flexible interval
            flexible_intervals_data.emplace_back(l, r, i);
        }
    }

    std::vector<int> ans(n, 1); // Initialize all answers to 1 (unique)

    // 1. Process fixed-point impressions
    // A fixed-point impression i (l_i=r_i=V) is non-unique if fixed_counts[V] > 1
    for (int i = 0; i < n; ++i) {
        int l, r, original_idx;
        std::tie(l, r, original_idx) = all_intervals[i];
        if (l == r) { // This is a fixed-point impression
            if (l >= 1 && l <= max_coord_val) {
                if (fixed_counts[l] > 1) {
                    ans[original_idx] = 0;
                }
            }
        }
    }
    // 2. Process flexible impressions
    // A flexible impression i (L, R) is non-unique if for every x in [L, R],
    // fixed_counts[x] >= 1.
    if (!flexible_intervals_data.empty()) {
        std::vector<bool> is_val_covered_by_fixed(max_coord_val + 2, false);
        for (int val = 1; val <= max_coord_val; ++val) {
            if (fixed_counts[val] >= 1) {
                is_val_covered_by_fixed[val] = true;
            }
        }

        std::vector<int> next_zero_val(max_coord_val + 2);
        // next_zero_val[k] = smallest m >= k such that is_val_covered_by_fixed[m] is false.
        // Initialize sentinel for values beyond max_coord_val
        next_zero_val[max_coord_val + 1] = max_coord_val + 1;

        for (int x = max_coord_val; x >= 1; --x) {
            if (!is_val_covered_by_fixed[x]) {
                next_zero_val[x] = x;
            }
            else {
                next_zero_val[x] = next_zero_val[x + 1];
            }
        }
        for (const auto &interval_data : flexible_intervals_data) {
            int l_flex, r_flex, original_idx;
            std::tie(l_flex, r_flex, original_idx) = interval_data;
            // If the first value >= l_flex not covered by a fixed point is > r_flex,
            // it means all values in [l_flex, r_flex] are covered by fixed points.
            if (l_flex >= 1 && r_flex <= max_coord_val && l_flex <= r_flex) { // Basic sanity checks
                if (next_zero_val[l_flex] > r_flex) {
                    ans[original_idx] = 0;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i];
    }
    std::cout << endl;
}

signed main()
{                                          // Or int main() if not using #define int LL
    std::ios_base::sync_with_stdio(false); // Faster I/O
    std::cin.tie(NULL);                    // Untie cin from cout
    std::cout.tie(NULL);                   // Untie cout (though less common to tie cout explicitly)

    int T = 1;
    std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}