// http://codeforces.com/problemset/problem/266/B
#include <algorithm>
#include <iostream>


int main() {
    uint32_t q_size, times_to_swap;
    std::string str;
    std::cin >> q_size >> times_to_swap;
    std::cin >> str;
    for(uint32_t i = 0; i < times_to_swap; ++i)
        for(uint32_t j = 1; j < q_size; ++j)
            if(str[j - 1] == 'B' && str[j] == 'G') {
                std::swap(str[j - 1], str[j]);
                ++j;
            }
    std::cout << str << std::endl;
}

