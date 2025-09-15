#include <iostream>
#include <vector>
#include <numeric>

// GCC/Clang built-in function for counting set bits
#if defined(__GNUC__) || defined(__clang__)
#define BUILTIN_POPCOUNT __builtin_popcount
#else
// Fallback for other compilers (slower)
int countSetBits(int n)
{
    int count = 0;
    while (n > 0) {
        n &= (n - 1);
        count++;
    }
    return count;
}
#define BUILTIN_POPCOUNT countSetBits
#endif

int main()
{
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    long long total_sum = 0;
    const int MAX_BITS = 30; // 10^8 < 2^27, so 30 is a safe upper bound

    for (int k = 0; k < MAX_BITS; ++k) {
        // counts[k_th_bit][parity_of_lower_bits_popcount]
        long long counts[2][2] = {{0, 0}, {0, 0}};

        int lower_bits_mask = (k == 0) ? 0 : (1 << k) - 1;

        for (int val : a) {
            // Standard 1: Get the k-th bit
            int k_th_bit = (val >> k) & 1;

            // Standard 2: Get the parity of popcount of lower bits
            int lower_bits = val & lower_bits_mask;
            int parity = BUILTIN_POPCOUNT(lower_bits) % 2;

            counts[k_th_bit][parity]++;
        }

        // Pairs from (k-th bit=0, parity=0) and (k-th bit=1, parity=0)
        long long contributing_pairs_parity0 = counts[0][0] * counts[1][0];

        // Pairs from (k-th bit=0, parity=1) and (k-th bit=1, parity=1)
        long long contributing_pairs_parity1 = counts[0][1] * counts[1][1];

        long long total_contributing_pairs = contributing_pairs_parity0 + contributing_pairs_parity1;

        // Add the contribution of the k-th bit to the total sum
        total_sum += total_contributing_pairs * (1LL << k);
    }

    std::cout << total_sum << std::endl;

    return 0;
}