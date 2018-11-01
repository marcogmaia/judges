#include <iostream>

#define NMAX 100001

int main(int argc, char const *argv[]) {
    long long n;
    std::cin >> n;
    // new() initialize all elements set to 0
    long long *cnt = new long long[NMAX]();
    long long *dp  = new long long[NMAX]();

    // count how many times each number appear
    while(n--) {
        long long i;
        std::cin >> i;
        ++cnt[i];
    }

    dp[0] = 0;
    dp[1] = cnt[1];
    long long maximum = -1;
    for(long long i = 2; i < NMAX; ++i) {
        // see if the previous has more points than the actual calculation
        // and select the maximum between them
        dp[i]   = std::max(dp[i - 1], dp[i - 2] + (cnt[i] * i));
        maximum = std::max(dp[i], maximum);
    }

    std::cout << maximum << std::endl;

    delete[] cnt;
    delete[] dp;
    return 0;
}