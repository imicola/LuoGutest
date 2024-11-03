#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<bool> not_prime(1e5);
vector<int> prime;

void eprime(int n)
{
    for (size_t i = 2; i <= n; i++) {
        if (!not_prime[i]) prime.push_back(i);
        for (auto &&j : prime) {
            if (i * j > n) break;
            not_prime[i * j] = 1;
            if (i % j == 0) break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    eprime(1010);
    int flag = 0;
    for (auto &&i : prime) {
        cout << i << ",";
        flag++;
    }
    cout << flag;
    return 0;
}