#include <cmath>
#include <iostream>

int main(int argc, char const *argv[]) {
    double n, m, a;
    std::cin >> n >> m >> a;
    std::cout << int(ceil(n / a)) * int(ceil(m / a)) << std::endl;
    return 0;
}
