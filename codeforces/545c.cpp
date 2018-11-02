// http://codeforces.com/problemset/problem/545/C
#include <iostream>

int main(int argc, char const *argv[]) {
    // try to use pair instead of a struct
    struct Tree {
        int xi;
        int hi;
    };

    int ntotal;
    int xi, hi;
    std::cin >> ntotal;

    Tree *v = new Tree[ntotal];

    for(int i = 0; i < ntotal; ++i) {
        std::cin >> xi >> hi;
        v[i] = {xi, hi};
    }

    // dp part starts here
    int ans = 0;
    for(int x1 = INT32_MIN, h1 = 0, i = 0; i<ntotal; ++i) {
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