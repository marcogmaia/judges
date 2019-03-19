// http://codeforces.com/problemset/problem/266/B
#include <algorithm>
#include <iostream>

int main(int argc, char const *argv[]) {
    int q_size, times_to_swap;
    std::string str;
    std::cin >> q_size >> times_to_swap;
    std::cin >> str;

    for(int i = 0; i < times_to_swap; ++i) {
        for(int j = 1; j < q_size; ++j) {
            if(str[j - 1] == 'B' && str[j] == 'G') {
                std::swap(str[j - 1], str[j]);
                // and jump one in the queue, because now str[j] contains a B
                // and the turn is over, otherwise it would swap again.
                ++j;
            }
        }
    }
    std::cout << str << std::endl;

    return 0;
}
