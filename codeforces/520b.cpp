// http://codeforces.com/problemset/problem/520/B
#include <iostream>

int solve(int n, int m) {
    int ans = 0;
    // it is easier if we take the reverse path to the problem
    while(n < m) {
        // if m is odd then we can only add 1
        // else m still greater than n, then we divide
        (m & 1) ? ++m : m >>= 1;
        ++ans;
    }
    // here n >= m, thus we need exactly n-m steps of add 1
    ans += n - m;
    return ans;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::cout << solve(n, m) << '\n';

    return 0;
}