// http://codeforces.com/problemset/problem/1/A
#include <cmath>
#include <iostream>

int main(int argc, char const *argv[]) {
    double n, m, a;
    std::cin >> n >> m >> a;
    std::cout << uint64_t(ceil(n / a)) * uint64_t(ceil(m / a)) << std::endl;
    return 0;
}