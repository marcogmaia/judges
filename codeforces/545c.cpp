// http://codeforces.com/problemset/problem/545/C
#include <iostream>

int main(int argc, char const *argv[]) {
    struct Tree {
        int xi;
        int hi;
    };

    int t;
    int xi, hi;
    std::cin >> t;

    Tree *v = new Tree[t];

    for(int i = 0; i < t; ++i) {
        std::cin >> xi >> hi;
        v[i] = {xi, hi};
    }

    // dp part starts here
    int ans = 0;
    for(int x1 = INT32_MIN, h1 = 0, i = 0; i<t; ++i) {
        if(v[i].xi <= x1 + h1) {
            --ans;
            h1 = 0;
        }
        if(x1 + h1 < v[i].xi - v[i].hi)
            h1 = 0;
        else
            h1 = v[i].hi;
        x1 = v[i].xi;
        ++ans;
    }

    std::cout << ans << std::endl;

    delete[] v;
    return 0;
}